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
//Ԥ���� ����ͷ�ļ� 

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
	EggStart(710,425);//����ͼ�λ����� 
	
	/*��ʾ���û�����ʾ */	
	printf("��ӭʹ��С�𳵵���ϵͳ(���)!\n12GС��ף����;���~\n\n");
	printf("�������λ��Ϊ:A���10-16������B���5-11����,A���18-26������C���12-20���֡�\n\n");
	printf("���й����У�\n����A��ֹͣ-������ A\n����A����������-������a\n����B��ֹͣ-������B\n����B����������-������b\n����C��ֹͣ-������C\n����C����������-������c\n");
	printf("\n�������ݽ����������ĵȴ�3s��������\n");
	printf("�������ݾ�Ϊ����,��Գ���Ա�Ѻ�:)   ����С��ֻ�ϵ�һλ�����ޣ�\n\n");
	printf("С��Ĭ�����ݣ�\nA.speed=4\tB.speed=2\tC.speed=2\nA.StartLoc=0\tB.StartLoc=0\tC.StartLoc=0\nA.StartTime=0\tB.StartTime=0\tC.StartTime=0\nA.Circle=1\tB.Circle=0\tB.Circle=0\nStayTime=0\n\n");
	printf("̽���λ��Ĭ����ÿ�ι����������\n\n");	
	
	/*��ʼǰ�Ľ��� */
	wel=LayEgg(); 
	DrawBitmap("Welcome.bmp");	
	while(FFLAG==0)//���ӿ��أ����û�������򲻽���ʣ����� 
	{
	if(WaitForEvent() == KEYDOWN)
        {
    	    if(GetStruckKey() == VK_LBUTTON) 
    	    	{	double  X = GetMouseX();
                	double  Y = GetMouseY();
                	if( (X >= 490 && X <= 630) && (Y >= 70 && Y <= 140) )//����Start,���г��� 
                
                    {SetActiveEgg(wel);
					ShowEgg(0);
					FFLAG=1;
					}
				
				}
		}
	}
	
	/*�û�ѡ���Ƿ����Ĭ��ֵ�Ľ��� */
	MOREN=LayEgg();
	DrawBitmap("����Ĭ��.bmp");
	while(FFFLAG==0)
	{	if(WaitForEvent()==KEYDOWN)
			{
				if(GetStruckKey() == VK_LBUTTON)
    	    	{	double  X = GetMouseX();
                	double  Y = GetMouseY();
                	if( (X >= 453.3 && X <= 510) && (Y >= 39.7 && Y <= 85) )//Ҫʹ��Ĭ��ֵ 
                	{	Or=1;
                		FFFLAG=1;
                			SetActiveEgg(MOREN);
							ShowEgg(0);
					}
					if((X >= 566.6 && X <= 634.7) && (Y >= 39.7 && Y <= 85))//��ʹ��Ĭ��ֵ 
                	{	    Or=0;
                		    FFFLAG=1;
                			SetActiveEgg(MOREN);
							ShowEgg(0);
					}
				}
			}
	}
	
	/*�û�ѡ�������뷽ʽ�Ľ��� */	
	SHURU=LayEgg();
	DrawBitmap("���뷽ʽ.bmp");
	/*������Ĭ��ֵ������£�ѡ�����뷽ʽ */	
    if(Or==0)
    {
	while(FFFFLAG==0)
	{	if(WaitForEvent()==KEYDOWN)
			{
				if(GetStruckKey() == VK_LBUTTON)
    	    	{	double  X = GetMouseX();
                	double  Y = GetMouseY();
                	if( (X >=141.6 && X <= 323) && (Y >= 85 && Y <= 141.6) )//���������� 
                	{	ML=1;
                		FFFFLAG=1;
                		SetActiveEgg(SHURU);
						ShowEgg(0);
					}
					if((X >= 368.3 && X <= 554.6) && (Y >= 85 && Y <= 141.6))//ͼ�λ����� 
                	{	ML=0;
                		FFFFLAG=1;
                		SetActiveEgg(SHURU);
						ShowEgg(0);
					}
				}
			}
	}
	if(ML==1)//���������� 
	{
		
   		getTrain();//�����û��������ݺ��� 
    
	}
	if(ML==0)//ͼ�λ����� 
	{   
	
	     Inputpicture();

	} 
	
}
    /*����Ĭ��ֵ����� */	
	if(Or==1)
	{	
	    SetActiveEgg(SHURU);
		ShowEgg(0);
		OriginalTrain();
	}
	
	 /*����С�����е������� */
    main_picture=LayEgg();
  	DrawBitmap("Track01.bmp");  
    
	 /*��ʼ��̽��� */    
	LightA7=LayEgg();
	MoveEgg(328.28, 316.96); 
	DrawBitmap("���1.bmp"); 
	LightA8=LayEgg();
	MoveEgg(328.28, 316.96); 
	DrawBitmap("�̵�1.bmp"); 
	ShowEgg(0);
	
	LightA5=LayEgg();
	MoveEgg(328.28, 232); 
	DrawBitmap("���1.bmp"); 
	LightA6=LayEgg();
	MoveEgg(328.28, 232); 
	DrawBitmap("�̵�1.bmp"); 
	ShowEgg(0);	
	
	LightA3=LayEgg();
	MoveEgg(232, 232); 
	DrawBitmap("���1.bmp"); 
	LightA4=LayEgg();
	MoveEgg(232, 232); 
	DrawBitmap("�̵�1.bmp"); 
	ShowEgg(0);	
	
	LightA1=LayEgg();
	MoveEgg(113.2, 232); 
	DrawBitmap("���1.bmp"); 
	LightA2=LayEgg();
	MoveEgg(113.2, 232); 
	DrawBitmap("�̵�1.bmp"); 
	ShowEgg(0);
	
	LightC1=LayEgg();
	MoveEgg(113.2, 169.8); 
	DrawBitmap("���1.bmp"); 
	LightC2=LayEgg();
	MoveEgg(113.2, 169.8); 
	DrawBitmap("�̵�1.bmp"); 
	ShowEgg(0);	
		
	LightC3=LayEgg();
	MoveEgg(232, 169.8); 
	DrawBitmap("���1.bmp"); 
	LightC4=LayEgg();
	MoveEgg(232, 169.8); 
	DrawBitmap("�̵�1.bmp"); 
	ShowEgg(0);
	
	LightB1=LayEgg();
	MoveEgg(380.2, 316.9); 
	DrawBitmap("���1.bmp"); 
	LightB2=LayEgg();
	MoveEgg(380.2, 316.9); 
	DrawBitmap("�̵�1.bmp"); 
	ShowEgg(0);
		
	LightB3=LayEgg();
	MoveEgg(380.2, 232); 
	DrawBitmap("���1.bmp"); 
	LightB4=LayEgg();
	MoveEgg(380.2, 232); 
	DrawBitmap("�̵�1.bmp"); 
	ShowEgg(0);		


    OriginalTrack();//��ʼ��������� 
   
     /*��������С�����еĻ��� */  
     /*A�� */ 
    aLeft=LayEgg();
        MoveEgg(0,0);
		DrawBitmap("TrainAleft_����.bmp");
	aRight=LayEgg();
	    MoveEgg(0,0);
		DrawBitmap("TrainAright_����.bmp");
	aUp=LayEgg();
	    MoveEgg(0,0);
	    DrawBitmap("TrainAup_����.bmp");
	aDown=LayEgg();
	    MoveEgg(0,0);
		DrawBitmap("TrainAdown_����.bmp"); 	
	/*B�� */ 
	bLeft=LayEgg();
	    MoveEgg(0,0);
		DrawBitmap("TrainBleft_����.bmp");
	bRight=LayEgg();
	    MoveEgg(0,0);
		DrawBitmap("TrainBright_����.bmp");
	bUp=LayEgg();
	    MoveEgg(0,0);
	    DrawBitmap("TrainBup_����.bmp");
	bDown=LayEgg();
	    MoveEgg(0,0);
		DrawBitmap("TrainBdown_����.bmp");	
	/*C�� */ 	
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
	
	/*�������Ȳ��Եİ�ťЧ�� */ 	
	Fast=LayEgg();
		MoveEgg(635,334);
		DrawBitmap("�쳵����.bmp"); 
		ShowEgg(0);
	Facility=LayEgg(); 
	    MoveEgg(635,285);
	    DrawBitmap("�˹�����.bmp");
	    ShowEgg(0);

    /*������ʾʱ��ĵ� */
	Time=LayEgg();//С������ʱ�� 
	ASstay=LayEgg();//A��ͣ��ʱ�� 
	BSstay=LayEgg();//B��ͣ��ʱ�� 
	CSstay=LayEgg();//C��ͣ��ʱ�� 
	
	/*��ʼ���û��Ի𳵿��ƵĿ��� */
    A.control=0;
    B.control=0;
    C.control=0;
    
    /*���Ƴ������е��߳� */
	HANDLE hThreadI,hThreadO,hyouxiancelue,haahahah,hThreadABC,hThreadAB,hThreadAC;
	hThreadABC=CreateThread(NULL,0,TrainABC,NULL,0,NULL);
	hThreadO=CreateThread(NULL,0,OUTPUT,NULL,0,NULL);//���ƻ�����״̬�����м��ļ�������߳�
    hThreadI=CreateThread(NULL,0,Input,NULL,0,NULL);//�����п���С�𳵿�ʼ����ͣ���߳� 
    hyouxiancelue=CreateThread(NULL,0,tuxinghuakongzhi,NULL,0,NULL);//ͼ�λ������Ͽ���С�𳵵��߳� 
    haahahah=CreateThread(NULL,0,Train_Picture,NULL,0,NULL);//С�ﳵͼ�λ����
    hThreadAB=CreateThread(NULL,0,WaitForSelectAB,NULL,0,NULL);
    hThreadAC=CreateThread(NULL,0,waitForSelectAC,NULL,0,NULL);
    CloseHandle(TrainABC);
	CloseHandle(OUTPUT);
	CloseHandle(Input);
	CloseHandle(tuxinghuakongzhi);
	CloseHandle(Train_Picture);
	CloseHandle(WaitForSelectAB);
	CloseHandle(waitForSelectAC);
	start=clock();//ʱ��Ƭ����ʼ 
	Sleep(5000000);   		
}





















