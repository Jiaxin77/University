#include<stdio.h>
#include<stdlib.h>

main()
{	int i,j,count,count1,flag,n;
	printf("Please input the first string:");
	char str1[100]={0};//�����ʼ�� 
	gets(str1);//��ȡ��һ������ 
	printf("Please input the second string:");
	char str2[100]={0};
	scanf("%c",&str2[0]);
	n=0;
	count=0;
	while(str2[n]!='\n')
	{	n++;
		scanf("%c",&str2[n]);
		count++;
	}//��ȡ�ڶ������飬��ͳ�������ַ����� 

	j=0;
	i=0;
	count1=0;
	flag=1;
	while(i<100)
	{	while(j<count)
		{	if(str2[j]==str1[i])
			{	flag=1;
				j++;	
			}//����Ӧλ����ͬ��������Ϊ1 
			else
			{	flag=0;
				break;
			}//��Ӧλ����ͬ������Ϊ0��ͬʱ����ѭ�� 
			
			i++;
		}
		
		if((j==count)&&(flag==1))//jѭ���꣬�ҿ���Ϊ1 
		{	count1++;//�ַ���1�������ַ���2++ 
			j=0;
			i=i-count;//�ַ���1�����һλ 
		}
		i++;
		j=0;//�ַ���2��ͷ��ʼ 
	}
	printf("The result is:%d\n",count1);
	system("pause");
	return 0;

 } 
