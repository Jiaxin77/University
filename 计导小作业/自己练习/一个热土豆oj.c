#include<stdio.h>


main()
{	int i,N,M,n=0,m=0,count=0;
	int *num;
	scanf("%d,%d",&N,&M);
	num=malloc(sizeof(int)*N);
	
	int flag=1;
	while(flag==1)
	{	m=0;
		while(m<M)
		{	if(num[n]!=1)
				{m++;
				n++;
				}
			else
				n++;
			if(n==N)
				n=0;
		}
		while(n<N)
		{	if(num[n]!=1)
			{	num[n]=1;
				printf("%d,",n+1);
				break;
			}
			else
				n++;
			if(n==N)
				n=0;
		}
		for(i=0;i<N;i++)
		{	if(num[i]!=1)
			count++;
		}
		if(count==1)
			flag=0;
		count=0;
	}
	for(i=0;i<N;i++)
	{	if(num[i]!=1)
		printf("%d\n",i+1);
	}
	free(num);
	return 0;
}
