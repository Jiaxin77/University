 #include<iostream>
 #include"PlayerClass.h"
 #include"mytype.h"
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
 
 
 void Admin::AddWord(word *w,int *WTotal)
 {
 	system("cls");
 	if(*WTotal+1>=wordNum)//单词总数上限
	 {
		 cout<<"无法录入，词库已达上限！\n"; 
	 }
	else
	{
		string newword;
 		int okFlag=1;
 		int Flag=0;
		 int CINFLAG;
 		while(Flag==0)
 		{	okFlag=1;
 			CINFLAG=0;
 			while(CINFLAG==0)
 			{
			 
		 		cout<<"请您输入要添加的单词"<<endl;
 				cin>>newword;
 				if(cin.fail())
				 {	cout<<"您的输入不符合要求"<<endl;
				 	CINFLAG=0;
				  }
				else
				{
					CINFLAG=1;
				}
 			}
 			for(int i=0;i<*WTotal&&okFlag==1;i++)
 			{
 				if(newword.compare(w[i].getdata())==0)
 				{	cout<<"您输入的单词已在库中，请重新输入！"<<endl;
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
		while(CINFLAG==0)
		{
		
			cout<<"请您输入单词长度:"<<endl;
			cin>>length;
			if(cin.fail())
			{	
				cout<<"您的输入不符合要求！\n";
				CINFLAG=0;
			}
			else
			{
				CINFLAG=1;
			}
		}
		w[*WTotal].setlength(length);
	
		(*WTotal)++;
		
		cout<<"您已成功录入！"<<endl;
		CCount++;//出题人出题数加一 
		changeCStage();
	}
	


 }
 
 void Admin::changeCStage()
 {
 	CStage=CCount/5+1;
 	
 }
 
