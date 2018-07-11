//插入排序
#include<iostream>
using namespace std;


void insertsort(int R[],int n,long int &ComCount,long int &MoveCount)//有问题？？腾挪？？ 
{	int i,temp,j;
	for(i=1;i<=n;i++)//i表示插入次数 共进行n-1次插入
	{	
		temp=R[i];//待排序元素赋给temp;
		j=i-1; 
		while((j>=0)&&(temp<R[j]))
		{	R[j+1]=R[j];
			j--;
			
			MoveCount++;
		} 
			ComCount++; 
			R[j+1]=temp;
		//	MoveCount++;
	} 

 } 
