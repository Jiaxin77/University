#include<stdio.h>
#include<stdlib.h>

main()
{	int n,count,count1,count2,count3,i;
	printf("Please input the number of integers:");
	scanf("%d",&n);
	printf("Please input the integers:");
	int original[n];
	int newline[n];
	count=0;
	count1=-1;
	count2=0;
	count3=0;
	while(count<n)
		{	scanf("%d",&original[count]);//��ȡԭ�������� 
			count++;
		}
		
	while(count2<n)
	{	if(original[count2]%2==0) 
		{	count1++;
			newline[count1]=original[count2];
			count2++;
		}//�Ȱ�ż������������ 
		else
			count2++;
	}
	
	count1++;
	while(count1<n)
	{	if(original[count3]%2==1)
		{	newline[count1]=original[count3];
			count3++;
			count1++;
		}//���������������� 
		else
		count3++;
	}
	printf("The elements of the new array are:");
	for(i=0;i<n;i++)
		{	printf("%d ",newline[i]);
		}//��ӡ������ 
	printf("\n");
	system("pause");
	return 0;

}
