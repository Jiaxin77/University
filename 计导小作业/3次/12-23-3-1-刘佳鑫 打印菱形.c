#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{printf("Please input an integer:");
int i,j,n;
scanf("%d",&n);
for(i=1;i<=n;i++)//����ѭ�� 
{for(j=1;j<=(n+i-1);j++)//ÿһ��ÿһ���ַ���ӡ���� 
if(j>(n-i))// ��ӡ*���� 
printf("*");
else
printf(" ");//��*���ӡ�ո� 
printf("\n");}
for(i=1;i<n;i++)
{for(j=1;j<=(2*n-i-1);j++)//�°벿�� 
if(j>i)
printf("*"); 
else
printf(" ");
printf("\n");
}
system("pause");
return 0;
}
