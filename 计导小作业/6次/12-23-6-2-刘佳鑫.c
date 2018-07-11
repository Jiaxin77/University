#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{	int a,b,a1,b1,num,n;
	int sum;
	scanf("%d %d",&a,&b);
	sum=a+b;
	if((sum<a)&&(sum<b))
	{	a1=a%10;
		b1=b%10;
		while((a>10)&&(b>10))
		{	n=(a1+b1)/10;
			a=a/10;
			b=b/10;
			b=b+n;
			a1=a%10;
			b1=b%10;
		}
		num=a1+b1;
	}
	else
	{	if(sum<0)
		{sum=-sum;
		}
		while(sum>10)
		{	sum=sum/10;	
		}
	num=sum;
	}
	printf("%d\n",num);
	system("pause");
	return 0;
}
