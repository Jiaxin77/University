#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int isPrime(int n);
void recurPrintFactor(int n);

int isPrime(int n)
{	int j,num;
	j=0;//用于判断素数 
	for(num=2;num<n-1;num++)//除数循环 
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
{	int flag1,flag2,num1,flag;
	flag2=0;
	flag1=isPrime(n);
	
	
	if((flag1==1)&&(flag2==0))
		{
		printf("%d",n); 
		n=1;
		}
	
	if(flag1==0)
	{	for(num1=2;num1<=n-1&&flag2==0;num1++)
			{	flag=isPrime(num1);//判断除数是否为素数 
				if((flag==1)&&(n%num1==0))
				{	flag2++;
					printf("%d*",num1);
					n=n/num1;
				}
				if(flag2==1)//用于跳出循环 
				{	num1=n;
				}
			}
	}
	if(n==1)
	printf("\n");		
	else
	return recurPrintFactor(n);
	
}
	

main()
{	int a,b,n;
	printf("Please input two integers:");
	scanf("%d %d",&a,&b);
	for(n=a;n<=b;n++)
	{	printf("%d=",n); 
		recurPrintFactor(n);
	
	}
	system("pause");
	return 0;
}
