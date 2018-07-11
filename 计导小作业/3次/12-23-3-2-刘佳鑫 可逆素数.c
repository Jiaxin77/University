#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{printf("Please input two integers:");
int num,num1,a,j,b,n,n1,re,count,y;
count=0;//计数器归零 
scanf("%d %d",&a,&b);

for(num=a;num<=b;num++)//被除数循环 
{j=0;//用于判断素数 
for(n=2;n<=sqrt(num);n++)//除数循环 
{if(num%n==0)
{j=j+1;}}
if(j==0)//为素数 
{num1=num;//赋给另一个变量 
re=0;//逆归零 
while(num1>0)
{
re=re*10+num1%10;
num1=num1/10;//求逆数 
}
for(n1=2;n1<=sqrt(re);n1++)//除数2循环 
{if(re%n1==0)
{j=j+1;}//用于判断逆数是否为素数 
}
if(j==0)
{
printf("%d\t",num);//打印符合要求的数 
count=count+1;//计数器计数 
if(count%5==0)
{printf("\n");}//五个换行 
}}}
if(count==0)
{printf("The is no proper number in the interval.");}//无符合条件的数 
system("pause");
return 0;
}

