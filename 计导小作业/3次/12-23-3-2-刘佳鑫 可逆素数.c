#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{printf("Please input two integers:");
int num,num1,a,j,b,n,n1,re,count,y;
count=0;//���������� 
scanf("%d %d",&a,&b);

for(num=a;num<=b;num++)//������ѭ�� 
{j=0;//�����ж����� 
for(n=2;n<=sqrt(num);n++)//����ѭ�� 
{if(num%n==0)
{j=j+1;}}
if(j==0)//Ϊ���� 
{num1=num;//������һ������ 
re=0;//����� 
while(num1>0)
{
re=re*10+num1%10;
num1=num1/10;//������ 
}
for(n1=2;n1<=sqrt(re);n1++)//����2ѭ�� 
{if(re%n1==0)
{j=j+1;}//�����ж������Ƿ�Ϊ���� 
}
if(j==0)
{
printf("%d\t",num);//��ӡ����Ҫ����� 
count=count+1;//���������� 
if(count%5==0)
{printf("\n");}//������� 
}}}
if(count==0)
{printf("The is no proper number in the interval.");}//�޷����������� 
system("pause");
return 0;
}

