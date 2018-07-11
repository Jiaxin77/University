/******************************************************************
�ļ���: ADMCLASS.cpp
������:��� ��ʫ� ������ ����
�ա���:2017-04-18
�޸���:���
�ա���:2017-04-26
�衡��:���ļ��а����˹���Ա�����ݳ�Ա����Get��Set�ľ��庯�����Լ��Թ���Ա����е����в������½�ͼ�飬�½����ߣ�ɾ�����ߵȣ�-��Ա�����ľ���ʵ��
�桡��: 050602
******************************************************************/


#include "ADMCLASS.h"
#include "search.h"
#include "Notice.h" 
#include "file.h"


void  Administration::SetReaderNum(int readernum)
{
	ReaderNum=readernum;
}

void  Administration::SetBookNum(int booknum)
{
	BookNum=booknum;
}

void Administration::SetAllBooks(int allbooks)
{
	AllBooks=allbooks;
}

int Administration::GetBookNum()
{
	return BookNum;
}

int Administration::GetReaderNum() 
{
	return ReaderNum;
}

int Administration::GetAllBooks()
{
	return AllBooks;
}

Administration::Administration(){
	AdmID=AdminID;
	AdmName='\0';
	ReaderNum=0;
	BookNum=0;
	AllBooks=0; 
	
}

Administration::~Administration(){
	;
}

/******************************************************************
������bool Administration::NewReader(Reader* p,long int readerid,string readername,int* Readertotal)
���ܣ��½�һ������
����ֵ��
    0 or 1 //�½��ɹ�����1���½�ʧ�ܷ���0
������
p, readerid, readername,Readertotal //ͼ����ָ��p��ͼ��id����������readername����������Readertotal
****************************************************************/

bool Administration::NewReader(Reader* p,long int readerid,string readername,int* Readertotal)
{	
    int i;
    i=SearchReader(p,readerid,*Readertotal);
     if(i!=-1||*Readertotal>=150)//�ȱ���������ڲ���,�����������ֵ
	 {
	 	return false;	 
	 }
	 
	int rank;
	rank=readerid/1000000;//��ȡ�����Ϣ 
	if(1==rank) 
	{
		p[ReaderNum].SetRank(rank);
		p[ReaderNum].SetTime(StuTime);
		p[ReaderNum].SetBookNum(StuBookNum);	
		
	}
	else if(2==rank)
	{	p[ReaderNum].SetRank(rank);
		p[ReaderNum].SetTime(TeaTime);
		p[ReaderNum].SetBookNum(TeaBookNum);
		
	}
	p[ReaderNum].SetReaderID(readerid);
	p[ReaderNum].SetReaderName(readername);
	
	ReaderNum++;
    (*Readertotal)++;
	return true;
	
}

/******************************************************************
������bool Administration::DelReader(Reader* p,long int readerid,string readername,const int Readertotal)
���ܣ�ɾ������
����ֵ��
    0 or 1 //ɾ���ɹ�����1��ɾ��ʧ�ܷ���0
������
p, readerid, readername,Readertotal //ͼ����ָ��p��ͼ��id����������readername����������Readertotal
****************************************************************/

bool Administration::DelReader(Reader* p,long int readerid,string readername,const int Readertotal)
{
	int i;//������id��Ӧ�Ķ��ߵ��±�
	i=SearchReader(p,readerid,Readertotal);//�����������ߵĺ��� 
	
	if(i==-1)//�Զ����±�����жϣ������ڷ���false
	{
		return false;
	 } 
	
	if(readername.compare(p[i].GetReaderName()) == 0){
		p[i].SetRS(cancel);
		ReaderNum--;
	}
		
	
	return true;
}

/******************************************************************
������NewBook(Book* p,BookType bt,string bookname,string author,string publish,float price,int* Booktotal,PubCodeList *pl,AuCodeList *al)
���ܣ��½�ͼ��
����ֵ��
    0 or 1 //�½��ɹ�����1���½�ʧ�ܷ���0
������
p, bt,bookname,author,publish,price,Booktotal,pl,al //ͼ����ָ��p��ͼ������booknamae��ͼ������author��ͼ�������publish��ͼ��۸�price��ͼ������Booktotal,���������ָ��pl,���߱���ָ��al
****************************************************************/

bool Administration::NewBook(Book* p,BookType bt,string bookname,string author,string publish,float price,int* Booktotal,PubCodeList *pl,AuCodeList *al)
{

    if(*Booktotal>=100)//�����������ֵ
    {
        return false;
    }

	int bopos=-1;//����book�࣬��������±�
	int i;//��С����±� 
	int BNS[50]={-1};
	int BNSAU[50]={-1};//�������߶�ƥ�� 
	for(int j = 0;j<50;j++){
		BNS[j]=-1;
		BNSAU[j]=-1;
	}
    SearchBookName(BNS,p,bookname,*Booktotal);//����ͼ��������������ͼ��
	for(int j=0,k=0;j<50&&BNS[j]!=-1;j++)
	{
		if(author.compare(p[BNS[j]].GetAuthor()) == 0)
		{
			BNSAU[k]=BNS[j];
			k++;
		} 
	 } 
	 for(int j=0;j<50&&BNSAU[j]!=-1;j++)
	 {
	 	if(publish.compare(p[BNSAU[j]].GetPublish()) == 0)
		{
			bopos=BNSAU[j];
		} 
	 }
	if(bopos!=-1)//�������Ȿ��
    {   if(p[bopos].GetTotal()>=OBlen)
        {
            return false;
        }
        for(i=0;i<OBlen&&(p[bopos].GetOBState(i)!=lose&&p[bopos].GetOBState(i)!=initiate);i++);//��Ҫ���û�˵��С��ı������ܳ���10
		p[bopos].SetOBState(i,Oinstore);
		int e=-1,t=-1;
		e=p[bopos].GetExist()+1;
		t=p[bopos].GetTotal()+1;
		p[bopos].SetExist(e);//�ڿ�ɽ��ı��� 
		p[bopos].SetTotal(t);//ͼ��ݹݲ����� 
		if(!SendReserveNotice(p,bopos))//����֪ͨ 
		{ 
		    cout<<"δ�ɹ���������֪ͨ"<<endl;//��ӡδ�ɹ���������֪ͨ
		};
	} 
	else
	{	
        long long bookid=CreateBookID(p,bt,author,publish,*Booktotal,pl,al);//���������б�ɾ����//����һ�����뺯��
        p[*Booktotal].SetBookID(bookid);
        p[*Booktotal].SetBookName(bookname);
        p[*Booktotal].SetBT(bt);
        p[*Booktotal].SetAuthor(author);
        p[*Booktotal].SetPublish(publish);
        p[*Booktotal].SetPrice(price);
        p[*Booktotal].SetExist(p[*Booktotal].GetExist()+1);
        p[*Booktotal].SetTotal(p[*Booktotal].GetTotal()+1);
        p[*Booktotal].SetOBState(0,Oinstore);
        p[*Booktotal].SetBBS(instore);
        (*Booktotal)++;
	    BookNum++;
	}
	
	return true;
}

/******************************************************************
������bool Administration::DelBook(Book* p,long long bookid,const int Booktotal)
���ܣ�ɾ��ͼ��
����ֵ��
    0 or 1 //ɾ���ɹ�����1��ɾ��ʧ�ܷ���0
������
p, bookid,bookBooktotal //ͼ����ָ��p��ͼ��id��ͼ������Booktotal
****************************************************************/

bool Administration::DelBook(Book* p,long long bookid,const int Booktotal)
{
	int i;//��λ�Ȿ���±�
	i=SearchBookID(p,bookid,Booktotal);//���ð��������ͼ��ĺ���
	
    if(i==-1||p[i].GetExist()<p[i].GetTotal())//���Ȿ�鲻��, �����н��

	{
		return false; 
	} 
	
	p[i].SetBBS(del);
	BookNum--;
	
	return true; 	
}
/******************************************************************
������bool Administration::HandinFine(Reader* p,long int readerid,float fine,const int Readertotal)
���ܣ����ɷ���
����ֵ��
    0 or 1 //���ɳɹ�����1������ʧ�ܷ���0
������
p,readerid,fine,Readertotal //ͼ����ָ��p������id������fine����������Readertotal
******************************************************************/


bool Administration::HandinFine(Reader* p,long int readerid,float fine,const int Readertotal) //���ɷ���
{
	int i;//��λ����˵��±� 
	i=SearchReader(p,readerid,Readertotal);    //���ð�����������ߵĺ���
    if(i==-1)//�������˲����� 
	{
		return false;
	}
    p[i].SetFine(p[i].GetFine()+fine);
    return true;
}



 
