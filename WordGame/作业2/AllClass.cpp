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
	WStage=1;//�ȼ�
	WPassedNum=1;//��Ϸ����
	WExp=0;//���� ??
		
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
		CStage=1;//�ȼ�
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
 
 
 
 /*****��Ϸ����****/

int Player::PlayerBox(const int PTotal,const int ATotal,Admin *a,Player *c)
{		int ChooseFlag=-1;


		cout<<"��ӭ"<<name<<endl;
		cout<<"�����������ң���ѡ����Ҫ���еĲ���";
		cout<<"1-������Ϸ��2-��ѯ�����ߣ�3-��ѯ�����ߣ�4-�鿴������������5-�鿴����������,6-����"<<endl;
		cin>>ChooseFlag; 
		if(ChooseFlag==6)
		{	return 0;//���� 
		 } 
		 else if(ChooseFlag==1)
		 {	
		 	//GameBox();//��Ϸ������Ҳ�ڸ����� ���Ѵ��������鴫��ȥ 
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
 
 
 
 
 
