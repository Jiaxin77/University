#include<stdio.h>
#include"varible.h"

int getTrain()
{   int r;//用于记录用户是否输入数据 
	int m;//用于判断用户是否输入数字 
	printf("欢迎使用小火车调度系统(☆▽☆)!\n12G小组祝您旅途愉快~\n\n");
	printf("公共轨道位置为:A轨道10-16部分与B轨道5-11部分,A轨道18-26部分与C轨道12-20部分。\n\n");

	printf("运行过程中：\n如需A车停止-请输入 A\n如需A车继续运行-请输入a\n如需B车停止-请输入B\n如需B车继续运行-请输入b\n如需C车停止-请输入C\n如需C车继续运行-请输入c\n");
	printf("\n输入数据结束后，请耐心等待3s输出结果！\n");
	printf("所输数据均为整数,请对程序员友好:)   否则小火车只认第一位数字噢！\n\n");
	printf("小火车默认数据：\nA.speed=4\tB.speed=2\tC.speed=2\nA.StartLoc=0\tB.StartLoc=0\tC.StartLoc=0\nA.StartTime=0\tB.StartTime=0\tC.StartTime=0\nA.Circle=1\tB.Circle=0\tB.Circle=0\nStayTime=0\n\n");
	printf("探测灯位置默认在每段公共轨道两端\n\n"); 

	printf("\n请问是否修改默认值：（是回复1，否回复0）");
	m=0;
 	fflush(stdin);//清空缓存 
	m=scanf("%d",&r);
	while(((r!=1)&&(r!=0))||m==0)
	{	printf("请输入0或1:");
	    fflush(stdin);//清空缓存 
		m=scanf("%d",&r);
	    
	}
	if(r==1)//如果用户要输入数据 

	{	
	printf("[StayTime]（>=0的整数）:");
	fflush(stdin);//清空缓存 
    m=scanf("%d",&StayTime);
    while(StayTime<0||m==0)
    {	printf("时光不能倒流,时间不能为负噢！\n");
		printf("[StayTime]（>=0的整数）:");
		fflush(stdin);
    	m=scanf("%d",&StayTime);
	} 
    
    printf("\n");
    printf("[A Speed](1-5之间整数):");
    fflush(stdin);//清空缓存 
	m=scanf("%d",&A.speed);
	while((A.speed>5)||(A.speed<1)||m==0)
	{		printf("请注意速度范围噢！\n");
			
			printf("[A Speed](1-5之间整数):");
			fflush(stdin);
			m=scanf("%d",&A.speed);	
	}
	
	printf("\n");
	printf("[B Speed](1-5之间整数):");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&B.speed);
	while((B.speed>5)||(B.speed<1)||m==0)
	{		printf("请注意速度范围噢！\n");
			printf("[B Speed](1-5之间整数):");
			fflush(stdin);
			m=scanf("%d",&B.speed);
	}
	
	printf("\n");
	printf("[C Speed](1-7之间整数):");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&C.speed);
	while((C.speed>7)||(C.speed<1)||m==0)
	{		printf("请注意速度范围噢！\n");
			printf("[C Speed](1-7整数):");
			fflush(stdin);
			m=scanf("%d",&C.speed);
	}

	printf("\n");
	printf("[A StartTime] (>=0的整数):");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&A.startTime);
	while(A.startTime<0||m==0)
	{	printf("时光不能倒流,时间不能为负噢！\n");
		printf("[A StartTime] (>=0的整数):");
		fflush(stdin);
		m=scanf("%d",&A.startTime); 
	}

	printf("\n");
	printf("[B StartTime](>=0的整数) :");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&B.startTime);
	while(B.startTime<0||m==0)
	{	printf("时光不能倒流,时间不能为负噢！\n");
		printf("[B StartTime] (>=0的整数):");
		fflush(stdin);
		m=scanf("%d",&B.startTime); 
	}
	printf("\n");
	printf("[C StartTime](>=0的整数):");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&C.startTime);
	while(C.startTime<0||m==0)
	{	printf("时光不能倒流,时间不能为负噢！\n");
		printf("[C StartTime] (>=0的整数):");
		fflush(stdin);
		m=scanf("%d",&C.startTime); 
	}
	printf("\n");
	printf("[A StartPoint](0-29的整数) :");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&A.startLoc);
	while(A.startLoc>29||A.startLoc<0||m==0)
	{	printf("请注意起始点范围噢~\n");
		printf("[A StartPoint](0-29的整数) :");
		fflush(stdin);
		m=scanf("%d",&A.startLoc);
	}
	printf("\n");
	if((A.startLoc>10)&&(A.startLoc<16))
		printf("B起始点不能在5-11,否则两车会打架噢！\n"); 
	printf("[B StartPoint](0-29的整数) :");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&B.startLoc);
	if((A.startLoc>10)&&(A.startLoc<16))
	{	while((B.startLoc>=5&&B.startLoc<=11)||m==0)
			{	printf("两车要打架了！请对程序员友好（微笑）\n");
				printf("[B StartPoint](0-29的整数) :");
				fflush(stdin);
				m=scanf("%d",&B.startLoc);
				
			}
	}
		while(B.startLoc>29||B.startLoc<0||m==0)
	{	printf("请注意起始点范围噢~\n");
		printf("[B StartPoint](0-29的整数) :");
		fflush(stdin);
		m=scanf("%d",&B.startLoc);
	}
	printf("\n");
		if((A.startLoc>18)&&(A.startLoc<26))
		printf("C起始点不能在12-20,否则两车会打架噢！\n");
	printf("[C StartPoint](0-23的整数) :");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&C.startLoc);
	if((A.startLoc>18)&&(A.startLoc<26))
	{	while((C.startLoc>=12&&C.startLoc<=20)||m==0)
			{	printf("两车要打架了！请对程序员友好（微笑）\n");
				printf("[C StartPoint](0-29的整数) :");
				fflush(stdin);
				m=scanf("%d",&C.startLoc);
				
			}
	} 
	while(C.startLoc>23||C.startLoc<0||m==0)
	{	printf("请注意起始点范围噢~\n");
		printf("[C StartPoint](0-23的整数) :");
		fflush(stdin);
		m=scanf("%d",&C.startLoc);
	}
	printf("\n");
	printf("[A Direction](顺时针为0，逆时针为1) :");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&A.Circle);
	while((A.Circle!=1&&A.Circle!=0)||m==0)
	{	printf("只能用1或0表示噢！\n");
		printf("[A Direction](顺时针为0，逆时针为1) :");
		fflush(stdin);
		m=scanf("%d",&A.Circle);
	}
	printf("\n");
	printf("[B Direction](顺时针为0，逆时针为1) :");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&B.Circle);
	while((B.Circle!=1&&B.Circle!=0)||m==0)
	{	printf("只能用1或0表示噢！\n");
		printf("[B Direction](顺时针为0，逆时针为1) :");
		fflush(stdin);
		m=scanf("%d",&B.Circle);
	}
	printf("\n");
	printf("[C Direction](顺时针为0，逆时针为1) :");
	fflush(stdin);//清空缓存 
	m=scanf("%d",&C.Circle);
	while((C.Circle!=1&&C.Circle!=0)||m==0)
	{	printf("只能用1或0表示噢！\n");
		printf("[C Direction](顺时针为0，逆时针为1) :");
		fflush(stdin);
		m=scanf("%d",&C.Circle);
	}
	printf("\n");
	printf("输入完毕，请耐心等待3s!\n");
	//探测点位置默认。 
	return 1;}
	if(r==0)//如果用户不输入数据 
		return 0;
	
}


void OriginalTrain()//初始化火车数据 
{


	StayTime=0;
	
	A.speed=4;
	B.speed=2;
	C.speed=2;

	A.startTime=0;
	B.startTime=0;
	C.startTime=0;
	
	
	A.startLoc=0;
	B.startLoc=0;
	C.startLoc=0;
	
	A.Circle=1;
	B.Circle=0;
	C.Circle=0;

}

void OriginalTrack()//初始化轨道数据 
{
	
	
	a.lenth=10;
	b.lenth=7;
	c.lenth=7;
	a.wide=5;
	b.wide=10;
	c.wide=5;
	
}

