
#include<iostream>

using namespace std;

void copy(int x[],int y[],int n)//y�����ֵ���Ƹ�x 
{
	for(int i=0;i<n;i++)
	{
		x[i]=y[i]; 
	}
	    
}
void copy1(int x[],int y[],int n)//y�����ֵ���Ƹ�x 
{
	for(int i=0;i<=n;i++)
	{
		x[i]=y[i]; 
	}
	    
}


void Merge(int c[],int d[],int l,int m,int r,long int &ComCount,long int &MoveCount)
//�ϲ� ��cΪԭ����dΪ�ϲ���lΪ��ʼ�㣬mΪ�ָ�㣬rΪ�ܳ��� 
{	int i=l,j=m+1,k=l; 
	while((i<=m)&&(j<=r)) 
	{	if(c[i]<=c[j])	
		{	
			d[k++]=c[i++];
			MoveCount++;
		}
		else 
		{	
			d[k++]=c[j++];
			MoveCount++;
		}
		ComCount++;
	}//�Ƚϣ��ϲ��Ӷ� 
	//ʣ��δ�ϲ��ģ�ֱ������ 
	if(i>m)
	{	for(int q=j;q<=r;q++)
		{
			d[k++]=c[q];
			MoveCount++;
		}
	}
	else 
		for(int q=i;q<=m;q++)
		{
			d[k++]=c[q];
			MoveCount++;
		}
}	

void MergePass(int x[],int y[],int s,int n,long int &ComCount,long int &MoveCount)

{	int i=0;int j;
	while(i<=n-2*s)
	{//�ϲ���СΪs������2��������
		Merge(x,y,i,i+s-1,i+2*s-1,ComCount,MoveCount) ;
		i=i+2*s;
	}
	//ʣ�µ�Ԫ�ظ�������2s
	if(i+s<n)
		Merge(x,y,i,i+s-1,n-1,ComCount,MoveCount);
	else
		for(j=i;j<=n-1;j++)
		{	
			y[j]=x[j];
		}
		copy(x,y,n);
}

void MergeSort(int a[],int n,long int &ComCount,long int &MoveCount)
{	int *b=new int[n];
	int s=1;
	
	while(s<n)
	{	MergePass(a,b,s,n,ComCount,MoveCount);//b���¶� 
		s+=s;
		MergePass(b,a,s,n,ComCount,MoveCount);
		s+=s;
	}
	
}

/* 
main()
	{	int num;
		cout<<"���ָ�����";
		cin>>num;
		int count;
		int *Array=new int[num];
		for(count=1;count<=num;count++)
			{	cin>>Array[count]; 
			 } 
		MergeSort(Array,num);
		for(count=1;count<=num;count++)//������ԣ����� 
			{	cout<<Array[count]<<" "; 
			 } 
		system("pause");
		return 0;
	}
	*/ 
