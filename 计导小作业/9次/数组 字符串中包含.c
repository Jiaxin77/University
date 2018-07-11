#include<stdio.h>
#include<stdlib.h>

main()
{	int i,j,count,count1,flag,n;
	printf("Please input the first string:");
	char str1[100]={0};//数组初始化 
	gets(str1);//读取第一个数组 
	printf("Please input the second string:");
	char str2[100]={0};
	scanf("%c",&str2[0]);
	n=0;
	count=0;
	while(str2[n]!='\n')
	{	n++;
		scanf("%c",&str2[n]);
		count++;
	}//读取第二个数组，并统计所含字符个数 

	j=0;
	i=0;
	count1=0;
	flag=1;
	while(i<100)
	{	while(j<count)
		{	if(str2[j]==str1[i])
			{	flag=1;
				j++;	
			}//若相应位数相同，开关设为1 
			else
			{	flag=0;
				break;
			}//相应位数不同，开关为0，同时跳出循环 
			
			i++;
		}
		
		if((j==count)&&(flag==1))//j循环完，且开关为1 
		{	count1++;//字符串1中所含字符串2++ 
			j=0;
			i=i-count;//字符串1往后错一位 
		}
		i++;
		j=0;//字符串2从头开始 
	}
	printf("The result is:%d\n",count1);
	system("pause");
	return 0;

 } 
