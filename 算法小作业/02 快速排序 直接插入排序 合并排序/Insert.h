//��������
#include<iostream>
using namespace std;


void insertsort(int R[],int n,long int &ComCount,long int &MoveCount)//�����⣿����Ų���� 
{	int i,temp,j;
	for(i=1;i<=n;i++)//i��ʾ������� ������n-1�β���
	{	
		temp=R[i];//������Ԫ�ظ���temp;
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
