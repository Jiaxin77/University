/******************************************************************
文件名: TimeMgt.cpp
创建人:张宇
日　期:2017.4.20
修改人:
日　期:
描　述:完成时间推进和时间转换
版　本: v050601 Copyright(c).
******************************************************************/
#include<ctime>
#include"mytype.h"


void TimePush()
{
	float secs=10; //定义浮点型变量secs,10秒推进一天 
	clock_t delay;//定义clock_t类型的变量，表示延时时间
	delay=secs *CLOCKS_PER_SEC;  //delay赋值为secs 乘以CLOCKS_PER_SEC值，将输入的秒数转化系统的时间
	clock_t start=clock(); //定义clock_t类型变量start，并赋值为当前系统的时间
	while(clock()-start < delay); // 如果当前时间减去上一刻的系统时间小于延时的系统时间，则执行循环等待，否则跳出循环
	TIME++;//系统时间加1全局变量 
} 


/*****************************************************************
函数名：string TimeConvert()
功能：完成整型数字和标准日期格式的转换。
返回值：
    标准日期格式下的时间
参数：
    string time;//存储转换完的系统时间
    int temp=TIME;//临时存系统时间，避免让其被修改
    int startyear=2017;//记录起始的年份
    int yearcount=0;//记录过去了几年
    int year;//记录年份
    int month;//记录月份
    int day;//记录日
    int flag;//标记闰年还是普通年
    int single;//记录从年月日里面单独取出的位数
    int ydivider=1000,mdivider=10,ddivider=10;//转换时间时使用
    int i;//标记转换了几位
****************************************************************/

string TimeConvert()//起始时间为2017.1.1 
{	string time;//存储转换完的系统时间 
	int temp=TIME;//临时存系统时间，避免让其被修改
	int startyear=2017;//记录起始的年份
	int yearcount=0;//记录过去了几年
	int year;//记录年份 
	int month;//记录月份 
	int day;//记录日 
	int flag;//标记闰年还是普通年 
	int single;//记录从年月日里面单独取出的位数 
	int ydivider=1000,mdivider=10,ddivider=10;//转换时间时使用 
    int i;//标记转换了几位	
	
	while(temp-365>0)
	{  
	   if(((yearcount+startyear)%4==0&&(yearcount+startyear)%100!=0)||((yearcount+startyear)%400==0))//如果当前是闰年 
		{	if(temp-366>0) 
				{
					temp=temp-366;
					yearcount++;	
				} 
			
		} 
		else//不为闰年 
		{
			temp=temp-365; 
			yearcount++; 
		}
	} 

	
	 if(((yearcount+startyear)%4==0&&(yearcount+startyear)%100!=0)||((yearcount+startyear)%400==0))//如果当前是闰年 
	 {
	 	flag=0; 
	 } 
	 else
	 {
	 	flag=-1;
	 }
	 
	 
	if(temp>=1&&temp<=31)  //1月 
	{
		month=1;
		day=temp;
	}
	else if(temp>=32&&temp<=(60+flag))	//2月 
	{
		month=2;
		day=temp-31;
	}
	else if(temp>=(61+flag)&&temp<=(91+flag))	//3月 
	{
		month=3;
		day=temp-(60+flag);
	}
	else if(temp>=(92+flag)&&temp<=(121+flag))	//4月 
	{
		month=4;
		day=temp-(91+flag);
	}
	else if(temp>=(122+flag)&&temp<=(152+flag))	//5月 
	{
  		month=5;
		day=temp-(121+flag);
	}
	else if(temp>=(153+flag)&&temp<=(182+flag))	//6月 
	{
		month=6;
		day=temp-(152+flag);
	}
	else if(temp>=(183+flag)&&temp<=(213+flag))	//7月 
	{
		month=7;
		day=temp-(182+flag);
	}
	else if(temp>=(214+flag)&&temp<=(244+flag))	//8月 
	{
		month=8;
		day=temp-(213+flag);
	}
	else if(temp>=(245+flag)&&temp<=(274+flag))	//9月 
	{
		month=9;
		day=temp-(244+flag);
	}
	else if(temp>=(275+flag)&&temp<=(305+flag))	//10月 
	{
		month=10;
		day=temp-(274+flag);
	}
	else if(temp>=(306+flag)&&temp<=(335+flag))	//11月 
	{
		month=11;
		day=temp-(305+flag);
	}
	else if(temp>=(336+flag)&&temp<=(366+flag))	//12月 
	{
		month=12;
		day=temp-(335+flag);
	}
	
	i=0;//将年份转换为字串 
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
	while(i<2)//将月份转换为字串 
	{	single=month/mdivider;
		time+=(single+'0');
		month=month%mdivider;
		mdivider=mdivider/10;
		i++;
	}
	time+='/';
	i=0;
	while(i<2)//将日期转换为字串 
	{	single=day/ddivider;
		time+=(single+'0');
		day=day%ddivider;
		ddivider=ddivider/10;
		i++;
	}
	
	return time;		
}

/*****************************************************************
函数名：string TimeConvertConst(int duetime)
功能：完成整型数字和标准日期格式的转换。
返回值：
    标准日期格式下的时间
参数：
    string time;//存储转换完的系统时间
    int temp=TIME;//临时存系统时间，避免让其被修改
    int startyear=2017;//记录起始的年份
    int yearcount=0;//记录过去了几年
    int year;//记录年份
    int month;//记录月份
    int day;//记录日
    int flag;//标记闰年还是普通年
    int single;//记录从年月日里面单独取出的位数
    int ydivider=1000,mdivider=10,ddivider=10;//转换时间时使用
    int i;//标记转换了几位
****************************************************************/

string TimeConvertConst(int duetime)//起始时间为2017.1.1
{	string time;//存储转换完的系统时间
    int temp=duetime;//临时存系统时间，避免让其被修改
    int startyear=2017;//记录起始的年份
    int yearcount=0;//记录过去了几年
    int year;//记录年份
    int month;//记录月份
    int day;//记录日
    int flag;//标记闰年还是普通年
    int single;//记录从年月日里面单独取出的位数
    int ydivider=1000,mdivider=10,ddivider=10;//转换时间时使用
    int i;//标记转换了几位

    while(temp-365>0)
    {
       if(((yearcount+startyear)%4==0&&(yearcount+startyear)%100!=0)||((yearcount+startyear)%400==0))//如果当前是闰年
        {	if(temp-366>0)
                {
                    temp=temp-366;
                    yearcount++;
                }

        }
        else//不为闰年
        {
            temp=temp-365;
            yearcount++;
        }
    }


     if(((yearcount+startyear)%4==0&&(yearcount+startyear)%100!=0)||((yearcount+startyear)%400==0))//如果当前是闰年
     {
        flag=0;
     }
     else
     {
        flag=-1;
     }


    if(temp>=1&&temp<=31)  //1月
    {
        month=1;
        day=temp;
    }
    else if(temp>=32&&temp<=(60+flag))	//2月
    {
        month=2;
        day=temp-31;
    }
    else if(temp>=(61+flag)&&temp<=(91+flag))	//3月
    {
        month=3;
        day=temp-(60+flag);
    }
    else if(temp>=(92+flag)&&temp<=(121+flag))	//4月
    {
        month=4;
        day=temp-(91+flag);
    }
    else if(temp>=(122+flag)&&temp<=(152+flag))	//5月
    {
        month=5;
        day=temp-(121+flag);
    }
    else if(temp>=(153+flag)&&temp<=(182+flag))	//6月
    {
        month=6;
        day=temp-(152+flag);
    }
    else if(temp>=(183+flag)&&temp<=(213+flag))	//7月
    {
        month=7;
        day=temp-(182+flag);
    }
    else if(temp>=(214+flag)&&temp<=(244+flag))	//8月
    {
        month=8;
        day=temp-(213+flag);
    }
    else if(temp>=(245+flag)&&temp<=(274+flag))	//9月
    {
        month=9;
        day=temp-(244+flag);
    }
    else if(temp>=(275+flag)&&temp<=(305+flag))	//10月
    {
        month=10;
        day=temp-(274+flag);
    }
    else if(temp>=(306+flag)&&temp<=(335+flag))	//11月
    {
        month=11;
        day=temp-(305+flag);
    }
    else if(temp>=(336+flag)&&temp<=(366+flag))	//12月
    {
        month=12;
        day=temp-(335+flag);
    }

    i=0;//将年份转换为字串
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
    while(i<2)//将月份转换为字串
    {	single=month/mdivider;
        time+=(single+'0');
        month=month%mdivider;
        mdivider=mdivider/10;
        i++;
    }
    time+='/';
    i=0;
    while(i<2)//将日期转换为字串
    {	single=day/ddivider;
        time+=(single+'0');
        day=day%ddivider;
        ddivider=ddivider/10;
        i++;
    }

    return time;
}
