#include"varible.h"
#include<stdio.h>
#include"egg.h" 
/*�쳵���Ȳ��� */
int priority1(double speed1,double speed2)
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
 
 
/*������� */
int priority2(double speed1,double speed2)
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

/*�˹����Ʋ����£�A��B�𳵵�ѡ�� */
DWORD WINAPI WaitForSelectAB(LPVOID IpParameter)
{
	while(1)
	{
	    while(AB_control==1&&priority_control==1)
	    {
		    if (WaitForEvent() == KEYDOWN)
            {
    	        if(GetStruckKey() == VK_LBUTTON) 
                {
                    double  X = GetMouseX();
                    double  Y = GetMouseY();
                    if( (X >= 515 && X <= 600) && (Y >= 180 && Y <= 210) )//ѡ��A�� 
                    {
                        A.state=1;
                        printf("��ѡ����A����\n");
                        if(A.Circle==0)
                        {
                            Light_control_AB=1;//����A����ϲ���� 
					    }
					    else
					    {
						    Light_control_AB=2;//����A����²���� 
					    }					                    
                        AB_control=2;
	                }
	                if( (X >= 615 && X <= 655) && (Y >= 180 && Y <= 210) )//ѡ��B�� 
                    {
                	    B.state=1;
                    	printf("��ѡ����B����\n"); 
                        if(B.Circle==0)
                        {
                            Light_control_BA=1;//����B����²���� 
					    }
					    else
					    {
						    Light_control_BA=2;//����B����ϲ���� 
					    }                	
                        AB_control=3;                  
	                }
               }
            }
        }
	}
}

/*�˹����Ʋ����£�A��C�𳵵�ѡ�� */
DWORD WINAPI waitForSelectAC(LPVOID IpParameter)
{
	while(1)
	{
	    while(AC_control==1&&priority_control==1)
	    {
		    if (WaitForEvent() == KEYDOWN)
            {
    	        if(GetStruckKey() == VK_LBUTTON) //������������
                {
                    double  X = GetMouseX();
                    double  Y = GetMouseY();
                    if( (X >= 515 && X <= 600) && (Y >= 180 && Y <= 210) )//ѡA�� 
                    {
                        A.state=1;
                        printf("��ѡ����A����\n");
                        if(A.Circle==0)
                        {
                            Light_control_AC=1;//����A����Ҳ���� 
					    }
					    else
					    {
						    Light_control_AC=2;//����A��������� 
					    }                    
                        AC_control=2;
	                }
	                if( (X >= 670 && X <= 710) && (Y >= 180 && Y <= 210) )//ѡB�� 
                    {
                        C.state=1;
                        printf("��ѡ����C����\n");
                        if(C.Circle==0)
                        {
                            Light_control_CA=1;//����C��������� 
					    }
					    else
					    {
						    Light_control_CA=2;//����C����Ҳ���� 
					    } 
					    AC_control=3;                
	                }
               }
            }
	    }
    } 
}

