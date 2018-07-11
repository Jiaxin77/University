#include<stdio.h>
#include<stdlib.h>
main()
{     
      int ch,sp,num,other;
      ch=0;
      sp=0;
      num=0;
      other=0;/*赋初值*/ 
      char c;

      printf("Please input a string:");
      while((c=getchar())!='\n')/*循环读取*/ 
      {if((c>='a')&&(c<='z')||(c>='A')&&(c<='Z'))/*判断是否为英文字母*/ 
      ch++ ;/*英文计数器加一*/
      else
      {if(c==32)/*判断是否为空格*/ 
      sp++;/*空格计数器加一*/ 
      else
      {if((c>='0')&&(c<='9'))/*判断是否为数字*/ 
      num++;/*数字计数器加一*/ 
      else
      other++;/*其他字符计数器加一*/ 
      }}}
      printf("The number of English characters,spaces,numbers,other characters are:%d,%d,%d,%d",ch,sp,num,other);
      system("pause");
return 0;

}
