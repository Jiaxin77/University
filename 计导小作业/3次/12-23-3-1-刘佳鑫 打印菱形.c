#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{printf("Please input an integer:");
int i,j,n;
scanf("%d",&n);
for(i=1;i<=n;i++)//行数循环 
{for(j=1;j<=(n+i-1);j++)//每一行每一个字符打印东西 
if(j>(n-i))// 打印*条件 
printf("*");
else
printf(" ");//除*外打印空格 
printf("\n");}
for(i=1;i<n;i++)
{for(j=1;j<=(2*n-i-1);j++)//下半部分 
if(j>i)
printf("*"); 
else
printf(" ");
printf("\n");
}
system("pause");
return 0;
}
