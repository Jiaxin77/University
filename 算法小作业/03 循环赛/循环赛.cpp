#include<iostream>

using namespace std;


void deal(int m,int A[][100])//��m��Ϊ����ѡ�� ����ѡ�����㺯�� 
{	int i,j;
	for(i=0;i<m-1;i++)
	{	for(j=0;j<=m;j++)
			{if(A[i][j]==m)
				{	A[i][j]=0;//�Ѻ�����ѡ�ֱ�����Ϊ0 
				}
			
			}
	 } 
}

void evenTable(int m,int A[][100])//�ϲ� 
{	int i,j;
	for(j=0;j<m;j++)
		{	for(i=0;i<m;i++)
			{	A[i+m][j]=A[i][j]+m;//�ڶ��Եİ��ţ��������½ǣ� 
			}
		}
		for(j=m;j<2*m;j++)
			{	for(i=0;i<m;i++)
				{	A[i][j]=A[i+m][j-m];//���½Ƿŵ����Ͻ� 
				}
				for(i=m;i<2*m;i++)
				{	A[i][j]=A[i-m][j-m];//���ϽǷŵ����½� 
				}
			}
		
}

void oddTable(int m,int A[][100])//Ū������������� 
{	int i,j;
	for(j=0;j<=m;j++)
	{	for(i=0;i<=m;i++)
		{	if(A[i][j]!=0)//���Ǻ��������pkʱ 
			{	A[i+m][j]=A[i][j]+m; 
			}
			else//���Ǻ��������pkʱ���໥���� 
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
	for(i=1;i<m;i++)//���� 
	{	for(j=m+1;j<2*m;j++)
		{	if((A[i-1][j]+1)%m==0)
				A[i][j]=A[i-1][j]+1;
			else
				A[i][j]=m+(A[i-1][j]+1)%m;//���ɣ�ѭ������ 
				
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
				oddTable(n/2,A);//���Ʊ�� 
			
		 } 
}
}






void print(int A[][100],int row,int col)//��ӡ 
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
 	cout<<"���������������С��100��"<<endl;

	cin>>num;
	if(num>=100||cin.fail())
	{	cout<<"����������������������"<<endl;
		cout<<"���������������С��100��"<<endl;
		cin.clear();
		cin.ignore();
		cin>>num;
	
	}
	int game[100][100];
	
	for(int i=0;i<num;i++)
	{	game[i][0]=i+1;//��ʼ����һ�� 
	}
	
	play(num,game); 
	
	if(num%2==0)
	{	print(game,num,num);
	}
	if(num%2==1)
	{	print(game,num,num+1);//������n�죬���Զ��һ�� 
	}
	
	system("pause");
	return 0;
	 
  } 

