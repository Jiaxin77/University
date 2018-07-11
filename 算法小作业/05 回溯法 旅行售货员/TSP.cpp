//解空间是排列树
#include<iostream>
#include<limits>//为了声明无穷 
using namespace std;
float floatmax=numeric_limits<float>::max();//floatmax则代表无穷 

class BTTSP
{
	friend void TSP(float **a,int n);
	
	float **a; //图G的邻接矩阵 
	int n;//图G的顶点数
	int *x;//当前解
	int *bestx;//当前最优解
	float bestc;//当前最优值 
	float cc;//当前费用 
	
	 
	private:
		 void backtrack(int i);

}; 


void BTTSP::backtrack(int i)
{
	if(i==n)//是叶子结点 
	{
		if (a[x[n-1]][x[n]]<floatmax&&a[x[n]][1]<floatmax)//存在路径
		{
			if(cc+a[x[n-1]][x[n]]+a[x[n]][1]<bestc)//加上该条，值小于最优解 
			{
				bestc=cc+a[x[n-1]][x[n]]+a[x[n]][1];//最优解更新 
				for(int j=1;j<=n;j++)//最优路径更新 
				{
					bestx[j]=x[j];
				}
			 } 
		} 
		
	} 
	else//不是叶子结点，回溯（排列树） 
	{
		for(int j=i;j<=n;j++)
		{
			if (a[x[i-1]][x[j]]<floatmax&&cc+a[x[i-1]][x[j]]<bestc)
			{
				swap(x[i],x[j]); //swap是系统函数！ 
				cc+=a[x[i-1]][x[i]];
				backtrack(i+1);
				cc-=a[x[i-1]][x[i]];
				swap(x[i],x[j]); 
				
			}
			
		}
	}
}

 void TSP(float **A,int m)//初始化以及调用回溯 
{
	BTTSP p;
	
	p.n=m;
	p.x= new int[m+1];
	p.bestx=new int[m+1];
	
	for(int j=1;j<=m;j++)
	{
		p.x[j]=j;
	}
	
	p.a=A;
	p.cc=0;
	p.bestc=floatmax;
	//搜索x[2:n]的全排列 
	p.backtrack(2);
	
	cout<<"应走路径为："<<endl;
	for(int j=1;j<=m;j++)
	{
		cout<<p.bestx[j]<<"\t";
	}
	cout<<p.bestx[1]<<endl;//回路又回到起点
	
	cout<<"最少路费为："<<endl;
	cout<<p.bestc<<endl;
	
	delete []p.x;
	p.x=0;
	delete []p.bestx;
	p.bestx=0;
	 
	
}

main()
{
	cout<<"请输入城市个数"<<endl;
	int n;
	cin>>n;
	float **A=new float *[n+1];
	for(int j=0;j<=n;j++)
	{
		A[j]=new float[n+1];
	}
	
	cout<<"请按顺序输入邻接矩阵,同城市请输入-1，不可达也请输入-1"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			{
				cin>>A[i][j];
			}
	}
	cout<<"邻接矩阵为"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			{
				cout<<A[i][j]<<" ";
			}
		cout<<endl;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			{
				if (A[i][j]==-1&&i!=j)
					{
						A[i][j]=floatmax;//把不可达设为距离为无穷 
					}
			}
		
	} 
	
	TSP(A,n);
	
	for(int j=0;j<=n;j++)
	{
		delete []A[j];
	}
	delete []A;
	
	A=0;
	system("pause");
	return 0;
}
