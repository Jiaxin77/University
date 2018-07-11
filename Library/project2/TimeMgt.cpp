/******************************************************************
�ļ���: TimeMgt.cpp
������:����
�ա���:2017.4.20
�޸���:
�ա���:
�衡��:���ʱ���ƽ���ʱ��ת��
�桡��: v050601 Copyright(c).
******************************************************************/
#include<ctime>
#include"mytype.h"


void TimePush()
{
	float secs=10; //���帡���ͱ���secs,10���ƽ�һ�� 
	clock_t delay;//����clock_t���͵ı�������ʾ��ʱʱ��
	delay=secs *CLOCKS_PER_SEC;  //delay��ֵΪsecs ����CLOCKS_PER_SECֵ�������������ת��ϵͳ��ʱ��
	clock_t start=clock(); //����clock_t���ͱ���start������ֵΪ��ǰϵͳ��ʱ��
	while(clock()-start < delay); // �����ǰʱ���ȥ��һ�̵�ϵͳʱ��С����ʱ��ϵͳʱ�䣬��ִ��ѭ���ȴ�����������ѭ��
	TIME++;//ϵͳʱ���1ȫ�ֱ��� 
} 


/*****************************************************************
��������string TimeConvert()
���ܣ�����������ֺͱ�׼���ڸ�ʽ��ת����
����ֵ��
    ��׼���ڸ�ʽ�µ�ʱ��
������
    string time;//�洢ת�����ϵͳʱ��
    int temp=TIME;//��ʱ��ϵͳʱ�䣬�������䱻�޸�
    int startyear=2017;//��¼��ʼ�����
    int yearcount=0;//��¼��ȥ�˼���
    int year;//��¼���
    int month;//��¼�·�
    int day;//��¼��
    int flag;//������껹����ͨ��
    int single;//��¼�����������浥��ȡ����λ��
    int ydivider=1000,mdivider=10,ddivider=10;//ת��ʱ��ʱʹ��
    int i;//���ת���˼�λ
****************************************************************/

string TimeConvert()//��ʼʱ��Ϊ2017.1.1 
{	string time;//�洢ת�����ϵͳʱ�� 
	int temp=TIME;//��ʱ��ϵͳʱ�䣬�������䱻�޸�
	int startyear=2017;//��¼��ʼ�����
	int yearcount=0;//��¼��ȥ�˼���
	int year;//��¼��� 
	int month;//��¼�·� 
	int day;//��¼�� 
	int flag;//������껹����ͨ�� 
	int single;//��¼�����������浥��ȡ����λ�� 
	int ydivider=1000,mdivider=10,ddivider=10;//ת��ʱ��ʱʹ�� 
    int i;//���ת���˼�λ	
	
	while(temp-365>0)
	{  
	   if(((yearcount+startyear)%4==0&&(yearcount+startyear)%100!=0)||((yearcount+startyear)%400==0))//�����ǰ������ 
		{	if(temp-366>0) 
				{
					temp=temp-366;
					yearcount++;	
				} 
			
		} 
		else//��Ϊ���� 
		{
			temp=temp-365; 
			yearcount++; 
		}
	} 

	
	 if(((yearcount+startyear)%4==0&&(yearcount+startyear)%100!=0)||((yearcount+startyear)%400==0))//�����ǰ������ 
	 {
	 	flag=0; 
	 } 
	 else
	 {
	 	flag=-1;
	 }
	 
	 
	if(temp>=1&&temp<=31)  //1�� 
	{
		month=1;
		day=temp;
	}
	else if(temp>=32&&temp<=(60+flag))	//2�� 
	{
		month=2;
		day=temp-31;
	}
	else if(temp>=(61+flag)&&temp<=(91+flag))	//3�� 
	{
		month=3;
		day=temp-(60+flag);
	}
	else if(temp>=(92+flag)&&temp<=(121+flag))	//4�� 
	{
		month=4;
		day=temp-(91+flag);
	}
	else if(temp>=(122+flag)&&temp<=(152+flag))	//5�� 
	{
  		month=5;
		day=temp-(121+flag);
	}
	else if(temp>=(153+flag)&&temp<=(182+flag))	//6�� 
	{
		month=6;
		day=temp-(152+flag);
	}
	else if(temp>=(183+flag)&&temp<=(213+flag))	//7�� 
	{
		month=7;
		day=temp-(182+flag);
	}
	else if(temp>=(214+flag)&&temp<=(244+flag))	//8�� 
	{
		month=8;
		day=temp-(213+flag);
	}
	else if(temp>=(245+flag)&&temp<=(274+flag))	//9�� 
	{
		month=9;
		day=temp-(244+flag);
	}
	else if(temp>=(275+flag)&&temp<=(305+flag))	//10�� 
	{
		month=10;
		day=temp-(274+flag);
	}
	else if(temp>=(306+flag)&&temp<=(335+flag))	//11�� 
	{
		month=11;
		day=temp-(305+flag);
	}
	else if(temp>=(336+flag)&&temp<=(366+flag))	//12�� 
	{
		month=12;
		day=temp-(335+flag);
	}
	
	i=0;//�����ת��Ϊ�ִ� 
	year=yearcount+startyear;		
	while(i<4)
	{	single=year/ydivider;
		time+=(single+'0');
		year=year%ydivider;
		ydivider=ydivider/10;
		i++;
	}
	time+='/';
	i=0;
	while(i<2)//���·�ת��Ϊ�ִ� 
	{	single=month/mdivider;
		time+=(single+'0');
		month=month%mdivider;
		mdivider=mdivider/10;
		i++;
	}
	time+='/';
	i=0;
	while(i<2)//������ת��Ϊ�ִ� 
	{	single=day/ddivider;
		time+=(single+'0');
		day=day%ddivider;
		ddivider=ddivider/10;
		i++;
	}
	
	return time;		
}

/*****************************************************************
��������string TimeConvertConst(int duetime)
���ܣ�����������ֺͱ�׼���ڸ�ʽ��ת����
����ֵ��
    ��׼���ڸ�ʽ�µ�ʱ��
������
    string time;//�洢ת�����ϵͳʱ��
    int temp=TIME;//��ʱ��ϵͳʱ�䣬�������䱻�޸�
    int startyear=2017;//��¼��ʼ�����
    int yearcount=0;//��¼��ȥ�˼���
    int year;//��¼���
    int month;//��¼�·�
    int day;//��¼��
    int flag;//������껹����ͨ��
    int single;//��¼�����������浥��ȡ����λ��
    int ydivider=1000,mdivider=10,ddivider=10;//ת��ʱ��ʱʹ��
    int i;//���ת���˼�λ
****************************************************************/

string TimeConvertConst(int duetime)//��ʼʱ��Ϊ2017.1.1
{	string time;//�洢ת�����ϵͳʱ��
    int temp=duetime;//��ʱ��ϵͳʱ�䣬�������䱻�޸�
    int startyear=2017;//��¼��ʼ�����
    int yearcount=0;//��¼��ȥ�˼���
    int year;//��¼���
    int month;//��¼�·�
    int day;//��¼��
    int flag;//������껹����ͨ��
    int single;//��¼�����������浥��ȡ����λ��
    int ydivider=1000,mdivider=10,ddivider=10;//ת��ʱ��ʱʹ��
    int i;//���ת���˼�λ

    while(temp-365>0)
    {
       if(((yearcount+startyear)%4==0&&(yearcount+startyear)%100!=0)||((yearcount+startyear)%400==0))//�����ǰ������
        {	if(temp-366>0)
                {
                    temp=temp-366;
                    yearcount++;
                }

        }
        else//��Ϊ����
        {
            temp=temp-365;
            yearcount++;
        }
    }


     if(((yearcount+startyear)%4==0&&(yearcount+startyear)%100!=0)||((yearcount+startyear)%400==0))//�����ǰ������
     {
        flag=0;
     }
     else
     {
        flag=-1;
     }


    if(temp>=1&&temp<=31)  //1��
    {
        month=1;
        day=temp;
    }
    else if(temp>=32&&temp<=(60+flag))	//2��
    {
        month=2;
        day=temp-31;
    }
    else if(temp>=(61+flag)&&temp<=(91+flag))	//3��
    {
        month=3;
        day=temp-(60+flag);
    }
    else if(temp>=(92+flag)&&temp<=(121+flag))	//4��
    {
        month=4;
        day=temp-(91+flag);
    }
    else if(temp>=(122+flag)&&temp<=(152+flag))	//5��
    {
        month=5;
        day=temp-(121+flag);
    }
    else if(temp>=(153+flag)&&temp<=(182+flag))	//6��
    {
        month=6;
        day=temp-(152+flag);
    }
    else if(temp>=(183+flag)&&temp<=(213+flag))	//7��
    {
        month=7;
        day=temp-(182+flag);
    }
    else if(temp>=(214+flag)&&temp<=(244+flag))	//8��
    {
        month=8;
        day=temp-(213+flag);
    }
    else if(temp>=(245+flag)&&temp<=(274+flag))	//9��
    {
        month=9;
        day=temp-(244+flag);
    }
    else if(temp>=(275+flag)&&temp<=(305+flag))	//10��
    {
        month=10;
        day=temp-(274+flag);
    }
    else if(temp>=(306+flag)&&temp<=(335+flag))	//11��
    {
        month=11;
        day=temp-(305+flag);
    }
    else if(temp>=(336+flag)&&temp<=(366+flag))	//12��
    {
        month=12;
        day=temp-(335+flag);
    }

    i=0;//�����ת��Ϊ�ִ�
    year=yearcount+startyear;
    while(i<4)
    {	single=year/ydivider;
        time+=(single+'0');
        year=year%ydivider;
        ydivider=ydivider/10;
        i++;
    }
    time+='/';
    i=0;
    while(i<2)//���·�ת��Ϊ�ִ�
    {	single=month/mdivider;
        time+=(single+'0');
        month=month%mdivider;
        mdivider=mdivider/10;
        i++;
    }
    time+='/';
    i=0;
    while(i<2)//������ת��Ϊ�ִ�
    {	single=day/ddivider;
        time+=(single+'0');
        day=day%ddivider;
        ddivider=ddivider/10;
        i++;
    }

    return time;
}
