#include<stdio.h>
#include<stdlib.h>
void RecurSelectSort(int a[],int n,int x,int max);

void RecurSelectSort(int a[],int n,int x,int max)
{	if(x==(n-1))//ֹͣ�ݹ飬��ӡ��� 
	{	int count;
		for(count=n-1;count>=0;count--)
		{	printf("%d ",a[count]);
		}
	}
	else
	{	int i,num,flag;
		for(i=x;i<n;i++)
		{	if(a[i]>=a[max])
			{max=i;
			}//������������ֵ 
		}
		
		num=a[x];
		a[x]=a[max];
		a[max]=num;//���� 
		if(x==max)
		{	max=x+1; 
		}//���պô���Ϊ���ֵ��������һ�����ֵΪ��һ���� 
	}
		return RecurSelectSort(a,n,x+1,max);//�ı�x��ֵ�����غ��� 
}
	

main()
{	int count,x,max,n;
	printf("Please input the number of intergers:");
	scanf("%d",&n);
	int line[1000]={0};//�����ʼ�� 
	printf("Please input the integers:");
	for(count=0;count<n;count++)
	{	scanf("%d",&line[count]);
	}//�������� 
	x=0;
	max=0;
	printf("The result is:");
	RecurSelectSort(line,n,x,max);//���ú��� 
	printf("\n");
	system("pause");
	return 0;
}


