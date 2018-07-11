#ifndef VARIBLE_H
#define VARIBLE_H
#include<time.h>
struct Train
{ int speed;
  int location;
  int startLoc;
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



extern int StayTime;//停靠时间 
extern int flag1;//优先权用于判断AB车 
extern int flag2;//优先权用于判断AC车 

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
