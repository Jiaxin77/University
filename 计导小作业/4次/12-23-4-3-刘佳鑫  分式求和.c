#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{     int n,count;
      double i,j,a,sum,num;
      printf("Please input an integer:");
      scanf("%d",&count);
      i=1; 
      j=1;//为分式规律赋初值 
      sum=0;//和归零 
      for(n=1;n<=count;n++)//计 分式个数，控制循环 
      {   a=j;//把初值先赋给另一个变量 
          j=i+j;//分子为上一分数子母之和 
          i=a;//分母为上一分数分子 
          num=j/i;//表示分数 
          sum=sum+num;//计算和 
      }
 printf("The result is:%lf",sum);//输出和 
 system("pause");
 return 0;
}
