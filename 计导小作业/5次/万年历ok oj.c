#include<stdio.h>
#include<math.h>
int isLeap(int year);
int GetMonthDays(int year,int month);
int GetWeekDay(int year,int month,int day);
void PrintMonthCalender(int startDay,int days);

int isLeap(int year)
{   int flag;

    if(year%4==0)
       return 1;
    else
       return 0;//�ж����� 
}

int GetMonthDays(int year,int month)
{   int monthday,i;
    i=isLeap(year);
    if(i==1)//���ж����꺯����ȷ���Ƿ����� 
    {  if(month==2)
       {  monthday=29;
       }
    }//2������ 
    else
    {  if(month==2)
       {monthday=28;
       }
    } 
    if((month==1)||(month==3)||(month==5)||(month==7)||(month==8)||(month==10)||(month==12))
    {  monthday=31;
    }//31����·� 
    if((month==4)||(month==6)||(month==9)||(month==11))
    {  monthday=30;
    }//30����·� 
    return monthday;
}

int GetWeekDay(int year,int month,int day)
{   int x,days,monthday,weekday,month1;
    x=year-1;
    days=x*365+x/400+x/4-x/100;
    month1=1;
    
    
    while(month1<month)
    {     monthday=GetMonthDays(year,month1);
          days=days+monthday;
          month1++;
   }//ֱ��ÿ��1������ 
    
    weekday=(days+1)%7;
    return weekday;//ÿ��1�������ڼ� 
}

void PrintMonthCalender(int startDay,int days)
{    int day,i;
   
    for(i=1;i<=startDay;i++)
    {   
        printf("\t");//1��ǰ��tab 
    }
    i=i-1;

     for(day=1;day<=days;day++)
     {   printf("%d\t",day);
         i++;
         if(i%7==0)
         printf("\n");//��ӡ���� 
     }

}

main()   
{     printf("Please input year and month:");   
      int year,month,day,startDay,days;
      scanf("%d %d",&year,&month);
      printf("The result is:\n");
      printf("\t\t\t%d-%d\n",year,month);
      printf("Sun.\tMon.\tTue.\tWed.\tThu.\tFri.\tSat.\n"); 
      day=1;
      startDay=GetWeekDay(year,month,day);//ÿ����ʼ���� 
      days=GetMonthDays(year,month);//ÿ������ 
      PrintMonthCalender(startDay,days);
      
      
return 0;
}
