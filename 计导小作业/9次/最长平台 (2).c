#include<stdio.h>
#include<stdlib.h>
int maxLen(int a[],int n);


 
 
 main()
 {	int n,max,count;
 	
	printf("Please input the number of integers:");
	scanf("%d",&n);
	int num[1000]={0};//�����ʼ�� 
	printf("Please input the integers:");
	count=0;
	while(count<n)//��ȡ���� 
	{	scanf("%d",&num[count]);
		count++; 
	}
	max=maxLen(num,n);//���ú��� 
	printf("The longest level is:%d\n",max);
	system("pause");
	return 0; 
 }
 
 int maxLen(int a[],int n)
 {	int count,count1,max;
 	count=1;
	count1=0;
	max=0;
 	while(count<n)
 	{	if(a[count]==a[count-1])
	 	{	count1++; 
	 	}	//��������ǰһ������ͬ��ƽ̨���ȼ�һ 
		else
		 {count1=1;
		 }//����ͬ��ƽ̨���ȹ�Ϊ1 
		 if(count1>max)
		 {max=count1;
		 }//�Ƚϳ��ƽ̨ 
		 count++;
 	}
 
 	return max;
 }
