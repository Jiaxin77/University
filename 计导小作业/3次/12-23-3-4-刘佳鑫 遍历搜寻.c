#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{
    int i,a,b,c,sum;
    int num=0;//���� 
    int n=1;
    printf("Input three integers:");
    scanf("%d %d %d",&a,&b,&c);
    printf("The result is:\n");
    for(i=a;i<=b;i++)//������ѭ�� 
{	sum=0; 
  for(n=1;n<i;n++)//����ѭ��       

{   if(i%n==0)
{   sum=sum+n;}}//�������ĺ� 
   
    if(abs(i-sum)<=c)
{   num=num+1;//������һ 
    printf("%d\t",i);
    if(num%5==0)//�������� 
{   printf("\n");}
    }}
    if(num==0) //�޴���� 
{   printf("There is no proper number in the interval");}
system("pause");
return 0;
}
