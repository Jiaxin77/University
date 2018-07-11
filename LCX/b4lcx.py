import argparse
import asyncio
import base64
import hashlib
import logging
import random
import struct


cmd_chap,cmd_bind,cmd_conn,cmd_data, = range(4)#创建一个整数列表，即cmd_chap=0，cmd_bind=1，以此类推
cmd_dict = {0:'chap', 1:'bind', 2:'conn', 3:'data'}#控制字段字典
listen_conn_id_last = 0

async def wait_conn_event(event):#等待连接事件
    await event.wait()

async def listen_do_client(reader, writer):#remote listen端对remote client端的操作
    peer_host, peer_port, = writer.get_extra_info('peername')#peername为对方的地址
    sock_host, sock_port, = writer.get_extra_info('sockname')#sockname为自己的地址
    log.info('S L R<C open {:5} < {:5}'.format(sock_port, peer_port))#日志的信息代表是remote client发给remote listen的，已经开启连接
	#获取slave端的读写流，是从remote listen端的绑定字典中根据与client端相连的本地端口查到的（此字典在slave发给listen监听端口时写入）
    reader_for_slave, writer_for_slave, = listen_bind_dict[sock_port]

    global listen_conn_id_last #定义一个全局量，指示目前最后一个连接的id
    listen_conn_id_last += 1 #id+1，因为新增了一个连接
    conn_id = listen_conn_id_last#连接id等于当前id
	#remote listen发给local slave的conn消息，消息格式为BHS，标识conn_id，b为字节序 connect-request
    msg_send('R', writer_for_slave, 'BHS', cmd_conn, conn_id, b'1')

    conn_event = asyncio.Event()#创建连接事件
    listen_conn_dict[conn_id] = reader_for_slave, writer, conn_event#将此reader流，writer流和连接事件加入到remote listen的连接字典中

    try:
        await asyncio.wait_for(wait_conn_event(conn_event), 40)#等待连接事件
    except Exception as e:#出现异常
        log.warning('S L R>C shut {:5} > {:5} exc {}'.format(sock_port, peer_port, e.args))#Remote Listen发给Remote Client的异常关闭消息
        listen_conn_dict.pop(conn_id, None)#去掉最新的conn_id，因为异常断开了
        writer.close()#写消息流关闭
        return

    while True:
        data = await raw_recv('R', reader, writer)#等待收到来自Remote client的消息 
        if not data:
            break
        msg_send('R', writer_for_slave, 'BHS', cmd_data, conn_id, data)#将此数据发给slave

    if not conn_id in listen_conn_dict:#conn-id不在连接字典中
        return
    msg_send('R', writer_for_slave, 'BHS', cmd_conn, conn_id, b'0')#将连接消息也发给slave
	#当长时间未收到消息时，会执行到此步，即为超时断开，会将此conn-id从连接字典中中去除。
    listen_conn_dict.pop(conn_id, None)
	

async def listen_do_slave(reader, writer):#remote listen对local slave端做的
    peer_host, peer_port, = writer.get_extra_info('peername')
    sock_host, sock_port, = writer.get_extra_info('sockname')
    log.info('S L>R C open {:5} < {:5}'.format(sock_port, peer_port))#将local slave发给remote listen的端口号记录日志
	#CHAP认证
    salt = str(random.randint(100000,999999)).encode('utf8')#获取salt中的随机数
    msg_send('R', writer, 'BS', cmd_chap, salt)#发送chap-salt

    err, cmd, username, digest, = await msg_recv('R', reader, writer, 'BSS', cmd_chap)#从收到来自local slave端的chap-hash中提取username等信息
    if err:
        return

    if not listen_user_dict.get(username, None):
		#发现listen remote存储用户名和密码的字典中没有此用户名，返回错误用户名提示
        log.error('S L<R C shut {:5} > {:5} error username {}'.format(sock_port, peer_port, username))
        writer.close()
        return

    if digest != base64.b64encode(hashlib.md5(username + listen_user_dict[username] + salt).digest()):
		#发现listen remote中的用户名和salt进行MD5加密后和从local slave中发过来的不一致
        log.error('S L<R C shut {:5} > {:5} error digest {}'.format(sock_port, peer_port, digest))#记录下错误验证
        writer.close()
        return

    err, cmd, bind_port = await msg_recv('R', reader, writer, 'BH', cmd_bind)#从收到来自local slave端的端口绑定消息(bind-request)中提取端口等信息
    if err:
        return

    server = None
    try:
        coro = asyncio.start_server(listen_do_client, '0.0.0.0', bind_port, loop=loop)#连接到绑定端口，进入事件循环
        server = await asyncio.wait_for(asyncio.ensure_future(coro), None)#ensure_future创建一个task
        bind_port = server.sockets[0].getsockname()[1]#若未给bind_port，则随机分配一个
 
        listen_bind_dict[bind_port] = reader, writer#将读写流存入绑定字典

        msg_send('R', writer, 'BH', cmd_bind, bind_port)#回给local slave端bind-response消息
    except Exception as e:#发生异常
        log.error('S L<R C shut {:5} < {:5} bind_port {} exc {}'.format(sock_port, peer_port, bind_port, e.args))#日志记录remote listen发给local slave的绑定异常，关闭消息
        writer.close()
        return

    while True:
        err, cmd, conn_id, data = await msg_recv('R', reader, writer, 'BHS', cmd_conn, cmd_data)# 收到来自local slave连接和数据消息
        if not err:
            reader_for_slave, writer_for_client, conn_event, = listen_conn_dict.get(conn_id, (None,None,None))#根据连接id获取读写流，连接事件信息
            if not writer_for_client:
                continue
            if reader_for_slave != reader: #如果通过conn_id查出来的此reader不是收消息的reader，为了避免conn_id冲突的问题，conn_id只能由listen指定
                log.error('S L<R C shut {:5} > {:5} conn_id {} error'.format(sock_port, peer_port, conn_id))
                writer.close()
                err = True
        if err:#如果出现错误
            close_list = [(conn_id, reader_for_slave, writer_for_client) for conn_id, (reader_for_slave, writer_for_client, conn_event) in listen_conn_dict.items()]#将出现错误的连接的信息加入closelist中
            for (conn_id, read_for_slave, writer_for_client) in close_list:#关闭所有出现错误的写流，并从连接字典中删去
                if reader_for_slave == reader:
                    writer_for_client.close()
                    listen_conn_dict.pop(conn_id, None)
            listen_bind_dict.pop(bind_port)#从绑定字典中删去
            server.close()
            await server.wait_closed()
            return

        client_host, client_port, = writer_for_client.get_extra_info('peername')
        if cmd == cmd_conn:#如果是连接消息
            listen_conn_dict[conn_id][2].set()#设置连接字典
            state = int(data)#将data域转为int型
            if not state:#如果为0，出现错误，无data发送
                log.info('S L R>C shut {:5} > {:5}'.format(bind_port, client_port))#日志记录remote listen向remote client发送关闭
                listen_conn_dict.pop(conn_id, None)#关闭写流，并从连接字典中删去
                writer_for_client.close()
        elif cmd == cmd_data:#如果是数据
            raw_send('R', writer_for_client, data)#remote listen将其发送给remote client
			
#消息接收函数，收到消息的处理。 其中role代表是角色，即是local slave还是remote listen。fmt为格式，expect_cmds为消息类型
async def msg_recv(role, reader, writer, fmt, *expect_cmds):
    direct_dict = {'L':'<', 'R':'>'}#字典定义方向
    direct = direct_dict[role]#通过查询字典确定方向
    result =[True]#初始值
    result.extend([None for x in fmt])#初始result数组大小，根据fmt动态获取

    peer_host, peer_port, = writer.get_extra_info('peername')#获取对方地址，端口号
    self_host, self_port, = writer.get_extra_info('sockname')#获取自己地址，端口号

    msg = None#初始化消息
    try:
        data = await reader.readexactly(2)#读取前两位数据-即message-lenth
        if not data:#读取失败
            log.error('S L{}R C recv {:5} < {:5} err EOF msg_len'.format(direct, self_port, peer_port))#日志记录错误信息，消息为空。LR之间填写之前从字典中查到的方向，之后填写本地端口和对方端口：如【举例】
            writer.close()
            return result
        msg_len, = struct.unpack('!H', data)#struct结构体解包，!代表为大端方式，H代表为C语言的unsignedshort类型 
        if not msg_len:#msg_len=0
            log.error('S L{}R C recv {:5} < {:5} err ZERO msg_len'.format(direct, self_port, peer_port))#记录错误信息，长度为0
            writer.close()
            return result

        msg = await reader.readexactly(msg_len)#读取msg_len长度的消息，即读取消息体
        if not msg:#消息体读取失败
            log.error('S L{}R C recv {:5} < {:5} err EOF msg_body'.format(direct, self_port,  peer_port))#日志记录错误信息，消息体读取失败
            writer.close()
            return result
        if not msg[0] in expect_cmds:#如果消息体第一位，即command域不在cmd列表中
		#日志记录错误信息，提示当前收到的cmd不在cmd列表中
            log.error('S L{}R C recv {:5} < {:5} err cmd {} expect {}'.format(direct, self_port, peer_port, msg[0], expect_cmds))
            writer.close()
            return result
    except Exception as e:#遇到异常
        log.warning('S L{}R C shut {:5} < {:5} exc {}'.format(direct, self_port, peer_port, e.args))#记录警告信息
        writer.close()
        return result
#解包
    unpack_dict = {'B':1, 'H':2}#解包字典，H为两位，B为1位
    pos = 0#位置为0
    try:
        for i,c in enumerate(fmt):#enumerate用于遍历索引和遍历元素。i为索引，c为元素。fmt为传入的形式，如‘BHS’
            if c == 'S':#如果元素为S（char[],python string型）
                s_len, = struct.unpack('!H', msg[pos:pos+2])#消息长度为前两位，类型为unsigned short，python integer
                pos += 2#位置向后移两位
                s_val, = struct.unpack('!{}s'.format(s_len), msg[pos:pos+s_len])#值为根据上面获得的s_len数据长度而从msg中定位到的部分
                pos += s_len#位置向后移
                result[i+1] = s_val#将值存入result数组
            else:
                v_len = unpack_dict[str(c)]#如果不是S，从unpack字典中看此形式对应的长度是多少（B-1，H-2）
                v_val, = struct.unpack('!' + str(c), msg[pos:pos+v_len])#则直接根据此长度获取值
                pos += v_len#位置后移
                result[i+1] = v_val#将值存入result数组
    except Exception as e:#遇到异常
        log.error('S L{}R C recv {:5} < {:5} exc {}'.format(direct, self_port, peer_port, e.args))
        writer.close()
        return

    log.info('S L{}R C {} {:5} < {:5} {}'.format(direct, cmd_dict[msg[0]], self_port, peer_port, result[2:]))#记录日志，记录下消息方向，消息类型（从cmd字典中根据消息体cmd字段的值查到），自己端口，对方端口，和保存下来的消息体
    result[0] = False
    return result#返回结果
#
def msg_send(role, writer, fmt, *args):#消息发送函数，角色为L或R，同消息接收函数。fmt为格式，args为收到的消息内容
    direct_dict = {'L':'>', 'R':'<'}
    direct = direct_dict[role]#根据方向字典查到方向

    peer_host, peer_port, = writer.get_extra_info('peername')#获取对方地址，端口号
    self_host, self_port, = writer.get_extra_info('sockname')#获取自己地址，端口号

    log.info('S L{}R C {} {:5} > {:5} {}'.format(direct, cmd_dict[args[0]], self_port, peer_port, args[1:]))#记录日志，记录发送方向，读取消息第一位作为cmd，查询字典，得到消息类型显示。记录自己端口，对方端口，以及之后的消息内容

    struct_fmt = '!'#格式字符串为大端模式
    struct_args = []#包的消息部分，为链表
    for i,c in enumerate(fmt):#遍历fmt
        if c == 'S':#若为string型
            struct_fmt += 'H{}s'.format(len(args[i]))#格式字符串加上H+此部分消息长度+s
            struct_args.extend([len(args[i]), args[i]])#包的消息部分扩展，加上消息长度和对应消息
        else:
            struct_fmt += str(c)#直接加上消息形式
            struct_args.append(args[i])#包的消息部分扩展，直接加上消息

    data = struct.pack(struct_fmt, *struct_args)#要发出的数据为格式和消息链表打包而成
    msg = struct.pack('!H', len(data)) + data#要发出的消息为消息格式，数据长度和数据打包而成
    writer.write(msg)#放入写流，发出


async def raw_recv(role, reader, writer):#用于Local Server发送给Local Slave的消息处理和Remote Client发送给Remote Listen之间的消息处理
    direct_dict = {'L':('>',' '), 'R':(' ','<')}#方向字典，可能有方向，也可能为空
    direct = direct_dict[role]#获取方向

    peer_host, peer_port, = writer.get_extra_info('peername')#获取对方地址，端口号
    self_host, self_port, = writer.get_extra_info('sockname')#获取自己地址，端口号

    data = None#初始化数据
    try:
        data = await reader.read(65530) ## 读取数据，max data_content is 65528 = 65535 - 1(cmd) - 2(conn_id) -2(data_len) 
        if not data:#读取失败
            log.info('S{}L R{}C shut {:5} < {:5}'.format(direct[0], direct[1], self_port, peer_port))#记录方向和端口，关闭信息
            writer.close()
            return
    except Exception as e:#发生异常
        log.error('S{}L R{}C shut {:5} < {:5} exc {}'.format(direct[0], direct[1], self_port, peer_port, e.args))#记录方向和端口，异常关闭信息
        writer.close()
        return
    log.info('S{}L R{}C recv {:5} < {:5} {}'.format(direct[0], direct[1], self_port, peer_port, data))#记录方向（若SL之间有方向，则RC直接为空格），端口和收到的数据
    return data


def raw_send(role, writer, data):##用于Local Slave发送给Local Server之间的消息处理和Remote Listen发送给Remote Client之间的消息处理
    direct_dict = {'L':('<',' '), 'R':(' ','>')}#方向字典，可能有方向，也可能为空
    direct = direct_dict[role]#获取方向

    peer_host, peer_port, = writer.get_extra_info('peername')#获取对方地址，端口号
    self_host, self_port, = writer.get_extra_info('sockname')#获取自己地址，端口号

    log.info('S{}L R{}C send {:5} < {:5} {}'.format(direct[0], direct[1], self_port, peer_port, data))#记录方向（若SL之间有方向，则RC直接为空格），端口和收到的数据
    writer.write(data)#放入写流，发出

#Local Slave的监听处理。参数有远端地址，远端端口，用户名，密码，本地地址，本地端口，绑定端口（默认为0，具体方式见方案设计）
async def slave_do_listen(remote_host, remote_port, username, password, local_host, local_port, bind_port=0):
    reader, writer = await asyncio.open_connection(remote_host, remote_port, loop=loop)#打开连接
    sock_host, sock_port = writer.get_extra_info('sockname')#获取本地地址和本地端口
    log.info('S L>R C open {:5} > {:5}'.format(sock_port, remote_port))#日志记录Local Slave给Remote Listen发送连接开启消息
	#先进行CHAP认证
    err, cmd, salt = await msg_recv('L', reader, writer, 'BS', cmd_chap)#收到消息，是来自Remote Listen的，格式为BS，类型为chap认证消息（chap-salt）
    if err:
        return
	#发送消息，给Remote Listen，类型为CHAP认证，同时发送用户名，和hash的MD5加密结果，为chap-hash消息
    msg_send('L', writer, 'BSS', cmd_chap, username, base64.b64encode(hashlib.md5(username + password + salt).digest()))
    msg_send('L', writer, 'BH', cmd_bind, bind_port)#给Remote Listen发送绑定消息，其中包括请求监听的端口号。（bind-request）

    err, cmd, bind_port = await msg_recv('L', reader, writer, 'BH', cmd_bind)#收到来自remote listen的bind-request消息
    if err:
        return

    while True:#循环接收数据
        err, cmd, conn_id, data = await msg_recv('L', reader, writer, 'BHS', cmd_conn, cmd_data)#收到来自remote listen的bind request消息
        if err:
            continue
        writer_for_server = slave_conn_dict.get(conn_id, None)#从slave的连接字典中获取给local server的写流
        if cmd == cmd_conn:#如果消息类型command为连接消息
            state = int(data)#强制类型转换
            if state:
                if not writer_for_server:#如果和local server端未建立读写流，新开一个
                    loop.create_task(slave_do_server(local_host, local_port, conn_id, writer))#创建任务
                # else:
                #     log.error('S L>R C shut {:5} > {:5} conn_id {} state {} error conn_id'.format(sock_port, remote_port, conn_id, state))
                #     writer.close()
                #     return
            elif writer_for_server:#如果已建立读写流
                self_host, self_port, = writer_for_server.get_extra_info('sockname')#获取本地地址和本地端口
                log.info('S<L R C shut {:5} > {:5}'.format(self_port, local_port))#日志记录
                slave_conn_dict.pop(conn_id, None)#从连接字典中移出
                writer_for_server.close()
            # else:
            #     log.error('S L>R C shut {:5} > {:5} conn_id {} state {} error conn_id'.format(sock_port, remote_port, conn_id, state))
            #     writer.close()
            #     return
                
        elif cmd == cmd_data:#消息类型是数据
            if not writer_for_server:#如果没有建立对server端的连接，就新开一个
                # log.error('S L>R C shut {:5} > {:5} conn_id {} data_len {} error conn_id'.format(sock_port, remote_port, conn_id, len(data)))
                # writer.close()
                msg_send('L', writer, 'BHS', cmd_conn, conn_id, b'0')#发送给remote listen的conn-response消息
                continue
            raw_send('L', writer_for_server, data)#发送给Local server的数据


async def slave_do_server(local_host, local_port, conn_id, writer_for_listen):#参数有本地地址，本地端口，连接id，对listen的写流
    sock_port = '-----'#本地端口
    speer_host, speer_port, = writer_for_listen.get_extra_info('peername')#获取对方地址，端口号
    slave_host, slave_port, = writer_for_listen.get_extra_info('sockname')#获取自己地址，端口号

    log.info('S<L R C conn {:5} > {:5}'.format(sock_port, local_port))#local slave发给local server的连接消息
    try:
        reader, writer = await asyncio.open_connection(local_host, local_port, loop=loop)#打开连接
        sock_host, sock_port, = writer.get_extra_info('sockname')#获取自己地址，端口号
        log.info('S<L R C open {:5} > {:5}'.format(sock_port, local_port))#已打开连接
        msg_send('L', writer_for_listen, 'BHS', cmd_conn, conn_id, b'1')#给remote listen发送connect-response消息
        slave_conn_dict[conn_id] = writer#在local slave端的连接字典中，此conn-id对应值为当前和local server之间的writer。
        while True:
            data = await raw_recv('L', reader, writer)#接收来自local server的数据
            if not data:
                break
            msg_send('L', writer_for_listen, 'BHS', cmd_data, conn_id, data)#消息类型为数据，将此数据发送给remote listen
    except Exception as e:#出现异常
        log.warning('S<L R C conn {:5} > {:5} exc {}'.format(sock_port, local_port, e.args))#记录warning异常

    if conn_id in slave_conn_dict:#长时间未收到数据，超时后，如果conn_id在slave的conn字典里 
        slave_conn_dict.pop(conn_id, None)#将其移出
        msg_send('L', writer_for_listen, 'BHS', cmd_conn, conn_id, b'0')#并通知remote listen

		#直接运行，相当于main
#日志级别等级：critical>error>warning>info>debug

# log_fmt = logging.Formatter('%(lineno)-3d %(levelname)7s %(funcName)-16s %(message)s')
log_fmt = logging.Formatter('%(lineno)-3d %(levelname)7s %(message)s')#日志的格式为：3为日志序号，7位string【测试中看】，string类型信息
log_handler = logging.StreamHandler()#流Handler,能够支持write()和flush()方法的对象
log_handler.setLevel(logging.DEBUG)#大于等于debug级别都会被显示
log_handler.setFormatter(log_fmt)#设置日志的格式
log = logging.getLogger(__file__)#输出信息之前获得一个logger，对应了程序的模块名（file）
log.addHandler(log_handler)#增加log_handler
log.setLevel(logging.DEBUG)#大于等于debug级别都会被显示

parser = argparse.ArgumentParser(description='asyncio lcx demo.')#创建一个解析器对象，给一个描述
subparsers = parser.add_subparsers(dest='mode', help='mode help')#增加子命令解析器，mode和help
#读取命令行运行信息
#listen
parser_listen = subparsers.add_parser('listen', help='listen mode help')#在子解析器中还要加上解析器
parser_listen.add_argument('-p', dest='port', required=True, type=int, help='Port listend for slave side')
parser_listen.add_argument('-u', dest='users', required=True, help='Users in format username:password[,...]')
#slave
parser_slave = subparsers.add_parser('slave', help='slave mode help')
parser_slave.add_argument('-b', dest='bind', type=int, default=0, help='Bind port in remote listen default 0')
parser_slave.add_argument('-l', dest='local', required=True, help='Local server address in slave mode when got CONNECT_REQ')
parser_slave.add_argument('-r', dest='remote', required=True, help='Remote listen address in format host:port')
parser_slave.add_argument('-u', dest='user', required=True, help='User in format username:password')

args = parser.parse_args()
log.info('='*40)#分界线

listen_bind_dict = dict()  ## key:bind_port val:reader_for_slave, writer_for_slave ，remote listen绑定端口字典
listen_conn_dict = dict()  ## key:conn_id   val:reader_for_slave, writer_for_client， remote listen连接id字典
listen_user_dict = dict()  ## key:username  val:password ，remote listen用户名密码字典

loop = asyncio.get_event_loop() #事件循环

slave_conn_dict = dict() ## key:conn_id val:(reader_for_server, writer_for_server) ，local slave连接字典

if args.mode == 'listen':#若模式为listen，代表此时为remote listen端
    listen_user_dict = {k.encode('utf8'):v.encode('utf8') for k,v in (x.split(':',1) for x in args.users.split(','))}#读取地址和端口号和用户名密码
    coro = asyncio.start_server(listen_do_slave, '0.0.0.0', args.port, loop=loop)#启动服务器
    server = loop.run_until_complete(coro)
    log.info('S L:R C bind {:5}'.format(args.port))#绑定端口号
    try:
        loop.run_forever()#事件一直持续循环
    except KeyboardInterrupt:#键盘中断
        pass
    server.close()#关闭服务器端
    loop.run_until_complete(server.wait_closed())#停止等待响应
elif args.mode == 'slave':#若模式为slave，代表此时为local slave端
    local_host, local_port = args.local.split(':', 1)#读取自己地址和端口号
    remote_host, remote_port = args.remote.split(':', 1)#读取remote listen地址和端口号
    username, password = args.user.split(':', 1)#读取自己username和password
    try:
        loop.run_until_complete(slave_do_listen(remote_host, remote_port, username.encode('utf8'), password.encode('utf8'), local_host, local_port, args.bind))#事件循环执行
    except KeyboardInterrupt:#键盘中断
        pass
else:
    parser.print_help()#输出帮助

loop.close()
