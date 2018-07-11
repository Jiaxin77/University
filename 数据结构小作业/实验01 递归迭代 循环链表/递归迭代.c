#include<stdio.h>
#include<stdlib.h>


long long int Fib(int n);

long long int Fib(int n)//递归 
{	if(n==0||n==1)
		return n;
	else	
		return Fib(n-2)+Fib(n-1);
}

long long int Fib2(int n)//迭代 
{	int first=0;
	long long int second=1;
	int s;
	int i;
	if(n==0||n==1)
		return n;
	for(i=2;i<=n;i++)
	{	s=first+second;//第三个数等于前两个相加 
	    
		first=second;//往下取数 
	    second=s;
	}
	
	return second;
 } 


main()
{	long long int s,r;
	int n;
	printf("Please input the number:");
	scanf("%d",&n); 
	s=Fib(n);//递归 
	r=Fib2(n);//迭代 
	printf("递归Fib %d=%lld\n",n,s);
	printf("迭代Fib %d=%lld",n,r);
	return 0;
	system("pause");

}
