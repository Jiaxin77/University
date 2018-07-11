
#include<iostream>

using namespace std;

void copy(int x[],int y[],int n)//y数组的值复制给x 
{
	for(int i=0;i<n;i++)
	{
		x[i]=y[i]; 
	}
	    
}
void copy1(int x[],int y[],int n)//y数组的值复制给x 
{
	for(int i=0;i<=n;i++)
	{
		x[i]=y[i]; 
	}
	    
}


void Merge(int c[],int d[],int l,int m,int r,long int &ComCount,long int &MoveCount)
//合并 ，c为原串，d为合并后，l为起始点，m为分割点，r为总长度 
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
	}//比较，合并子段 
	//剩余未合并的，直接连上 
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
	{//合并大小为s的相邻2段子数组
		Merge(x,y,i,i+s-1,i+2*s-1,ComCount,MoveCount) ;
		i=i+2*s;
	}
	//剩下的元素个数少于2s
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
	{	MergePass(a,b,s,n,ComCount,MoveCount);//b是新段 
		s+=s;
		MergePass(b,a,s,n,ComCount,MoveCount);
		s+=s;
	}
	
}

/* 
main()
	{	int num;
		cout<<"数字个数：";
		cin>>num;
		int count;
		int *Array=new int[num];
		for(count=1;count<=num;count++)
			{	cin>>Array[count]; 
			 } 
		MergeSort(Array,num);
		for(count=1;count<=num;count++)//输出不对？？？ 
			{	cout<<Array[count]<<" "; 
			 } 
		system("pause");
		return 0;
	}
	*/ 
