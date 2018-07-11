 

#include"userbox.h"

using namespace std;
 /*****游戏界面****/

int PlayerBox(int i,const int PTotal,const int ATotal,const int WTotal,Admin *a,Player *c,word *w)
{		system("cls");
		int ChooseFlag=-1;
	
		int Flag=1;
		cout<<"欢迎"<<c[i].getname()<<endl;
		cout<<"您的身份是玩家，请选择您要进行的操作";
		
		while(Flag==1) 
		{
		cin.clear();
		cin.ignore();
		ChooseFlag=-1;
		cout<<"\n1-进入游戏，2-查询闯关者，3-查询出题者，4-查看闯关者排名，5-查看出题者排名,6-返回"<<endl;
		cin>>ChooseFlag; 
		if(ChooseFlag!=1&&ChooseFlag!=2&&ChooseFlag!=3&&ChooseFlag!=4&&ChooseFlag!=5&&ChooseFlag!=6||cin.fail())
		{
		cout<<"您的输入有误"<<endl;
		cin.clear();
		cin.ignore();
		
		}
			else if(ChooseFlag==6)
			{	Flag=0;//返回 
			 } 
		 	else if(ChooseFlag==1)
			 {	
		 		c[i].GameBox(w,WTotal);//return 1;//GameBox();//游戏函数，也在该类中 ，把词组类数组传进去 
			 }
		 	else if(ChooseFlag==2)
		 	{	SearchPlayer(c,PTotal) ;
		 	 //	return 1;//查询玩家 
		 	 } 
		 	else if(ChooseFlag==3)
			 {	
				SearchAdmin(a,ATotal);
		 	//	return 1;
			 }
		 	else if(ChooseFlag==4)
		 	{	rankPlayer(c,PTotal); 
		 	//	return 1;//RankPlayer(Player *c,const int PTotal);
		 	}
			 else if(ChooseFlag==5)
			 {	rankAdmin(a,ATotal); 
			 //	return 1;//RankAdmin(Admin *a,const int ATotal);
			 }
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////
int AdminBox(int i,const int PTotal,const int ATotal,int *WTotal,Admin *a,Player *c,word *w) 
{		system("cls");
		int ChooseFlag=-1;

		int Flag=1;
		cout<<"欢迎"<<a[i].getname()<<endl;
		cout<<"您的身份是出题人，请选择您要进行的操作";
		
		while(Flag==1) 
		{
		cin.clear();
		cin.ignore();
		ChooseFlag=-1;
		while(ChooseFlag!=1&&ChooseFlag!=2&&ChooseFlag!=3&&ChooseFlag!=4&&ChooseFlag!=5&&ChooseFlag!=6||cin.fail())
		{
			cout<<"\n1-出题，2-查询闯关者，3-查询出题者，4-查看闯关者排名，5-查看出题者排名,6-返回"<<endl;
			cin>>ChooseFlag; 
		}
			if(ChooseFlag==6)
			{	Flag=0;//返回 
			 } 
		 	else if(ChooseFlag==1)
			 {	
		 		 a[i].AddWord(w,WTotal);//return 1;//WordBox();//出题函数，
			 }
		 	else if(ChooseFlag==2)
		 	{	SearchPlayer(c,PTotal) ;
		 	 //	return 1;//查询玩家 
		 	 } 
		 	else if(ChooseFlag==3)
			 {	
				SearchAdmin(a,ATotal);
		 	//	return 1;
			 }
		 	else if(ChooseFlag==4)
		 	{	rankPlayer(c,PTotal); 
		 	//	return 1;//RankPlayer(Player *c,const int PTotal);
		 	}
			 else if(ChooseFlag==5)
			 {	rankAdmin(a,ATotal); 
			 //	return 1;//RankAdmin(Admin *a,const int ATotal);
			 }
	}
	return 0;
}




int SearchPlayer(Player *c,const int PTotal)
{	int SPFlag=-1;
	while(SPFlag!=1&&SPFlag!=2&&SPFlag!=3&&SPFlag!=4||cin.fail())
	{
		cout<<"请选择你要查找的玩家属性：\n1-查找姓名	2-查找已闯关关卡数	3-查找闯关者经验值	4-查找闯关者等级\n";
		cin>>SPFlag;
	}
	int SP[SearchPlayerNum]; //之后const 用于盛放搜索到的玩家数？
	for(int j=0;j<SearchPlayerNum;j++)
	{	SP[j]=-1;
	}
	int count=0;

	if(SPFlag==1)
	{	string name;
		int CINFLAG=0;
		while(CINFLAG==0)
		{ 
			cout<<"请输入您要查找的姓名：\n";
			cin>>name;
			if(cin.fail())
			{	
				cout<<"您的输入不符合要求"<<endl;
				CINFLAG=0;
			 } 
			else
			{
				CINFLAG=1;
			}
		} 
		for(int i=0;i<PTotal;i++)
		{	if(name.compare(c[i].getname())==0)
			{	SP[count]=i;
				count++;
			}
		}
	 } 
	 else if(SPFlag==2)
	 {	int passednum;
	 	int CINFLAG=0;
		while(CINFLAG==0)
		{
		
			cout<<"请输入您想查询的已闯关卡数：\n";
	 		cin>>passednum;
	 		if(cin.fail())
	 		{	cout<<"您的输入不符合要求"<<endl;
			 	CINFLAG=0;
			 }
			 else
			 {
			 	CINFLAG=1;
			 }
		 }
	 	for(int i=0;i<PTotal;i++)
	 	{	if(passednum==c[i].getWPassedNum())
	 			{	SP[count]=i;
	 				count++;
				 }
		 }
	 }
	 else if(SPFlag==3)
	 {	int EXP;
	 	int CINFLAG=0;
	 	while(CINFLAG==0)
	 	{
		 
	 		cout<<"请输入您想查询的经验值：\n";
			cin>>EXP;
			if(cin.fail()) 
			{	
				cout<<"您的输入不符合要求"<<endl;
				CINFLAG=0;
			}
			else
			{
				CINFLAG=1;
			}
		} 
		for(int i=0;i<PTotal;i++)
		{	if(EXP==c[i].getWExp())
			{	SP[count]=i;
				count++;
			}
		 }
	}
	else if(SPFlag==4)
	{	int stage;
		int CINFLAG=0;
		while(CINFLAG==0)
		{
			cout<<"请输入您想查询的闯关者等级：\n";
			cin>>stage;
			if(cin.fail())
			{	
				cout<<"您的输入不符合要求"<<endl;
				CINFLAG=0;
			}
			else
			{
				CINFLAG=1;
			}
		}
		for(int i=0;i<PTotal;i++)
		{	if(stage==c[i].getWStage())
			{	SP[count]=i;
				count++;
			}
		 } 
	}
	cout<<"\n您查询结果如下：\n";
	if(count==0)
	{	cout<<"未查到符合条件的玩家\n";
	 } 
	else
	{
		for(int j=0;j<SearchPlayerNum&&SP[j]!=-1;j++)
		{	cout<<"姓名："<<c[SP[j]].getname()<<endl<<"已闯关卡数"<<c[SP[j]].getWPassedNum()<<endl<<"经验值"<<c[SP[j]].getWExp()<<endl<<"等级"<<c[SP[j]].getWStage()<<endl;	
		}
		cout<<"信息输出完毕\n"; 
		
	}
	
	 
}

int SearchAdmin(Admin *a,const int ATotal)
{
	int SAFlag=-1;
	while(SAFlag!=1&&SAFlag!=2&&SAFlag!=3||cin.fail())
	{
	
		cout<<"请选择你要查找的出题人属性：\n1-查找姓名	2-查找已出题数	3-查找等级\n";
		cin>>SAFlag;
	}
	int SA[SearchAdminNum]; //之后const 用于盛放搜索到的玩家数？
	for(int j=0;j<SearchAdminNum;j++)
	{	SA[j]=-1;
	}
	int count=0;
	
	if(SAFlag==1)
	{	int CINFLAG=0; 
		string name;
		while(CINFLAG==0)
		{
		  
			cout<<"请输入您要查找的姓名：\n";
			cin>>name;
			if(cin.fail())
			{	
				cout<<"您的输入不符合要求"<<endl;
				CINFLAG=0;
			}
			else
			{	
				CINFLAG=1;
			}
		}
		for(int i=0;i<ATotal;i++)
		{	if(name.compare(a[i].getname())==0)
			{	SA[count]=i;
				count++;
			}
		}
	 } 
	 else if(SAFlag==2)
	 {	int ccount;
	 	int CINFLAG=0;
	 	while(CINFLAG==0)
	 	{
		 
	 		cout<<"请输入您想查询的已出题数：\n";
	 		cin>>ccount;
	 		if(cin.fail())
	 		{
	 			cout<<"您的输入不符合要求"<<endl;
	 			CINFLAG=0;
		 	}
		 	else
		 	{	CINFLAG=1;
		 	}
		 }
		 for(int i=0;i<ATotal;i++)
	 	{	if(ccount==a[i].getCCount())
	 			{	SA[count]=i;
	 				count++;
				 }
		 }
	 }
	 else if(SAFlag==3)
	 {	int stage;
	 	int CINFLAG=0;
	 	while(CINFLAG==0)
	 	{
		 
			cout<<"请输入您想查询的等级：\n";
			cin>>stage;
			if(cin.fail())
			{	
				cout<<"您的输入不符合要求"<<endl;
				CINFLAG=0;
			}
			else
			{
				CINFLAG=1;
			}
		}
		for(int i=0;i<ATotal;i++)
		{	if(stage==a[i].getCStage())
			{	SA[count]=i;
				count++;
			}
		 }
	}
	
	cout<<"\n您查询结果如下：\n";
	if(count==0)
	{	cout<<"未查到符合条件的出题人\n";
	 } 
	else
	{
		for(int j=0;j<SearchAdminNum&&SA[j]!=-1;j++)
		{	cout<<"姓名："<<a[SA[j]].getname()<<endl<<"已出题数"<<a[SA[j]].getCCount()<<endl<<"等级"<<a[SA[j]].getCStage()<<endl;	
		}
		cout<<"信息输出完毕\n"; 
		
	}
	
}
