#include<stdio.h>
#include<stdlib.h>
void InsertSort(int a[],int n);  //插入排序函数//

main()
{	int n,count;
	printf("Please input the number of intergers:");
	scanf("%d",&n);
	printf("Please input the integers:");
	count=0;
	int line[1000]={0};//数组初始化 
	while(count<n)
	{	scanf("%d",&line[count]);
		count++;
	}//读取数字存入数组 
	printf("The result is:");
	InsertSort(line,n);//调用函数 
	printf("\n");
	system("pause");
	return 0;
}

void InsertSort(int a[],int n)
{  int i,j,num,count;
   for(i=1;i<n;i++)  
     { 	j=0;
      	 while(j<=i)  
         { 		if(a[i]<a[j])  //比较第i个数和它之前的数 
		   		{	num=a[i];
           			a[i]=a[j];
           			a[j]=num;
           		}//若小于，交换位置 
        		j++;
		 }
     	
	 }
	for(count=0;count<n;count++)
	{	printf("%d ",a[count]);//输出新数组 
	}
}
