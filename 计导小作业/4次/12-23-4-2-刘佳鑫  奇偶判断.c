#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{     int num,i,odd,even;
      odd=0;//�������������� 
      even=0;//ż������������ 
      printf("Please input an integer:");
      scanf("%d",&num);
      while(num>0)
{          i=num%10;//�����һλ��ʼ�ж� 
           num=num/10;//ȥ�����һλ 
               if(i%2==0)//�ж����һλ��ż 
               {even=even+1;}//��Ϊż����ż����������һ 
               else
               {odd=odd+1;}//��Ϊ������������������һ 
}
     if(even==0)
     {printf("The result is:odd number only!");}//��ż������������Ϊ0����ȫΪ���� 
     else
     {if(odd==0)
        {printf("The result is:even number only!");}//����������������Ϊ0����ȫΪż�� 
     else
        {printf("The result is:both!");}//����ż����������Ϊ0����ȫ�� 
     }
     system("pause");
     return 0;
}
