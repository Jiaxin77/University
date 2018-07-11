package software;
import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.LinkedList;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import testWB.*;
import condition.*;
public class TcpServer {
	public static int PORT = 8800;//监听的端口号 
	public static final Logger log = Logger.getLogger("tesglog");  
	public static SchedulingStrategy sstrategy = new SchedulingStrategy();
	public static LinkedList<Room> roomlist = new LinkedList<Room>();//给ui使用 
	public static server1 UI;
	
	public static void main(String[] args) throws SecurityException, IOException {  
		TcpServer server = new TcpServer(); 
		Setting.init();
		SchedulingStrategy.sev_num = Setting.getSevnum();
		TcpServer.PORT = Setting.getPort();
		
		log.setLevel(Level.ALL);  
        FileHandler fileHandler = new FileHandler("testlog.log");  
        fileHandler.setLevel(Level.ALL);  
        fileHandler.setFormatter(new LogFormatter());  
        log.addHandler(fileHandler); 
        
        //新建ui
        UI = new server1();
        UI.initialize();
        UI.newThread();
        
        Add_state.InitDatabase();
        server.init(); 	
	}  

	public void init() {  
		
		ServerSocket serverSocket = null;
		try {  
			serverSocket = new ServerSocket(PORT);
			//新建调度线程
			/*
			ExecutorService threadPool = Executors.newFixedThreadPool(1);
			SchedulingStrategy scheduleThread = new SchedulingStrategy();
			threadPool.execute(scheduleThread);*/
			sstrategy.start();
			
			//System.out.println("before schedule thread");
			//scheduleThread.start();
			//System.out.println("before listen");
			while (true) {  
				Socket client = serverSocket.accept();//接收连接
				ServerThread serverThread = new ServerThread(client);//创建新线程
				serverThread.start();		
			}  
		} catch (Exception e) {  
			e.printStackTrace();  
		} finally{
			try {
				if(serverSocket != null){
					serverSocket.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}  
}  
	
class ServerThread extends Thread{
	//和本线程相关的SOCKET
	private Socket socket = null;
	private Room room = null;
	
	private int open_count = 0;//开机次数
	private int ex_cmd = -1;//前一个收到的指令
	
	public ServerThread(Socket socket) {
		room = new Room(socket);
		this.socket = socket;
	}
	
	public ServerThread() {
			
	}
	
	public void run() {
		System.out.println("open:"+room.getSock()+"\n");
		InputStream is = null;
		InputStreamReader isr = null;
		BufferedReader br = null;
		DataOutputStream os = null;
		try {
			is = socket.getInputStream();
			isr = new InputStreamReader(is);
			br = new BufferedReader(isr);
			os = new DataOutputStream(socket.getOutputStream());
			while(!room.getExit()) {
				msgDecode(br,os);//解码
			}
		}catch(IOException e) {
			e.printStackTrace();
		}finally {
			try {//关闭资源
				if(os!=null)
					os.close();
				if(br!=null)
					br.close();
				if(isr!=null)
					isr.close();
				if(is!=null)
					is.close();
				if(socket!=null)
					socket.close();
				TcpServer.roomlist.remove(room);
				room = null;
				System.out.println("exit\n");
			}catch(IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	
	public void executeMsg(DataOutputStream os,int res) {
		if(res == 0) {//非法断开连接
			room.setExitTrue();
			TcpServer.roomlist.remove(room);
			return;
		}
		switch(ex_cmd) {
		case CmdConstant.OPEN_CODE:
			if(open_count > 1) {
				msgEncode_open_ack(os,CmdConstant.OPEN_ACK_CODE,0,Setting.getMode(),Setting.getDefault_dst_temp(),Setting.getDefault_speed(),Setting.getLow_temp(),Setting.getHigh_temp(),room.getCost(),room.getEnergy());
			}
			else {
				TempRoomInfo.getOldInfo(this.room);
				TcpServer.roomlist.add(this.room);
				TcpServer.sstrategy.accept(this.room);//加入服务队列
				room.setOpenCost(0);//清记录一次开关机的费用
				msgEncode_open_ack(os,CmdConstant.OPEN_ACK_CODE,1,Setting.getMode(),Setting.getDefault_dst_temp(),Setting.getDefault_speed(),Setting.getLow_temp(),Setting.getHigh_temp(),room.getCost(),room.getEnergy());
				//匹配数据库，查看是否是vip
				if(Add_state.isVIP(room.getRoom_id())) {
					this.room.setIdentify(CmdConstant.VIP);
				}
				else {
					this.room.setIdentify(CmdConstant.COMMON);
				}
				
				this.room.setState(CmdConstant.OPEN);
				
				//开机状态变化 写数据库
				String on_time = Time.timeChange();
				Add_state.update(room.getRoom_id(),on_time,-1);
				Add_state.add_state(room.getRoom_id(),CmdConstant.run,on_time,-1);
				TcpServer.log.info("Room_id:" + room.getRoom_id() +"Temp:" + room.getCur_temp() + "open conditioner\n");
			}
			break;
		case CmdConstant.CLOSE_CODE:
			msgEncode(os,CmdConstant.CLOSE_ACK_CODE,CmdConstant.SUCCESS);
			//关机状态变化 写数据库
			
			
			String off_time = Time.timeChange();
			if(room.getState() == CmdConstant.COMPUTE) {
				Add_state.update(room.getRoom_id(),off_time,room.getSubcost());//更新一次调度的费用
				Add_state.add_state(room.getRoom_id(),CmdConstant.stop,off_time,room.getOpenCost());
			}
			else {
				Add_state.update(room.getRoom_id(),off_time,0);
				Add_state.add_state(room.getRoom_id(),CmdConstant.stop,off_time,room.getOpenCost());
			}
			
			this.room.setState(CmdConstant.CLOSE);
			
			System.out.println("room open cost:"+room.getOpenCost());
			room.setOpenCost(0);
			room.setSubcost(0);
			
			TcpServer.log.info("Room_id:" +  room.getRoom_id() + "close conditioner\n");
			TcpServer.roomlist.remove(room);
			TcpServer.sstrategy.removeList(room);//移出队列
			TempRoomInfo.updateRoomInfo(this.room);
			room.setExitTrue();//跳出循环
			break;
		case CmdConstant.SPEED_CODE:
			msgEncode(os, CmdConstant.SPEED_ACK_CODE,CmdConstant.SUCCESS);
			//查费率
			float feerate = Setting.getFeeRate(room.getSpeed(),room.getIdentify());
			//风速状态变化 写数据库
			Add_state.add_speed(room.getRoom_id(),room.getSpeed(),Time.timeChange(),feerate);
			TcpServer.log.info("Room_id:" +  room.getRoom_id() + "speed:" + room.getSpeed() + "\n");
			break;
		case CmdConstant.TEMP_CODE:
			msgEncode(os, CmdConstant.TEMP_ACK_CODE,CmdConstant.SUCCESS);
			Add_state.add_temp(room.getRoom_id(),room.getDst_temp(),Time.timeChange());
			TcpServer.log.info("Room_id:" +  room.getRoom_id() + "temp:" + room.getDst_temp() +"\n");
			break;
		case CmdConstant.TEMP_BACK_CODE:	
			TcpServer.sstrategy.accept(this.room);//加入服务队列
			//System.out.println("add list:"+TcpServer.sstrategy.que.getFirst());
			break;
		default:
			break;
		}
		ex_cmd = -1;
	}
	
	
	public void msgDecode(BufferedReader br,DataOutputStream os) {
		String msg = "";
		boolean isClose = false;
		char[] ch = new char[500];
		int state = 1;
		for(int i =0;i<500;i++) {
			ch[i] = '!';
		}
		try {
			br.read(ch);
			for(int i = 0;ch[i] != '!' && i < 500;i++ ) {
				msg = msg + ch[i];
			}
			System.out.println(msg);
		} catch (IOException e1) {
			System.out.println("read abnormally exit\n");
			TcpServer.log.info("room" + room.getRoom_id() + "close abnormally!" + "\n");
			e1.printStackTrace();
			
			String off_time = Time.timeChange();
			if(room.getState() == CmdConstant.COMPUTE) {
				Add_state.update(room.getRoom_id(),off_time,room.getSubcost());//更新一次调度的费用
				Add_state.add_state(room.getRoom_id(),CmdConstant.stop,off_time,room.getOpenCost());
			}
			else {
				Add_state.update(room.getRoom_id(),off_time,0);
				Add_state.add_state(room.getRoom_id(),CmdConstant.stop,off_time,room.getOpenCost());
			}
			
			this.room.setState(CmdConstant.CLOSE);
			
			TempRoomInfo.updateRoomInfo(this.room);
			state = 0;
			executeMsg(os,state);//回包
			return ;
		}
		
		//解决粘包问题
		String msglist[] = msg.split("\\*");//第0个为空，从第一个开始
		for(int i = 1;i < msglist.length && !isClose;i ++) {
			String args[] = msglist[i].split("\\|");//拆解协议
			try { 
				if (Integer.parseInt(args[0]) < CmdConstant.OPEN_CODE || Integer.parseInt(args[0]) > CmdConstant.TEMP_BACK_CODE) {
					Exception e = new Exception();
					throw e;
				}
			}
			catch(Exception e){
				ex_cmd = -1;
				return;
			}
			
			this.ex_cmd = Integer.parseInt(args[0]);
			
			switch(Integer.parseInt(args[0])) {//类型转换和解包	
				case CmdConstant.OPEN_CODE:
					open_count ++;
					String room_id = args[1];
					this.room.setRoom_id(room_id);
					room.setCur_temp(Float.parseFloat(args[2]));
					break;
				case CmdConstant.CLOSE_CODE:
					isClose = true;
					break;
				case CmdConstant.SPEED_CODE:
					System.out.println("args:"+args);
					int speed = Integer.parseInt(args[2]);
					this.room.setSpeed(speed);
					System.out.println("speed set:"+room.getSpeed());
					break;
				case CmdConstant.TEMP_CODE:
					//int identifier_t = Integer.parseInt(args[2]);
					float temp = Float.parseFloat(args[2]);/*
					if(Setting.getMode() == CmdConstant.COLD && temp > room.getCur_temp() || Setting.getMode() == CmdConstant.HOT && temp < room.getCur_temp()) {
						//制冷模式下 当前温度低于请求温度以及制热模式下 当前温度高于请求温度 视为不合理请求
						state = 2;
					}*/
					this.room.setDst_temp(temp);
					//目标温度状态变化 写数据库
					
					break;
				case CmdConstant.TEMP_BACK_CODE:	
					float cur_temp = Float.parseFloat(args[2]);
					this.room.setCur_temp(cur_temp);
					String sev_time = Time.timeChange();
					Add_state.update(room.getRoom_id(),sev_time,0);
					Add_state.add_state(room.getRoom_id(),CmdConstant.run,sev_time,-1);
					TcpServer.log.info( "Room_id:" + room.getRoom_id()+ "cur_temp:" + cur_temp +"\n");
					break;
				default:
					break;
			}
			executeMsg(os,state);//回包
				
		}
		
	}
	
	public int msgEncode_open_ack(DataOutputStream out,int cmd,int res,int mode,float default_temp,int speed,float low_temp,float high_temp,float cost,float energy) {
		int state = 0;
		String sendmsg = "";
		if(cmd != CmdConstant.OPEN_ACK_CODE) {
			return state;
		}
		
		sendmsg += "*";
		sendmsg += cmd;
		sendmsg += CmdConstant.DELIMITER;
		sendmsg += res;
		sendmsg += CmdConstant.DELIMITER;
		sendmsg += mode;
		sendmsg += CmdConstant.DELIMITER;
		sendmsg += new BigDecimal(default_temp).setScale(1, BigDecimal.ROUND_HALF_UP).floatValue();
		sendmsg += CmdConstant.DELIMITER;
		sendmsg += speed;
		sendmsg += CmdConstant.DELIMITER;
		sendmsg += new BigDecimal(low_temp).setScale(1, BigDecimal.ROUND_HALF_UP).floatValue();
		sendmsg += CmdConstant.DELIMITER;
		sendmsg += new BigDecimal(high_temp).setScale(1, BigDecimal.ROUND_HALF_UP).floatValue();
		sendmsg += CmdConstant.DELIMITER;
		sendmsg += new BigDecimal(cost).setScale(2, BigDecimal.ROUND_HALF_UP).floatValue();
		sendmsg += CmdConstant.DELIMITER;
		sendmsg += new BigDecimal(energy).setScale(3, BigDecimal.ROUND_HALF_UP).floatValue();
		
		try {
			out.write(sendmsg.getBytes());
			System.out.println("sendmsg:"+sendmsg+"\n");
		}
		catch(Exception e){
			TcpServer.log.info("msgSend error\n");
			e.printStackTrace();
			return state;
		}
		
		state = 1;
		return state;
	}
	
	public int msgEncode(DataOutputStream out,int cmd,int res) {
		int state = 0;
		String sendmsg = "";
		
		sendmsg += "*";
		sendmsg += cmd;
		sendmsg += CmdConstant.DELIMITER;
		sendmsg += res;
		
		try {
			out.write(sendmsg.getBytes());
			System.out.println("sendmsg:"+sendmsg+"\n");
		}
		catch(Exception e){
			TcpServer.log.info("msgSend error\n");
			e.printStackTrace();
			return state;
		}
		state = 1;
		return state;
	}
	
	public int msgEncode_Halt(DataOutputStream out,int cmd,String room_id) {
		int state = 0;
		String sendmsg = "";
		
		sendmsg += "*";
		sendmsg += cmd;
		sendmsg += CmdConstant.DELIMITER;
		sendmsg += room_id;
		
		try {
			out.write(sendmsg.getBytes());
			System.out.println("sendmsg:"+sendmsg+"\n");
		}
		catch(Exception e){
			TcpServer.log.info("msgSend error\n");
			e.printStackTrace();
			return state;
		}
		state = 1;
		return state;
	}
	
	
	public int msgEncode_state(DataOutputStream out,String room_id,float cur_temp,float target_temp,int speed,float energy,float cost) {
		int state = 0;
		String sendmsg = "";
		 
		sendmsg += "*";
		sendmsg += CmdConstant.State_Resp_CODE;
		sendmsg += CmdConstant.DELIMITER;
		sendmsg += room_id;
		sendmsg += CmdConstant.DELIMITER;	
		sendmsg += new BigDecimal(cur_temp).setScale(1, BigDecimal.ROUND_HALF_UP).floatValue(); 
		sendmsg += CmdConstant.DELIMITER;
		sendmsg += new BigDecimal(energy).setScale(3, BigDecimal.ROUND_HALF_UP).floatValue(); 
		sendmsg += CmdConstant.DELIMITER;
		sendmsg += new BigDecimal(cost).setScale(2, BigDecimal.ROUND_HALF_UP).floatValue(); 
		try {
			out.write(sendmsg.getBytes());
			System.out.println("sendmsg:"+sendmsg+"\n");
		}
		catch(Exception e){
			TcpServer.log.info("msgSend error\n");
			e.printStackTrace();
			return state;
		}
		state = 1;
		return state;
	}
	
}

