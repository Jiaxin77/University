#include<iostream>

using namespace std;


void deal(int m,int A[][100])//第m号为虚拟选手 虚拟选手置零函数 
{	int i,j;
	for(i=0;i<m-1;i++)
	{	for(j=0;j<=m;j++)
			{if(A[i][j]==m)
				{	A[i][j]=0;//把和虚拟选手比赛置为0 
				}
			
			}
	 } 
}

void evenTable(int m,int A[][100])//合并 
{	int i,j;
	for(j=0;j<m;j++)
		{	for(i=0;i<m;i++)
			{	A[i+m][j]=A[i][j]+m;//第二对的安排（分配左下角） 
			}
		}
		for(j=m;j<2*m;j++)
			{	for(i=0;i<m;i++)
				{	A[i][j]=A[i+m][j-m];//左下角放到右上角 
				}
				for(i=m;i<2*m;i++)
				{	A[i][j]=A[i-m][j-m];//左上角放到右下角 
				}
			}
		
}

void oddTable(int m,int A[][100])//弄明白这个？？？ 
{	int i,j;
	for(j=0;j<=m;j++)
	{	for(i=0;i<=m;i++)
		{	if(A[i][j]!=0)//不是和虚拟对手pk时 
			{	A[i+m][j]=A[i][j]+m; 
			}
			else//都是和虚拟对手pk时，相互补上 
			{	A[i+m][j]=i+1;
				A[i][j]=i+m+1;
			}
		}
	}
	i=0;
	for(j=m+1;j<2*m;j++)
	{	A[i][j]=j+1;
		A[(A[i][j]-1)][j]=i+1;
		
	}
	for(i=1;i<m;i++)//复制 
	{	for(j=m+1;j<2*m;j++)
		{	if((A[i-1][j]+1)%m==0)
				A[i][j]=A[i-1][j]+1;
			else
				A[i][j]=m+(A[i-1][j]+1)%m;//规律：循环递增 
				
				A[(A[i][j]-1)][j]=i+1;
		}
	}
}



void play(int n,int A[][100]) 
{	if(n==1)
		{A[0][0]=1;
		
		
		}
	else{
	
	if(n%2==1)
		{	play(n+1,A);
			
			deal(n+1,A); 
			
		}
	else
		{	play(n/2,A);
			if((n/2)%2==0)
				evenTable(n/2,A);
			else
				oddTable(n/2,A);//复制表格 
			
		 } 
}
}






void print(int A[][100],int row,int col)//打印 
{	for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
				{	cout<<A[i][j]<<" ";
				}
			cout<<endl;	
		}
		 
 } 
 
 main() 
 {	int num;
 	cout<<"请输入比赛人数（小于100）"<<endl;

	cin>>num;
	if(num>=100||cin.fail())
	{	cout<<"您的输入有误，请重新输入"<<endl;
		cout<<"请输入比赛人数（小于100）"<<endl;
		cin.clear();
		cin.ignore();
		cin>>num;
	
	}
	int game[100][100];
	
	for(int i=0;i<num;i++)
	{	game[i][0]=i+1;//初始化第一列 
	}
	
	play(num,game); 
	
	if(num%2==0)
	{	print(game,num,num);
	}
	if(num%2==1)
	{	print(game,num,num+1);//奇数是n天，所以多出一列 
	}
	
	system("pause");
	return 0;
	 
  } 

