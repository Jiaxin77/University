#include<stdio.h>



main()
{	int n,m,i,count=0;
	
	scanf("%d %d",&n,&m);
	int *people;
	people=malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{	scanf("%d",&people[i]);
		getchar();
	}
	for(i=0;i<n;i++)
	{	for(m=0;m<n;m++)
		{	if(people[i]==people[m])
				count++;
		}
		if(count-1==0)
			printf("BeiJu\n");
		else
			printf("%d\n",count-1);
		count=0;
		
	}
	
	return 0;
}
