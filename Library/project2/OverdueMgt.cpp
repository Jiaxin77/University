/******************************************************************
�ļ���: OverdueMgt.cpp
������:����
�ա���:2017.4.20
�޸���:��ʫ漡����
�ա���:2017.5.3
�衡��:���ڴ���
�桡��: v050601 Copyright(c).
******************************************************************/
#include "search.h"
#include "Notice.h"
#include "file.h"


/*****************************************************************
��������void OverdueMgt(Reader* rptr,Book* bptr,const int Booktotal,const int Readertotal)
���ܣ�������ڴ�������ʱ�������ж��Ƿ����ڣ����ڽ�����Ӧ������
����ֵ����
������
    int i,j,rank;//ѭ������
    int readerpos;//��Ӧ�����ڴ��е�λ��
    int passday;//��¼��������
    int readerid;//����id
    const int DIVIDEND=1000000;
****************************************************************/

void OverdueMgt(Reader* rptr,Book* bptr,const int Booktotal,const int Readertotal)//���ڴ���Booktotal���ڴ����������������ע��״̬�� 
{
	int i,j,rank;//ѭ������
	int readerpos;//��Ӧ�����ڴ��е�λ�� 
	int passday;//��¼�������� 
	int readerid;//����id 
	const int DIVIDEND=1000000;
	for(i=0;i<Booktotal;i++)
	{
		if(bptr[i].GetBBS()==instore&&bptr[i].GetExist()<bptr[i].GetTotal())//�����ڿ��������� 
		{   for(j=0;j<bptr[i].GetTotal();j++)//С�鱾�� 
            {
              if(bptr[i].GetOBState(j)==borrowed)
              {	readerid= bptr[i].GetOBReID(j);
				rank=readerid/DIVIDEND;
				if(1==rank)//ѧ��
				{
                    if(TIME>=bptr[i].GetOBBoTime(j)+StuTime)//ϵͳ��ǰʱ�䣬������ ,TIMEϵͳ��ǰʱ��
					{
						readerpos=SearchReader(rptr,readerid,Readertotal);//�ҵ��������ڴ��ж�Ӧ���±� 
						rptr[readerpos].SetFine(rptr[readerpos].GetFine()-OverdueFine);//�޸ķ����� 
						passday=bptr[i].GetOBPassDay(j)+1;
						bptr[i].SetOBPassDay(j,passday);//�޸��������� 
						if(1==passday)
                        {
                          SendPassDayNotice(readerid,bptr[i].GetBookID()+j,bptr[i].GetBookName());//��������֪ͨ
                          UpdateFineFile(rptr[readerpos].GetReaderID(),bptr[i].GetBookID(),OverdueFine,pass);//�������1��1ԪǮ
                        }

					} 
				}
				if(2==rank)//��ʦ
				{
                    if(TIME>=bptr[i].GetOBBoTime(j)+TeaTime)//ϵͳ��ǰʱ�䣬������ ,TIMEϵͳ��ǰʱ��
					{
						readerpos=SearchReader(rptr,readerid,Readertotal);//�ҵ��������ڴ��ж�Ӧ���±�
						rptr[readerpos].SetFine(rptr[readerpos].GetFine()-OverdueFine);//�޸ķ����� 
						passday=bptr[i].GetOBPassDay(j)+1;
						bptr[i].SetOBPassDay(j,passday);//�޸���������
						if(1==passday)  
                        {
                            SendPassDayNotice(readerid,bptr[i].GetBookID()+j,bptr[i].GetBookName());//��������֪ͨ
                            UpdateFineFile(rptr[readerpos].GetReaderID(),bptr[i].GetBookID(),OverdueFine,pass);//�������1��1ԪǮ
                        }

					} 
				} 
					
              }
           }
		}
	} 
	
	
} 
