#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{int a,b,c,d;
double x1,x2,f1,f2;
x1=1;
printf("Please input for integers:");
scanf("%d %d %d %d",&a,&b,&c,&d); 
f1=a*x1*x1*x1+b*x1*x1+c*x1+d;//公式 
f2=3*a*x1*x1+2*b*x1+c;//公式 
while(fabs(x2-x1)>(1e-5))//判断是否足够接近 
{
x1=x2;//把x2值赋给x1 
f1=a*x1*x1*x1+b*x1*x1+c*x1+d;
f2=3*a*x1*x1+2*b*x1+c;
x2=x1-f1/f2;}//公式
printf("The solution is:%lf",x2);
system("pause");
return 0;
}
