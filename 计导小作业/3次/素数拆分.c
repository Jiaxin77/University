#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int isPrime(int n);
void recurPrintFactor(int n);

int isPrime(int n)
{	int j,num;
	j=0;//用于判断素数 
	for(num=2;num<=sqrt(n);num++)//除数循环 
	{	if(n%num==0)
		{	j=j+1;
		}
	}
	if(j==0)
		return 1;
	else
		return 0;
}

void recurPrintFactor(int n)
{	int flag1,num1,flag;
	flag1=isPrime(n);
	while(flag1==0)
	{
		for(num1=1;num1<=n;num1++)
		{	flag=isPrime(num1);
			if(flag==1)
			{	printf("%d*",num1);
				n=n/num1;	
			}	
		}
		flag1=isPrime(n);
	}
	printf("%d",n);
}

main()
{	int a,b,n;
	printf("Please input two integers:");
	scanf("%d %d",&a,&b);
	for(n=a;n<=b;n++)
	{	void recurPrintFactor(n);
	}
	system("pause");
	return 0;
}
