/******************************************************************
�ļ���: Notice.cpp
������:����
�ա���:2017.4.20
�޸���:
�ա���:
�衡��:��Ϣ�����������͵���֪ͨ������֪ͨ��ԤԼʧЧ֪ͨ��
�桡��: v050601 Copyright(c).
******************************************************************/
#include <fstream>
#include "TimeMgt.h"
#include "BOOKCLASS.h"//����book���.h 
#include <QDebug>



//����ʱ��ģ��ĺ��� 

bool SendReserveNotice(Book* p,int n)//���͵���֪ͨ 
{	RePeople *rp;
	int i,j;//ѭ������ 
	int temp,divider;//temp�����id��divider�ǳ�ʼ���� 
	long int readerid;
    char filename[ReIDLen+30]="..\\project2\\ReaderNotice\\0000000.txt";//�ļ���ʼ·��
	string bookname;
	const int DIVIDER=1000000;//��ȡ����idλ�Ĵ��� 
	
	if(p[n].GetReBook()>0)//���Ȿ���Ƿ�ԤԼ��������֪ͨ 
	{   readerid=p[n].FirstNNPeople();
		if(readerid>0)
		{	
			temp=readerid;
			divider=DIVIDER;
            for(i=0,j=25;i<ReIDLen;i++,j++) //�������͵Ķ��߱�Ŵ����ַ��������Ӧλ��
			{
				filename[j]=temp/divider+'0';
				temp=temp%divider;
				divider=divider/10;
			}
			
			bookname=p[n].GetBookName();
			
			ofstream fptr;
			fptr.open(filename,ios::out|ios::app);//�Զ���β��׷�ӵķ�ʽ���ļ� 
			fptr<<"��ԤԼ��ͼ�顶"<<bookname<<"���ѵ����뾡��ǰȥ���ġ�"<<TimeConvert()<<"\n";//������д���ļ� 
			fptr.close();
			
			RePeople *&head=p[n].GetRePePo();
			rp=head->nextPtr;
			if(NULL==rp)
			{
			return false;
			}
			else
			{
				while(rp!=NULL)
				{
					if(rp->ReaderID==readerid)
					{	
						rp->Notice=0;//������������Ϊ�� 
					}	
					rp=rp->nextPtr;
		   		} 
			
	  		 }
	   		 rp=NULL; 
		}
	}
	return true;
}

bool SendPassDayNotice(long int readerid,long long bookid,string bookname)//��������֪ͨ
{	
	int i,j;//ѭ������ 
	int temp,divider;//temp�����id��divider�ǳ�ʼ���� 
    char filename[ReIDLen+30]="..\\project2\\ReaderNotice\\0000000.txt";//�ļ���ʼ·��
	const int DIVIDER=1000000;//��ȡ����idλ�Ĵ��� 
	
	temp=readerid;
	divider=DIVIDER;
    for(i=0,j=25;i<ReIDLen;i++,j++) //�������͵Ķ��߱�Ŵ����ַ��������Ӧλ��
	{
		filename[j]=temp/divider+'0';
		temp=temp%divider;
		divider=divider/10;
	}

	ofstream fptr;
	fptr.open(filename,ios::out|ios::app);//�Զ���β��׷�ӵķ�ʽ���ļ� 
	fptr<<"�����ĵı��Ϊ"<<bookid<<"��ͼ�顶"<<bookname<<"����"<<TimeConvert()<<"������"<<"���뾡��ǰȥ�黹��\n";//������д���ļ�
	fptr.close();
			
	
	return true;	
}

bool SendMaxReNotice(long int readerid,long long bookid,string bookname)//������ԤԼʱ�䳬��ʱ����ȡ��ԤԼ�ʸ�
{
	int i,j;//ѭ������ 
	int temp,divider;//temp�����id��divider�ǳ�ʼ���� 
    char filename[ReIDLen+30]="..\\project2\\ReaderNotice\\0000000.txt";//�ļ���ʼ·��
	const int DIVIDER=1000000;//��ȡ����idλ�Ĵ��� 
	
	temp=readerid;
	divider=DIVIDER;
    for(i=0,j=25;i<ReIDLen;i++,j++) //�������͵Ķ��߱�Ŵ����ַ��������Ӧλ��
	{
		filename[j]=temp/divider+'0';
		temp=temp%divider;
		divider=divider/10;
	}

	ofstream fptr;
	fptr.open(filename,ios::out|ios::app);//�Զ���β��׷�ӵķ�ʽ���ļ� 

	fptr<<"��ԤԼ�ı��Ϊ"<<bookid<<"��ͼ�顶"<<bookname<<"�������ʱ��û�����ģ��ѱ�ȡ��ԤԼ�ʸ�������Ҫ������ԤԼ��"<<TimeConvert()<<"\n";//������д���ļ�
	fptr.close();
			
	
	return true;	



} 



