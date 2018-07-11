/******************************************************************
文件名: BOOKCLASS.cpp
创建人:高楠 万诗婕 刘佳鑫 张宇
日　期:2017-04-18
修改人:高楠
日　期:2017-04-26
描　述:该文件中包含了图书类数据成员的所有Get和Set的具体函数，以及对图书类类进行的所有操作（更新，遍历等）-成员函数的具体实现
版　本: 050602
******************************************************************/



#include "BOOKCLASS.h"


long long Book::GetBookID()
{	
   return BookID;
}

BookType Book::GetBT()
{
	return BT; 
} 
string Book::GetBookName()
{	
   return BookName; 
}

string Book::GetAuthor()
{	
	return Author;
}

string Book::GetPublish()
{
	return Publish;
}
	
float Book::GetPrice()
{
	return Price; 
}

int Book::GetExist()//在库可借阅本数
{
	return Exist;
}
	
int Book::GetTotal()//图书馆馆藏总数
{
	return Total;
}

int Book::GetBoCount()
{
	return BoCount;
}
	
int Book::GetReBook()
{
	return ReBook;
}

RePeople *&Book::GetRePePo()//得到预约单的头指针 
{
	return head;
}

OneBookState Book::GetOBState(int i)//i:子书的下标，s:更改后的状态 
{
	return OB[i].OBS; 
} 

	
long int Book::GetOBReID(int i)
{
	return OB[i].ReaderID; 
}

int Book::GetOBPassDay(int i)
{
	return OB[i].PassDays; 
}
	
int Book::GetOBBoTime(int i)
{
	return OB[i].BoTime; 	
}


BigBookState Book::GetBBS()
{
	return BBS;
}

void Book::SetBookID(long long id)
{
	BookID=id;
}

void Book::SetBookName(string Name)
{	
    BookName=Name;
}

void Book::SetBT(BookType bt)
{
	BT=bt;
}

void Book::SetAuthor(string Name)
{
	Author=Name; 
}

void Book::SetPublish(string Name)
{
	Publish=Name;
}
void Book::SetPrice(float price)
{
	Price=price;
}

void Book::SetExist(int exist)
{
	Exist=exist;
}

void Book::SetTotal(int total)
{
	Total=total;
}

void Book::SetBoCount(int count)
{
	BoCount=count;
}

void Book::SetBBS(BigBookState bbs)
{
	BBS=bbs;
}

void Book::SetReBook(int rebook)
{
	ReBook=rebook;
}

void Book::SetRePeople(long int ReaderID)
{
	RePeople *p,*r,*pre;
	int i = 0;
	p=head->nextPtr;
	for(;i<ReBook-1;i++){
		pre=p;
		p=p->nextPtr;
	} 
	r = new RePeople;
	r->nextPtr = NULL;
	pre->nextPtr=r;
	p=r;
	if(0 == i){
		head->nextPtr = p;
	}
	if(NULL == p){	
      cout<<"SetRePeople头指针空"<<endl;
	  
	}
	else{
		p->ReaderID = ReaderID;
		p->Notice = -1;
	 } 
}


void Book::SetOBState(int i,OneBookState s)//i:子书的下标，s:更改后的状态
{
	OB[i].OBS=s;
}

void Book::SetOBReID(int i,long int ReaderID)
{
	OB[i].ReaderID=ReaderID;
}

void Book::SetOBPassDay(int i,int PaTime)
{
	OB[i].PassDays=PaTime;
}

void Book::SetOBBoTime(int i,int BoTime)
{
	OB[i].BoTime=BoTime;
}

//每次新char一个数组后，初始化'\0' 
//存char数组后一定要存个'\0' 

/*****************************************************************
函数名：void Book::DelRePeople(long int ReaderID)
功能：删除预定图书的读者
返回值：
    无
参数：
ReaderID　//读者ID
****************************************************************/

void Book::DelRePeople(long int ReaderID)
{
	RePeople *p,*pre;
	
	p=head->nextPtr;
	pre=head;
	while(NULL!=p)
	{
		if(p->ReaderID==ReaderID)
		{
			pre->nextPtr=p->nextPtr;
			delete p;
			p=NULL;
		}
		else
		{
			pre=p;
			p=p->nextPtr;	
		}
	}
}

/*****************************************************************
函数名：long int Book::FirstNNPeople()
功能：返回第一个未被通知的人是谁 ,如果都被通知了返回-1
返回值：
    未被通知读者的id，-1
参数：
无
****************************************************************/

long int Book::FirstNNPeople()//返回第一个未被通知的人是谁 ,如果都被通知了返回-1 
{
	RePeople *p;
	p=head->nextPtr;
	if(NULL==p)
	{
		return -1;
	}
	else
	{
		while(p!=NULL)
		{
			if(p->Notice<0)
			{
				return p->ReaderID;
			}
			else
			{
				p=p->nextPtr;
			}
		 } 
			
	}
	p=NULL;
    return -1;
}

/*****************************************************************
函数名：bool Book::TraReList(long int ReaderID)
功能：遍历预约单，找是否有该读者。
返回值：
    0 or 1 // 找到返回1，没找到返回0
参数：
    ReaderID //读者id
****************************************************************/

bool Book::TraReList(long int ReaderID)
{
	RePeople *p;
	
	p=head->nextPtr;
	while(p!=NULL)
	{
		if(p->ReaderID==ReaderID){
			return true;
		}
		p=p->nextPtr;
	}
	
	return false;
}

/*****************************************************************
函数名：int Book::FindTheInBook()
功能：查询在库的具体图书编号
返回值：
    i //返回值为下标
参数：
无
****************************************************************/

int Book::FindTheInBook()
{
	int i=0;
	if(0==Exist)
	{
		return -1;
	}
    for(i=0;Oinstore!=OB[i].OBS&&i<5;i++);
	 
	return i;
}




Book::Book()
{	int i;

	BookName="\0";
	Author="\0";
	Publish="\0";
	Price=0;
	Exist=0;
	Total=0;
	BoCount=0;
	ReBook=0;
	BT=humanity;
	BBS=begin;
	for(i=0;i<OBlen;i++)
	{	OB[i].BoTime=0;
		OB[i].OBS=initiate;
		OB[i].PassDays=0;
		OB[i].ReaderID=0;
	}
	head=new RePeople;
	if(NULL==head)
	{
        cout<<"Book里RePeople头指针空"<<endl;
	}
	else
	{
		head->nextPtr=NULL;
		head->ReaderID=0;
		head->Notice=-1;//未通知状态 
	}
}

Book::~Book()
{
	RePeople *p,*q;
	p=head->nextPtr;
	q=head->nextPtr;
	while(NULL != p){
		q=p->nextPtr;
		delete p;
		p=q;
	}
	delete head;
	head=NULL;
}


