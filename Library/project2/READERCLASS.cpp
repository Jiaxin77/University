/******************************************************************
�ļ���: READERCLASS.cpp
������:��� ��ʫ� ������ ����
�ա���:2017-04-18
�޸���:���
�ա���:2017-04-26
�衡��:���ļ��а����˶��������ݳ�Ա����Get��Set�ľ��庯�����Լ���ͼ������е����в��������飬���飬Ԥ���ȣ�-��Ա�����ľ���ʵ��
�桡��: 050602
******************************************************************/


#include "READERCLASS.h" 
#include "file.h"
#include "search.h"
#include "Notice.h"
//ûд���캯�������� 

Reader::Reader()
{		
	ReaderID=0;
	ReaderName="\0";
	Rank=0;//��ʼ״̬Ϊ0��ѧ��1����ʦ2 
	Time=0;//�ɽ���ʱ�� 
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

void Reader::GetBoBookID(long long* bookid)//���Ѿ����ĵ�ͼ���ſ�������
{
	for(int i=0;i<BIlen;i++)
	{	
	    bookid[i]=BoBookID[i];
	}
 } 
 
int Reader::GetBoBookPo(long long bookid)//���ؽ���Ȿ����±� ///////////
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
��������bool Reader::Reserve(Book* p,int n)
���ܣ�ԤԼͼ��
����ֵ��
    0 or 1 //ԤԼ�ɹ�����1��ԤԼʧ�ܷ���0
������
p,n //ͼ����ָ��p��ͼ���±�n
****************************************************************/

bool Reader::Reserve(Book* p,int n)
{	
    int rebook;//��ԤԼ���鱾��
	string bookname;
	long long bookid; 
	rebook=p[n].GetReBook();
    if(Fine<=MaxFine||BoedNum>=BookNum||p[n].GetBBS()==del||p[n].GetExist()!=0)//�������Ȼ���������ﵽ����
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
    UpdateJournalFile("..\\project2\\initiate\\ReserveLog.txt",bookname,bookid,ReaderName,ReaderID);//д��ԤԼ��
	
	
	return true;
}

/*****************************************************************
��������bool Reader::CancelReserve(Book* p,int n)
���ܣ�ȡ��ԤԼ
����ֵ��
    0 or 1 //ȡ���ɹ�����1��ȡ��ʧ�ܷ���0
������
p,n //ͼ����ָ��p��ͼ���±�n
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
��������bool Reader::BorrowBook(Book *p,int n)
���ܣ�����ͼ��
����ֵ��
    0 or 1 //����ɹ�����1������ʧ�ܷ���0
������
p,n //ͼ����ָ��p��ͼ���±�n
****************************************************************/

bool Reader::BorrowBook(Book *p,int n)
{
	int OBNum;
	
	if(Fine<=MaxFine||BoedNum>=BookNum||p[n].GetBBS()==del)//�������Ȼ���������ﵽ���� 
	{
		return false; 
	}
	p[n].DelRePeople(ReaderID);//ȡ��ԤԼ��������ԤԼ��Ҳ��Ӱ�� 
	OBNum=p[n].FindTheInBook();//���ڿ��С�� 
	if(OBNum<0||OBNum>5)
	{
		return false; 
	}
	else
	{
		p[n].SetOBState(OBNum,borrowed);
		p[n].SetOBReID(OBNum,ReaderID);
		p[n].SetOBPassDay(OBNum,0);
		p[n].SetOBBoTime(OBNum,TIME);//TIME:ϵͳ��ǰʱ�� 
		p[n].SetBoCount(p[n].GetBoCount()+1);
		p[n].SetExist(p[n].GetExist()-1);
		int ep=FindBoBookFirEmp();//��������Ŀ�λ�� 
		BoBookID[ep]=p[n].GetBookID()+OBNum;//������Ŀ�λ�� 
		BoedNum++;
		
		return true;
	}
	
} 

/*****************************************************************
��������bool Reader::ReturnBook(Book* p,long long BookID,const int Booktotal)
���ܣ�����
����ֵ��
    0 or 1 //����ɹ�����1������ʧ�ܷ���0
������
p, BookID, Booktotal //ͼ����ָ��p��ͼ��id��ͼ������Booktotal
****************************************************************/

bool Reader::ReturnBook(Book* p,long long BookID,const int Booktotal)
{
	int n;
	int OBNum;
	int bobookpo; 
	n=SearchBookID(p,BookID,Booktotal);//���ͼ���࣬�����������λ�±�
	OBNum=BookID%100;
	if(p[n].GetOBPassDay(OBNum)>0)//��ʾ���ڶ����� 
	{
		p[n].SetOBPassDay(OBNum,0); 
	}
	p[n].SetOBState(OBNum,Oinstore);
	p[n].SetOBReID(OBNum,0);
	p[n].SetOBBoTime(OBNum,0);
	p[n].SetExist(p[n].GetExist()+1);
	if(!SendReserveNotice(p,n)) //����֪ͨ 
	{ 
	   cout<<"δ�ɹ���������֪ͨ"<<endl;//��ӡδ�ɹ���������֪ͨ 
	};
	BoedNum--;
	bobookpo=GetBoBookPo(BookID);//���ػ����Ȿ����±� 
    BoBookID[bobookpo]=-1;//���ѽ�ͼ���������Ȿ��ɾ��
	
	return true; 
	
}

/*****************************************************************
������int Reader::FindBoBookFirEmp()/
���ܣ����ѽ�ͼ������Ŀ�λ��
����ֵ��
    -1 or i //�����ѽ�ͼ������ĵ�һ��λ�ã�û�ҵ�����-1
������
��
****************************************************************/

int Reader::FindBoBookFirEmp()//���ѽ�ͼ������Ŀ�λ�� 
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
������bool Reader::ReportLoss(Reader* p,long int readerid,Book* q,long long bookid,const int Readertotal,const int Booktotal)
���ܣ���ʧͼ��
����ֵ��
    0 or 1 //��ʧ�ɹ�����1����ʧʧ�ܷ���0
������
p, readerid, bookid,Readertotal,Booktotal //ͼ����ָ��p��ͼ��id����������Readertotal��ͼ������Booktotal
****************************************************************/

bool Reader::ReportLoss(Reader* p,long int readerid,Book* q,long long bookid,const int Readertotal,const int Booktotal)//��ʧ���� Report the loss �Ż�����¼ʱ��n���ڴ��ڵ�����,����n 
{
    int bobookpo;//����book�࣬��������±�
    int onum;
	int i;//��λ����˵��±� 
	i=SearchReader(p,readerid,Readertotal);  //���ð�����������ߵĺ���
	int j;//��λ�Ȿ���±�
	j=SearchBookID(q,bookid,Booktotal);//���ð��������ͼ��ĺ���
    onum=bookid%2;
    if(i==-1)//�������˲����� 
	{
		return false;
	}
	if(j==-1)//���Ȿ�鲻��
	{
		return false; 
	} 
	if(q[j].GetTotal()<=1)//������ܱ��飨�жϣ�
	   q[j].SetBBS(del);
    p[i].SetFine(p[i].GetFine()-q[j].GetPrice());//���ߵĽ�
    p[i].SetBoedNum(p[i].GetBoedNum()-1);
    q[j].SetOBState(onum,lose);//��״̬

    bobookpo=GetBoBookPo(bookid);//���ػ����Ȿ����±�
    BoBookID[bobookpo]=-1;//���ѽ�ͼ���������Ȿ��ɾ��

    UpdateFineFile(readerid,bookid,q[j].GetPrice(),lost);

	return true;
}










