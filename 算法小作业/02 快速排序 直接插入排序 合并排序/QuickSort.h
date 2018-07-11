#include<iostream>
#include<time.h> 
#include<stdlib.h>
using namespace std;



int partition1(int A[],int head,int tail,long int &ComCount,long int &MoveCount)//ComCount是比较次数 MoveCount是腾挪次数 
{	int temp=A[head];
	int i,j,r;
	i=head;
	for(j=head+1;j<=tail;j++)
		{	if(A[j]<=temp)
				{	i++;
					r=A[i];
					A[i]=A[j];
					A[j]=r;
					MoveCount++;
				}
			ComCount++;
		}
	r=A[i];
	A[i]=A[head];
	A[head]=r;
	MoveCount++;
	return i;
}

void QuickSort1(int A[],int p,int r,long int &ComCount,long int &MoveCount) //不随机选取划分点 
{	int q;
	if (p<r)
		{q=partition1(A,p,r,ComCount,MoveCount);
		 QuickSort1(A,p,q-1,ComCount,MoveCount);
		 QuickSort1(A,q+1,r,ComCount,MoveCount);
		}
}


int RandomPar(int A[],int head,int tail,long int &ComCount,long int &MoveCount)//随机取划分位置 
{	srand(time(0));
	int i=head+rand()%(tail-head+1);
	int r=A[head];
	A[head]=A[i];
	A[i]=r;
	return partition1(A,head,tail,ComCount,MoveCount);
}//随机取一个数放到第一个位置 

void QuickSort2(int A[],int p,int r,long int &ComCount,long int &MoveCount)
{	if(p<r)
	{	int q=RandomPar(A,p,r,ComCount,MoveCount);	
		QuickSort2(A,p,q-1,ComCount,MoveCount);
		QuickSort2(A,q+1,r,ComCount,MoveCount);
	}
 } 





/* 

main()
{	printf("几个数：");
	int i,num;

	scanf("%d",&num);
	int *Array;
	Array=(int*)malloc(sizeof(int)*num);
	printf("输入数列：\n");
	for(i=1;i<=num;i++)
		{	scanf("%d",&Array[i]);
		}
	
	QuickSort(Array,1,num);
	for(i=1;i<=num;i++)
		{	printf("%d ",Array[i]);
		}
	free(Array);
		system("pause");
		return 0;
	}
*/
