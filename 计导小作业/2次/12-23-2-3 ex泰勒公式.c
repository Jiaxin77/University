#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{   
  double n,j,d,ex,x,y;
  n=1;
  j=1;
  d=1;
  ex=1;/*Ϊ��������ֵ*/ 
  printf("Please input an float number:");
  scanf("%lf",&x);
  y=x; 
  for(n=1;;n++)
 {  
    d=d*n;/*�׳�*/
    ex+=x/d;/*��ʽ*/ 
    x=x*y;/*x��n�η�*/

 if((fabs(x/d))<(1e-8))
 {
 break;}}/*���Ʒ�Χ��ѭ����ֹ*/ 
 printf("The result is:%lf\n",ex);
 printf("%.4lf\n",exp(y));/*��������ȷ��*/
 system("pause");
 return 0;
 }
