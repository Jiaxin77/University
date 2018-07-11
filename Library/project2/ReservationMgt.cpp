/******************************************************************
文件名: ReservationMgt.cpp
创建人:张宇
日　期:2017.4.20
修改人:万诗婕
日　期:2017.5.1
描　述:和时间同步，完成预约处理。
版　本: v050601 Copyright(c).
******************************************************************/
#include"mytype.h"
#include "Notice.h"
#include <QDebug>

/*****************************************************************
函数名：void ReservationMgt(Book *p,const int Booktotal)
功能：完成预约处理。
返回值：无
参数：
    int i,j;//循环变量
    long int readerid;//记读者编号
    long long bookid;
    int passpeople=0;//记录超过提醒次数人数
    string bookname;
    RePeople *rep,*temp;//预约单以链表形式存储，申请两个指针用来做搜索等操作
****************************************************************/

void ReservationMgt(Book *p,const int Booktotal)//每一天做一次处理 
{
	int i,j;//循环变量 
	long int readerid;//记读者编号
	long long bookid;
	int passpeople=0;//记录超过提醒次数人数 
	string bookname; 
	RePeople *rep,*temp;
	
	for(i=0;i<Booktotal;i++)
	{
		if(p[i].GetBBS()==instore)
		{
			if(p[i].GetReBook()>0)
				{
					RePeople *&headrep=p[i].GetRePePo();
					rep=headrep->nextPtr;
					while(rep!=NULL&&rep->Notice>=0)//天数往前推进一天 
					{	
						rep->Notice++;
						
						if(rep->Notice>MaxReNoticeDay) {
							temp=rep->nextPtr;
							readerid=rep->ReaderID;
							bookid=p[i].GetBookID();
							bookname=p[i].GetBookName();
							SendMaxReNotice(readerid,bookid,bookname);
							p[i].DelRePeople(readerid);
							passpeople++; 
							rep=temp;
						}
						else{
							rep=rep->nextPtr;
						}
					}
					p[i].SetReBook(p[i].GetReBook()-passpeople);//设置一下预约的人数 
					
					rep=headrep->nextPtr;
					for(j=0;j<passpeople&&rep!=NULL;j++,rep=rep->nextPtr)
                    {
                        qDebug()<<readerid<<"R"<<endl;
						SendReserveNotice(p,i);
					}
					
				}
			passpeople=0;	
		
		}
		
		
		
	}
	

	rep=NULL;//将指针置空	
	
} 
