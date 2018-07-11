#include"AllClass.h"

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
	WPassedNum=1;//游戏关数
	WExp=0;//排名 ??
		
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
 
 Admin::Admin()
 {		name="\0";
		password="\0";
		CStage=1;//等级
		CCount=0;
 }
 
 int Admin::getCCount()
 {
 	return CCount;
 }
 
 int Admin::getCStage()
 {
 	return CStage;
 }
 
 void Admin::setCCount(int count)
 {
 	CCount=count;
 }
 
 void Admin::setCStage(int stage)
 {
 	CStage=stage;
 }
 
 
 
 /*****游戏界面****/

int Player::PlayerBox(const int PTotal,const int ATotal,Admin *a,Player *c)
{		int ChooseFlag=-1;


		cout<<"欢迎"<<name<<endl;
		cout<<"您的身份是玩家，请选择您要进行的操作";
		cout<<"1-进入游戏，2-查询闯关者，3-查询出题者，4-查看闯关者排名，5-查看出题者排名,6-返回"<<endl;
		cin>>ChooseFlag; 
		if(ChooseFlag==6)
		{	return 0;//返回 
		 } 
		 else if(ChooseFlag==1)
		 {	
		 	//GameBox();//游戏函数，也在该类中 ，把词组类数组传进去 
		 }
		 else if(ChooseFlag==2)
		 {	//SearchPlayer(Player *c,const int PTotal);
		  } 
		 else if(ChooseFlag==3)
		 {	//SearchAdmin(Admin *a,const int ATotal);
		 }
		 else if(ChooseFlag==4)
		 {	//RankPlayer(Player *c,const int PTotal);
		 }
		 else if(ChooseFlag==5)
		 {	//RankAdmin(Admin *a,const int ATotal);
		 }
		 
}
 
 
 
 
 
