#include<stdio.h>

#include<stdlib.h>

int mystrlen(char str[]);
void mystrcat(char str1[],char str2[]);

int mystrlen(char str[])
{	int count;
	count=0;
	while(str[count+1]!='\0')
	{	count++;
	}
	return count;
}

void mystrcat(char str1[],char str2[])
{	int count,count1,a;
	count=0;
	count1=0;
	while(str1[count]!='\0')	
		count++;
	str1[count]=' ';//�ַ���1��2֮��ӿո� 
	count=count+1;
	while(str2[count1]!='\0')
	{	str1[count]=str2[count1];//���ַ���2�����ַ���1���� 
		count++;
		count1++;
	}
	str1[count]='\0';
	printf("%s\n",str1);
}

main()
{	char s1[500]={0};//�����ʼ�� 
	char s2[500]={0};//�����ʼ�� 
	int flag;
	printf("Please input the flag:");
	scanf("%d",&flag);
	if(flag==1)
	{	int num,i;
		char ch;
		i=0;	
		printf("Please input the string:");
		fflush(stdin);
		scanf("%c",&s1[i]);
		while(ch!='\n')
		{	i++;
			scanf("%c",&ch);
			s1[i]=ch;
		}//����gets��ȡ�ַ���������\n���������� 
		num=mystrlen(s1);
		printf("The result is:%d\n",num);
	}
	
	if(flag==4)
	{	fflush(stdin);//ȥ���س���gets��ȡ��ȷ�ַ��� 
		printf("Please input the string1:");
		gets(s1);
		fflush(stdin);
		printf("Please input the string2:");
		gets(s2);
		printf("The result is:");
	    mystrcat(s1,s2);//���ú��� 
	}
	system("pause");
	return 0;
}


