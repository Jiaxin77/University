/******************************************************************
�ļ���: search.cpp
������:������
�ա���:2017.4.20
�޸���:������
�ա���:2017.5.3
�衡��:�����������������������������������������ͼ�����������������������Ͱ����������
�桡��: v050601 Copyright(c).
******************************************************************/
#include <iostream> 
#include"BOOKCLASS.h"
#include"READERCLASS.h"
//��Ϊ50 

using namespace std;
/*****************************************************************
��������int SearchReader(Reader *r,long int readerid,const int Readertotal)
���ܣ���øö���id��Ӧ�Ķ����������±�
����ֵ��
�����������Ķ����������±꣬��������ʱ����-1
������
Reader *r��[in] ����������
long int readerid��[in] Ҫ�����Ķ���id
const int Readertotal��[in] ��������
int ��[out] �������Ķ����������±꣬��������ʱ����-1
��ע����
****************************************************************/
int SearchReader(Reader *r,long int readerid,const int Readertotal)//ͨ�����߱���Ҷ������±� 
{	int i; 
	for(i=0;i<Readertotal;i++)
	{	
		if(r[i].GetReaderID()==readerid)
			{	
				return i;
			}
			
	}
	return -1;//û�ҵ� 
} 


/*****************************************************************
��������int SearchBookID(Book *p,long long bookid,const int Booktotal)
���ܣ���ø�ͼ��id��Ӧ��ͼ���������±�
����ֵ��
������������ͼ���������±꣬��������ʱ����-1
������
Book *p��[in] ͼ��������
long long bookid��[in] Ҫ������ͼ��id
const int Booktotal��[in] ͼ������
int ��[out] ��������ͼ���������±꣬��������ʱ����-1
��ע����
****************************************************************/

int SearchBookID(Book *p,long long bookid,const int Booktotal)//ͨ��ͼ��id��ͼ�����±�
{	int i; 
    for(i=0;i<Booktotal;i++)
	{	
		if(p[i].GetBookID()==((bookid/100)*100))
			{
				return i;
			}
	} 
	return -1;//��û�ҵ� 
 } 
 
/*****************************************************************
��������void  SearchBookAuthor(int *BAS,Book *p,string Author,const int Booktotal)
���ܣ����������ߵ�ȫ��ͼ��
����ֵ���޷���ֵ
������
int *BAS��[in] ʢ�Ÿ���������ͼ���Ӧ��ͼ�����±������
Book *p��[in] ͼ��������
string Author��[in] �����������ԡ�\0����β���ַ���
const int Booktotal��[in] ͼ������
��ע����
****************************************************************/
void  SearchBookAuthor(int *BAS,Book *p,string Author,const int Booktotal)
{	int i;
	int BAScount=0;
	string SAuthor;

	for(int j=0;j<BSearch;j++)
	{	BAS[j]=-1;
	 } 

	for(i=0;i<Booktotal;i++)
	{	SAuthor=p[i].GetAuthor();
		if(Author.compare(SAuthor)==0)
			{	
				BAS[BAScount]=i;
				BAScount++;
			}
	}
	

		 
}

/*****************************************************************
��������void  SearchBookPublish(int *BPS,Book *p,string Publish,const int Booktotal)
���ܣ������ó������ȫ��ͼ��
����ֵ���޷���ֵ
������
int *BPS��[in] ʢ�Ÿó���������ͼ���Ӧ��ͼ�����±������
Book *p��[in] ͼ��������
string Publish��[in] ���������֣��ԡ�\0����β���ַ���
const int Booktotal��[in] ͼ������
��ע����
****************************************************************/
void  SearchBookPublish(int *BPS,Book *p,string Publish,const int Booktotal)
{	int i;
	int BPScount=0;
	string SPublish;
	for(int j=0;j<BSearch;j++)
	{	BPS[j]=-1;
	} 

	for(i=0;i<Booktotal;i++)
	{	SPublish=p[i].GetPublish();
		if(Publish.compare(SPublish)==0)
			{	
				BPS[BPScount]=i;
				BPScount++;
			}
	}
	
	
		 
}

/*****************************************************************
��������void   SearchBookName(int *BNS,Book *p,string Name,const int Booktotal)
���ܣ���������ΪName��ȫ��ͼ��
����ֵ���޷���ֵ
������
int *BNS��[in] ʢ�Ÿ���������ͼ���Ӧ��ͼ�����±������
Book *p��[in] ͼ��������
string Name��[in] ͼ�����֣��ԡ�\0����β���ַ���
const int Booktotal��[in] ͼ������
��ע����
****************************************************************/
void   SearchBookName(int *BNS,Book *p,string Name,const int Booktotal)
{	int i;
	int BNScount=0;
	string SName;
	for(int j=0;j<BSearch;j++)
	{	BNS[j]=-1;
	 } 

	for(i=0;i<Booktotal;i++)
	{	SName=p[i].GetBookName();
		if(Name.compare(SName) == 0)
			{	
				BNS[BNScount]=i;
				BNScount++;
			}
	}
	
	
		 
}

/*****************************************************************
��������void  SearchBookType(int *BTS,Book *p ,BookType bt,const int Booktotal)
���ܣ����������͵�ȫ��ͼ��
����ֵ���޷���ֵ
������
int *BTS��[in] ʢ�Ÿ���������ͼ���Ӧ��ͼ�����±������
Book *p��[in] ͼ��������
BookType bt��[in] ͼ�����ͣ�Ϊö�������е�һ��
const int Booktotal��[in] ͼ������
��ע��ʹ��ͼ������ʱ�����ȿ����ò��õ����ַ���תö�����ͺ�����
****************************************************************/
void  SearchBookType(int *BTS,Book *p ,BookType bt,const int Booktotal)//BTS���ڴ�����������͵��±� 
{
	int i;
	int BTScount=0;
	for(int j=0;j<BSearch;j++)
	{	BTS[j]=-1;
	 } 
	for(i=0;i<Booktotal;i++)
	{	
		if(p[i].GetBT()==bt)
			{
				BTS[BTScount]=i;
				BTScount++;
			}
	}
	
	
}
