#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"egg.h"

struct Train
{ double speed;//���� 
  double location;//λ�� 
  double startLoc;//��ʼλ�� 
int startTime;//��ʼʱ�� 
int state;//״̬ ��ͣ����ʻ
int Circle;//˳��ʱ��
int control;//�û����� 
};//����ṹTrain 

struct Train A,B,C;

struct Track
{ int  lenth;
  int  wide;
int inPoint;
int outPoint; 
};//����ṹ ��� 



struct Track a,b,c;
int sleephaha=0;
int speed_OK=0;
int priority_control=0;
int AB_control=0;
int AC_control=0;
int Light_control_AC=0;
int Light_control_AB=0;
int Light_control_CA=0;
int Light_control_BA=0;
int StayTime;//ͣ��ʱ�� 
int flag1=0;//����Ȩ�����ж�AB�� 
int flag2=0;//����Ȩ�����ж�AC�� 
int count;
int FFLAG=0,FFFLAG=0,FFFFLAG=0;
int Or=0,ML=0;
    HEGG main_picture;
	HEGG Fast,Facility;
	HEGG MOREN,SHURU;
	HEGG aLeft,aRight,aUp,aDown;
	HEGG bLeft,bRight,bUp,bDown;
	HEGG cLeft,cRight,cUp,cDown;
	HEGG wel,Time,ASstay,BSstay,CSstay;
    HEGG LightA1,LightA2,LightA3,LightA4,LightA5,LightA6,LightA7,LightA8;
    HEGG LightB1,LightB2,LightB3,LightB4;
    HEGG LightC1,LightC2,LightC3,LightC4;
    HEGG InputPicture;
clock_t start, finish;

int FlagFast=1;
char Astay[10]={0};
char Bstay[10]={0};
char Cstay[10]={0};

clock_t AStayStart,BStayStart,CStayStart,AStayFinish,BStayFinish,CStayFinish;
int AStay,BStay,CStay;
int countA=0,countB=0,countC=0;
int AB=0,AC=0;

double Adx,Ady,Bdx,Bdy,Cdx,Cdy;
//�涨̽���λ�� 
int FLAG=0;//B.Cͬ�ٶ�ʱ���Ȳ��Ե�ʹ�� 
int Light1loc=50;
int Light2loc=75;
int Light3loc=90;
int Light4loc=125;
int Light5loc=25;
int Light6loc=50;
int Light7loc=60;
int Light8loc=95;
int Light1State,Light2State,Light3State,Light4State,Light5State,Light6State,Light7State,Light8State;
