#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{     int num,i,odd,even;
      odd=0;//奇数计数器归零 
      even=0;//偶数计数器归零 
      printf("Please input an integer:");
      scanf("%d",&num);
      while(num>0)
{          i=num%10;//从最后一位开始判断 
           num=num/10;//去掉最后一位 
               if(i%2==0)//判断最后一位奇偶 
               {even=even+1;}//若为偶数，偶数计数器加一 
               else
               {odd=odd+1;}//若为奇数，奇数计数器加一 
}
     if(even==0)
     {printf("The result is:odd number only!");}//若偶数计数器最终为0，则全为奇数 
     else
     {if(odd==0)
        {printf("The result is:even number only!");}//若奇数计数器最终为0，则全为偶数 
     else
        {printf("The result is:both!");}//若奇偶计数器都不为0，则全有 
     }
     system("pause");
     return 0;
}
