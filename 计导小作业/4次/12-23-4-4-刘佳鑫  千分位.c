#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{     int num,num1,num3,length,i,d;
      printf("Please input an integer:");
      scanf("%d",&num);
      length=0;//����λ������ 
      num1=num;//�����ָ�����һ���� 
      while(num>=1) 
      {     num=num/10;
            length=length+1;
      }//����λ�� 
      printf("The result is:");
      while(length>3) 
      {     d=(length-1)/3;
            i=pow(10,d*3);
            num3=num1/i;//Ҫ��������� 
            num1=num1%i;//ʣ������ 
            printf("%d,",num3);
            length=3*d;//ʣ�����ֵ�λ�� 
      }
      printf("%d",num1);//ʣ�����λʱֱ����� 
      system("pause");
      return 0;
 }
