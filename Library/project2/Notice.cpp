/******************************************************************
文件名: Notice.cpp
创建人:张宇
日　期:2017.4.20
修改人:
日　期:
描　述:消息处理，包括发送到书通知，逾期通知，预约失效通知。
版　本: v050601 Copyright(c).
******************************************************************/
#include <fstream>
#include "TimeMgt.h"
#include "BOOKCLASS.h"//包含book类的.h 
#include <QDebug>



//用了时间模块的函数 

bool SendReserveNotice(Book* p,int n)//发送到书通知 
{	RePeople *rp;
	int i,j;//循环变量 
	int temp,divider;//temp存读者id，divider记初始除数 
	long int readerid;
    char filename[ReIDLen+30]="..\\project2\\ReaderNotice\\0000000.txt";//文件初始路径
	string bookname;
	const int DIVIDER=1000000;//做取读者id位的处理 
	
	if(p[n].GetReBook()>0)//查这本书是否被预约，发到书通知 
	{   readerid=p[n].FirstNNPeople();
		if(readerid>0)
		{	
			temp=readerid;
			divider=DIVIDER;
            for(i=0,j=25;i<ReIDLen;i++,j++) //将长整型的读者编号存入字符数组的相应位置
			{
				filename[j]=temp/divider+'0';
				temp=temp%divider;
				divider=divider/10;
			}
			
			bookname=p[n].GetBookName();
			
			ofstream fptr;
			fptr.open(filename,ios::out|ios::app);//以读和尾部追加的方式打开文件 
			fptr<<"您预约的图书《"<<bookname<<"》已到，请尽快前去借阅。"<<TimeConvert()<<"\n";//将提醒写入文件 
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
						rp->Notice=0;//将提醒天数置为零 
					}	
					rp=rp->nextPtr;
		   		} 
			
	  		 }
	   		 rp=NULL; 
		}
	}
	return true;
}

bool SendPassDayNotice(long int readerid,long long bookid,string bookname)//发送逾期通知
{	
	int i,j;//循环变量 
	int temp,divider;//temp存读者id，divider记初始除数 
    char filename[ReIDLen+30]="..\\project2\\ReaderNotice\\0000000.txt";//文件初始路径
	const int DIVIDER=1000000;//做取读者id位的处理 
	
	temp=readerid;
	divider=DIVIDER;
    for(i=0,j=25;i<ReIDLen;i++,j++) //将长整型的读者编号存入字符数组的相应位置
	{
		filename[j]=temp/divider+'0';
		temp=temp%divider;
		divider=divider/10;
	}

	ofstream fptr;
	fptr.open(filename,ios::out|ios::app);//以读和尾部追加的方式打开文件 
	fptr<<"您借阅的编号为"<<bookid<<"的图书《"<<bookname<<"》于"<<TimeConvert()<<"已逾期"<<"，请尽快前去归还。\n";//将提醒写入文件
	fptr.close();
			
	
	return true;	
}

bool SendMaxReNotice(long int readerid,long long bookid,string bookname)//发送因预约时间超过时长而取消预约资格
{
	int i,j;//循环变量 
	int temp,divider;//temp存读者id，divider记初始除数 
    char filename[ReIDLen+30]="..\\project2\\ReaderNotice\\0000000.txt";//文件初始路径
	const int DIVIDER=1000000;//做取读者id位的处理 
	
	temp=readerid;
	divider=DIVIDER;
    for(i=0,j=25;i<ReIDLen;i++,j++) //将长整型的读者编号存入字符数组的相应位置
	{
		filename[j]=temp/divider+'0';
		temp=temp%divider;
		divider=divider/10;
	}

	ofstream fptr;
	fptr.open(filename,ios::out|ios::app);//以读和尾部追加的方式打开文件 

	fptr<<"您预约的编号为"<<bookid<<"的图书《"<<bookname<<"》因过长时间没来借阅，已被取消预约资格。如有需要请重新预约。"<<TimeConvert()<<"\n";//将提醒写入文件
	fptr.close();
			
	
	return true;	



} 



