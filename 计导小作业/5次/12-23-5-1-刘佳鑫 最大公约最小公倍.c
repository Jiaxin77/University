#include<stdio.h>
#include<stdlib.h>
int GCD(int a,int b);
int LCM(int a,int b);

int GCD(int a,int b)
{	int num,i;
	if(a<b)//�ж�����С 
	{ num=a;
 	  a=b;
 	  b=num;
 	}//������С�� 
 	
 	while(a%b!=0)
 	{	  i=b;
 		  b=a%b;
		  a=i; 
	}//շת��� 
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
	}//������Լ�� 
	if(x%y!=0)
	x=x*y/b;//����С���� 
	return x;
}

main()
{	printf("Please input two integers:");
	int a,b,gcd,lcm;
	scanf("%d %d",&a,&b);
	gcd=GCD(a,b);//�ú���GCD����С��Լ 
	lcm=LCM(a,b);//�ú���LCM����󹫱� 
	printf("The greatest common divisor is %d and the lowest common multiple is %d.",gcd,lcm);
	return 0;
}
