#include<stdio.h>
#include<stdlib.h>


long long int Fib(int n);

long long int Fib(int n)//�ݹ� 
{	if(n==0||n==1)
		return n;
	else	
		return Fib(n-2)+Fib(n-1);
}

long long int Fib2(int n)//���� 
{	int first=0;
	long long int second=1;
	int s;
	int i;
	if(n==0||n==1)
		return n;
	for(i=2;i<=n;i++)
	{	s=first+second;//������������ǰ������� 
	    
		first=second;//����ȡ�� 
	    second=s;
	}
	
	return second;
 } 


main()
{	long long int s,r;
	int n;
	printf("Please input the number:");
	scanf("%d",&n); 
	s=Fib(n);//�ݹ� 
	r=Fib2(n);//���� 
	printf("�ݹ�Fib %d=%lld\n",n,s);
	printf("����Fib %d=%lld",n,r);
	return 0;
	system("pause");

}
