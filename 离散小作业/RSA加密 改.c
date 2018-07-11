#include<stdio.h>
//#include<stdlib.h>
#include<math.h>
#define N 100000000//题目要求100000000 
int Binary(long long int e,int a[]);
int Binary(long long int e,int a[])
{	long long p;
 	int u;
 	u=0;
 	while(p!=0)
 	{	a[u]=p%2;
 	    p=p/2;
 	    u=u+1;
 	    
	 }
	 return u-1;
}
int Modular(int b,long long n,int a[],int z);
int Modular(int b,long long n,int a[],int z)
{	int x=1;
	int i; 
	long long power;
	power=b%n;
	for(i=0;i<=z;i++)
		{	if(a[i]==1)
				x=(x*power)%n;
			power=(power*power)%n;
			
		}
		return x;
}
main()
{ long long int password1[10]={0},password2[10]={0},mi;
  int k=0,k1=0,i1=0,j=0,be,ci,count2=0,l;
  int count[10]={0};
  char c;
  char g;
  char a[800]={0};
  char b[800]={0};
  int t[800]={0};
  long long int n,e,i=0,x=0,x1=0,number1=0,number2=1,number0=0;
  scanf("%lld %lld",&n,&e);
  gets(a);
  gets(b);
  //scanf("%c",&c);
  while(b[j]!='\0')
  {		if((b[j]>='A')&&(b[j]<='Z'))//处理大写字母 
  		{
		  i=b[j]-65;
    	  x=x*100+i;
		  }
		if((b[j]>='a')&&(b[j]<='z'))//处理小写字母 
		{	i=b[j]-65-32;
		    x=x*100+i;
		}
   j++;
  }
  x1=x;
  while(x>10)
  {	x=x/10;
  	count2++;
  }
  l=(count2+1)/8;
  
  /*while(x1>N)
  	{ password1[k]=x1%N;
  	  i1=0;
  	  while(i1<e)
  	  {	number1=number2*password1[k];
  	    number2=number1%n;
  	    i1++;
	  }//取余 */
	  be=Binary(e,t);
	  ci=count2+1-8;
	  mi=pow(10,ci);
	  while(ci>0)
	  {	password1[k]=x1/mi;
	    number2=Modular(password1[k],n,t,be);
	  	password2[k]=number2;
	  
	  number0=number2;
	  while(number0>=10)
	  {		number0=number0/10;
	  		count[k]++;
	  }
  	  k++;
  	  ci=ci-8;
		x1=x1%mi;

  	  	mi=pow(10,ci);
  	  
  	  	 
	  
  	  
  }
   
   password1[k]=x1;
	    number2=Modular(password1[k],n,t,be);
	  	password2[k]=number2;
	  
	  number0=number2;
	  while(number0>=10)
	  {		number0=number0/10;
	  		count[k]++;
	  }
  	  k++;

  	  
   for(k1=0;k1<=k;k1++)
      {	while((count[k1]+1)%8!=0)
	{	printf("0");
		count[k1]++;
	}
	  
	  printf("%lld",password2[k1]);
	}
		  //空格问题？？ 
		
   //system("pause");
   return 0;
}
