#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h> 
#include"Define.h"
#include"funtion.h"
#include"input.h"
#include"output.h"
#include"priority.h"
#include"traincontrol.h"
#include"varible.h"
#include"egg.h"
#include<string.h>
/*命令行输出+文件输出的线程*/ 
DWORD WINAPI OUTPUT(LPVOID lpParameter)
{
	FILE*f1=fopen("模拟火车调度系统.txt","w");
	clock_t start1, finish1;//创建时刻 
	fclose(f1);
	start1=clock();
	char tra[10]={0}; 
    char run[10]={0};
    while(1)
	{
		f1=fopen("模拟火车调度系统.txt","a");//用可添加方式打开文件 
		
		
		finish1=clock();
	    count=(finish1-start1)/1000;//计算当前时间 
		if(count%1==0)//每1s输出一次 
		{
		    Sleep(1000); 
		    printf("当前时间：%d\n",count);//输出当前时间 
		    /*输出当前控制策略*/ 
		    if(priority_control==0)
		    {
		        printf("当前策略为快车优先策略\n");			
		    }
            else
            {
        	    printf("当前策略为人工控制策略\n");
		    }
				
		    /*输出当前时间和控制策略到文件*/ 
   		    fprintf(f1,"当前时间：%d\n",count);
		    if(priority_control==0) 
		    {
			    fprintf(f1,"当前策略为快车优先策略\n"); 
		    }		
            else
            {
        	    fprintf(f1,"当前策略为人工控制策略\n"); 
		    }
		    
		    
            /*输出A火车的信息到命令行和文件*/
            /*输出A火车的顺逆时针信息到命令行和文件*/
		    if(A.Circle==0)
		    { 
		        printf("A火车顺时针运行\n");
		        fprintf(f1,"A火车顺时针运行\n");
		    } 
		    if(A.Circle==1)
		    { 
		        printf("A火车逆时针运行\n"); 
		        fprintf(f1,"A火车逆时针运行\n"); 
		    }
		    
		    /*输出A火车的状态信息到命令行和文件*/
		    if(A.state==0&&((A.location>50)&&(A.location<75)||(A.location>90)&&(A.location<125)))//A在公共轨道内且状态为静止	   	
		    {	
			    if(A.control==1)//判断A暂停的原因 
			    {
				    strcpy(tra,"接受用户命令");
				    strcpy(run,"暂停");	
			    }
			    else
			    {
			        strcpy(tra,"占用公共轨道");
			        strcpy(run,"停靠");
			        AStayFinish=clock();
			        AStay=StayTime*1000-(AStayFinish-AStayStart)+100;//计算A停靠剩余时间 
			        if(count<=A.startTime)
			        {	
				        printf("A车等待出发\n");
				        fprintf(f1,"A车等待出发\n");
			        }
			        else
			        {
			            printf("A车停靠剩余时间：%d毫秒\n",AStay);
			            fprintf(f1,"A车停靠剩余时间：%d毫秒\n",AStay);
			        }
			    }
		    }
				   
		    if(A.state==0&&((A.location<=50)||((A.location>=75)&&(A.location<=90))||(A.location>=125)))//A在在公共轨道外且状态为静止
		    {	
			    if(A.control==1)
			    {	
				    strcpy(tra,"接受用户命令");
				    strcpy(run,"暂停");	
			    }
			    else
			    {
			        strcpy(tra,"等待公共轨道");
			        strcpy(run,"暂停");
				}
		    }		
			  
		    if(A.state==1&&(((A.location>50)&&(A.location<75))||((A.location>90)&&(A.location<125))))//A在公共轨道内且状态为运动 
		    {
			    strcpy(tra,"公共轨道");
			    strcpy(run,"运行");
		    }
		    
		    if(A.state==1&&(A.location<=50||(A.location>=75)&&(A.location<=90)||A.location>=125))//A在公共轨道内且状态为运动		   
		    {
   			    strcpy(tra,"非公共轨道");
		 	    strcpy(run,"运行");
		    }
		    printf("A火车运行状态：%s-%s\n",run,tra);//输出A车状态 
		    printf("A火车当前位置：%f\n",A.location);//输出A车位置 
		    fprintf(f1,"A火车运行状态：%s-%s\n",run,tra);//输出A车状态 
		    fprintf(f1,"A火车当前位置：%f\n",A.location);//输出A车位置 




            /*输出B火车的信息到命令行和文件*/ 
            /*输出B火车的顺逆时针信息到命令行和文件*/
	        if(B.Circle==0)
	        { 
		        printf("B火车顺时针运行\n");
		        fprintf(f1,"B火车顺时针运行\n");
		    } 
		    if(B.Circle==1)
		    {
			   printf("B火车逆时针运行\n"); 
		       fprintf(f1,"B火车逆时针运行\n"); 
		    } 
		    
		    /*输出B火车的状态信息到命令行和文件*/
		    if(B.state==0&&(B.location>25&&B.location<50))//B公共轨道内且状态为静止
	     	{	
			    if(B.control==1)//判断B车暂停原因 
			    {	
				    strcpy(tra,"接受用户命令");
			  	    strcpy(run,"暂停");
			    }
			    else
			    {
			        strcpy(tra,"占用公共轨道");
			        strcpy(run,"停靠");
			        BStayFinish=clock();//计算B车停靠剩余时间 
			        BStay=StayTime*1000-(BStayFinish-BStayStart)+100;
			        if(count<=B.startTime)
			        {	
					    printf("B车等待出发\n");
				        fprintf(f1,"B车等待出发\n");
			        }
			        else
			        {
			            printf("B车停靠剩余时间:%d毫秒\n",BStay);
			            fprintf(f1,"B车停靠剩余时间:%d毫秒\n",BStay);
                    }
			    } 
		    }
    		if(B.state==0&&(B.location<=25||B.location>=50))//B在公共轨道外且状态为静止
		    {	
			    if(B.control==1)
			    {	
				    strcpy(tra,"接受用户命令");
			  	    strcpy(run,"暂停");
			    }
			    else
			    {
			        strcpy(tra,"等待公共轨道");
			        strcpy(run,"暂停");
				} 
		    }	   
    		if(B.state==1&&(B.location>25&&B.location<505))//B在公共轨道外且状态为运动	   	
		    { 
			    strcpy(tra,"公共轨道");
			    strcpy(run,"运行");	
			}
			if((B.state==1)&&((B.location<=25)||(B.location>=50)))//B在公共轨道内且状态为静止	   	
		    {
			    strcpy(tra,"非公共轨道");
			    strcpy(run,"运行");
		    }	   	  
            printf("B火车运行状态：%s-%s\n",run,tra);//输出B车状态
		    printf("B火车当前位置：%f\n",B.location);//输出B车位置 
		    fprintf(f1,"B火车运行状态：%s-%s\n",run,tra);//输出B车状态
		    fprintf(f1,"B火车当前位置：%f\n",B.location);//输出B车位置 



            /*输出C火车的信息到命令行和文件*/  
            /*输出C火车的顺逆时针信息到命令行和文件*/
		    if(C.Circle==0)
		    {
			    printf("C火车顺时针运行\n");
		        fprintf(f1,"C火车顺时针运行\n");
		    } 
		    if(C.Circle==1)
		    {
			    printf("C火车逆时针运行\n");
		        fprintf(f1,"C火车逆时针运行\n");
			} 
	
	        /*输出C火车的状态信息到命令行和文件*/
		    if(C.state==0&&(C.location>60&&C.location<95))//C在公共轨道外且状态为静止	   	
		    {	
			    if(C.control==1)
			    {
				    strcpy(tra,"接受用户命令");
			        strcpy(run,"暂停"); 
			    }
			    else
			    {
			        strcpy(tra,"占用公共轨道");
			        strcpy(run,"停靠");
			        CStayFinish=clock();//计算C车停靠剩余时间 
		         	CStay=StayTime*1000-(CStayFinish-CStayStart)+100;
			        if(count<=C.startTime)
			        {	
				        printf("C车等待出发\n");
				        fprintf(f1,"C车等待出发\n");
			        }
			        else
					{ 
			            printf("C车停靠剩余时间:%d毫秒\n",CStay);
			            fprintf(f1,"C车停靠剩余时间:%d毫秒\n",CStay);
	                }
			   } 
		    }
	        if(C.state==0&&(C.location<=60||C.location>=95))//C在公共轨道内且状态为静止		   	
		    {
			    if(C.control==1)
			    {
				    strcpy(tra,"接受用户命令");
			        strcpy(run,"暂停"); 
			    }
			    else
			    {
			        strcpy(tra,"等待公共轨道");
			        strcpy(run,"暂停");
				}
		    }	   
		    if(C.state==1&&(C.location>60&&C.location<95))	//C在公共轨道外且状态为运动	   	
		    { 
			    strcpy(tra,"公共轨道");
			    strcpy(run,"运行");	
	        }
		    if((C.state==1)&&((C.location<=60||C.location>=95)))//C在公共轨道外且状态为静止		   	
		    {
			    strcpy(tra,"非公共轨道");
			    strcpy(run,"运行");
	        }	   	  
     	    printf("C火车运行状态：%s-%s\n",run,tra);
		    printf("C火车当前位置：%f\n",C.location);
		    fprintf(f1,"C火车运行状态：%s-%s\n",run,tra);
		    fprintf(f1,"C火车当前位置：%f\n",C.location);
		    


		    /*输出AB公共轨道状态*/
		    if((A.location>50)&&(A.location<75))
		    {
		        printf("AB公共轨道被A车占用\n");
		        fprintf(f1,"AB公共轨道被A车占用\n");
	      	} 
		    else if((B.location>25)&&(B.location<50))
		    {
		        printf("AB公共轨道被B车占用\n");
		        fprintf(f1,"AB公共轨道被B车占用\n");
		    }
		    else
		    {
		        printf("AB公共轨道空闲\n"); 
		        fprintf(f1,"AB公共轨道空闲\n"); 
		    }
		    /*输出AC公共轨道状态*/
		    if((A.location>90)&&(A.location<125))
		    {
		        printf("AC公共轨道被A车占用\n");
		        fprintf(f1,"AC公共轨道被A车占用\n");
		    }
		    else if((C.location>60)&&(C.location<95))
		    {
		        printf("AC公共轨道被C车占用\n");
		        fprintf(f1,"AC公共轨道被C车占用\n");
		    }
		    else
		    {
		        printf("AC公共轨道空闲\n");
		        fprintf(f1,"AC公共轨道空闲\n"); 	
	     	}

					
		    printf("\n");	
		    fprintf(f1,"\n");	
		
	
		    finish1=clock();
		    count=(finish1-start1)/1000;
		}
	        fclose(f1);//关闭并储存文件 
	}
}

/*图形化输出函数*/
void Output_picture()
{
	    char time[10]={0};
	    
	    
	    /*控制火车的画布的更新*/
		TrainAmove();
        TrainBmove();
        TrainCmove();


         /*控制按钮的画布的更新*/
		if(FlagFast==1)//按下快车优先 
		{	
		    fast();
		}
		if(FlagFast==0)//按下人工控制 
		{	
		    facility();
		}
		
		
         /*控制总时间的画布的更新*/		
		int m;
		if(count>0)
		{
			m=count-1;
		}
		else
		{
			m=0;
		}
		sprintf(time,   "%d ",   m); //把数字转换为字符串了
	   	SetActiveEgg(Time);
	   	MovePen(650.9,396.2);
	   	DrawString(time);	
	   	
	   	
	   	/*控制A停靠时间的画布的更新*/
	   	if(A.state==0&&((A.location>50)&&(A.location<75)||(A.location>90)&&(A.location<125)))	   	
		{	
		    if(A.control==1) 
			{	
			}
			else
			{
			    if(count<=A.startTime)
			    {	
			    }
			    else//以上为A显示示停靠时间的条件 
			    {
			        memset(Astay,'\0',sizeof(Astay));
			        sprintf(Astay,   "%d ",   AStay);
			        SetActiveEgg(ASstay);
		           	ShowEgg(1);
	   		        MovePen(396.2,424.5);
	   		        DrawString(Astay);
	  	 	        strcpy(Astay,"0000"); 

			    }
			}
		}
		else
		{	
		    SetActiveEgg(ASstay);
			ShowEgg(0);
		}
		
		/*控制B停靠时间的画布的更新*/
		if(B.state==0&&(B.location>25&&B.location<50))	   	
		{	if(B.control==1)
			{	
			}
			else
			{
			    if(count<=B.startTime)
			    {
			    }
			    else//以上为B显示示停靠时间的条件 
			    {
			        sprintf(Bstay,   "%d ",   BStay);			    	
			        SetActiveEgg(BSstay);
			        ShowEgg(1);
	   		        MovePen(452.8,424.5);
	   		        DrawString(Bstay);
	  	 	        strcpy(Bstay,"0"); 
			    }
			} 
		}
		else
		{	
		    SetActiveEgg(BSstay);
			ShowEgg(0);
		}
		
		/*控制C停靠时间的画布的更新*/
		if(C.state==0&&(C.location>60&&C.location<95))	   	
		{	
		    if(C.control==1)
			{
			}
			else
			{

			    if(count<=C.startTime)
			    {	
			    }
			    else
				{ 
			        sprintf(Cstay,   "%d ",   CStay);
			        SetActiveEgg(CSstay);
			        ShowEgg(1);
	   		        MovePen(537.7,424.5);
	   		        DrawString(Cstay);
	  	 	        strcpy(Cstay,"0000"); 
			   }
			} 
		}
		else
		{
			SetActiveEgg(CSstay);
			ShowEgg(0);
		}
		

	    /*控制探测灯的画布的更新*/
		if(Light_control_AB==1)
		{
		    SetActiveEgg(LightA7);
		    ShowEgg(0);
		    SetActiveEgg(LightA8);
		    ShowEgg(1);
		}
		else if(Light_control_AB==2)
		{
		    SetActiveEgg(LightA5);
		    ShowEgg(0);
		    SetActiveEgg(LightA6);
		    ShowEgg(1);
		}
		if(A.location>=75||A.location<=50)
		{
			Light_control_AB=0;
			SetActiveEgg(LightA8);
			ShowEgg(0);
			SetActiveEgg(LightA7);
			ShowEgg(1);
			SetActiveEgg(LightA6);
			ShowEgg(0);
			SetActiveEgg(LightA5);
			ShowEgg(1);
		}				
		
				
		if(Light_control_AC==1)
		{
		    SetActiveEgg(LightA3);
		    ShowEgg(0);
		    SetActiveEgg(LightA4);
		    ShowEgg(1);			
		}
		else if(Light_control_AC==2)
		{
		    SetActiveEgg(LightA1);
		    ShowEgg(0);
		    SetActiveEgg(LightA2);
		    ShowEgg(1); 
		}
		if(A.location>=125||A.location<=90)
		{
			Light_control_AC=0;
			SetActiveEgg(LightA2);
			ShowEgg(0);
			SetActiveEgg(LightA1);
			ShowEgg(1);
			SetActiveEgg(LightA4);
			ShowEgg(0);
			SetActiveEgg(LightA3);
			ShowEgg(1);
		}
		
		if(Light_control_BA==1)
		{
		    SetActiveEgg(LightB3);
		    ShowEgg(0);
		    SetActiveEgg(LightB4);
		    ShowEgg(1);
		}
		else if(Light_control_BA==2)
		{
		    SetActiveEgg(LightB1);
		    ShowEgg(0);
		    SetActiveEgg(LightB2);
		    ShowEgg(1);
		}
		if(B.location>=50||B.location<=25)
		{
			Light_control_BA=0;
		    SetActiveEgg(LightB4);
		    ShowEgg(0);
		    SetActiveEgg(LightB3);
		    ShowEgg(1);	
			SetActiveEgg(LightB2);
		    ShowEgg(0);
		    SetActiveEgg(LightB1);
		    ShowEgg(1);		
		}
		
		
		if(Light_control_CA==1)
		{
		    SetActiveEgg(LightC1);
		    ShowEgg(0);
		    SetActiveEgg(LightC2);
		    ShowEgg(1);
		}
		else if(Light_control_CA==2)
		{
		    SetActiveEgg(LightC3);
		    ShowEgg(0);
		    SetActiveEgg(LightC4);
		    ShowEgg(1); 			
		}
		if(C.location>=95||C.location<=60)
		{
			Light_control_CA=0;
			SetActiveEgg(LightC4);
		    ShowEgg(0);
		    SetActiveEgg(LightC3);
		    ShowEgg(1);
		    SetActiveEgg(LightC2);
		    ShowEgg(0);
		    SetActiveEgg(LightC1);
		    ShowEgg(1);		    
		}	
}



/*需要即时输出时调用的函数*/
void printChange()
{
	FILE*f1=fopen("模拟火车调度系统.txt","a");
    //f1=fopen("模拟火车调度系统1.txt","a");
	char trac[10]={0}; 
    char runc[10]={0};
   
    
    int count1;
	{	finish=clock();
	    count1=(finish-start)/1000;
	   
	
		printf("当前时间：%d\n",count1);
		if(priority_control==0)
		{
		    printf("当前策略为快车优先策略\n");			
		}
        else
        {
        	printf("当前策略为人工控制策略\n");
		}
   		    fprintf(f1,"当前时间：%d\n",count);
		    if(priority_control==0) 
		    {
			    fprintf(f1,"当前策略为快车优先策略\n"); 
		    }		
            else
            {
        	    fprintf(f1,"当前策略为人工控制策略\n"); 
		    }		
		
		
		
		    if(A.Circle==0)
		    { 
		        printf("A火车顺时针运行\n");
		        fprintf(f1,"A火车顺时针运行\n");
		    } 
		    if(A.Circle==1)
		    { 
		        printf("A火车逆时针运行\n"); 
		        fprintf(f1,"A火车逆时针运行\n"); 
		    }

		    if(A.state==0&&((A.location>50)&&(A.location<75)||(A.location>90)&&(A.location<125)))//A在公共轨道内且状态为静止	   	
		    {	
			    if(A.control==1)//判断A暂停的原因 
			    {
				    strcpy(trac,"接受用户命令");
				    strcpy(runc,"暂停");	
			    }
			    else
			    {
			        strcpy(trac,"占用公共轨道");
			        strcpy(runc,"停靠");
			        AStayFinish=clock();
			        AStay=StayTime*1000-(AStayFinish-AStayStart)+100;//计算A停靠剩余时间 
			        if(count<=A.startTime)
			        {	
				        printf("A车等待出发\n");
				        fprintf(f1,"A车等待出发\n");
			        }
			        else
			        {
			            printf("A车停靠剩余时间：%d毫秒\n",AStay);
			            fprintf(f1,"A车停靠剩余时间：%d毫秒\n",AStay);
			        }
			    }
		    }	   
		    if(A.state==0&&((A.location<=50)||((A.location>=75)&&(A.location<=90))||(A.location>=125)))//A在在公共轨道外且状态为静止
		    {	
			    if(A.control==1)
			    {	
				    strcpy(trac,"接受用户命令");
				    strcpy(runc,"暂停");	
			    }
			    else
			    {
			        strcpy(trac,"等待公共轨道");
			        strcpy(runc,"暂停");
				}
		    }		
			  
		    if(A.state==1&&(((A.location>50)&&(A.location<75))||((A.location>90)&&(A.location<125))))//A在公共轨道内且状态为运动 
		    {
			    strcpy(trac,"公共轨道");
			    strcpy(runc,"运行");
		    }
		    
		    if(A.state==1&&(A.location<=50||(A.location>=75)&&(A.location<=90)||A.location>=125))//A在公共轨道内且状态为运动		   
		    {
   			    strcpy(trac,"非公共轨道");
		 	    strcpy(runc,"运行");
		    }
		    printf("A火车运行状态：%s-%s\n",runc,trac);//输出A车状态 
		    printf("A火车当前位置：%f\n",A.location);//输出A车位置 
		    fprintf(f1,"A火车运行状态：%s-%s\n",runc,trac);//输出A车状态 
		    fprintf(f1,"A火车当前位置：%f\n",A.location);//输出A车位置 
		    

	        if(B.Circle==0)
	        { 
		        printf("B火车顺时针运行\n");
		        fprintf(f1,"B火车顺时针运行\n");
		    } 
		    if(B.Circle==1)
		    {
			   printf("B火车逆时针运行\n"); 
		       fprintf(f1,"B火车逆时针运行\n"); 
		    } 
		    
		    
		    if(B.state==0&&(B.location>25&&B.location<50))//B公共轨道内且状态为静止
	     	{	
			    if(B.control==1)//判断B车暂停原因 
			    {	
				    strcpy(trac,"接受用户命令");
			  	    strcpy(runc,"暂停");
			    }
			    else
			    {
			        strcpy(trac,"占用公共轨道");
			        strcpy(runc,"停靠");
			        BStayFinish=clock();//计算B车停靠剩余时间 
			        BStay=StayTime*1000-(BStayFinish-BStayStart)+100;
			        if(count<=B.startTime)
			        {	
					    printf("B车等待出发\n");
				        fprintf(f1,"B车等待出发\n");
			        }
			        else
			        {
			            printf("B车停靠剩余时间:%d毫秒\n",BStay);
			            fprintf(f1,"B车停靠剩余时间:%d毫秒\n",BStay);
                    }
			    } 
		    }
    		if(B.state==0&&(B.location<=25||B.location>=50))//B在公共轨道外且状态为静止
		    {	
			    if(B.control==1)
			    {	
				    strcpy(trac,"接受用户命令");
			  	    strcpy(runc,"暂停");
			    }
			    else
			    {
			        strcpy(trac,"等待公共轨道");
			        strcpy(runc,"暂停");
				} 
		    }	   
    		if(B.state==1&&(B.location>25&&B.location<505))//B在公共轨道外且状态为运动	   	
		    { 
			    strcpy(trac,"公共轨道");
			    strcpy(runc,"运行");	
			}
			if((B.state==1)&&((B.location<=25)||(B.location>=50)))//B在公共轨道内且状态为静止	   	
		    {
			    strcpy(trac,"非公共轨道");
			    strcpy(runc,"运行");
		    }	   	  
            printf("B火车运行状态：%s-%s\n",runc,trac);//输出B车状态
		    printf("B火车当前位置：%f\n",B.location);//输出B车位置 
		    fprintf(f1,"B火车运行状态：%s-%s\n",runc,trac);//输出B车状态
		    fprintf(f1,"B火车当前位置：%f\n",B.location);//输出B车位置 
		
		    if(C.Circle==0)
		    {
			    printf("C火车顺时针运行\n");
		        fprintf(f1,"C火车顺时针运行\n");
		    } 
		    if(C.Circle==1)
		    {
			    printf("C火车逆时针运行\n");
		        fprintf(f1,"C火车逆时针运行\n");
			}
	
	
		    if(C.state==0&&(C.location>60&&C.location<95))//C在公共轨道外且状态为静止	   	
		    {	
			    if(C.control==1)
			    {
				    strcpy(trac,"接受用户命令");
			        strcpy(runc,"暂停"); 
			    }
			    else
			    {
			        strcpy(trac,"占用公共轨道");
			        strcpy(runc,"停靠");
			        CStayFinish=clock();//计算C车停靠剩余时间 
		         	CStay=StayTime*1000-(CStayFinish-CStayStart)+100;
			        if(count<=C.startTime)
			        {	
				        printf("C车等待出发\n");
				        fprintf(f1,"C车等待出发\n");
			        }
			        else
					{ 
			            printf("C车停靠剩余时间:%d毫秒\n",CStay);
			            fprintf(f1,"C车停靠剩余时间:%d毫秒\n",CStay);
	                }
			   } 
		    }
	        if(C.state==0&&(C.location<=60||C.location>=95))//C在公共轨道内且状态为静止		   	
		    {
			    if(C.control==1)
			    {
				    strcpy(trac,"接受用户命令");
			        strcpy(runc,"暂停"); 
			    }
			    else
			    {
			        strcpy(trac,"等待公共轨道");
			        strcpy(runc,"暂停");
				}
		    }	   
		    if(C.state==1&&(C.location>60&&C.location<95))	//C在公共轨道外且状态为运动	   	
		    { 
			    strcpy(trac,"公共轨道");
			    strcpy(runc,"运行");	
	        }
		    if((C.state==1)&&((C.location<=60||C.location>=95)))//C在公共轨道外且状态为静止		   	
		    {
			    strcpy(trac,"非公共轨道");
			    strcpy(runc,"运行");
	        }	   	  
     	    printf("C火车运行状态：%s-%s\n",runc,trac);
		    printf("C火车当前位置：%f\n",C.location);
		    fprintf(f1,"C火车运行状态：%s-%s\n",runc,trac);
		    fprintf(f1,"C火车当前位置：%f\n",C.location);

		
		    if((A.location>50)&&(A.location<75))
		    {
		        printf("AB公共轨道被A车占用\n");
		        fprintf(f1,"AB公共轨道被A车占用\n");
	      	} 
		    else if((B.location>25)&&(B.location<50))
		    {
		        printf("AB公共轨道被B车占用\n");
		        fprintf(f1,"AB公共轨道被B车占用\n");
		    }
		    else
		    {
		        printf("AB公共轨道空闲\n"); 
		        fprintf(f1,"AB公共轨道空闲\n"); 
		    }
		    /*输出AC公共轨道状态*/
		    if((A.location>90)&&(A.location<125))
		    {
		        printf("AC公共轨道被A车占用\n");
		        fprintf(f1,"AC公共轨道被A车占用\n");
		    }
		    else if((C.location>60)&&(C.location<95))
		    {
		        printf("AC公共轨道被C车占用\n");
		        fprintf(f1,"AC公共轨道被C车占用\n");
		    }
		    else
		    {
		        printf("AC公共轨道空闲\n");
		        fprintf(f1,"AC公共轨道空闲\n"); 	
	     	}
	
			
		printf("\n");	
			
		fclose(f1);
		}
	}




/*控制快车优先按钮的动画*/
void fast()
{		SetActiveEgg(Facility);
	   	ShowEgg(0);
    	SetActiveEgg(Fast);
    //	MoveEgg(635,334);
	   	ShowEgg(1);
}
/*控制人工控制按钮的动画*/
void facility()
{	SetActiveEgg(Fast);
	ShowEgg(0);
	SetActiveEgg(Facility);
//	MoveEgg(635,285);
	ShowEgg(1);
}
