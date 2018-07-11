//��ռ���������
#include<iostream>
#include<limits>//Ϊ���������� 
using namespace std;
float floatmax=numeric_limits<float>::max();//floatmax��������� 

class BTTSP
{
	friend void TSP(float **a,int n);
	
	float **a; //ͼG���ڽӾ��� 
	int n;//ͼG�Ķ�����
	int *x;//��ǰ��
	int *bestx;//��ǰ���Ž�
	float bestc;//��ǰ����ֵ 
	float cc;//��ǰ���� 
	
	 
	private:
		 void backtrack(int i);

}; 


void BTTSP::backtrack(int i)
{
	if(i==n)//��Ҷ�ӽ�� 
	{
		if (a[x[n-1]][x[n]]<floatmax&&a[x[n]][1]<floatmax)//����·��
		{
			if(cc+a[x[n-1]][x[n]]+a[x[n]][1]<bestc)//���ϸ�����ֵС�����Ž� 
			{
				bestc=cc+a[x[n-1]][x[n]]+a[x[n]][1];//���Ž���� 
				for(int j=1;j<=n;j++)//����·������ 
				{
					bestx[j]=x[j];
				}
			 } 
		} 
		
	} 
	else//����Ҷ�ӽ�㣬���ݣ��������� 
	{
		for(int j=i;j<=n;j++)
		{
			if (a[x[i-1]][x[j]]<floatmax&&cc+a[x[i-1]][x[j]]<bestc)
			{
				swap(x[i],x[j]); //swap��ϵͳ������ 
				cc+=a[x[i-1]][x[i]];
				backtrack(i+1);
				cc-=a[x[i-1]][x[i]];
				swap(x[i],x[j]); 
				
			}
			
		}
	}
}

 void TSP(float **A,int m)//��ʼ���Լ����û��� 
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
	//����x[2:n]��ȫ���� 
	p.backtrack(2);
	
	cout<<"Ӧ��·��Ϊ��"<<endl;
	for(int j=1;j<=m;j++)
	{
		cout<<p.bestx[j]<<"\t";
	}
	cout<<p.bestx[1]<<endl;//��·�ֻص����
	
	cout<<"����·��Ϊ��"<<endl;
	cout<<p.bestc<<endl;
	
	delete []p.x;
	p.x=0;
	delete []p.bestx;
	p.bestx=0;
	 
	
}

main()
{
	cout<<"��������и���"<<endl;
	int n;
	cin>>n;
	float **A=new float *[n+1];
	for(int j=0;j<=n;j++)
	{
		A[j]=new float[n+1];
	}
	
	cout<<"�밴˳�������ڽӾ���,ͬ����������-1�����ɴ�Ҳ������-1"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			{
				cin>>A[i][j];
			}
	}
	cout<<"�ڽӾ���Ϊ"<<endl;
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
						A[i][j]=floatmax;//�Ѳ��ɴ���Ϊ����Ϊ���� 
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
