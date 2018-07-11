/******************************************************************
�ļ���: ReservationMgt.cpp
������:����
�ա���:2017.4.20
�޸���:��ʫ�
�ա���:2017.5.1
�衡��:��ʱ��ͬ�������ԤԼ����
�桡��: v050601 Copyright(c).
******************************************************************/
#include"mytype.h"
#include "Notice.h"
#include <QDebug>

/*****************************************************************
��������void ReservationMgt(Book *p,const int Booktotal)
���ܣ����ԤԼ����
����ֵ����
������
    int i,j;//ѭ������
    long int readerid;//�Ƕ��߱��
    long long bookid;
    int passpeople=0;//��¼�������Ѵ�������
    string bookname;
    RePeople *rep,*temp;//ԤԼ����������ʽ�洢����������ָ�������������Ȳ���
****************************************************************/

void ReservationMgt(Book *p,const int Booktotal)//ÿһ����һ�δ��� 
{
	int i,j;//ѭ������ 
	long int readerid;//�Ƕ��߱��
	long long bookid;
	int passpeople=0;//��¼�������Ѵ������� 
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
					while(rep!=NULL&&rep->Notice>=0)//������ǰ�ƽ�һ�� 
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
					p[i].SetReBook(p[i].GetReBook()-passpeople);//����һ��ԤԼ������ 
					
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
	

	rep=NULL;//��ָ���ÿ�	
	
} 
