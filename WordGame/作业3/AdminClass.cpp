#include<iostream>
#include"PlayerClass.h"
#include"mytype.h"
 
#include <winsock2.h> 
#pragma comment(lib,"ws2_32.lib")  
#include"Recsend.h"
#include<sstream>
 
 using namespace std;
 
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
 
 
 void Admin::AddWord(SOCKET sc,word *w,int *WTotal)
 {
 	
 	 stringstream sout;
	  
 //	system("cls");
 	if(*WTotal+1>=wordNum)//单词总数上限
	 {	sout.str(""); 
	  	sout<<"无法录入，词库已达上限！\n"; 
	  	SEND(sc,sout.str().c_str());
		
	 }
	else
	{
		string newword;
 		int okFlag=1;
 		int Flag=0;
		 int CINFLAG;
 		while(Flag==0)
 		{	okFlag=1;
 			
			 	sout.str(""); 
	  			sout<<"请您输入要添加的单词"<<endl;
	  			SEND(sc,sout.str().c_str());
		 		SEND(sc,"END");
 			//	cin>>newword;
 				newword=RECV(sc); 
 			
 			for(int i=0;i<*WTotal&&okFlag==1;i++)
 			{
 				if(newword.compare(w[i].getdata())==0)
 				{	
				 sout.str(""); 
	  			 sout<<"您输入的单词已在库中，请重新输入！"<<endl;
	  			 SEND(sc,sout.str().c_str());
				 //	cout<<
 				 okFlag=0;
				 }	
			}
			if(okFlag==1)
			{
				Flag=1;
			}

		}
		w[*WTotal].setdata(newword);
		CINFLAG=0;
		int length;
		string lengthstr;
	
			sout.str(""); 
	  		sout<<"请您输入单词长度:"<<endl;
	  		SEND(sc,sout.str().c_str());
			SEND(sc,"END");
			lengthstr=RECV(sc);
			length=atoi(lengthstr.c_str());
			
	
		w[*WTotal].setlength(length);
	
		(*WTotal)++;
		
		
		sout.str(""); 
	  	sout<<"您已成功录入！"<<endl;
	  	SEND(sc,sout.str().c_str());
	//	cout<<"您已成功录入！"<<endl;
		CCount++;//出题人出题数加一 
		changeCStage();
	}
	


 }
 
 void Admin::changeCStage()
 {
 	CStage=CCount/5+1;
 	
 }
 
