#include<stdio.h>

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
		if(num1==i)
		{printf("%d",num1);
		break;
		}
		printf("%d",i);
		
		num1=num1-i;
		count=count-1;
		while(num1<pow(2,count))
		{	count=count-1;
		}
		printf(",");
	}
    if((num1==2)||(num1==1))
	{printf("%d",num1);
	}
	
	return 0;
}

