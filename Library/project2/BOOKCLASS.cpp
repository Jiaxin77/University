/******************************************************************
�ļ���: BOOKCLASS.cpp
������:��� ��ʫ� ������ ����
�ա���:2017-04-18
�޸���:���
�ա���:2017-04-26
�衡��:���ļ��а�����ͼ�������ݳ�Ա������Get��Set�ľ��庯�����Լ���ͼ��������е����в��������£������ȣ�-��Ա�����ľ���ʵ��
�桡��: 050602
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

int Book::GetExist()//�ڿ�ɽ��ı���
{
	return Exist;
}
	
int Book::GetTotal()//ͼ��ݹݲ�����
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

RePeople *&Book::GetRePePo()//�õ�ԤԼ����ͷָ�� 
{
	return head;
}

OneBookState Book::GetOBState(int i)//i:������±꣬s:���ĺ��״̬ 
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
      cout<<"SetRePeopleͷָ���"<<endl;
	  
	}
	else{
		p->ReaderID = ReaderID;
		p->Notice = -1;
	 } 
}


void Book::SetOBState(int i,OneBookState s)//i:������±꣬s:���ĺ��״̬
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

//ÿ����charһ������󣬳�ʼ��'\0' 
//��char�����һ��Ҫ���'\0' 

/*****************************************************************
��������void Book::DelRePeople(long int ReaderID)
���ܣ�ɾ��Ԥ��ͼ��Ķ���
����ֵ��
    ��
������
ReaderID��//����ID
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
��������long int Book::FirstNNPeople()
���ܣ����ص�һ��δ��֪ͨ������˭ ,�������֪ͨ�˷���-1
����ֵ��
    δ��֪ͨ���ߵ�id��-1
������
��
****************************************************************/

long int Book::FirstNNPeople()//���ص�һ��δ��֪ͨ������˭ ,�������֪ͨ�˷���-1 
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
��������bool Book::TraReList(long int ReaderID)
���ܣ�����ԤԼ�������Ƿ��иö��ߡ�
����ֵ��
    0 or 1 // �ҵ�����1��û�ҵ�����0
������
    ReaderID //����id
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
��������int Book::FindTheInBook()
���ܣ���ѯ�ڿ�ľ���ͼ����
����ֵ��
    i //����ֵΪ�±�
������
��
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
        cout<<"Book��RePeopleͷָ���"<<endl;
	}
	else
	{
		head->nextPtr=NULL;
		head->ReaderID=0;
		head->Notice=-1;//δ֪ͨ״̬ 
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


