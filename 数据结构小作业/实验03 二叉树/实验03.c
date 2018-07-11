#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -1



typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;//���Һ���ָ�� 
}BiTNode,*BiTree;

int count=0;

BiTree CreateBiTree(BiTree T)//���������� 
{	char ch;
	scanf("%c",&ch);
	if(ch=='*')
		{T=NULL;
		}
	else
		{
		 
		
		 T=(BiTree)malloc(sizeof(BiTNode));	//�����ڴ� 
		 T->data=ch;
		 //T->lchild=NULL;
		 //T->rchild=NULL;
		 T->lchild=CreateBiTree(T->lchild);// Ҫ��T->lchild������ 
		 T->rchild=CreateBiTree(T->rchild);
		}
	return T; 
}

/*
int Leaves(BiTree T)
{	if(T==NULL)
		return 0;
	else if(T->lchild==NULL&&T->rchild==NULL)
		return 1;
	else
		{	return Leaves(T->lchild)+Leaves(T->rchild);
		}
}*/

void leaf(BiTree Ta)
 {	if(Ta!=NULL)
 	{	if((Ta->lchild==NULL)&&(Ta->rchild==NULL))//���Һ��Ӷ�Ϊ�� 
 		count++;//Ҷ�ӽڵ�����1 
		leaf(Ta->lchild);//���������ӵ� 
		leaf(Ta->rchild);
 	}
 }


void output(BiTree Tb,int depth)//�������� 
{	int i;
	if(Tb!=NULL)
	{
			depth++;//��ȼ�һ 
		for(i=1;i<depth;i++)
			printf("  ");//�����������ո� 
		printf("%c\n",Tb->data);
	if(Tb->lchild!=NULL)
		output(Tb->lchild,depth);
	if(Tb->rchild!=NULL)
		output(Tb->rchild,depth);
	}
}

main()
{	printf("Please input the data:\n");
	int i;
	BiTree Tr;
//	Tr=(BiTree)malloc(sizeof(BiTNode));	
	Tr=CreateBiTree(Tr);
	
	leaf(Tr);//Ҷ�ӽڵ���� 
	printf("Leaves number:%d\n",count);
	output(Tr,0);
	system("pause");
	return 0;
 } 
