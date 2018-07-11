#include<stdio.h>
#include<stdlib.h>
void Puts();
struct STUDENT{
	char name[20];
	int score;
			}test;//结构 
			
void Puts()
{	int i,j,a,num;
	char ch;
	char ch1[30],ch2[10];
	num=0;
	a=0;
	scanf("%c",&ch);
	for(i=0;ch!='\n';i++)
	{	ch1[i]=ch;
		scanf("%c",&ch);
	}//读取全部字符 
	for(j=0;j<i;j++)
	{	if((ch1[j]>'9')||(ch1[j]==' '))
		{	test.name[a]=ch1[j];
			a++;
		}//把名字提出来 
	}
	test.name[a+1]='\0';
	for(j=0;j<i;j++)
	{	if((ch1[j]>='0')&&(ch1[j]<='9'))
			num=num*10+ch1[j]-'0';
	}//把数字提出来 
	test.score=num;
	
}


main()
{	int n;
	int i,j,k;
	printf("Please input the number of the students:");
	scanf("%d",&n);
	struct STUDENT a[n];
	struct STUDENT b;
	char ch1;
	printf("The name and the total scores are:\n");
	scanf("%c",&ch1);
	for(i=0;i<n;i++)
	{	Puts();
		a[i]=test;
	}//读取 
	
	for(i=0;i<n;i++)
	{	j=0;
		while(j<=i)
			{if(a[i].score>a[j].score)
				{  b=a[i];
				   a[i]=a[j];
				   a[j]=b;
				}//分数高低排序 冒泡 
			if((a[i].score==a[j].score)&&(a[i].name[0]<a[j].name[0]))
				{b=a[i];
				 a[i]=a[j];
				 a[j]=b;
				}//名字ASCII码排序 
				j++;	
		 	}	 
	}
	printf("The students' information:\n");
	for(i=0;i<n;i++)
	{	printf("Name:");
		for(k=0;a[i].name[k+1]!='\0';k++)
			{printf("%c",a[i].name[k]);}
		printf("\ntotal:");
		printf("%d\n",a[i].score);
		printf("\n");
	}//打印结果 
	system("pause");
	return 0;
}
	
		 

