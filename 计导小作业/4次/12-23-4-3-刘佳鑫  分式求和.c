#include<stdio.h>
#include<stdlib.h>
#include<math.h>
main()
{     int n,count;
      double i,j,a,sum,num;
      printf("Please input an integer:");
      scanf("%d",&count);
      i=1; 
      j=1;//Ϊ��ʽ���ɸ���ֵ 
      sum=0;//�͹��� 
      for(n=1;n<=count;n++)//�� ��ʽ����������ѭ�� 
      {   a=j;//�ѳ�ֵ�ȸ�����һ������ 
          j=i+j;//����Ϊ��һ������ĸ֮�� 
          i=a;//��ĸΪ��һ�������� 
          num=j/i;//��ʾ���� 
          sum=sum+num;//����� 
      }
 printf("The result is:%lf",sum);//����� 
 system("pause");
 return 0;
}
