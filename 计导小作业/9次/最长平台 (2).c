#include<stdio.h>
#include<stdlib.h>
int maxLen(int a[],int n);


 
 
 main()
 {	int n,max,count;
 	
	printf("Please input the number of integers:");
	scanf("%d",&n);
	int num[1000]={0};//数组初始化 
	printf("Please input the integers:");
	count=0;
	while(count<n)//读取数组 
	{	scanf("%d",&num[count]);
		count++; 
	}
	max=maxLen(num,n);//调用函数 
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
	 	}	//若该数与前一个数相同，平台长度加一 
		else
		 {count1=1;
		 }//若不同，平台长度归为1 
		 if(count1>max)
		 {max=count1;
		 }//比较出最长平台 
		 count++;
 	}
 
 	return max;
 }
