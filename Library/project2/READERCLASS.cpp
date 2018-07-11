/******************************************************************
文件名: READERCLASS.cpp
创建人:高楠 万诗婕 刘佳鑫 张宇
日　期:2017-04-18
修改人:高楠
日　期:2017-04-26
描　述:该文件中包含了读者类数据成员所有Get和Set的具体函数，以及对图书类进行的所有操作（借书，还书，预定等）-成员函数的具体实现
版　本: 050602
******************************************************************/


#include "READERCLASS.h" 
#include "file.h"
#include "search.h"
#include "Notice.h"
//没写构造函数，析构 

Reader::Reader()
{		
	ReaderID=0;
	ReaderName="\0";
	Rank=0;//初始状态为0，学生1，教师2 
	Time=0;//可借书时长 
	BookNum=0;
	BoedNum=0;
	Fine=0;
	for(int i = 0;i<BIlen;i++)
	{
		BoBookID[i] = -1;
	}
	RS=start;
}


Reader::~Reader()
{;
}

long int Reader::GetReaderID()
{
	return ReaderID;
}

string Reader::GetReaderName()
{
	return ReaderName;
}

int Reader::GetRank()
{
	return Rank;
}

int Reader::GetTime()
{
	return Time;
}

int Reader::GetBookNum()
{
	return BookNum;
}
	
int Reader::GetBoedNum()
{
	return BoedNum;
}

float Reader::GetFine()
{
	return Fine;
 } 

void Reader::GetBoBookID(long long* bookid)//将已经借阅的图书编号拷贝出来
{
	for(int i=0;i<BIlen;i++)
	{	
	    bookid[i]=BoBookID[i];
	}
 } 
 
int Reader::GetBoBookPo(long long bookid)//返回借的这本书的下标 ///////////
{	
	for(int i=0;i<BIlen;i++)
	{	
	    if(BoBookID[i]==bookid)
	    return i;
	}
	
	return -1; 
}

	
ReaderState Reader::GetRS()
{
	return RS;
}

void Reader::SetReaderID(long int id)
{
	ReaderID=id;
}

void Reader::SetReaderName(string name)
{
		
	    ReaderName = name;
	
}

void Reader::SetRank(int rank)
{
	Rank=rank;
}

void Reader::SetTime(int time)
{
	Time=time;
}

void Reader::SetBookNum(int num)
{
	BookNum=num;
}

void Reader::SetBoedNum(int num)
{
	BoedNum=num;
}

void Reader::SetFine(float fine)
{
	Fine=fine;
}

void Reader::SetBoBookID(long long bookid)
{ 	int flag=0;
    for(int i=0;i<BIlen&&flag==0;i++)
    {
    	if(BoBookID[i]==-1)
		{
			BoBookID[i]=bookid;
			flag=1;
		}	
	}
}

void Reader::SetRS(ReaderState a)
{
	RS=a;
}

/*****************************************************************
函数名：bool Reader::Reserve(Book* p,int n)
功能：预约图书
返回值：
    0 or 1 //预约成功返回1，预约失败返回0
参数：
p,n //图书类指针p，图书下标n
****************************************************************/

bool Reader::Reserve(Book* p,int n)
{	
    int rebook;//已预约的书本数
	string bookname;
	long long bookid; 
	rebook=p[n].GetReBook();
    if(Fine<=MaxFine||BoedNum>=BookNum||p[n].GetBBS()==del||p[n].GetExist()!=0)//当罚款额度或借书总数达到上限
	{
		return false; 
	}
	if(rebook>=p[n].GetTotal())
	{
		return false;
	}
	p[n].SetReBook(rebook+1);
	p[n].SetRePeople(ReaderID);
	bookname=p[n].GetBookName();
	bookid=p[n].GetBookID();
    UpdateJournalFile("..\\project2\\initiate\\ReserveLog.txt",bookname,bookid,ReaderName,ReaderID);//写入预约单
	
	
	return true;
}

/*****************************************************************
函数名：bool Reader::CancelReserve(Book* p,int n)
功能：取消预约
返回值：
    0 or 1 //取消成功返回1，取消失败返回0
参数：
p,n //图书类指针p，图书下标n
****************************************************************/

bool Reader::CancelReserve(Book* p,int n)
{
	if(p[n].TraReList(ReaderID))
	{
		p[n].DelRePeople(ReaderID);
		p[n].SetReBook(p[n].GetReBook()-1);
		
		return true;
	}
	
	return false;
}

/*****************************************************************
函数名：bool Reader::BorrowBook(Book *p,int n)
功能：借阅图书
返回值：
    0 or 1 //借书成功返回1，借书失败返回0
参数：
p,n //图书类指针p，图书下标n
****************************************************************/

bool Reader::BorrowBook(Book *p,int n)
{
	int OBNum;
	
	if(Fine<=MaxFine||BoedNum>=BookNum||p[n].GetBBS()==del)//当罚款额度或借书总数达到上限 
	{
		return false; 
	}
	p[n].DelRePeople(ReaderID);//取消预约，若不在预约单也不影响 
	OBNum=p[n].FindTheInBook();//找在库的小书 
	if(OBNum<0||OBNum>5)
	{
		return false; 
	}
	else
	{
		p[n].SetOBState(OBNum,borrowed);
		p[n].SetOBReID(OBNum,ReaderID);
		p[n].SetOBPassDay(OBNum,0);
		p[n].SetOBBoTime(OBNum,TIME);//TIME:系统当前时间 
		p[n].SetBoCount(p[n].GetBoCount()+1);
		p[n].SetExist(p[n].GetExist()-1);
		int ep=FindBoBookFirEmp();//返回数组的空位置 
		BoBookID[ep]=p[n].GetBookID()+OBNum;//找数组的空位置 
		BoedNum++;
		
		return true;
	}
	
} 

/*****************************************************************
函数名：bool Reader::ReturnBook(Book* p,long long BookID,const int Booktotal)
功能：还书
返回值：
    0 or 1 //还书成功返回1，还书失败返回0
参数：
p, BookID, Booktotal //图书类指针p，图书id，图书总数Booktotal
****************************************************************/

bool Reader::ReturnBook(Book* p,long long BookID,const int Booktotal)
{
	int n;
	int OBNum;
	int bobookpo; 
	n=SearchBookID(p,BookID,Booktotal);//大的图书类，按编号搜索定位下标
	OBNum=BookID%100;
	if(p[n].GetOBPassDay(OBNum)>0)//提示逾期多少天 
	{
		p[n].SetOBPassDay(OBNum,0); 
	}
	p[n].SetOBState(OBNum,Oinstore);
	p[n].SetOBReID(OBNum,0);
	p[n].SetOBBoTime(OBNum,0);
	p[n].SetExist(p[n].GetExist()+1);
	if(!SendReserveNotice(p,n)) //到书通知 
	{ 
	   cout<<"未成功发出到书通知"<<endl;//打印未成功发出到书通知 
	};
	BoedNum--;
	bobookpo=GetBoBookPo(BookID);//返回还的这本书的下标 
    BoBookID[bobookpo]=-1;//把已借图书数组中这本书删掉
	
	return true; 
	
}

/*****************************************************************
函数名int Reader::FindBoBookFirEmp()/
功能：找已借图书数组的空位置
返回值：
    -1 or i //返回已借图书数组的第一空位置，没找到返回-1
参数：
无
****************************************************************/

int Reader::FindBoBookFirEmp()//找已借图书数组的空位置 
{
	int i;
	for(i=0;i<=BoedNum;i++)
	{
        if(-1==BoBookID[i])
		    return i;
	}
	return -1;
} 

/*****************************************************************
函数名bool Reader::ReportLoss(Reader* p,long int readerid,Book* q,long long bookid,const int Readertotal,const int Booktotal)
功能：挂失图书
返回值：
    0 or 1 //挂失成功返回1，挂失失败返回0
参数：
p, readerid, bookid,Readertotal,Booktotal //图书类指针p，图书id，读者总数Readertotal，图书总数Booktotal
****************************************************************/

bool Reader::ReportLoss(Reader* p,long int readerid,Book* q,long long bookid,const int Readertotal,const int Booktotal)//挂失功能 Report the loss 优化，登录时吧n存在窗口的类里,传入n 
{
    int bobookpo;//遍历book类，返回书的下标
    int onum;
	int i;//定位这个人的下标 
	i=SearchReader(p,readerid,Readertotal);  //调用按编号搜索读者的函数
	int j;//定位这本书下标
	j=SearchBookID(q,bookid,Booktotal);//调用按编号搜索图书的函数
    onum=bookid%2;
    if(i==-1)//如果这个人不存在 
	{
		return false;
	}
	if(j==-1)//若这本书不在
	{
		return false; 
	} 
	if(q[j].GetTotal()<=1)//大书的总本书（判断）
	   q[j].SetBBS(del);
    p[i].SetFine(p[i].GetFine()-q[j].GetPrice());//读者的金额，
    p[i].SetBoedNum(p[i].GetBoedNum()-1);
    q[j].SetOBState(onum,lose);//书状态

    bobookpo=GetBoBookPo(bookid);//返回还的这本书的下标
    BoBookID[bobookpo]=-1;//把已借图书数组中这本书删掉

    UpdateFineFile(readerid,bookid,q[j].GetPrice(),lost);

	return true;
}










