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
//Ԥ���� ����ͷ�ļ� 

DWORD WINAPI TrainA(LPVOID lpParameter);
DWORD WINAPI TrainB(LPVOID lpParameter);
DWORD WINAPI TrainC(LPVOID lpParameter);
DWORD WINAPI Input(LPVOID lpParameter);
DWORD WINAPI OUTPUT(LPVOID lpParameter);

main()
{	int k1;//�����ж��û��Ƿ��������� 
    k1= getTrain();//�����û��������ݺ��� 
    
    if (k1==0)//����û�δ�������ݣ���ʼ������ 
        OriginalTrain();
    OriginalTrack();//��ʼ��������� 

    A.control=0;//�û�������Ϊ0 
    B.control=0;
    C.control=0;
    
	HANDLE hThreadA,hThreadB,hThreadC,hThreadI,hThreadO;//�����߳� 
	hThreadA=CreateThread(NULL,0,TrainA,NULL,0,NULL);
	hThreadB=CreateThread(NULL,0,TrainB,NULL,0,NULL);
	hThreadC=CreateThread(NULL,0,TrainC,NULL,0,NULL);
	hThreadO=CreateThread(NULL,0,OUTPUT,NULL,0,NULL);
    hThreadI=CreateThread(NULL,0,Input,NULL,0,NULL);
    CloseHandle(hThreadA);
    CloseHandle(hThreadB);
    CloseHandle(hThreadC);
	CloseHandle(OUTPUT);
	start=clock();//ʱ��Ƭ����ʼ 

	Sleep(5000000);
    
    
    
   		
}
