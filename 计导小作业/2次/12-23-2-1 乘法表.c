#include<stdio.h>
#include<stdlib.h>
main()
{int i,j,result;
for(i=1;i<=9;i=i+1)/*�˷���һ������Χѭ��*/ 
{
for(j=1;j<=i;j=j+1)/*�ڶ�������Χѭ��*/ 
{result=i*j;
printf("%d*%d=%d\t",i,j,result);/*������*/ 
}
printf("\n");/*����*/ 
}

system("pause");
return 0;

}
