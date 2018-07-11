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
void outputLight()//输出探测灯位置，命令行不用 ，图形化可能使用 
{
	
	
	if(Light1State==01)
	printf("LampA1 is on\n");
	
	if(Light1State==00)
	printf("LampA1 is off\n");
	
	if(Light2State==01)
	printf("LampA2 is on\n");
	
	if(Light2State==00)
	printf("LampA2 is off\n");
	
	if(Light3State==01)
	printf("LampA3 is on\n");
	
	if(Light3State==00)
	printf("LampA3 is off\n");
	
	if(Light4State==01)
	printf("LampA4 is on\n");
	
	if(Light4State==00)
	printf("LampA4 is off\n");
	
	if(Light5State==01)
	printf("LampB1 is on\n");
	
	if(Light5State==00)
	printf("LampB1 is off\n");
	
	if(Light6State==01)
	printf("LampB2 is on\n");
	
	if(Light6State==00)
	printf("LampB2 is off\n");
	
	if(Light7State==01)
	printf("LampC1 is on\n");
	
	if(Light7State==00)
	printf("LampC1 is off\n");
	
	if(Light8State==01)
	printf("LampC2 is on\n");
	
	if(Light8State==00)
	printf("LampC2 is off\n");
 } 


DWORD WINAPI OUTPUT(LPVOID lpParameter)//屏幕输出+文件输出线程 
{
	clock_t start1, finish1;//创建时刻 
	FILE*f1=fopen("模拟火车调度系统.txt","w");
	fclose(f1);
	start1=clock();
	char tra[10]={0}; 
    char run[10]={0};
    while(1)
	{	f1=fopen("模拟火车调度系统.txt","a");//用可添加方式打开文件 
		finish1=clock();
	    count=(finish1-start1)/1000;//输出当前时间 
	   
		if(count%3==0)//每3s输出一次 
		{
		Sleep(1000); 
		printf("当前时间：%d\n",count);//输出当前时间 
		printf("当前策略为快车优先策略\n");
		 
		fprintf(f1,"当前时间：%d\n",count);//输出时间到文件 
		fprintf(f1,"当前策略为快车优先策略\n"); 
		 
		//输出火车A信息 
		if(A.Circle==0)
		printf("A火车顺时针运行\n");
		fprintf(f1,"A火车顺时针运行\n");
		if(A.Circle==1)
		printf("A火车逆时针运行\n"); 
		fprintf(f1,"A火车逆时针运行\n"); 
		
		if(A.state==0&&((A.location>10)&&(A.location<16)||(A.location>18)&&(A.location<26))	)//判断A车状态	   	
		{	if(A.control==1)//判断A暂停的原因 
			{	strcpy(tra,"接受用户命令");
				strcpy(run,"暂停");	
			}
			else
			{
			strcpy(tra,"占用公共轨道");
			strcpy(run,"停靠");
			AStayFinish=clock();//判断A停靠剩余时间 
			AStay=StayTime*1000-(AStayFinish-AStayStart)+100;
			if(count<=A.startTime)
			{	printf("A车等待出发\n");
				fprintf(f1,"A车等待出发\n");
			}
			else
			{
			printf("A车停靠剩余时间：%d毫秒\n",AStay);
			fprintf(f1,"A车停靠剩余时间：%d毫秒\n",AStay);}
			}//输出到文件 
		}	   
		if(A.state==0&&((A.location<=10)||((A.location>=16)&&(A.location<=18))||(A.location>=26)))	//判断A车状态   
		{	if(A.control==1)
			{	strcpy(tra,"接受用户命令");
				strcpy(run,"暂停");	
			}
			else
			{
			strcpy(tra,"等待公共轨道");
			strcpy(run,"暂停");}
		}		  
		if(A.state==1&&(((A.location>10)&&(A.location<16))||((A.location>18)&&(A.location<26))))//判断A车状态 
		{
			strcpy(tra,"公共轨道");
			strcpy(run,"运行");
		}
		if(A.state==1&&(A.location<=10||(A.location>=16)&&(A.location<=18)||A.location>=26))	//判断A车状态	   
		{
   			strcpy(tra,"非公共轨道");
			strcpy(run,"运行");
		}
		printf("A火车运行状态：%s-%s\n",run,tra);//输出A车状态 
		
		printf("A火车当前位置：%d\n",A.location);//输出A车位置 
		fprintf(f1,"A火车运行状态：%s-%s\n",run,tra);//输出A车状态 
		
		fprintf(f1,"A火车当前位置：%d\n",A.location);//输出A车位置 

//输出B车信息 
	    if(B.Circle==0)
		printf("B火车顺时针运行\n");
		fprintf(f1,"B火车顺时针运行\n");
		if(B.Circle==1)
		printf("B火车逆时针运行\n"); 
		fprintf(f1,"B火车逆时针运行\n"); 
		if(B.state==0&&(B.location>5&&B.location<11))	 //判断B车状态  	
		{	if(B.control==1)//判断B车暂停原因 
			{	strcpy(tra,"接受用户命令");
			  	strcpy(run,"暂停");
			}
			else
			{
			strcpy(tra,"占用公共轨道");
			strcpy(run,"停靠");
			BStayFinish=clock();//计算B车停靠剩余时间 
			BStay=StayTime*1000-(BStayFinish-BStayStart)+100;
			if(count<=B.startTime)
			{	printf("B车等待出发\n");
				fprintf(f1,"B车等待出发\n");
			}
			else
			{
			printf("B车停靠剩余时间:%d毫秒\n",BStay);
			fprintf(f1,"B车停靠剩余时间:%d毫秒\n",BStay);}
			} 
		}
    		if(B.state==0&&(B.location<=5||B.location>=11))	//判断B车状态	   	
		{	if(B.control==1)
			{	strcpy(tra,"接受用户命令");
			  	strcpy(run,"暂停");
			}
			else
			{
			strcpy(tra,"等待公共轨道");
			strcpy(run,"暂停");} 
		}	   
    		if(B.state==1&&(B.location>5&&B.location<11))//判断B车状态		   	
		{ 
			strcpy(tra,"公共轨道");
			strcpy(run,"运行");	
			
		}
			if((B.state==1)&&((B.location<=5)||(B.location>=11)))		   	
		{
			strcpy(tra,"非公共轨道");
			strcpy(run,"运行");
		
		}	   	  
 
		printf("B火车运行状态：%s-%s\n",run,tra);
		
		printf("B火车当前位置：%d\n",B.location);
		fprintf(f1,"B火车运行状态：%s-%s\n",run,tra);
		
		fprintf(f1,"B火车当前位置：%d\n",B.location);
//输出C车信息 
		if(C.Circle==0)
		printf("C火车顺时针运行\n");
		fprintf(f1,"C火车顺时针运行\n");
		if(C.Circle==1)
		printf("C火车逆时针运行\n");
		fprintf(f1,"C火车逆时针运行\n"); 
	
	
		if(C.state==0&&(C.location>12&&C.location<20))	   	
		{	if(C.control==1)
			{strcpy(tra,"接受用户命令");
			 strcpy(run,"暂停"); 
			}
			else
			{
			strcpy(tra,"占用公共轨道");
			strcpy(run,"停靠");
			CStayFinish=clock();//计算C车停靠剩余时间 
			CStay=StayTime*1000-(CStayFinish-CStayStart)+100;
			if(count<=C.startTime)
			{	printf("C车等待出发\n");
				fprintf(f1,"C车等待出发\n");
			}
			else{ 
			printf("C车停靠剩余时间:%d毫秒\n",CStay);
			fprintf(f1,"C车停靠剩余时间:%d毫秒\n",CStay);}
			} 
		}
	   if(C.state==0&&(C.location<=12||C.location>=20))		   	
		{
			if(C.control==1)
			{strcpy(tra,"接受用户命令");
			 strcpy(run,"暂停"); 
			}
			else
			{
			strcpy(tra,"等待公共轨道");
			strcpy(run,"暂停");}
		}	   
		if(C.state==1&&(C.location>12&&C.location<20))		   	
		{ 
			strcpy(tra,"公共轨道");
			strcpy(run,"运行");	
	
		}
		if((C.state==1)&&((C.location<=12||C.location>=20)))		   	
		{
			strcpy(tra,"非公共轨道");
			strcpy(run,"运行");
	
		}	   	  
     	
		printf("C火车运行状态：%s-%s\n",run,tra);
		
		printf("C火车当前位置：%d\n",C.location);
		
		fprintf(f1,"C火车运行状态：%s-%s\n",run,tra);
		
		fprintf(f1,"C火车当前位置：%d\n",C.location);

	//输出轨道状态	
		if((A.location>10)&&(A.location<16))
		{
		printf("AB公共轨道被A车占用\n");
		fprintf(f1,"AB公共轨道被A车占用\n");
		} 
		else if((B.location>5)&&(B.location<11))
		{
		printf("AB公共轨道被B车占用\n");
		fprintf(f1,"AB公共轨道被B车占用\n");
		}
		else
		{
		printf("AB公共轨道空闲\n"); 
		fprintf(f1,"AB公共轨道空闲\n"); 
		}
		if((A.location>18)&&(A.location<26))
		{
		printf("AC公共轨道被A车占用\n");
		fprintf(f1,"AC公共轨道被A车占用\n");
		}
		else if((C.location>12)&&(C.location<20))
		{
		printf("AC公共轨道被C车占用\n");
		fprintf(f1,"AC公共轨道被C车占用\n");
		}
		else
		{
		printf("AC公共轨道空闲\n");
		fprintf(f1,"AC公共轨道空闲\n"); 	
		}
		//outputLight();（不要求输出灯状态） 
			
		printf("\n");	
		fprintf(f1,"\n");	
		
	
		finish1=clock();
		count=(finish1-start1)/1000;}
	 fclose(f1);//关闭并储存文件 
		}
		

	}






void printChange()
{	char trac[10]={0}; 
    char runc[10]={0};
   
    
    int count1;
	{	finish=clock();
	    count1=(finish-start)/1000;
	   
	
		printf("当前时间：%d\n",count1);
		printf("当前策略为快车优先策略\n"); 
		
		
		if(A.Circle==0)
		printf("A火车顺时针运行\n");
		if(A.Circle==1)
		printf("A火车逆时针运行\n"); 

		if(A.state==0&&((A.location>10)&&(A.location<16)||(A.location>18)&&(A.location<26))	)	   	
		{	if(A.control==1)
			{	strcpy(trac,"接受用户命令");
				strcpy(runc,"暂停");	
			}
			else
			{
			strcpy(trac,"占用公共轨道");
			strcpy(runc,"停靠");
			AStayFinish=clock();
			AStay=StayTime*1000-(AStayFinish-AStayStart);
			printf("A车停靠剩余时间：%d毫秒\n",AStay);}
		}	   
		if(A.state==0&&((A.location<=10)||((A.location>=16)&&(A.location<=18))||(A.location>=26)))	   
		{	if(A.control==1)
			{	strcpy(trac,"接受用户命令");
				strcpy(runc,"暂停");	
			}
			else
			{
			strcpy(trac,"等待公共轨道");
			strcpy(runc,"暂停");}
		}		  
		if(A.state==1&&(((A.location>10)&&(A.location<16))||((A.location>18)&&(A.location<26))))
		{
			strcpy(trac,"公共轨道");
			strcpy(runc,"运行");
		}
		if(A.state==1&&(A.location<=10||(A.location>=16)&&(A.location<=18)||A.location>=26))		   
		{
   			strcpy(trac,"非公共轨道");
			strcpy(runc,"运行");
		}
		printf("A火车运行状态：%s-%s\n",runc,trac);
		
		printf("A火车当前位置：%d\n",A.location);


	    if(B.Circle==0)
		printf("B火车顺时针运行\n");
		if(B.Circle==1)
		printf("B火车逆时针运行\n"); 

		if(B.state==0&&(B.location>5&&B.location<11))	   	
		{	if(B.control==1)
			{	strcpy(trac,"接受用户命令");
			  	strcpy(runc,"暂停");
			}
			else
			{
			strcpy(trac,"占用公共轨道");
			strcpy(runc,"停靠");
			BStayFinish=clock();
			BStay=StayTime*1000-(BStayFinish-BStayStart);
			printf("B车停靠剩余时间:%d毫秒\n",BStay);}
		}
    		if(B.state==0&&(B.location<=5||B.location>=11))		   	
		{	if(B.control==1)
			{	strcpy(trac,"接受用户命令");
			  	strcpy(runc,"暂停");
			}
			else
			{
			strcpy(trac,"等待公共轨道");
			strcpy(runc,"暂停");} 
		}	   
    		if(B.state==1&&(B.location>5&&B.location<11))		   	
		{ 
			strcpy(trac,"公共轨道");
			strcpy(runc,"运行");	
			
		}
			if((B.state==1)&&((B.location<=5)||(B.location>=11)))		   	
		{
			strcpy(trac,"非公共轨道");
			strcpy(runc,"运行");
	
		}	   	  
 
		printf("B火车运行状态：%s-%s\n",runc,trac);
		
		printf("B火车当前位置：%d\n",B.location);

		if(C.Circle==0)
		printf("C火车顺时针运行\n");
		if(C.Circle==1)
		printf("C火车逆时针运行\n"); 
	
	
		if(C.state==0&&(C.location>12&&C.location<20))	   	
		{	if(C.control==1)
			{strcpy(trac,"接受用户命令");
			 strcpy(runc,"暂停"); 
			}
			else
			{
			strcpy(trac,"占用公共轨道");
			strcpy(runc,"停靠");
			CStayFinish=clock();
			CStay=StayTime*1000-(CStayFinish-CStayStart);
			printf("C车停靠剩余时间:%d毫秒\n",CStay);}
		}
	   if(C.state==0&&(C.location<=12||C.location>=20))		   	
		{
			if(C.control==1)
			{strcpy(trac,"接受用户命令");
			 strcpy(runc,"暂停"); 
			}
			else
			{
			strcpy(trac,"等待公共轨道");
			strcpy(runc,"暂停");}
		}	   
		if(C.state==1&&(C.location>12&&C.location<20))		   	
		{ 
			strcpy(trac,"公共轨道");
			strcpy(runc,"运行");	
	
		}
		if((C.state==1)&&((C.location<=12||C.location>=20)))		   	
		{
			strcpy(trac,"非公共轨道");
			strcpy(runc,"运行");
	
		}	   	  
     	
		printf("C火车运行状态：%s-%s\n",runc,trac);
		
		printf("C火车当前位置：%d\n",C.location);

		
		if((A.location>10)&&(A.location<16))
		printf("AB公共轨道被A车占用\n");
		else if((B.location>5)&&(B.location<11))
		printf("AB公共轨道被B车占用\n");
		else
		printf("AB公共轨道空闲\n"); 

		if((A.location>18)&&(A.location<26))
		printf("AC公共轨道被A车占用\n");
		else if((C.location>12)&&(C.location<20))
		printf("AC公共轨道被C车占用\n");
		else
		printf("AC公共轨道空闲\n");
	
		//outputLight();命令行输出不需要，图形化可能用 
			
		printf("\n");	
			
		
		}
	}















