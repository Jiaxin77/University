 

#include"userbox.h"
using namespace std;
 /*****��Ϸ����****/

int PlayerBox(int i,const int PTotal,const int ATotal,Admin *a,Player *c)
{		int ChooseFlag=-1;

		int Flag=1;
		cout<<"��ӭ"<<c[i].getname()<<endl;
		cout<<"�����������ң���ѡ����Ҫ���еĲ���";
		
		while(Flag==1) 
		{
		cin.clear();
		cin.ignore();
		cout<<"\n1-������Ϸ��2-��ѯ�����ߣ�3-��ѯ�����ߣ�4-�鿴������������5-�鿴����������,6-����"<<endl;
		cin>>ChooseFlag; 
			if(cin.fail()||(ChooseFlag!=1&&ChooseFlag!=2&&ChooseFlag!=3&&ChooseFlag!=4&&ChooseFlag!=5&&ChooseFlag!=6))
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
		 		cout<<"�˹�����ʱ�޷�ʹ�ã�����°汾"<<endl; 
				 //return 1;//GameBox();//��Ϸ������Ҳ�ڸ����� ���Ѵ��������鴫��ȥ 
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
int AdminBox(int i,const int PTotal,const int ATotal,Admin *a,Player *c) 
{		int ChooseFlag=-1;

		int Flag=1;
		cout<<"��ӭ"<<a[i].getname()<<endl;
		cout<<"��������ǳ����ˣ���ѡ����Ҫ���еĲ���";
		
		while(Flag==1) 
		{
		cin.clear();
		cin.ignore();
		cout<<"\n1-���⣬2-��ѯ�����ߣ�3-��ѯ�����ߣ�4-�鿴������������5-�鿴����������,6-����"<<endl;
		cin>>ChooseFlag; 
		
		if(cin.fail()||(ChooseFlag!=1&&ChooseFlag!=2&&ChooseFlag!=3&&ChooseFlag!=4&&ChooseFlag!=5&&ChooseFlag!=6))
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
		 		cout<<"�˹�����ʱ�޷�ʹ�ã�����°汾"<<endl; 
				 //return 1;//WordBox();//���⺯����
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
{	cout<<"��ѡ����Ҫ���ҵ�������ԣ�\n1-��������	2-�����Ѵ��عؿ���	3-���Ҵ����߾���ֵ	4-���Ҵ����ߵȼ�\n";
	int SP[50]; //֮��const ����ʢ�����������������
	for(int j=0;j<50;j++)
	{	SP[j]=-1;
	}
	int count=0;
	int SPFlag=-1;
	cin>>SPFlag;
	if(cin.fail()||(SPFlag!=1&&SPFlag!=2&&SPFlag!=3&&SPFlag!=4))
		{
			cout<<"������������"<<endl;
			cin.clear();
			cin.ignore(); 
			
		}
	
	else if(SPFlag==1)
	{	string name;
		cout<<"��������Ҫ���ҵ�������\n";
		cin>>name;
		
		for(int i=0;i<PTotal;i++)
		{	if(name.compare(c[i].getname())==0)
			{	SP[count]=i;
				count++;
			}
		}
	 } 
	 else if(SPFlag==2)
	 {	int passednum;
	 	cout<<"�����������ѯ���Ѵ��ؿ�����\n";
	 	cin>>passednum;
	 	for(int i=0;i<PTotal;i++)
	 	{	if(passednum==c[i].getWPassedNum())
	 			{	SP[count]=i;
	 				count++;
				 }
		 }
	 }
	 else if(SPFlag==3)
	 {	int EXP;
	 	cout<<"�����������ѯ�ľ���ֵ��\n";
		cin>>EXP;
		for(int i=0;i<PTotal;i++)
		{	if(EXP==c[i].getWExp())
			{	SP[count]=i;
				count++;
			}
		 }
	}
	else if(SPFlag==4)
	{	int stage;
		cout<<"�����������ѯ�Ĵ����ߵȼ���\n";
		cin>>stage;
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
		for(int j=0;j<50&&SP[j]!=-1;j++)
		{	cout<<"������"<<c[SP[j]].getname()<<endl<<"�Ѵ��ؿ���"<<c[SP[j]].getWPassedNum()<<endl<<"����ֵ"<<c[SP[j]].getWExp()<<endl<<"�ȼ�"<<c[SP[j]].getWStage()<<endl;	
		}
		cout<<"��Ϣ������\n"; 
		
	}
	
	 
}

int SearchAdmin(Admin *a,const int ATotal)
{
	
	cout<<"��ѡ����Ҫ���ҵĳ��������ԣ�\n1-��������	2-�����ѳ�����	3-���ҵȼ�\n";
	int SA[50]; //֮��const ����ʢ�����������������
	for(int j=0;j<50;j++)
	{	SA[j]=-1;
	}
	int count=0;
	int SAFlag=-1;
	cin>>SAFlag;
	if(cin.fail()||(SAFlag!=1&&SAFlag!=2&&SAFlag!=3))
		{
			cout<<"������������"<<endl;
			cin.clear();
			cin.ignore(); 
			
		}
	
	else if(SAFlag==1)
	{	string name;
		cout<<"��������Ҫ���ҵ�������\n";
		cin>>name;
		
		for(int i=0;i<ATotal;i++)
		{	if(name.compare(a[i].getname())==0)
			{	SA[count]=i;
				count++;
			}
		}
	 } 
	 else if(SAFlag==2)
	 {	int ccount;
	 	cout<<"�����������ѯ���ѳ�������\n";
	 	cin>>ccount;
	 	for(int i=0;i<ATotal;i++)
	 	{	if(ccount==a[i].getCCount())
	 			{	SA[count]=i;
	 				count++;
				 }
		 }
	 }
	 else if(SAFlag==3)
	 {	int stage;
	 	cout<<"�����������ѯ�ĵȼ���\n";
		cin>>stage;
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
		for(int j=0;j<50&&SA[j]!=-1;j++)
		{	cout<<"������"<<a[SA[j]].getname()<<endl<<"�ѳ�����"<<a[SA[j]].getCCount()<<endl<<"�ȼ�"<<a[SA[j]].getCStage()<<endl;	
		}
		cout<<"��Ϣ������\n"; 
		
	}
	
}
