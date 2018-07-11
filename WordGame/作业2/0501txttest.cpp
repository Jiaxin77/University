#include <fstream>
#include <iostream>
#include <string>
#include<string.h> 
#include<stdlib.h>
#include<stdio.h>
#include"logresign.h"
#include"PlayerClass.h"
#include "file.h"
#include "userbox.h" 
#include"WordClass.h"
#include"mytype.h"
using namespace std;



main()
{	int choose=-1;
	int flag=1;  
	int logoFlag=0; 
	Player c[playerNum];
	Admin a[adminNum];
	word w[wordNum];
	int PTotal=0,ATotal=0,WTotal=0;
	int PlayFlag=1;
	int AdminFlag=1;
	PTotal=ReadPlayerFile(c);
	ATotal=ReadAdminFile(a);
	WTotal=ReadWordFile(w);
	ATotal=ReadAdminFile(a);
	int *PTotalptr=&PTotal;
	int *ATotalptr=&ATotal;
	int *WTotalptr=&WTotal;
/*	for(int k=0;k<*WTotalptr;k++)
	{	
		cout<<endl<<w[k].getdata()<<endl<<w[k].getlength()<<endl<<w[k].getUseCount()<<endl<<w[k].getCorrectCount()<<endl;
	}
*/
	while(flag)
	{	
	/*	for(int j=0;j<*PTotalptr;j++)
		{	cout<<endl<<endl<<c[j].getname()<<endl<<c[j].getpassword()<<endl<<c[j].getWStage()<<endl<<c[j].getWPassedNum()<<endl<<c[j].getWExp()<<endl;
	 	} 
	 	for(int y=0;y<*ATotalptr;y++)
	 	{	cout<<endl<<endl<<a[y].getname()<<endl<<a[y].getpassword()<<endl<<a[y].getCCount()<<endl<<a[y].getCStage()<<endl;
		 }*/
		 
		choose=-1; 
		cout<<"请您选择您要进行的操作：\n";
		cout<<"0-退出 1-登录 2-注册 "<<endl;
		cin>>choose;
		if(choose!=0&&choose!=1&&choose!=2||cin.fail()) //防止暴力输入 
		{
		cout<<"您的输入有误"<<endl;
		cin.clear();
		cin.ignore();
		
		}
		else if(choose==0)
		{	flag=0;
			updatePlayerFile(c,*PTotalptr);
			updateAdminFile(a,*ATotalptr);
			updateWordFile(w,*WTotalptr);
		}
		else if(choose==1)
		{	int idFlag=-1;
			while(idFlag!=1&&idFlag!=2||cin.fail()) 
			{
				cout<<"请输入您的身份,1代表玩家，2代表出题人\n";
	 			cin>>idFlag; 
			}
			logoFlag=logo(*PTotalptr,*ATotalptr,c,a,idFlag);
			if(logoFlag!=-1)
				{	 flag=0;
					 PlayFlag=1;
					 AdminFlag=1;
					if(idFlag==1)
					{	cout<<"游戏主页"<<endl; 
						PlayFlag=PlayerBox(logoFlag,*PTotalptr,*ATotalptr,*WTotalptr,a,c,w);
						if(PlayFlag==0)
						{flag=1;	}//int型 
					}
					else if(idFlag==2)
					{
						cout<<"出题人主页"<<endl;
						AdminFlag=AdminBox(logoFlag,*PTotalptr,*ATotalptr,WTotalptr,a,c,w); 
						if(AdminFlag==0)
						{	flag=1;
						}
					}
					
				}
			
		}
		else if(choose==2)
		{	int idFlag=-1;
			while(idFlag!=1&&idFlag!=2||cin.fail())
			{
				cout<<"请输入您的身份,1代表玩家，2代表出题人\n";
	 			cin>>idFlag; 
	 		}
			regist(c,a,ATotalptr,PTotalptr,idFlag);
		 } 
	}
	system("pause");
	return 0;
}
