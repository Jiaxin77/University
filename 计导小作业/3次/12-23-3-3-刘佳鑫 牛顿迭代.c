#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{int a,b,c,d;
double x1,x2,f1,f2;
x1=1;
printf("Please input for integers:");
scanf("%d %d %d %d",&a,&b,&c,&d); 
f1=a*x1*x1*x1+b*x1*x1+c*x1+d;//��ʽ 
f2=3*a*x1*x1+2*b*x1+c;//��ʽ 
while(fabs(x2-x1)>(1e-5))//�ж��Ƿ��㹻�ӽ� 
{
x1=x2;//��x2ֵ����x1 
f1=a*x1*x1*x1+b*x1*x1+c*x1+d;
f2=3*a*x1*x1+2*b*x1+c;
x2=x1-f1/f2;}//��ʽ
printf("The solution is:%lf",x2);
system("pause");
return 0;
}
