#include<time.h>
struct Train
{ int speed;//车速 
  int location;//位置 
  int startLoc;//起始位置 
int startTime;//起始时间 
int state;//状态 暂停或行驶
int Circle;//顺逆时针
int control;//用户控制 
};//定义结构Train 

struct Train A,B,C;




struct Track
{ int  lenth;
  int  wide;
int inPoint;
int outPoint; 
};//定义结构 轨道 



struct Track a,b,c;

int StayTime;//停靠时间 
int flag1=0;//优先权用于判断AB车 
int flag2=0;//优先权用于判断AC车 
int count;

clock_t start, finish;

clock_t AStayStart,BStayStart,CStayStart,AStayFinish,BStayFinish,CStayFinish;
int AStay,BStay,CStay;
int AB=0,AC=0;
//规定探测灯位置 
int FLAG=0;//B.C同速度时优先策略的使用 
int Light1loc=10;
int Light2loc=15;
int Light3loc=18;
int Light4loc=25;
int Light5loc=5;
int Light6loc=10;
int Light7loc=12;
int Light8loc=19;
int Light1State,Light2State,Light3State,Light4State,Light5State,Light6State,Light7State,Light8State;
