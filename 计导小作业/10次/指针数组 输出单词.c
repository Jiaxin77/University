#include<stdio.h>
#include<stdlib.h>
main()
{	int count,count1,count2,i;
	count=0;
	count1=0;
	count2=0;
	printf("Please input a string:");
	char *word[10000]={NULL};//ָ�������ʼ�� 
	char input[10000]={0};
	gets(input);
	word[0]=&input[0];//ָ�����鱣��ÿ�����ʵĿ�ʼλ�ã�0��ʱ�� 
	count++;
	count1++;
	while(input[count]!='\0')
	{	if(input[count]==' ')
		{	word[count1]=&input[count+1];//ָ�����鱣��ÿ�����ʵĿ�ʼλ�� 
			input[count]='\0';//�ѿո�ת����\0 
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
		}//��ӡ��� 
	printf("\n");
	count2++;
	}
	system("pause");
	return 0;
}
	
	

