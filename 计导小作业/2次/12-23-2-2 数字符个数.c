#include<stdio.h>
#include<stdlib.h>
main()
{     
      int ch,sp,num,other;
      ch=0;
      sp=0;
      num=0;
      other=0;/*����ֵ*/ 
      char c;

      printf("Please input a string:");
      while((c=getchar())!='\n')/*ѭ����ȡ*/ 
      {if((c>='a')&&(c<='z')||(c>='A')&&(c<='Z'))/*�ж��Ƿ�ΪӢ����ĸ*/ 
      ch++ ;/*Ӣ�ļ�������һ*/
      else
      {if(c==32)/*�ж��Ƿ�Ϊ�ո�*/ 
      sp++;/*�ո��������һ*/ 
      else
      {if((c>='0')&&(c<='9'))/*�ж��Ƿ�Ϊ����*/ 
      num++;/*���ּ�������һ*/ 
      else
      other++;/*�����ַ���������һ*/ 
      }}}
      printf("The number of English characters,spaces,numbers,other characters are:%d,%d,%d,%d",ch,sp,num,other);
      system("pause");
return 0;

}
