#include<time.h>
struct Train
{ int speed;//���� 
  int location;//λ�� 
  int startLoc;//��ʼλ�� 
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

int StayTime;//ͣ��ʱ�� 
int flag1=0;//����Ȩ�����ж�AB�� 
int flag2=0;//����Ȩ�����ж�AC�� 
int count;

clock_t start, finish;

clock_t AStayStart,BStayStart,CStayStart,AStayFinish,BStayFinish,CStayFinish;
int AStay,BStay,CStay;
int AB=0,AC=0;
//�涨̽���λ�� 
int FLAG=0;//B.Cͬ�ٶ�ʱ���Ȳ��Ե�ʹ�� 
int Light1loc=10;
int Light2loc=15;
int Light3loc=18;
int Light4loc=25;
int Light5loc=5;
int Light6loc=10;
int Light7loc=12;
int Light8loc=19;
int Light1State,Light2State,Light3State,Light4State,Light5State,Light6State,Light7State,Light8State;
