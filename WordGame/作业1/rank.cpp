/*rank.cpp*/
#include"rank.h"
using namespace std;



void rankPlayer(Player *c,const int PTotal)
{	
	rankStruct *rptr=NULL;
	rptr=new rankStruct[PTotal];
	int all;
	int i,j;
	int temppo,tempda;//暂存位置和数据，用于交换
	int RankData; 
	cout<<"请选择排序标准\n1-按闯关卡数排序	2-按经验值排序	3-按等级排序\n";
	int RankFlag=0;
	cin>>RankFlag;
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
	for(Outcome=0;Outcome<10&&Outcome<PTotal;Outcome++)
	{	cout<<"姓名:"<<c[rptr[Outcome].position].getname()<<endl<<"经验"<<c[rptr[Outcome].position].getWExp()<<endl<<"等级："<<c[rptr[Outcome].position].getWStage()<<endl<<"已过关卡数："<<c[rptr[Outcome].position].getWPassedNum()<<endl; 
		cout<<endl; 
	}
	
}


void rankAdmin(Admin *a,const int ATotal)
{	
	rankStruct *rptr=NULL;
	rptr=new rankStruct[ATotal];
	int all;
	int i,j;
	int temppo,tempda;//暂存位置和数据，用于交换
	int RankData; 
	cout<<"请选择排序标准\n1-按出题数排序	2-按等级排序\n";
	int RankFlag=0;
	cin>>RankFlag;
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
	for(Outcome=0;Outcome<10&&Outcome<ATotal;Outcome++)
	{	cout<<"姓名:"<<a[rptr[Outcome].position].getname()<<endl<<"出题数："<<a[rptr[Outcome].position].getCCount()<<endl<<"等级"<<a[rptr[Outcome].position].getCStage()<<endl; 
		cout<<endl; 
	}
	
	
}
