/******************************************************************
文件名:file.c
创建人:万诗婕
日　期:2017-04-20
修改人:万诗婕、张宇、高楠、刘佳鑫
日　期:2017-05
描　述:本文件中包含了所有程序中涉及文件操作的函数。实现了用文件初始化程序，存储运行结果，更新文件信息等与文件操作相关的所有功能。
版　本: v050602
******************************************************************/

#include<fstream>
#include"mytype.h"
#include <string>
#include <QString>
#include <iostream>
#include "BOOKCLASS.h"
#include "READERCLASS.h" 
#include "file.h" 
#include<windows.h>
#include <QDebug>
#include <QFile>
#include <stdio.h>
#include "TimeMgt.h"
using namespace std;


/*****************************************************************
函数名：void InitiateCodeList(PubCodeList *pl,AuCodeList *al)
功能：从文件中读取信息，初始化出版社和作者编码的编码表
返回值：
    无
参数：
自定义的结构体变量：PubCodeList* pl，AuCodeList* al
分别存储出版社名称及其对应编码和作者名称及其对应编码
****************************************************************/

void InitiateCodeList(PubCodeList *pl,AuCodeList *al){//从文件中读取出版社和作者编码信息 
    ifstream pubfile("..\\project2\\initiate\\PubCode.txt");
    ifstream aufile("..\\project2\\initiate\\AuCode.txt");
	 
	
	if(NULL==pl||NULL==al){
		printf("内存分配失败！！\n");
	} 
	else{
		int i; 
		for(i=0;!pubfile.eof();i++){
			pubfile>>pl[i].pub;
			pubfile>>pl[i].code;
		}
		pl[i].pub='\0';//为数组结尾做标记 
		pl[i].code=-1;
	/*	for(i=0;pl[i].code!=-1;i++){
			cout<<pl[i].pub<<endl;
			cout<<pl[i].code<<endl;
		}*/
		for(i=0;!aufile.eof();i++){
			aufile>>al[i].Au;
			aufile>>al[i].code;
		}
		al[i].Au='\0';//为数组结尾做标记 
		al[i].code=-1;
	/*	for(i=0;al[i].code!=-1;i++){
			cout<<al[i].Au<<endl;
			cout<<al[i].code<<endl;
		}*/
	}
	pubfile.close();
	aufile.close();
} 

/*****************************************************************
函数名：long long CreateBookID(Book* p,BookType t ,string Author,string Publish,int index,PubCodeList *pl,AuCodeList *al)
功能：根据图书的类型，作者和出版社生成新增图书的图书编号
返回值：
    新增图书的图书编号
参数：
自定义的类变量：Book* p
存储图书馆馆藏图书的详细信息的对象数组，Book是图书类
自定义的结构体变量：PubCodeList*，AuCodeList*
分别存储出版社名称及其对应编码和作者名称及其对应编码，传入的是编码表（即两个结构体数组）
自定义的枚举类型：BookType t，传入新增图书的类型
enum BookType{humanity,science,social,art,compre}; //人文，理工，社科，艺术，综合
string Author,string Publish
传入新增图书的作者和出版社
int index
当前内存中存储的图书总数（大于等于实际库存总数，因为我们在注销图书时只是将图书状态置为“注销”）
****************************************************************/

long long CreateBookID(Book* p,BookType t,string Author,string Publish,int index,PubCodeList *pl,AuCodeList *al)//index：当前内存中存有的图书本数（包含过程中被删除的）
{
	long long type,pub,aut,flow,lastflow;
	long long newid,lastid;
	
	lastid=p[index-1].GetBookID();//内存中最后一本书的流水号是不是一定是最大的？？？？？？？？？？？？？？？？ 
	lastflow=(lastid%100000)/100;//获取最大流水号
	flow=lastflow+1;//生成新的流水号 
	type=BookTypeEncode(t);//查表得到当前类型的编码
	pub=PublishEecode(Publish,pl);//查表得到当前出版社的编码，如果表中存在直接返回值，不存在则需要重新追加编码 
	aut=AuthorEncode(Author,al);//查表得到当前读者的编码 ，如果表中存在直接返回值，不存在则需要重新追加编码 
	newid=type*10000000000+pub*100000000+aut*100000+flow*100;//得到新的图书编号
	
	return newid; 
 }
/*****************************************************************
函数名：int BookTypeEncode(enum BookType t)
功能： 对图书类型进行编码
返回值：
    类型编码
参数：
自定义的枚举类型：BookType t，传入新增图书的类型
enum BookType{humanity,science,social,art,compre}; //人文，理工，社科，艺术，综合
****************************************************************/
int BookTypeEncode(enum BookType t){//对图书类型进行编码 
	return (int)t+10;//保证类型编码是两位， 
} 
/*****************************************************************
函数名： int PublishEecode(string s,PubCodeList *pl){
功能： 先搜寻已存在的出版社编码表，如果出版社已存在，直接返回该出版社的编码，如果出版社不存在则新增编码，并返回编码
返回值：
    出版社编码
参数：
    string s，传入的新增图书出版社字符串
自定义的结构体变量：PubCodeList* pl
存储出版社名称及其对应编码，传入的是编码表（即结构体数组）
****************************************************************/

int PublishEecode(string s,PubCodeList *pl){//对出版社进行编码 
	int i;
	
	for(i=1;i<=pl[0].code;i++){//先遍历表，找到对应的出版社直接返回编码即可 
		if(pl[i].pub.compare(s) == 0){
			return pl[i].code;
		}
	}
	pl[i].pub=s;//没找到改出版社，需要新增出版社，并为其编码 
	pl[i].code=pl[i-1].code+1;
    pl[0].code++;

	return pl[i].code; 
} 
/*****************************************************************
函数名： int AuthorEncode(string s,AuCodeList *al)
功能： 先搜寻已存在的作者编码表，如果作者已存在，直接返回该作者的编码，如果作者不存在则新增编码，并返回编码
返回值：
    作者编码
参数：
    string s，传入的新增图书作者字符串
自定义的结构体变量：AuCodeList *al
存储作者名称及其对应编码，传入的是编码表（即结构体数组）
****************************************************************/

int AuthorEncode(string s,AuCodeList *al){//对作者进行编码 
	int i;
	
	for(i=1;i<=al[0].code;i++){
		if(al[i].Au==s){
			return al[i].code;
		}
	}
	al[i].Au=s;
	al[i].code=al[i-1].code+1;
    al[0].code++;
	
	return al[i].code;
}
/*****************************************************************
函数名： int GetBookInformation(Book *p)
功能： 从文件中读取在库图书的详细信息以及上一次退出系统时的系统时间
返回值：
    当前在库图书的总数
参数：
自定义的类变量：Book* p
存储图书馆馆藏图书的详细信息的对象数组首地址，Book是图书类
****************************************************************/

int GetBookInformation(Book *p)
{
	
	int num;
	string ID,BName,Type,Aname,Pub,Price,Enum,Total,Bnum,Rnum,Num,Time;//暂存文件中每一行的提示中文 
	int exnum,total,bnum,rnum;
	long long id=0;
	float price;
	string bname,aname,pub,type,temp;
	OneBook ob[10];//暂存子书信息的数组 
	
    ifstream bookfile("..\\project2\\initiate\\BookInfo.txt");//以只读方式打开一个文件
	bookfile>>Time;
	bookfile>>TIME;
	bookfile>>Num;//吧“图书总数”四个字读出来 
	bookfile>>num;//把图书总数读出来

	for(int i=0;i<num&&(! bookfile.eof() ) ;i++){
		p[i].SetBBS(begin);
		bookfile>>ID;//读取第i本书的图书编号 
		bookfile>>id;
		p[i].SetBookID(id);

		bookfile>>BName;//读取第i本书的图书名称 
		bookfile>>bname;

		p[i].SetBookName(bname);

		bookfile>>Type;//读取第i本书的图书类型 
		bookfile>>type;
		enum BookType t;
        t=_TransBookType(type);//查表转换类型函数
		p[i].SetBT(t); 

		bookfile>>Aname;//读取第i本书的作者名称 
		bookfile>>aname;

		p[i].SetAuthor(aname); 

		bookfile>>Pub;//读取第i本书的出版社 
		bookfile>>pub;

		p[i].SetPublish(pub); 

		bookfile>>Price;//读取第i本书的价格 
		bookfile>>price;
		p[i].SetPrice(price); 

		bookfile>>Enum;//读取第i本书的在库可借本数 
		bookfile>>exnum;
		p[i].SetExist(exnum); 

		bookfile>>Total;//读取第i本书的馆藏总数 
		bookfile>>total;
		p[i].SetTotal(total); 

		bookfile>>Bnum;//读取第i本书的借出次数 
		bookfile>>bnum;
		p[i].SetBoCount(bnum); 

		bookfile>>Rnum;//读取第i本书的预约本数 
		bookfile>>rnum;
		p[i].SetReBook(rnum); 

		GetReserveInformation(p,i);//读取预约单中的信息 

		for(int j = 0;j<6;j++){
			bookfile>>temp;
			//读取提示文字“子书信息”
		}

		int tid;
		string state;
		for(int j=0;j<total;j++){//读取子书的信息，暂定最多10本 
			bookfile>>tid;
			bookfile>>state;

			//查表转换状态函数/////////////////////////////
            ob[j].OBS=_TransOBState(state);
            if(ob[j].OBS == initiate){
                            ob[j].OBS=Oinstore;
                        }
            p[i].SetOBState(j,ob[j].OBS);
			bookfile>>ob[j].ReaderID;
			p[i].SetOBReID(j,ob[j].ReaderID);
			bookfile>>ob[j].PassDays;
			p[i].SetOBPassDay(j,ob[j].PassDays);
			bookfile>>ob[j].BoTime;
			p[i].SetOBBoTime(j,ob[j].BoTime);
		}
		p[i].SetBBS(instore);
	}
	
	bookfile.close();
	
	return num;
}
/*****************************************************************
函数名： bool UpdateBookInformation(Book *p,int amount,const int Booktotal)
功能： 更新图书馆馆藏图书的信息变化
返回值：
bool型变量，用来标记更新是否成功
参数：
自定义的类变量：Book* p
存储图书馆馆藏图书的详细信息的对象数组首地址，Book是图书类
int amount，当前图书馆内馆藏图书的实际本数
const int Booktotal
当前内存中存储的图书总数（大于等于实际库存总数，因为我们在注销图书时只是将图书状态置为“注销”）
****************************************************************/

bool UpdateBookInformation(Book *p,int amount,const int Booktotal){//Booktotal:内存中图书的总数 ,有效的图书总数 
	char buffer[]="子书编号	子书状态	相关读者编号	逾期天数	借书时间";//存提示文字“ 子书编号	子书状态	相关读者编号	逾期天数	借书时间” 
	string Amount="图书总数",ID="图书编号",BName="图书名称",Type="图书类型",Time="系统时间",
			Aname="图书作者",Pub="图书出版社",Price="图书价格",Enum="在库可借本数",
			Total="图书馆藏总数",Bnum="借出次数",Rnum="已预约本数",temp="子书信息";//暂存文件中每一行的提示中文 
	int exnum,total,bnum,rnum;
	long long id;
	float price;
	string bname,aname,pub,type;
    ofstream bookfile("..\\project2\\initiate\\BookInfo.txt");
	
	bookfile<<Time<<"\t";
	bookfile<<TIME<<"\n";
	bookfile<<Amount<<"\t";
	bookfile<<amount<<"\n\n";
	
	for(int i=0;i<Booktotal;i++){
        if(p[i].GetBBS()!=del){
			bookfile<<ID<<"\t";//在文件中写入第i本书的图书编号 
			id=p[i].GetBookID();
			bookfile<<id<<"\n";
			bname=p[i].GetBookName();
			bookfile<<BName<<"\t";//在文件中写入第i本书的图书名称 
			bookfile<<bname<<"\n";
            type=TransBookType(p[i].GetBT());//查表类型转换函数
			bookfile<<Type<<"\t";//在文件中写入第i本书的图书类型 
			bookfile<<type<<"\n";
			aname=p[i].GetAuthor();
			bookfile<<Aname<<"\t";//在文件中写入第i本书的图书作者 
			bookfile<<aname<<"\n";
			pub=p[i].GetPublish();
			bookfile<<Pub<<"\t";//在文件中写入第i本书的图书出版社 
			bookfile<<pub<<"\n";
			price=p[i].GetPrice();
			bookfile<<Price<<"\t";//在文件中写入第i本书的价格 
			bookfile<<price<<"\n";
			exnum=p[i].GetExist();
			bookfile<<Enum<<"\t";//在文件中写入第i本书的在库可借阅本数 
			bookfile<<exnum<<"\n";
			total=p[i].GetTotal();
			bookfile<<Total<<"\t";//在文件中写入第i本书的图书馆藏总数 
			bookfile<<total<<"\n";
			bnum=p[i].GetBoCount();
			bookfile<<Bnum<<"\t";//在文件中写入第i本书的借出次数 
			bookfile<<bnum<<"\n";
			rnum=p[i].GetReBook();
			bookfile<<Rnum<<"\t";//在文件中写入第i本书的预约次数 
			bookfile<<rnum<<"\n";
			bookfile<<temp<<"\n"; 
			bookfile<<buffer<<"\n";
			for(int j=0;j<total;j++){
				bookfile<<j+1<<"\t\t";
				string state;
				state=TransOBState(p[i].GetOBState(j));
				bookfile<<state<<"\t\t";//查表状态转换函数 
				bookfile<<p[i].GetOBReID(j)<<"\t\t";
				bookfile<<p[i].GetOBPassDay(j)<<"\t\t";
				bookfile<<p[i].GetOBBoTime(j)<<"\n"; 
			}
			bookfile<<"\n";
		} 
	}
  return true;
} 
/*****************************************************************
函数名：int GetReaderInformation(Reader *p)
功能： 从文件中读取注册用户的详细信息
返回值：
    当前注册用户的总数
参数：
自定义的类变量：Reader* p
存储图书馆注册用户的详细信息的对象数组首地址，Reader是图书类
****************************************************************/

int GetReaderInformation(Reader *p){
    string Amount,ID,Name,Rank,Time,Ability,Num,Boed,Fine;
	string name; 
    long long id,boed;
    int amount=-1,rank=-1,time=-1,ability=-1,num=-1;
	float fine=-1;
    ifstream readerfile;
    readerfile.open("..\\project2\\initiate\\ReaderInfo.txt",ios::in);//xiangduilujingduwenjian

	readerfile>>Amount;
	readerfile>>amount;

	for(int i=0;i<amount;i++){
		p[i].SetRS(available);
		readerfile>>ID;//读取第i个读者的编号 
		readerfile>>id;
		p[i].SetReaderID(id); 
		readerfile>>Name;//读取第i个读者的姓名 
		readerfile>>name;
		p[i].SetReaderName(name);
		readerfile>>Rank;//读取第i个读者的等级 
		readerfile>>rank;
		p[i].SetRank(rank);
		readerfile>>Time;//读取第i个读者的可借书时长 
		readerfile>>time;
		p[i].SetTime(time);
		readerfile>>Ability;//读取第i个读者的可借书本数 
		readerfile>>ability;
		p[i].SetBookNum(ability);
		readerfile>>Num;//读取第i个读者的已借书本数 
		readerfile>>num;
		p[i].SetBoedNum(num);
		readerfile>>Boed;//读取第i个读者的借阅图书的编号 
        if(num==0)
        {
            for(int j=0;j<num+1;j++){
                readerfile>>boed;
                p[i].SetBoBookID(boed);
            }

        }
        else
        {
            for(int j=0;j<num;j++){
                readerfile>>boed;
                p[i].SetBoBookID(boed);
            }
        }

		readerfile>>Fine;//读取第i个读者的账户余额 
		readerfile>>fine;
		p[i].SetFine(fine);
	}
	
	readerfile.close();
	return amount;
}
/*****************************************************************
函数名： bool UpdateReaderInformation(Reader *p,const int Readertotal,int ReaderNum)
功能： 更新图书馆注册用户的信息变化
返回值：
bool型变量，用来标记更新是否成功
参数：
自定义的类变量：Reader* p
存储图书馆注册用户的详细信息的对象数组首地址，Reader是图书类
int ReaderNum，当前图书馆内注册用户的实际人数
,const int Readertotal,
当前内存中存储的用户总数（大于等于实际用户总数，因为我们在注销用户时只是将用户状态置为“注销”）
****************************************************************/

bool UpdateReaderInformation(Reader *p,const int Readertotal,int ReaderNum) {//Readertotal内存中读者的数量，ReaderNum读者总数 
	string Amount="读者总数",ID="读者编号",Name="读者姓名",Rank="用户等级",
			Time="可借书时长",Ability="可借书本书",Num="已借书本数",
			Boed="已借阅图书",Fine="用户余额";
	string name;
	long long id,boedid[BIlen]={-1};
    int rank,time,ability,num;
	float fine;
    ofstream readerfile("..\\project2\\initiate\\ReaderInfo.txt");
	
	readerfile<<Amount<<"\t";
	readerfile<<ReaderNum<<"\n\n";
	for(int i=0;i<Readertotal;i++){
        if(p[i].GetRS()!=cancel){
			id=p[i].GetReaderID();
			readerfile<<ID<<"\t";//在文件中写入第i个读者的编号 
			readerfile<<id<<"\n";
			name=p[i].GetReaderName();
			readerfile<<Name<<"\t";//在文件中写入第i个读者的姓名 
			readerfile<<name<<"\n";
			rank=p[i].GetRank();
			readerfile<<Rank<<"\t";//在文件中写入第i个读者的等级 
			readerfile<<rank<<"\n";
			time=p[i].GetTime();
			readerfile<<Time<<"\t";//在文件中写入第i个读者 的可借书时长 
			readerfile<<time<<"\n";
			ability=p[i].GetBookNum();
			readerfile<<Ability<<"\t";//在文件中写入第i个读者 可借书本数 
			readerfile<<ability<<"\n";
			num=p[i].GetBoedNum();
			readerfile<<Num<<"\t";//在文件中写入第i个读者已借阅本数 
			readerfile<<num<<"\n";
			readerfile<<Boed<<"\t";
			p[i].GetBoBookID(boedid);//////////////////////////////////////////
			if(num == 0){
				readerfile<<"-1";
			}
			else{
                for(int j=0;j<BIlen;j++){//在文件中写入第i个读者的已借阅图书的编号
                    if(boedid[j]!=-1)
                    {
                     readerfile<<boedid[j]<<"\t";
                    }

				}
			}
			readerfile<<"\n";
			fine=p[i].GetFine();
			readerfile<<Fine<<"\t";//在文件中写入第i个读者的用户余额 
			readerfile<<fine<<"\n\n";
		}
		
	}
	
    return true;
} 
/*****************************************************************
函数名： void UpdateJournalFile(string filename,string bookname,long long bookid,string readername,long int readerid)
功能： 更新日志文件
返回值：
无
参数：
string filename，当前需要更新的文件的名称
string bookname，图书的名称
long long bookid，图书的编号
string readername，读者名称
long int readerid，读者编号
****************************************************************/

void UpdateJournalFile(string filename,string bookname,long long bookid,string readername,long int readerid){

	ofstream file(filename.c_str(),ios::app);
	file<<bookid<<"\t";
	file<<bookname<<"\t";
	file<<readerid<<"\t";
	file<<readername<<"\t";
    file<<TimeConvert()<<"\n";
	
}

/*****************************************************************
函数名： void CreateReserveList(Book *p,const int Booktotal)
功能： 为每一本书生成预约单
返回值：
无
参数：
自定义的类变量：Book* p
存储图书馆馆藏图书的详细信息的对象数组首地址，Book是图书类
const int Booktotal
当前内存中存储的图书总数（大于等于实际库存总数，因为我们在注销图书时只是将图书状态置为“注销”）
****************************************************************/

void CreateReserveList(Book *p,const int Booktotal){
	RePeople *q;
	long long bid;
	int renum;
	string Renum="预约总数";
	
	for(int i=0;i<Booktotal;i++){//写每个图书的预约单 
			renum=p[i].GetReBook(); 
			RePeople * &head=p[i].GetRePePo();//获取预约单的头指针 
			q=head->nextPtr;
			bid=p[i].GetBookID();
			string filename;
			filename=CreateFileName(bid);/////////////用编号生成文件名称 ,记得标注具体路径 
		if(p[i].GetBBS()!=del){//如果用户没有被注销 
			ofstream file(filename.c_str());
			file<<Renum<<"\t";
			file<<renum<<"\n";
			for(int j=0;j<renum;j++){
				file<<j+1<<"\t";
				file<<q->ReaderID<<"\t\t";
				file<<q->Notice<<"\n";
				q=q->nextPtr;
			}
			file.close();
		} 
		else{//用户被注销时，要在文件夹中删除对应的文件 
            const char *fn=filename.c_str();
                        remove(fn);
		}
	}
}

/*****************************************************************
函数名： void GetReserveInformation(Book *p,int i)
功能： 读取预约单，获取每一本图书的预约信息
返回值：
无
参数：
自定义的类变量：Book* p
存储图书馆馆藏图书的详细信息的对象数组首地址，Book是图书类
int i，读取预约单的图书在数组中的位置
****************************************************************/
void GetReserveInformation(Book *p,int i){//读取预约单中的信息 
	RePeople *q,*r;
	string filename;
    int tid;
    int renum;//预约人数 
    string Renum;
	 
    RePeople *&head=p[i].GetRePePo();
	filename=CreateFileName(p[i].GetBookID());
	ifstream file(filename.c_str());

    file>>Renum;
    file>>renum;
	    for(int j=0;j<renum;j++){
			r=new RePeople;
			r->nextPtr=NULL;
			if(0 == j){
				head->nextPtr=r;
				q=r;
			}
			else{
				q->nextPtr=r;
				q=q->nextPtr;
			}
			file>>tid;
			file>>q->ReaderID;
			file>>q->Notice;
		}	

	file.close(); 
}
/*****************************************************************
函数名： bool  UpdateFineFile(long int readerid,long long bookid,float fine,int reason)
功能： 更新罚款日志文件
返回值：
bool型变量，用来标记更新是否成功
参数：
long int readerid，读者编号
long long bookid，图书编号
float fine，罚款金额
int reason，罚款原因（丢失或逾期）
****************************************************************/
bool  UpdateFineFile(long int readerid,long long bookid,float fine,int reason){//const int pass 0,const int lost 1
    ofstream file("..\\project2\\initiate\\FineLog.txt",ios::app);
	
	file<<bookid<<"\t";
	file<<readerid<<"\t";
	if(reason==pass){
		file<<"逾期"<<"\t"; 
	}
	else{
		file<<"丢失"<<"\t";
	}
	file<<fine<<"\n";
    return true;
}

/*****************************************************************
函数名：string CreateFileName(long long bookid)
功能：根据图书信息生成文件名
返回值：
string型变量，返回文件名
参数：
long long bookid，图书编号
****************************************************************/

string CreateFileName(long long bookid){//用图书编号生成文件名 
    string name="..\\project2\\initiate\\ReserveList\\";//相对路径
	string t; 
	char temp;
	int l;

	for(int i=0;i<12;i++){
		temp=(char)(bookid%10+48);
		if(0==i)
			t=temp;
		else{
			t+=temp;
		}
		bookid=bookid/10;
		
	} 
	l=t.length();
	for (int i = 0; i<l/2; i++)
	{
	  	temp = t[i];
	 	t[i] = t[l-i-1];
	  	t[l-i-1] = temp;
	}
	name=name+t+".txt";
	
	return name;
}

/*****************************************************************
函数名：string TransOBState(enum OneBookState s)
功能：根据子书状态的枚举类型转换为相应的中文字符串，便于文件输出
返回值：
    string类型变量，传递对应中文字符串
参数：
自定义枚举类型：OneBookState s
enum OneBookState{initiate,Oinstore,borrowed,restored,lose};
//初始，在库，预约，借出，归还，丢失
****************************************************************/

string TransOBState(enum OneBookState s){//实现子书状态和对应文字之间的转换 
	int n;
	n=(int)s;
	string state;
	
	switch(n){
		case 1:
			state="在库";
			break;
		case 2:
			state="借出";
			break; 
		case 3:
			state="预约";
			break; 
		case 4:
			state="丢失";
			break; 
		default:
			state="初始";
			break;
	}
	
	return state; 
}

/*****************************************************************
函数名：OneBookState _TransOBState(string s)
功能：根据文件中子书的中文描述状态转换为相应的枚举类型
返回值：
自定义枚举类型：OneBookState
enum OneBookState{initiate,Oinstore,borrowed,restored,lose};
//初始，在库，预约，借出，归还，丢失
参数：
    string s，文件中状态的中文描述字符串
****************************************************************/

OneBookState _TransOBState(string s){//实现文字和子书状态之间的转换 
	enum OneBookState state;
	
	if (s.compare("丢失") == 0)
	{
		state=lose;
	}
    else if (s.compare("在库") == 0)	
    {
    	state=Oinstore;
	}
	else if (s.compare("借出") == 0)	
    {
    	state=borrowed;
	}
	else if (s.compare("归还") == 0)	
    {
    	state=restored;
	}
	else
	{
		state=initiate;
	}

	return state;
}

/*****************************************************************
函数名：string TransBookType(enum BookType t)
功能：根据图书类型的枚举类型转换为相应的中文字符串，便于文件输出
返回值：
    string类型变量，传递对应中文字符串
参数：
自定义枚举类型：enum BookType t
enum BookType{humanity,science,social,art,compre};//人文，理工，社科，艺术，综合
****************************************************************/

string TransBookType(enum BookType t){//实现图书类型和对应文字之间的转换
	int n;
	n=(int)t;
	string type;
	
	switch(n){
		case 0:
			type="人文";
			break;
		case 1:
			type="理工";
			break;
		case 2:
			type="社科";
			break;
		case 3:
			type="艺术";
			break;
		default:
			type="综合";
			break;	
	} 
	
	return type; 
} 

/*****************************************************************
函数名：BookType _TransBookType(string s)
功能：根据文件中图书类型的中文描述状态转换为相应的枚举类型
返回值：
自定义枚举类型：enum BookType t
enum BookType{humanity,science,social,art,compre};//人文，理工，社科，艺术，综合
参数：
    string s，文件中图书类型的中文描述字符串
****************************************************************/

BookType _TransBookType(string s){//实现文字和图书类型之间的转换 
	enum BookType type;
	
	if (s.compare("人文") == 0)
	{
		type=humanity;
	}
	else if (s.compare("理工") == 0)
	{
		type=science;
	}
	else if (s.compare("社科") == 0)
	{
		type=social;
	}
	else if (s.compare("艺术") == 0)
	{
		type=art;
	}
	else
	{
		type=compre;
	}

	return type;
}

/*****************************************************************
函数名：void UpdateCodeList(PubCodeList *pl,AuCodeList *al)
功能： 更新出版社编码表文件和读者编码表文件
返回值：
无
参数：
自定义的结构体变量：PubCodeList* pl，AuCodeList* al
分别存储出版社名称及其对应编码和作者名称及其对应编码
****************************************************************/

void UpdateCodeList(PubCodeList *pl,AuCodeList *al)
{
    ofstream pubfile("..\\project2\\initiate\\PubCode.txt");
    ofstream aufile("..\\project2\\initiate\\AuCode.txt");

    pubfile<<pl[0].pub<<"\t"<<pl[0].code<<endl<<endl;
    for(int i = 1;i<=pl[0].code;i++){
        pubfile<<pl[i].pub<<"\t"<<pl[i].code<<endl;
    }

    aufile<<al[0].Au<<"\t"<<al[0].code<<endl<<endl;
    for(int i = 1;i<=al[0].code;i++){
        aufile<<al[i].Au<<"\t"<<al[i].code<<endl;
    }

    pubfile.close();
    aufile.close();

}
