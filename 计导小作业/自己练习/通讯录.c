#include<stdio.h>
#include<stdlib.h>
#define Maxsize 100
 
typedef struct 
{	char name[20];
	char addr[20];
	char telephone[15];
	char mobile[12];
}data;//�������ݵ� 

typedef struct 
{	data ListData[Maxsize+1];
	int ListLen;
}listType; //����˳���ṹ 

int addperson(list *SL,int n,data A)//����ڵ㺯�� 
{	int i;
	if(SL->ListLen>=Maxsize)//�ڵ㳬����Χ 
		{	printf("˳������������ܲ���\n");
			return 0;//δ�ɹ����뷵��0 
		}
	if(n<1||n>SL->ListLen-1)//�ڵ���� 
		{	printf("����λ������\n");
			return 0;
		}
	for(i=SL->ListLen;i>=n;i--)
	{	SL->ListData[i+1]=SL->ListData[i];//������ڵ��ģ�ÿ������� 
	}
	SL->ListData[n]=A;//����ڵ� 
	SL->ListLen++;//�ܳ��ȼ�һ 
	return 1; //�ɹ����뷵��1 
	
}

int deleteperson(list *SL,int n,data A)
{	int i;
	if(n<1||n>SL->ListLen-1)
		{	printf("����λ������\n")��
			return 0; 
		}
	if(SL->ListLen-1<1)
		{	printf("�޷�ɾ��\n");
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
	{	printf("�����λ������\n");
		return 0;
		
	}
	for(i=0;i<=SL->ListLen;i--)
	{	if(strcmp())
	}
}
