#include<stdio.h>
#include<stdlib.h>
main()
{int i,j,result;
for(i=1;i<=9;i=i+1)/*乘法第一个数范围循环*/ 
{
for(j=1;j<=i;j=j+1)/*第二个数范围循环*/ 
{result=i*j;
printf("%d*%d=%d\t",i,j,result);/*输出结果*/ 
}
printf("\n");/*换行*/ 
}

system("pause");
return 0;

}
