#include<stdio.h>
#include<stdlib.h>
int convert(int n);

int convert(int n)
{	if ((n==0)||(n==1))
		return n;
	else
		return n%10+convert(n/10)*2; 
}

main()
{	int n,num;
	printf("Please input an integer:");
	scanf("%d",&n);
	num=convert(n);
	printf("The result is:%d\n",num);
	system("pause");
	return 0;
}
