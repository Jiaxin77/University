/******************************************************************
文件名: Stats.cpp
创建人:张宇、刘佳鑫
日　期:2017.4.20
修改人:
日　期:
描　述:进行图书排行。
版　本: v050601 Copyright(c).
******************************************************************/
#include "Stats.h" 
#include "file.h"
#include <QDebug>

/*****************************************************************
函数名：void Stats(Book* p,const int index,QStandardItemModel *rankinfo_model)
功能：进行图书排行，并输出借阅次数前十名的图书。。
返回值：
参数：
  BookRanking* brptr=NULL;//排行时使用的自定义结构体
  brptr=new BookRanking[index];//存一下所有书的下标和借阅次数
  int i,j,k;//循环变量
  int all;//记录实际的本数
  int temppos,tempbo;//临时记录位置信息和借阅次数，交换时使用
  long long int lbookid;//图书的编号
  int total;//库存总数
  string sbookname;//string类型的图书名
  string sauthor; //string类型的读者名
  string spublish;//string类型的出版社名
  string stype;//string类型的图书类型
  QString qbookid,qbookname,qauthor,qpublish,qtype,qtotal,qbocount;//用于设置输出显示
****************************************************************/

void Stats(Book* p,const int index,QStandardItemModel *rankinfo_model)//index是内存中书的总数，包括注销状态的
{
  BookRanking* brptr=NULL;
  brptr=new BookRanking[index];//存一下所有书的下标和借阅次数 
  int i,j,k;//循环变量 
  int all;//记录实际的本数 
  int temppos,tempbo;//临时记录位置信息和借阅次数，交换时使用 
  
  for(i=0,j=0;i<index;i++)
  {	
  	if(p[i].GetBBS()==instore) 
  	{
  		brptr[j].position=i;
		brptr[j].bocount=p[i].GetBoCount();
		j++;	
	}
  
  }
  
  all=j;
  
  for(i=0;i<all-1;i++) //排序测试过没有问题 
  { j=i;
  	for(k=i+1;k<all;k++)
	  {
	  	if(brptr[j].bocount<brptr[k].bocount) j=k;
	   } 
  	if(i!=j)
  	{
  	temppos=brptr[i].position;
	tempbo=brptr[i].bocount;
	brptr[i].position=brptr[j].position;
	brptr[i].bocount=brptr[j].bocount;
	brptr[j].bocount=tempbo;
	brptr[j].position=temppos;	
	}
  
  }	

  long long int lbookid;
  int total;
  string sbookname;
  string sauthor;
  string spublish;
  string stype;
  QString qbookid,qbookname,qauthor,qpublish,qtype,qtotal,qbocount;

   for(i=0;i<10;i++)//打印前十名
   {


       lbookid=p[brptr[i].position].GetBookID();//得到相应数据 类型转换
       total=p[brptr[i].position].GetTotal();
       sbookname=p[brptr[i].position].GetBookName();
       sauthor=p[brptr[i].position].GetAuthor();
       spublish=p[brptr[i].position].GetPublish();
       stype=TransBookType(p[brptr[i].position].GetBT());

       qbookid=QString("%1").arg(lbookid);
       qbookname=qbookname.fromLocal8Bit(sbookname.data());
       qauthor=qauthor.fromLocal8Bit(sauthor.data());
       qpublish=qpublish.fromLocal8Bit(spublish.data());
       qtype=qtype.fromLocal8Bit(stype.data());
       qtotal=QString("%1").arg(total);
       qbocount=QString("%1").arg(brptr[i].bocount);

       rankinfo_model->setItem(i, 0, new QStandardItem(qbookid));//对对应item进行设置
       rankinfo_model->setItem(i, 1, new QStandardItem(qbookname));
       rankinfo_model->setItem(i, 2, new QStandardItem(qauthor));
       rankinfo_model->setItem(i, 3, new QStandardItem(qpublish));
       rankinfo_model->setItem(i, 4, new QStandardItem(qtype));
       rankinfo_model->setItem(i, 5, new QStandardItem(qtotal));
       rankinfo_model->setItem(i, 6, new QStandardItem(qbocount));

   }


	
}




