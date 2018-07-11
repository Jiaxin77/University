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
//预处理 包含头文件 

DWORD WINAPI Input(LPVOID lpParameter);
DWORD WINAPI OUTPUT(LPVOID lpParameter);
DWORD WINAPI tuxinghuakongzhi(LPVOID lpParameter);
DWORD WINAPI Train_Picture(LPVOID IpParameter);
DWORD WINAPI TrainABC(LPVOID IpParameter);
DWORD WINAPI WaitForSelectAB(LPVOID IpParameter);
DWORD WINAPI waitForSelectAC(LPVOID IpParameter);
void DrawRectangle(double x1, double y1, double x2, double y2); 

main()
{
	EggStart(710,425);//创建图形化界面 
	
	/*显示对用户的提示 */	
	printf("欢迎使用小火车调度系统(☆▽☆)!\n12G小组祝您旅途愉快~\n\n");
	printf("公共轨道位置为:A轨道10-16部分与B轨道5-11部分,A轨道18-26部分与C轨道12-20部分。\n\n");
	printf("运行过程中：\n如需A车停止-请输入 A\n如需A车继续运行-请输入a\n如需B车停止-请输入B\n如需B车继续运行-请输入b\n如需C车停止-请输入C\n如需C车继续运行-请输入c\n");
	printf("\n输入数据结束后，请耐心等待3s输出结果！\n");
	printf("所输数据均为整数,请对程序员友好:)   否则小火车只认第一位数字噢！\n\n");
	printf("小火车默认数据：\nA.speed=4\tB.speed=2\tC.speed=2\nA.StartLoc=0\tB.StartLoc=0\tC.StartLoc=0\nA.StartTime=0\tB.StartTime=0\tC.StartTime=0\nA.Circle=1\tB.Circle=0\tB.Circle=0\nStayTime=0\n\n");
	printf("探测灯位置默认在每段公共轨道两端\n\n");	
	
	/*开始前的界面 */
	wel=LayEgg(); 
	DrawBitmap("Welcome.bmp");	
	while(FFLAG==0)//增加开关，若用户不点击则不进入剩余程序 
	{
	if(WaitForEvent() == KEYDOWN)
        {
    	    if(GetStruckKey() == VK_LBUTTON) 
    	    	{	double  X = GetMouseX();
                	double  Y = GetMouseY();
                	if( (X >= 490 && X <= 630) && (Y >= 70 && Y <= 140) )//按下Start,运行程序。 
                
                    {SetActiveEgg(wel);
					ShowEgg(0);
					FFLAG=1;
					}
				
				}
		}
	}
	
	/*用户选择是否采用默认值的界面 */
	MOREN=LayEgg();
	DrawBitmap("输入默认.bmp");
	while(FFFLAG==0)
	{	if(WaitForEvent()==KEYDOWN)
			{
				if(GetStruckKey() == VK_LBUTTON)
    	    	{	double  X = GetMouseX();
                	double  Y = GetMouseY();
                	if( (X >= 453.3 && X <= 510) && (Y >= 39.7 && Y <= 85) )//要使用默认值 
                	{	Or=1;
                		FFFLAG=1;
                			SetActiveEgg(MOREN);
							ShowEgg(0);
					}
					if((X >= 566.6 && X <= 634.7) && (Y >= 39.7 && Y <= 85))//不使用默认值 
                	{	    Or=0;
                		    FFFLAG=1;
                			SetActiveEgg(MOREN);
							ShowEgg(0);
					}
				}
			}
	}
	
	/*用户选择是输入方式的界面 */	
	SHURU=LayEgg();
	DrawBitmap("输入方式.bmp");
	/*不采用默认值的情况下，选择输入方式 */	
    if(Or==0)
    {
	while(FFFFLAG==0)
	{	if(WaitForEvent()==KEYDOWN)
			{
				if(GetStruckKey() == VK_LBUTTON)
    	    	{	double  X = GetMouseX();
                	double  Y = GetMouseY();
                	if( (X >=141.6 && X <= 323) && (Y >= 85 && Y <= 141.6) )//命令行输入 
                	{	ML=1;
                		FFFFLAG=1;
                		SetActiveEgg(SHURU);
						ShowEgg(0);
					}
					if((X >= 368.3 && X <= 554.6) && (Y >= 85 && Y <= 141.6))//图形化输入 
                	{	ML=0;
                		FFFFLAG=1;
                		SetActiveEgg(SHURU);
						ShowEgg(0);
					}
				}
			}
	}
	if(ML==1)//命令行输入 
	{
		
   		getTrain();//调用用户输入数据函数 
    
	}
	if(ML==0)//图形化输入 
	{   
	
	     Inputpicture();

	} 
	
}
    /*采用默认值的情况 */	
	if(Or==1)
	{	
	    SetActiveEgg(SHURU);
		ShowEgg(0);
		OriginalTrain();
	}
	
	 /*创建小火车运行的主界面 */
    main_picture=LayEgg();
  	DrawBitmap("Track01.bmp");  
    
	 /*初始化探测灯 */    
	LightA7=LayEgg();
	MoveEgg(328.28, 316.96); 
	DrawBitmap("红灯1.bmp"); 
	LightA8=LayEgg();
	MoveEgg(328.28, 316.96); 
	DrawBitmap("绿灯1.bmp"); 
	ShowEgg(0);
	
	LightA5=LayEgg();
	MoveEgg(328.28, 232); 
	DrawBitmap("红灯1.bmp"); 
	LightA6=LayEgg();
	MoveEgg(328.28, 232); 
	DrawBitmap("绿灯1.bmp"); 
	ShowEgg(0);	
	
	LightA3=LayEgg();
	MoveEgg(232, 232); 
	DrawBitmap("红灯1.bmp"); 
	LightA4=LayEgg();
	MoveEgg(232, 232); 
	DrawBitmap("绿灯1.bmp"); 
	ShowEgg(0);	
	
	LightA1=LayEgg();
	MoveEgg(113.2, 232); 
	DrawBitmap("红灯1.bmp"); 
	LightA2=LayEgg();
	MoveEgg(113.2, 232); 
	DrawBitmap("绿灯1.bmp"); 
	ShowEgg(0);
	
	LightC1=LayEgg();
	MoveEgg(113.2, 169.8); 
	DrawBitmap("红灯1.bmp"); 
	LightC2=LayEgg();
	MoveEgg(113.2, 169.8); 
	DrawBitmap("绿灯1.bmp"); 
	ShowEgg(0);	
		
	LightC3=LayEgg();
	MoveEgg(232, 169.8); 
	DrawBitmap("红灯1.bmp"); 
	LightC4=LayEgg();
	MoveEgg(232, 169.8); 
	DrawBitmap("绿灯1.bmp"); 
	ShowEgg(0);
	
	LightB1=LayEgg();
	MoveEgg(380.2, 316.9); 
	DrawBitmap("红灯1.bmp"); 
	LightB2=LayEgg();
	MoveEgg(380.2, 316.9); 
	DrawBitmap("绿灯1.bmp"); 
	ShowEgg(0);
		
	LightB3=LayEgg();
	MoveEgg(380.2, 232); 
	DrawBitmap("红灯1.bmp"); 
	LightB4=LayEgg();
	MoveEgg(380.2, 232); 
	DrawBitmap("绿灯1.bmp"); 
	ShowEgg(0);		


    OriginalTrack();//初始化轨道数据 
   
     /*创建控制小火车运行的画布 */  
     /*A火车 */ 
    aLeft=LayEgg();
        MoveEgg(0,0);
		DrawBitmap("TrainAleft_副本.bmp");
	aRight=LayEgg();
	    MoveEgg(0,0);
		DrawBitmap("TrainAright_副本.bmp");
	aUp=LayEgg();
	    MoveEgg(0,0);
	    DrawBitmap("TrainAup_副本.bmp");
	aDown=LayEgg();
	    MoveEgg(0,0);
		DrawBitmap("TrainAdown_副本.bmp"); 	
	/*B火车 */ 
	bLeft=LayEgg();
	    MoveEgg(0,0);
		DrawBitmap("TrainBleft_副本.bmp");
	bRight=LayEgg();
	    MoveEgg(0,0);
		DrawBitmap("TrainBright_副本.bmp");
	bUp=LayEgg();
	    MoveEgg(0,0);
	    DrawBitmap("TrainBup_副本.bmp");
	bDown=LayEgg();
	    MoveEgg(0,0);
		DrawBitmap("TrainBdown_副本.bmp");	
	/*C火车 */ 	
	cLeft=LayEgg();
	    MoveEgg(0,0);
		DrawBitmap("TrainCleft.bmp");	
	cRight=LayEgg();
	    MoveEgg(0,0);
		DrawBitmap("TrainCright.bmp");		
	cUp=LayEgg();
	    MoveEgg(0,0);
	    DrawBitmap("TrainCup.bmp");
	cDown=LayEgg();
	    MoveEgg(0,0);
		DrawBitmap("TrainCdown.bmp");							    
	
	/*控制优先策略的按钮效果 */ 	
	Fast=LayEgg();
		MoveEgg(635,334);
		DrawBitmap("快车优先.bmp"); 
		ShowEgg(0);
	Facility=LayEgg(); 
	    MoveEgg(635,285);
	    DrawBitmap("人工控制.bmp");
	    ShowEgg(0);

    /*创建显示时间的蛋 */
	Time=LayEgg();//小火车运行时间 
	ASstay=LayEgg();//A火车停靠时间 
	BSstay=LayEgg();//B火车停靠时间 
	CSstay=LayEgg();//C火车停靠时间 
	
	/*初始化用户对火车控制的开关 */
    A.control=0;
    B.control=0;
    C.control=0;
    
    /*控制程序运行的线程 */
	HANDLE hThreadI,hThreadO,hyouxiancelue,haahahah,hThreadABC,hThreadAB,hThreadAC;
	hThreadABC=CreateThread(NULL,0,TrainABC,NULL,0,NULL);
	hThreadO=CreateThread(NULL,0,OUTPUT,NULL,0,NULL);//控制火车运行状态命令行及文件输出的线程
    hThreadI=CreateThread(NULL,0,Input,NULL,0,NULL);//命令行控制小火车开始和暂停的线程 
    hyouxiancelue=CreateThread(NULL,0,tuxinghuakongzhi,NULL,0,NULL);//图形化界面上控制小火车的线程 
    haahahah=CreateThread(NULL,0,Train_Picture,NULL,0,NULL);//小伙车图形化输出
    hThreadAB=CreateThread(NULL,0,WaitForSelectAB,NULL,0,NULL);
    hThreadAC=CreateThread(NULL,0,waitForSelectAC,NULL,0,NULL);
    CloseHandle(TrainABC);
	CloseHandle(OUTPUT);
	CloseHandle(Input);
	CloseHandle(tuxinghuakongzhi);
	CloseHandle(Train_Picture);
	CloseHandle(WaitForSelectAB);
	CloseHandle(waitForSelectAC);
	start=clock();//时间片定起始 
	Sleep(5000000);   		
}





















