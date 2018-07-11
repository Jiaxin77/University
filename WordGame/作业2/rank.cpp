/*rank.cpp*/
#include"rank.h"
using namespace std;

void rankPlayer(Player *c,const int PTotal)
{	
	rankStruct *rptr=NULL;
	rptr=new rankStruct[PTotal];
	int all;
	int i,j;
	int temppo,tempda;//�ݴ�λ�ú����ݣ����ڽ���
	int RankData; 
	int RankFlag=0;
	while(RankFlag!=1&&RankFlag!=2&&RankFlag!=3||cin.fail())
	{
	
		cout<<"��ѡ�������׼\n1-�����ؿ�������	2-������ֵ����	3-���ȼ�����\n"; 
		cin>>RankFlag;
	}
	if(RankFlag==1)
	{
		
		j=0;
	
		for(i=0;i<PTotal;i++)
		{	
			rptr[j].position=i;
			rptr[j].rankdata=c[i].getWPassedNum();
			j++;
		}
	
		all=j;
		for(int z=0;z<all-1;z++)
		{	
			j=z;
			for(int k=z+1;k<all;k++)
				{
					if(rptr[j].rankdata<rptr[k].rankdata) j=k;
				} 
			if(z!=j)
			{	
			temppo=rptr[z].position;
			tempda=rptr[z].rankdata;
			rptr[z].position=rptr[j].position;
			rptr[z].rankdata=rptr[j].rankdata;
			rptr[j].rankdata=tempda;
			rptr[j].position=temppo;
			}
		}
	}
	
	else if(RankFlag==2)
	{
		
		int i,j;
		j=0;
			
		for( i=0;i<PTotal;i++)
		{	
			rptr[j].position=i;
			rptr[j].rankdata=c[i].getWExp(); 
			j++;
		}
	
		all=j;
		for(int z=0;z<all-1;z++)
		{	
			j=z;
			for(int k=z+1;k<all;k++)
				{
					if(rptr[j].rankdata<rptr[k].rankdata) j=k;
				} 
			if(z!=j)
			{	
			temppo=rptr[z].position;
			tempda=rptr[z].rankdata;
			rptr[z].position=rptr[j].position;
			rptr[z].rankdata=rptr[j].rankdata;
			rptr[j].rankdata=tempda;
			rptr[j].position=temppo;
			}
		}
			
	}
	else if(RankFlag==3)
	{	
		int i,j;
		j=0;			
		for(i=0;i<PTotal;i++)
		{	
			rptr[j].position=i;
			rptr[j].rankdata=c[i].getWStage(); 
			j++;
		}
	
		all=j;
		for(int z=0;z<all-1;z++)
		{	
			j=z;
			for(int k=z+1;k<all;k++)
				{
					if(rptr[j].rankdata<rptr[k].rankdata) j=k;
				} 
			if(z!=j)
			{	
			temppo=rptr[z].position;
			tempda=rptr[z].rankdata;
			rptr[z].position=rptr[j].position;
			rptr[z].rankdata=rptr[j].rankdata;
			rptr[j].rankdata=tempda;
			rptr[j].position=temppo;
			}
		}
	}
	
	int Outcome;
	for(Outcome=0;Outcome<rankOutCome&&Outcome<PTotal;Outcome++)
	{	cout<<"����:"<<c[rptr[Outcome].position].getname()<<endl<<"���飺"<<c[rptr[Outcome].position].getWExp()<<endl<<"�ȼ���"<<c[rptr[Outcome].position].getWStage()<<endl<<"�ѹ��ؿ�����"<<c[rptr[Outcome].position].getWPassedNum()<<endl; 
		cout<<endl; 
	}
	//cout�����ǰʮ�ɣ� 
	
	//δ������ �����ٸ���һ�£��������Ա 
	
}


void rankAdmin(Admin *a,const int ATotal)
{	
	rankStruct *rptr=NULL;
	rptr=new rankStruct[ATotal];
	int all;
	int i,j;
	int temppo,tempda;//�ݴ�λ�ú����ݣ����ڽ���
	int RankData;
	int RankFlag=0;
	while(RankFlag!=1&&RankFlag!=2||cin.fail())
	{
	cout<<"��ѡ�������׼\n1-������������	2-���ȼ�����\n";
	cin>>RankFlag;
	}
	if(RankFlag==1)
	{
		
		j=0;
	
		for(i=0;i<ATotal;i++)
		{	
			rptr[j].position=i;
			rptr[j].rankdata=a[i].getCCount();
			j++;
		}
	
		all=j;
		for(int z=0;z<all-1;z++)
		{	
			j=z;
			for(int k=z+1;k<all;k++)
				{
					if(rptr[j].rankdata<rptr[k].rankdata) j=k;
				} 
			if(z!=j)
			{	
			temppo=rptr[z].position;
			tempda=rptr[z].rankdata;
			rptr[z].position=rptr[j].position;
			rptr[z].rankdata=rptr[j].rankdata;
			rptr[j].rankdata=tempda;
			rptr[j].position=temppo;
			}
		}
	}
	
	else if(RankFlag==2)
	{
		
		int i,j;
		j=0;
			
		for( i=0;i<ATotal;i++)
		{	
			rptr[j].position=i;
			rptr[j].rankdata=a[i].getCStage(); 
			j++;
		}
	
		all=j;
		for(int z=0;z<all-1;z++)
		{	
			j=z;
			for(int k=z+1;k<all;k++)
				{
					if(rptr[j].rankdata<rptr[k].rankdata) j=k;
				} 
			if(z!=j)
			{	
			temppo=rptr[z].position;
			tempda=rptr[z].rankdata;
			rptr[z].position=rptr[j].position;
			rptr[z].rankdata=rptr[j].rankdata;
			rptr[j].rankdata=tempda;
			rptr[j].position=temppo;
			}
		}
			
	}

	
	int Outcome;
	for(Outcome=0;Outcome<rankOutCome&&Outcome<ATotal;Outcome++)
	{	cout<<"����:"<<a[rptr[Outcome].position].getname()<<endl<<"��������"<<a[rptr[Outcome].position].getCCount()<<endl<<"�ȼ���"<<a[rptr[Outcome].position].getCStage()<<endl; 
		cout<<endl; 
	}

	
}
