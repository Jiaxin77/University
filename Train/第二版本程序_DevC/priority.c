#include"varible.h"
#include<stdio.h>
#include"egg.h" 
/*快车优先策略 */
int priority1(double speed1,double speed2)
{	int i;
	if(speed1>speed2)
      return 1;//返回车辆1 
    else if(speed2>speed1)
      return 0;//返回车辆2 
    else if(speed1==speed2)
      { i=priority2(speed1,speed2);//调用交替策略 
        return i;
	  }
}
 
 
/*交替策略 */
int priority2(double speed1,double speed2)
{	

    if((speed2==B.speed)&&(FLAG==1))
      {	FLAG=0;
	  	if(flag1==0)
      		{	flag1=1;	
			  	return 1;//返回车辆1 
			  }
		if(flag1==1)
			{	flag1=0;
			     return 0;//返回车辆2 
			}
		
	  }
	if((speed2==C.speed)&&(FLAG==0))
		{	FLAG=1;
			if(flag2==0)
				{	flag2=1;
				     return 1;//返回车辆1 
				}
			if(flag2==1)
				{	flag2=0;
				    return 0;//返回车辆2 
				}
			
		}
}

/*人工控制策略下，A和B火车的选择 */
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
                    if( (X >= 515 && X <= 600) && (Y >= 180 && Y <= 210) )//选择A车 
                    {
                        A.state=1;
                        printf("您选择了A先走\n");
                        if(A.Circle==0)
                        {
                            Light_control_AB=1;//控制A轨道上侧灯亮 
					    }
					    else
					    {
						    Light_control_AB=2;//控制A轨道下侧灯亮 
					    }					                    
                        AB_control=2;
	                }
	                if( (X >= 615 && X <= 655) && (Y >= 180 && Y <= 210) )//选择B车 
                    {
                	    B.state=1;
                    	printf("您选择了B先走\n"); 
                        if(B.Circle==0)
                        {
                            Light_control_BA=1;//控制B轨道下侧灯亮 
					    }
					    else
					    {
						    Light_control_BA=2;//控制B轨道上侧灯亮 
					    }                	
                        AB_control=3;                  
	                }
               }
            }
        }
	}
}

/*人工控制策略下，A和C火车的选择 */
DWORD WINAPI waitForSelectAC(LPVOID IpParameter)
{
	while(1)
	{
	    while(AC_control==1&&priority_control==1)
	    {
		    if (WaitForEvent() == KEYDOWN)
            {
    	        if(GetStruckKey() == VK_LBUTTON) //鼠标左键被按下
                {
                    double  X = GetMouseX();
                    double  Y = GetMouseY();
                    if( (X >= 515 && X <= 600) && (Y >= 180 && Y <= 210) )//选A车 
                    {
                        A.state=1;
                        printf("您选择了A先走\n");
                        if(A.Circle==0)
                        {
                            Light_control_AC=1;//控制A轨道右侧灯亮 
					    }
					    else
					    {
						    Light_control_AC=2;//控制A轨道左侧灯亮 
					    }                    
                        AC_control=2;
	                }
	                if( (X >= 670 && X <= 710) && (Y >= 180 && Y <= 210) )//选B车 
                    {
                        C.state=1;
                        printf("您选择了C先走\n");
                        if(C.Circle==0)
                        {
                            Light_control_CA=1;//控制C轨道左侧灯亮 
					    }
					    else
					    {
						    Light_control_CA=2;//控制C轨道右侧灯亮 
					    } 
					    AC_control=3;                
	                }
               }
            }
	    }
    } 
}

