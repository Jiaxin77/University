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
 		int WStage;//�ȼ�
		int WPassedNum;//��Ϸ����
		int WExp; 
	//	int Wrank;//���� ??
		
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
 		int CStage;//�ȼ�
		int CCount;//������Ŀ 
		
	public:
		int getCStage();
		int getCCount();
		void setCStage(int Stage);
		void setCCount(int count);
		Admin();
		~Admin(){}; 
				
 };
 
 

