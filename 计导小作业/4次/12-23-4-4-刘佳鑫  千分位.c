#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{     int num,num1,num3,length,i,d;
      printf("Please input an integer:");
      scanf("%d",&num);
      length=0;//计算位数归零 
      num1=num;//把数字赋给另一变量 
      while(num>=1) 
      {     num=num/10;
            length=length+1;
      }//计算位数 
      printf("The result is:");
      while(length>3) 
      {     d=(length-1)/3;
            i=pow(10,d*3);
            num3=num1/i;//要输出的数字 
            num1=num1%i;//剩余数字 
            printf("%d,",num3);
            length=3*d;//剩余数字的位数 
      }
      printf("%d",num1);//剩最后三位时直接输出 
      system("pause");
      return 0;
 }
