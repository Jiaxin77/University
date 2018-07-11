#include<stdio.h>
#include<stdlib.h>
void RecurSelectSort(int a[],int n,int x,int max);

void RecurSelectSort(int a[],int n,int x,int max)
{	if(x==(n-1))//停止递归，打印结果 
	{	int count;
		for(count=n-1;count>=0;count--)
		{	printf("%d ",a[count]);
		}
	}
	else
	{	int i,num,flag;
		for(i=x;i<n;i++)
		{	if(a[i]>=a[max])
			{max=i;
			}//求该组数中最大值 
		}
		
		num=a[x];
		a[x]=a[max];
		a[max]=num;//交换 
		if(x==max)
		{	max=x+1; 
		}//若刚好此数为最大值，则设下一轮最大值为下一个数 
	}
		return RecurSelectSort(a,n,x+1,max);//改变x的值，返回函数 
}
	

main()
{	int count,x,max,n;
	printf("Please input the number of intergers:");
	scanf("%d",&n);
	int line[1000]={0};//数组初始化 
	printf("Please input the integers:");
	for(count=0;count<n;count++)
	{	scanf("%d",&line[count]);
	}//存入数组 
	x=0;
	max=0;
	printf("The result is:");
	RecurSelectSort(line,n,x,max);//引用函数 
	printf("\n");
	system("pause");
	return 0;
}


