#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
    int i,a,b,c,sum;
    int num=0;//计数 
    int n=1;
    printf("Input three integers:");
    scanf("%d %d %d",&a,&b,&c);
    printf("The result is:\n");
    for(i=a;i<=b;i++)//被除数循环 
{	sum=0; 
  for(n=1;n<i;n++)//除数循环       

{   if(i%n==0)
{   sum=sum+n;}}//求因数的和 
   
    if(abs(i-sum)<=c)
{   num=num+1;//计数加一 
    printf("%d\t",i);
    if(num%5==0)//换行条件 
{   printf("\n");}
    }}
    if(num==0) //无答案情况 
{   printf("There is no proper number in the interval");}
system("pause");
return 0;
}
