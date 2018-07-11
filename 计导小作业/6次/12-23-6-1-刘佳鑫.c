#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int getTriangleNum(int cNum);

int getTriangleNum(int cNum)
{	int a,b,c,count;
	count=0;//计数器归零 
	
	for(a=1;a<cNum;a++)
		{	for(b=1;b<cNum;b++)
			{	if(a>=b)
				{	for(c=1;c<cNum;c++)
					{	if(b>=c)
						{	if((a+b+c==cNum)&&(a+b>c)&&(a-b<c))//三角形周长条件 
							{	count=count+1;//计数器加一 
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
	{	count=getTriangleNum(cNum);//调用函数 
		if(count!=0)
		{	printf("%d,%d\n",cNum,count);
			count1=count1+1;
		}
		scanf("%d",&cNum);//读下一个字符 
		if(cNum==-1)//直到-1 
		break;//跳出循环 
	}
		if(count1==0)
		{	printf("没有满足条件的三角形\n"); 
		}
		
	
	system("pause");
	return 0;
}
