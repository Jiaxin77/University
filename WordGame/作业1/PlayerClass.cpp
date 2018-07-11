#include<iostream>
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
 
 
 
 
