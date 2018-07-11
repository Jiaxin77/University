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
	WStage=1;//等级
	WPassedNum=0;//游戏关数
	WExp=0;//经验值 
		
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
 	begin=rand()%WTotal;//随机选起始位置 
 	for(int choose=0;choose<choosecount;choose++)//取一段区域内的 
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
 
 	//每次进入游戏，经验值减少一些，这样重复玩一关的次数越多，经验值会比一次通关的人少
	 if(WExp!=0&&WExp-5>=0)
	 {	WExp=WExp-5;
	  } 
	else{
		WExp=0;
	}
	  
	  cout<<"您即将进入第"<<WPassedNum+1<<"关"<<endl;
	  cout<<"此关共有"<<choosecount<<"单词，每个单词停留时间为"<<timecount/1000<<"秒"<<endl<<endl; 
 	while(playcount<choosecount&&correctflag==0)
 	{	cout<<"第"<<playcount+1<<"单词:"<<endl; 
	 	w[CW[playcount]].setUseCount(w[CW[playcount]].getUseCount()+1);//单词使用次数+1 
 		cout<<"该单词为："<<endl;
 		cout<<w[CW[playcount]].getdata()<<endl;
 		Sleep(timecount);
 		string playerWord;
 		system("cls");
 		int CINFLAG=0;
		while(CINFLAG==0)
		{
		
 		cout<<"请您输入刚才出现的单词"<<endl;
		cin>>playerWord;
		if(cin.fail())
			{	cout<<"您的输入不符合要求!\n";
				CINFLAG=0;	
			}
		else
			{
				CINFLAG=1;
			}
		}
		if(playerWord.compare(w[CW[playcount]].getdata())==0)
		{	correctflag=0;
			cout<<"恭喜您答对了！"<<endl;
			
			w[CW[playcount]].setCorrectCount(w[CW[playcount]].getCorrectCount()+1);//正确次数+1	
		  } 
		else
		{	
			cout<<"很遗憾，本题错误！"<<endl;
			correctflag=1;
		}
		playcount++;	   
	 }
	 if(correctflag==0)
	 {	
	 	cout<<"恭喜您，顺利通关！"<<endl;
		WPassedNum++;//已过关卡数增加
		int exptemp=0; 
		for(int t=0;t<choosecount;t++)
		{	exptemp=exptemp+w[CW[t]].getlength();//按照单词长度加经验值 
		 } 
		 WExp=WExp+exptemp/choosecount+WPassedNum;//加平均长度 和关卡数 
		 
	 }
	 if(correctflag==1)
	 {	
	 	cout<<"很遗憾，闯关失败！"<<endl;
	 }
	 changeStage();
		 cout<<"您当前用户状态为：\n"<<"已过关数："<<WPassedNum<<"\n经验值："<<WExp<<"\n等级："<<WStage<<endl ;
		 
	 
 	
  } 
  
  
  	void Player::changeStage()
	  {		WStage=WExp/10+1;
	   } 
 
 
 
 
