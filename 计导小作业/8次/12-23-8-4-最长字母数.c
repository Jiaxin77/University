#include<stdio.h>
#include<stdlib.h>

main()
{	char c;
	int count,count1,num;
	int wordNum[100]={0};
	printf("Please input the string:");
	scanf("%c",&c);
	count=0;
	count1=0;
	while(c!='.')
	{	
		while((c!=' ')&&(c!='.'))
		{	wordNum[count]++;//������ĸ����+1 
			scanf("%c",&c);//��ȡ�ַ� 
		}
		count++;
		
		if(c=='.')
			break;
		else
		scanf("%c",&c);
	}
	num=wordNum[0];
	while(count1<=count)
	{	if(num<wordNum[count1])
		{	num=wordNum[count1];
		}//�Ƚϴ�С 
		count1++; 
	}
	printf("The longest word's digits are:%d",num);
	system("pause");
	return 0;
}
