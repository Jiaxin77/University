#include"varible.h"
#include<stdio.h>
int priority1(int speed1,int speed2)//�쳵���Ȳ��� 
{	int i;
	if(speed1>speed2)
      return 1;//���س���1 
    else if(speed2>speed1)
      return 0;//���س���2 
    else if(speed1==speed2)
      { i=priority2(speed1,speed2);//���ý������ 
        return i;
	  }
}
 

int priority2(int speed1,int speed2)//������� 
{	

    if((speed2==B.speed)&&(FLAG==1))
      {	FLAG=0;
	  	if(flag1==0)
      		{	flag1=1;	
			  	return 1;//���س���1 
			  }
		if(flag1==1)
			{	flag1=0;
			     return 0;//���س���2 
			}
		
	  }
	if((speed2==C.speed)&&(FLAG==0))
		{	FLAG=1;
			if(flag2==0)
				{	flag2=1;
				     return 1;//���س���1 
				}
			if(flag2==1)
				{	flag2=0;
				    return 0;//���س���2 
				}
			
		}
}



