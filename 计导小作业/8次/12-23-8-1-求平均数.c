#include<stdio.h>
#include<stdlib.h>

main()
{	int n,n1,x,count;
	double  sum,average;
	sum=0;
	count=0;
	n1=0;
	printf("Please input the number of courses:");
	scanf("%d",&n);
	int score[n];//定义数组 
	printf("Please input %d scores:",n);
	
	while(count<n)
	{	scanf("%d",&x);//读取数字 
		score[n1]=x;
		n1++;
		count++;
	}
	for(n1=0;n1<n;n1++)
	{	sum=sum+score[n1];//计算总和 
	}
	average=sum/n;
	printf("The average score is:%lf\n",average);
	system("pause");
	return 0;
}
