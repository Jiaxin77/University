#pragma once
#include<iostream>
#include"PlayerClass.h"
#include"WordClass.h"
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
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
		
		void GameBox(word *w,const int WTotal); 
		void changeStage(); 
		
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
				
		void AddWord(word *w,int *WTotal);	
		void changeCStage();	
				
 };
 
 

