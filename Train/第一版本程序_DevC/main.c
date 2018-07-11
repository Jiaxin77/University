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
//预处理 包含头文件 

DWORD WINAPI TrainA(LPVOID lpParameter);
DWORD WINAPI TrainB(LPVOID lpParameter);
DWORD WINAPI TrainC(LPVOID lpParameter);
DWORD WINAPI Input(LPVOID lpParameter);
DWORD WINAPI OUTPUT(LPVOID lpParameter);

main()
{	int k1;//用于判断用户是否输入数据 
    k1= getTrain();//调用用户输入数据函数 
    
    if (k1==0)//如果用户未输入数据，初始化数据 
        OriginalTrain();
    OriginalTrack();//初始化轨道数据 

    A.control=0;//用户控制置为0 
    B.control=0;
    C.control=0;
    
	HANDLE hThreadA,hThreadB,hThreadC,hThreadI,hThreadO;//创建线程 
	hThreadA=CreateThread(NULL,0,TrainA,NULL,0,NULL);
	hThreadB=CreateThread(NULL,0,TrainB,NULL,0,NULL);
	hThreadC=CreateThread(NULL,0,TrainC,NULL,0,NULL);
	hThreadO=CreateThread(NULL,0,OUTPUT,NULL,0,NULL);
    hThreadI=CreateThread(NULL,0,Input,NULL,0,NULL);
    CloseHandle(hThreadA);
    CloseHandle(hThreadB);
    CloseHandle(hThreadC);
	CloseHandle(OUTPUT);
	start=clock();//时间片定起始 

	Sleep(5000000);
    
    
    
   		
}
