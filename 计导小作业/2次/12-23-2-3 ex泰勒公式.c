#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{   
  double n,j,d,ex,x,y;
  n=1;
  j=1;
  d=1;
  ex=1;/*为变量赋初值*/ 
  printf("Please input an float number:");
  scanf("%lf",&x);
  y=x; 
  for(n=1;;n++)
 {  
    d=d*n;/*阶乘*/
    ex+=x/d;/*公式*/ 
    x=x*y;/*x的n次方*/

 if((fabs(x/d))<(1e-8))
 {
 break;}}/*限制范围，循环终止*/ 
 printf("The result is:%lf\n",ex);
 printf("%.4lf\n",exp(y));/*检验结果正确性*/
 system("pause");
 return 0;
 }
