#pragma once
#include<iostream>

using namespace std; 

class user
{	protected:
		string password;
		string name;
	public:
		string getpassword();
		string getname();
		void setpassword(string pw);
		void setname(string na);
		
 } ;
 


  class Player:public user
 {	protected:
 		int WStage;//等级
		int WPassedNum;//游戏关数
		int WExp; 
	//	int Wrank;//排名 ??
		
	public:
		int getWStage();
		int getWPassedNum();
		int getWExp();
		void setWStage(int Stage);
		void setWPassedNum(int PassedNum);
		void setWExp(int exp);
		Player();
		~Player(){};
		
//	PlayerBox(const int PTotal,const int ATotal,Player *c,Admin *a);
				
 };
 
 
 class Admin:public user
 {	protected:
 		int CStage;//等级
		int CCount;//出题数目 
		
	public:
		int getCStage();
		int getCCount();
		void setCStage(int Stage);
		void setCCount(int count);
		Admin();
		~Admin(){}; 
				
 };
 
 

