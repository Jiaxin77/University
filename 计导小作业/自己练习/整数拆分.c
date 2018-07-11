#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{	int num,num1,count,i;
	scanf("%d",&num);
	num1=num;
	count=0;
	while(num>1)
	{	num=num/2;
		count=count+1;
	}
	while(num1>2)
	{
	
		i=pow(2,count);
		printf("%d",i);
		num1=num1-i;
		count=count-1;
		while(num1<pow(2,count))
		{	count=count-1;
		}
		printf(",");
	}
    if(num1!=0)
	{printf("%d",num1);
	}
	system("pause");
	return 0;
}

