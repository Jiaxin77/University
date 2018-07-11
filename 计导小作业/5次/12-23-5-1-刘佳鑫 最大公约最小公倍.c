#include<stdio.h>
#include<stdlib.h>
int GCD(int a,int b);
int LCM(int a,int b);

int GCD(int a,int b)
{	int num,i;
	if(a<b)//判断数大小 
	{ num=a;
 	  a=b;
 	  b=num;
 	}//大数除小数 
 	
 	while(a%b!=0)
 	{	  i=b;
 		  b=a%b;
		  a=i; 
	}//辗转相除 
	return b;
	 
}
int LCM(int a,int b)
{	int num,i,x,y;
	if(a<b)
	{ num=a;
 	  a=b;
 	  b=num;
 	}
 	x=a;
 	y=b;
 	while(a%b!=0)
 	{	  i=b;
 		  b=a%b;
		  a=i; 
	}//求出最大公约后 
	if(x%y!=0)
	x=x*y/b;//求最小公倍 
	return x;
}

main()
{	printf("Please input two integers:");
	int a,b,gcd,lcm;
	scanf("%d %d",&a,&b);
	gcd=GCD(a,b);//用函数GCD求最小公约 
	lcm=LCM(a,b);//用函数LCM求最大公倍 
	printf("The greatest common divisor is %d and the lowest common multiple is %d.",gcd,lcm);
	return 0;
}
