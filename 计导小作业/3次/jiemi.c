#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10000

int isPrime(int n1);
int isPrime(int n1)
{	int j,num;
	j=0;//用于判断素数 
	for(num=2;num<=sqrt(n1);num++)//除数循环 
	{	if(n1%num==0)
		{	j=j+1;
		}
	}
	if(j==0)
		return 1;
	else
		return 0;
}

main()
{	long long int n,e,password,p,q,num,num1,x,x1,x2,d,j1;
    long long int text1[1600]={0},text2[1600]={0};
	int flag,i,k=0,h=0,j2=0;
	char ALP[800]={0};
	char c;
	scanf("%lld %lld",&n,&e); 
	scanf("%c",&c);
	scanf("%lld",&password);
    for(i=2;i<=sqrt(n);i++)
       {	flag=isPrime(i);
            if(flag==1)
            	{	if(n%i==0)
            	       {p=i;
					    q=n/i;
					    break;
						}
				}
	   }//找出p,q 
	num=(p-1)*(q-1);
	for(d=1;;d++)
	{	num1=d*e;
	    if(num1%num==1)
	    	break;
	}//找出d 
	while(password>N)
	{	x1=password%N;
	    x=1;x2=1;
	    text1[k]=x1;
	    while(h<d)
	    {	
			x=x2*text1[k];
	        x2=x%n;
	        h++;
		}
		text2[k]=x2;
	    k++;
	    password=password/N;
	}//如果分着读 则不需要 (拆分输入密文password)
	x1=password%N;
	    x=1;x2=1;
	    text1[k]=x1;
	    while(h<d)
	    {	
			x=x2*text1[k];
	        x2=x%n;
	        h++;
		}
		text2[k]=x2;////如果分着读 则不需要 (拆分输入密文password)
		//
		for(i=0;i<=k;i++)
		{	printf("%lld\n",text2[i]);
		}
	for(i=0;i<=k;i++)
	{	while(text2[i]>100)
			{	j1=text2[i]%100;
			    ALP[j2]=j1+65;
			    j2++;
			    text2[i]=text2[i]/100;
			}
				j1=text2[i]%100;
			    ALP[j2]=j1+65;
			    j2++;
			
	}
	printf("%d\n",d);
	for(i=j2;i>=0;i--)
	{	printf("%c",ALP[i]);
	}
	system("pause");
	return 0;

 } 
