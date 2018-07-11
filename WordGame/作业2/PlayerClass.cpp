#include"PlayerClass.h" 

using namespace std;

void user::setname(string na)
{	
	name=na;
}

void user::setpassword(string pw)
{	
	password=pw;
}

string user::getname() 
{	
	return name;
}

string user::getpassword()
{
	return password;
}


Player::Player()
{	name="\0";
	password="\0";
	WStage=1;//�ȼ�
	WPassedNum=0;//��Ϸ����
	WExp=0;//����ֵ 
		
}
 
 int Player::getWPassedNum()
 {
 	return WPassedNum;
 }
 
 int Player::getWStage()
 {	
 	return WStage;
 }
 
 int Player::getWExp()
 {
 	return WExp;
 }
 
 void Player::setWPassedNum(int PassedNum)
 {
 	WPassedNum=PassedNum;
 }
 
 void Player::setWStage(int Stage)
 {
 	WStage=Stage;
 }

 void Player::setWExp(int exp)
 {
 	WExp=exp;
 }
 

 
 void Player::GameBox(word *w,const int WTotal)
 {
 	
	int choosecount;
	choosecount=(((WPassedNum)/3)+1)*3;
	int timecount;
	if((WPassedNum+1)%3==1)
	{	timecount=3000;//3s 
	}
	else if((WPassedNum+1)%3==2)
	{
		timecount=2000;//2s
	}
	else if((WPassedNum+1)%3==0)
	{
		timecount=1000;//1s 
	}
	int *CW=NULL;
	CW=new int[choosecount];
	
 	int begin=0;
 	srand((unsigned)time(NULL)); 
 	begin=rand()%WTotal;//���ѡ��ʼλ�� 
 	for(int choose=0;choose<choosecount;choose++)//ȡһ�������ڵ� 
	{	
		if(begin+1>WTotal)
		{	begin=1;
		}
		else
		{
			begin=begin+1; 
		} 
		CW[choose]=begin-1;
		
	 } 
 	int playcount=0;
 	int correctflag=0;
 
 	//ÿ�ν�����Ϸ������ֵ����һЩ�������ظ���һ�صĴ���Խ�࣬����ֵ���һ��ͨ�ص�����
	 if(WExp!=0&&WExp-5>=0)
	 {	WExp=WExp-5;
	  } 
	else{
		WExp=0;
	}
	  
	  cout<<"�����������"<<WPassedNum+1<<"��"<<endl;
	  cout<<"�˹ع���"<<choosecount<<"���ʣ�ÿ������ͣ��ʱ��Ϊ"<<timecount/1000<<"��"<<endl<<endl; 
 	while(playcount<choosecount&&correctflag==0)
 	{	cout<<"��"<<playcount+1<<"����:"<<endl; 
	 	w[CW[playcount]].setUseCount(w[CW[playcount]].getUseCount()+1);//����ʹ�ô���+1 
 		cout<<"�õ���Ϊ��"<<endl;
 		cout<<w[CW[playcount]].getdata()<<endl;
 		Sleep(timecount);
 		string playerWord;
 		system("cls");
 		int CINFLAG=0;
		while(CINFLAG==0)
		{
		
 		cout<<"��������ղų��ֵĵ���"<<endl;
		cin>>playerWord;
		if(cin.fail())
			{	cout<<"�������벻����Ҫ��!\n";
				CINFLAG=0;	
			}
		else
			{
				CINFLAG=1;
			}
		}
		if(playerWord.compare(w[CW[playcount]].getdata())==0)
		{	correctflag=0;
			cout<<"��ϲ������ˣ�"<<endl;
			
			w[CW[playcount]].setCorrectCount(w[CW[playcount]].getCorrectCount()+1);//��ȷ����+1	
		  } 
		else
		{	
			cout<<"���ź����������"<<endl;
			correctflag=1;
		}
		playcount++;	   
	 }
	 if(correctflag==0)
	 {	
	 	cout<<"��ϲ����˳��ͨ�أ�"<<endl;
		WPassedNum++;//�ѹ��ؿ�������
		int exptemp=0; 
		for(int t=0;t<choosecount;t++)
		{	exptemp=exptemp+w[CW[t]].getlength();//���յ��ʳ��ȼӾ���ֵ 
		 } 
		 WExp=WExp+exptemp/choosecount+WPassedNum;//��ƽ������ �͹ؿ��� 
		 
	 }
	 if(correctflag==1)
	 {	
	 	cout<<"���ź�������ʧ�ܣ�"<<endl;
	 }
	 changeStage();
		 cout<<"����ǰ�û�״̬Ϊ��\n"<<"�ѹ�������"<<WPassedNum<<"\n����ֵ��"<<WExp<<"\n�ȼ���"<<WStage<<endl ;
		 
	 
 	
  } 
  
  
  	void Player::changeStage()
	  {		WStage=WExp/10+1;
	   } 
 
 
 
 
