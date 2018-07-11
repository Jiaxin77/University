#include<iostream>
#include<stdlib.h>
using namespace std;
//生成排好序的数据集

void UpSorted(int A[],int n)//升序 
{	int i;
	for(i=0;i<=n;i++)
	{	A[i]=i*2;
	}
	
 }  
 
 void DownSorted(int A[],int n)//降序 
 {	int i;
 	for(i=0;i<=n;i++)
 	{	A[n-i+1]=i*2;
	 }
 }
 
 void Rands(int A[],int n)//随机 
 {	int i;
 	for(i=0;i<=n;i++)
 	{	A[i]=rand()%1000;
	 }
 }
 
 
