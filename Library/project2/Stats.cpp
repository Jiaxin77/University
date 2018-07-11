/******************************************************************
�ļ���: Stats.cpp
������:���������
�ա���:2017.4.20
�޸���:
�ա���:
�衡��:����ͼ�����С�
�桡��: v050601 Copyright(c).
******************************************************************/
#include "Stats.h" 
#include "file.h"
#include <QDebug>

/*****************************************************************
��������void Stats(Book* p,const int index,QStandardItemModel *rankinfo_model)
���ܣ�����ͼ�����У���������Ĵ���ǰʮ����ͼ�顣��
����ֵ��
������
  BookRanking* brptr=NULL;//����ʱʹ�õ��Զ���ṹ��
  brptr=new BookRanking[index];//��һ����������±�ͽ��Ĵ���
  int i,j,k;//ѭ������
  int all;//��¼ʵ�ʵı���
  int temppos,tempbo;//��ʱ��¼λ����Ϣ�ͽ��Ĵ���������ʱʹ��
  long long int lbookid;//ͼ��ı��
  int total;//�������
  string sbookname;//string���͵�ͼ����
  string sauthor; //string���͵Ķ�����
  string spublish;//string���͵ĳ�������
  string stype;//string���͵�ͼ������
  QString qbookid,qbookname,qauthor,qpublish,qtype,qtotal,qbocount;//�������������ʾ
****************************************************************/

void Stats(Book* p,const int index,QStandardItemModel *rankinfo_model)//index���ڴ����������������ע��״̬��
{
  BookRanking* brptr=NULL;
  brptr=new BookRanking[index];//��һ����������±�ͽ��Ĵ��� 
  int i,j,k;//ѭ������ 
  int all;//��¼ʵ�ʵı��� 
  int temppos,tempbo;//��ʱ��¼λ����Ϣ�ͽ��Ĵ���������ʱʹ�� 
  
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
  
  for(i=0;i<all-1;i++) //������Թ�û������ 
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

   for(i=0;i<10;i++)//��ӡǰʮ��
   {


       lbookid=p[brptr[i].position].GetBookID();//�õ���Ӧ���� ����ת��
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

       rankinfo_model->setItem(i, 0, new QStandardItem(qbookid));//�Զ�Ӧitem��������
       rankinfo_model->setItem(i, 1, new QStandardItem(qbookname));
       rankinfo_model->setItem(i, 2, new QStandardItem(qauthor));
       rankinfo_model->setItem(i, 3, new QStandardItem(qpublish));
       rankinfo_model->setItem(i, 4, new QStandardItem(qtype));
       rankinfo_model->setItem(i, 5, new QStandardItem(qtotal));
       rankinfo_model->setItem(i, 6, new QStandardItem(qbocount));

   }


	
}




