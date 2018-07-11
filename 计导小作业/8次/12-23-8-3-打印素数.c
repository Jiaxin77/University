#include<stdio.h>
#include<stdlib.h>

main()
{	int p,i,count,count1;
	count=0;
	count1=0;
	int num[999]={0};//数组初始化 
	p=2;
	for(i=p+1;i<999;i++)
	{	if((num[i]==0)&&(i%p==0))
		{	num[i]=1;
		}//非素数化为1 
	}
	p++;
	while(p*p<=999)
	{	for(i=p+1;i<999;i++)
		if((num[i]==0)&&(i%p==0))
		{	num[i]=1;
		}
		p++;
	}
	printf("The prime numbers between 1 and 999 are:\n");
	for(count=2;count<999;count++)
	{	if(num[count]==0)
		{	printf("%d\t",count);//打印素数 
			count1++;
			if(count1%5==0)
			{	printf("\n");
			}
		}
	}
	printf("\n");
	system("pause");
	return 0;
 } 
