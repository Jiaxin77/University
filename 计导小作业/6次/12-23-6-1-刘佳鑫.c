#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int getTriangleNum(int cNum);

int getTriangleNum(int cNum)
{	int a,b,c,count;
	count=0;//���������� 
	
	for(a=1;a<cNum;a++)
		{	for(b=1;b<cNum;b++)
			{	if(a>=b)
				{	for(c=1;c<cNum;c++)
					{	if(b>=c)
						{	if((a+b+c==cNum)&&(a+b>c)&&(a-b<c))//�������ܳ����� 
							{	count=count+1;//��������һ 
							}
						}
					}
				}
			}
		}
	
	return count;
}

main()
{	int cNum,count1,count;
	count=0;
	count1=0;
	scanf("%d",&cNum);
	while(cNum!=0)
	{	count=getTriangleNum(cNum);//���ú��� 
		if(count!=0)
		{	printf("%d,%d\n",cNum,count);
			count1=count1+1;
		}
		scanf("%d",&cNum);//����һ���ַ� 
		if(cNum==-1)//ֱ��-1 
		break;//����ѭ�� 
	}
		if(count1==0)
		{	printf("û������������������\n"); 
		}
		
	
	system("pause");
	return 0;
}
