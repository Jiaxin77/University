#include<stdio.h>
#include<stdlib.h>
main()
{	int count,count1,count2,i;
	count=0;
	count1=0;
	count2=0;
	printf("Please input a string:");
	char *word[10000]={NULL};//指针变量初始化 
	char input[10000]={0};
	gets(input);
	word[0]=&input[0];//指针数组保存每个单词的开始位置（0的时候） 
	count++;
	count1++;
	while(input[count]!='\0')
	{	if(input[count]==' ')
		{	word[count1]=&input[count+1];//指针数组保存每个单词的开始位置 
			input[count]='\0';//把空格转换成\0 
			count1++;
		}
		count++;
	}
	word[count]='\0';
	printf("The result is:\n");
	while(word[count2]!='\0')
	{	while(*word[count2]!='\0')
		{	printf("%c",*word[count2]);
			*word[count2]++;
		}//打印结果 
	printf("\n");
	count2++;
	}
	system("pause");
	return 0;
}
	
	

