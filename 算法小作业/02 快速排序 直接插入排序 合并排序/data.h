#include<iostream>
#include<stdlib.h>
using namespace std;
//�����ź�������ݼ�

void UpSorted(int A[],int n)//���� 
{	int i;
	for(i=0;i<=n;i++)
	{	A[i]=i*2;
	}
	
 }  
 
 void DownSorted(int A[],int n)//���� 
 {	int i;
 	for(i=0;i<=n;i++)
 	{	A[n-i+1]=i*2;
	 }
 }
 
 void Rands(int A[],int n)//��� 
 {	int i;
 	for(i=0;i<=n;i++)
 	{	A[i]=rand()%1000;
	 }
 }
 
 
