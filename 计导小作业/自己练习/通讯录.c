#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
 
typedef struct 
{	char name[20];
	char addr[20];
	char telephone[15];
	char mobile[12];
}data;//存入数据的 

typedef struct 
{	data ListData[Maxsize+1];
	int ListLen;
}listType; //定义顺序表结构 

int addperson(list *SL,int n,data A)//插入节点函数 
{	int i;
	if(SL->ListLen>=Maxsize)//节点超出范围 
		{	printf("顺序表已满，不能插入\n");
			return 0;//未成功插入返回0 
		}
	if(n<1||n>SL->ListLen-1)//节点错误 
		{	printf("插入位置有误\n");
			return 0;
		}
	for(i=SL->ListLen;i>=n;i--)
	{	SL->ListData[i+1]=SL->ListData[i];//待插入节点后的，每个向后移 
	}
	SL->ListData[n]=A;//插入节点 
	SL->ListLen++;//总长度加一 
	return 1; //成功插入返回1 
	
}

int deleteperson(list *SL,int n,data A)
{	int i;
	if(n<1||n>SL->ListLen-1)
		{	printf("插入位置有误\n")；
			return 0; 
		}
	if(SL->ListLen-1<1)
		{	printf("无法删除\n");
			return 0;
		}
	for(i=SL->ListLen;i>=n;i--)
	{	SL->ListData[i]=SL->ListData[i+1];
	}
	SL->ListData[SL->Listen]=NULL;
	SL->ListLen--;
	return 1;
}

int selectperson(list *SL,int n)
{	int i;
	if(n<1||n>SL->ListLen-1)
	{	printf("插入的位置有误\n");
		return 0;
		
	}
	for(i=0;i<=SL->ListLen;i--)
	{	if(strcmp())
	}
}
