 

#include"userbox.h"

using namespace std;
 /*****��Ϸ����****/

int PlayerBox(int i,const int PTotal,const int ATotal,const int WTotal,Admin *a,Player *c,word *w)
{		system("cls");
		int ChooseFlag=-1;
	
		int Flag=1;
		cout<<"��ӭ"<<c[i].getname()<<endl;
		cout<<"�����������ң���ѡ����Ҫ���еĲ���";
		
		while(Flag==1) 
		{
		cin.clear();
		cin.ignore();
		ChooseFlag=-1;
		cout<<"\n1-������Ϸ��2-��ѯ�����ߣ�3-��ѯ�����ߣ�4-�鿴������������5-�鿴����������,6-����"<<endl;
		cin>>ChooseFlag; 
		if(ChooseFlag!=1&&ChooseFlag!=2&&ChooseFlag!=3&&ChooseFlag!=4&&ChooseFlag!=5&&ChooseFlag!=6||cin.fail())
		{
		cout<<"������������"<<endl;
		cin.clear();
		cin.ignore();
		
		}
			else if(ChooseFlag==6)
			{	Flag=0;//���� 
			 } 
		 	else if(ChooseFlag==1)
			 {	
		 		c[i].GameBox(w,WTotal);//return 1;//GameBox();//��Ϸ������Ҳ�ڸ����� ���Ѵ��������鴫��ȥ 
			 }
		 	else if(ChooseFlag==2)
		 	{	SearchPlayer(c,PTotal) ;
		 	 //	return 1;//��ѯ��� 
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
		cout<<"��ӭ"<<a[i].getname()<<endl;
		cout<<"��������ǳ����ˣ���ѡ����Ҫ���еĲ���";
		
		while(Flag==1) 
		{
		cin.clear();
		cin.ignore();
		ChooseFlag=-1;
		while(ChooseFlag!=1&&ChooseFlag!=2&&ChooseFlag!=3&&ChooseFlag!=4&&ChooseFlag!=5&&ChooseFlag!=6||cin.fail())
		{
			cout<<"\n1-���⣬2-��ѯ�����ߣ�3-��ѯ�����ߣ�4-�鿴������������5-�鿴����������,6-����"<<endl;
			cin>>ChooseFlag; 
		}
			if(ChooseFlag==6)
			{	Flag=0;//���� 
			 } 
		 	else if(ChooseFlag==1)
			 {	
		 		 a[i].AddWord(w,WTotal);//return 1;//WordBox();//���⺯����
			 }
		 	else if(ChooseFlag==2)
		 	{	SearchPlayer(c,PTotal) ;
		 	 //	return 1;//��ѯ��� 
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
		cout<<"��ѡ����Ҫ���ҵ�������ԣ�\n1-��������	2-�����Ѵ��عؿ���	3-���Ҵ����߾���ֵ	4-���Ҵ����ߵȼ�\n";
		cin>>SPFlag;
	}
	int SP[SearchPlayerNum]; //֮��const ����ʢ�����������������
	for(int j=0;j<SearchPlayerNum;j++)
	{	SP[j]=-1;
	}
	int count=0;

	if(SPFlag==1)
	{	string name;
		int CINFLAG=0;
		while(CINFLAG==0)
		{ 
			cout<<"��������Ҫ���ҵ�������\n";
			cin>>name;
			if(cin.fail())
			{	
				cout<<"�������벻����Ҫ��"<<endl;
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
		
			cout<<"�����������ѯ���Ѵ��ؿ�����\n";
	 		cin>>passednum;
	 		if(cin.fail())
	 		{	cout<<"�������벻����Ҫ��"<<endl;
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
		 
	 		cout<<"�����������ѯ�ľ���ֵ��\n";
			cin>>EXP;
			if(cin.fail()) 
			{	
				cout<<"�������벻����Ҫ��"<<endl;
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
			cout<<"�����������ѯ�Ĵ����ߵȼ���\n";
			cin>>stage;
			if(cin.fail())
			{	
				cout<<"�������벻����Ҫ��"<<endl;
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
	cout<<"\n����ѯ������£�\n";
	if(count==0)
	{	cout<<"δ�鵽�������������\n";
	 } 
	else
	{
		for(int j=0;j<SearchPlayerNum&&SP[j]!=-1;j++)
		{	cout<<"������"<<c[SP[j]].getname()<<endl<<"�Ѵ��ؿ���"<<c[SP[j]].getWPassedNum()<<endl<<"����ֵ"<<c[SP[j]].getWExp()<<endl<<"�ȼ�"<<c[SP[j]].getWStage()<<endl;	
		}
		cout<<"��Ϣ������\n"; 
		
	}
	
	 
}

int SearchAdmin(Admin *a,const int ATotal)
{
	int SAFlag=-1;
	while(SAFlag!=1&&SAFlag!=2&&SAFlag!=3||cin.fail())
	{
	
		cout<<"��ѡ����Ҫ���ҵĳ��������ԣ�\n1-��������	2-�����ѳ�����	3-���ҵȼ�\n";
		cin>>SAFlag;
	}
	int SA[SearchAdminNum]; //֮��const ����ʢ�����������������
	for(int j=0;j<SearchAdminNum;j++)
	{	SA[j]=-1;
	}
	int count=0;
	
	if(SAFlag==1)
	{	int CINFLAG=0; 
		string name;
		while(CINFLAG==0)
		{
		  
			cout<<"��������Ҫ���ҵ�������\n";
			cin>>name;
			if(cin.fail())
			{	
				cout<<"�������벻����Ҫ��"<<endl;
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
		 
	 		cout<<"�����������ѯ���ѳ�������\n";
	 		cin>>ccount;
	 		if(cin.fail())
	 		{
	 			cout<<"�������벻����Ҫ��"<<endl;
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
		 
			cout<<"�����������ѯ�ĵȼ���\n";
			cin>>stage;
			if(cin.fail())
			{	
				cout<<"�������벻����Ҫ��"<<endl;
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
	
	cout<<"\n����ѯ������£�\n";
	if(count==0)
	{	cout<<"δ�鵽���������ĳ�����\n";
	 } 
	else
	{
		for(int j=0;j<SearchAdminNum&&SA[j]!=-1;j++)
		{	cout<<"������"<<a[SA[j]].getname()<<endl<<"�ѳ�����"<<a[SA[j]].getCCount()<<endl<<"�ȼ�"<<a[SA[j]].getCStage()<<endl;	
		}
		cout<<"��Ϣ������\n"; 
		
	}
	
}
