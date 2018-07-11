#ifndef VARIBLE_H
#define VARIBLE_H
#include<time.h>
#include"egg.h"
struct Train
{ double speed;
  double location;
  double startLoc;
int startTime;
int state;//状态 暂停或行驶
int Circle;//顺逆时针
int control;
};


struct Train A,B,C;


struct Track
{ int  lenth;
  int  wide;
int inPoint;
int outPoint; 
};

struct Track a;
struct Track b;
struct Track c;
extern int FFLAG;
extern int FFFLAG,FFFFLAG;
extern int Or,ML;
extern  HEGG main_picture;
extern	HEGG MOREN,SHURU;
extern  HEGG Fast,Facility;
extern	HEGG aLeft,aRight,aUp,aDown;
extern	HEGG bLeft,bRight,bUp,bDown;
extern	HEGG cLeft,cRight,cUp,cDown;
extern  HEGG wel,Time,ASstay,BSstay,CSstay;	
extern  HEGG LightA1,LightA2,LightA3,LightA4,LightA5,LightA6,LightA7,LightA8;
extern  HEGG LightB1,LightB2,LightB3,LightB4;
extern  HEGG LightC1,LightC2,LightC3,LightC4;	
extern  HEGG InputPicture;
extern int speed_OK;
extern int sleephaha;
extern int priority_control;
extern int AB_control;
extern int AC_control;
extern int Light_control_AC;
extern int Light_control_AB;
extern int Light_control_CA;
extern int Light_control_BA;
extern int StayTime;//停靠时间 
extern int flag1;//优先权用于判断AB车 
extern int flag2;//优先权用于判断AC车 
extern int countA,countB,countC;
extern int FlagFast;

extern char Astay[10];
extern char Bstay[10];
extern char Cstay[10];

extern double Adx,Ady,Bdx,Bdy,Cdx,Cdy;

extern clock_t start, finish;
extern clock_t AStayStart,BStayStart,CStayStart,AStayFinish,BStayFinish,CStayFinish;
extern int AStay,BStay,CStay; 

extern int FLAG;
extern int AB,AC;
extern int count;
extern int Light1loc;//灯的位置 
extern int Light2loc;
extern int Light3loc;
extern int Light4loc;
extern int Light5loc;
extern int Light6loc;
extern int Light7loc;
extern int Light8loc;
extern int Light1State,Light2State,Light3State,Light4State,Light5State,Light6State,Light7State,Light8State;
#endif
