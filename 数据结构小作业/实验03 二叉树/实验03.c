#include<stdio.h>
#include<stdlib.h>
#define OVERFLOW -1



typedef struct BiTNode{
	char data;
	struct BiTNode *lchild,*rchild;//左右孩子指针 
}BiTNode,*BiTree;

int count=0;

BiTree CreateBiTree(BiTree T)//创建二叉树 
{	char ch;
	scanf("%c",&ch);
	if(ch=='*')
		{T=NULL;
		}
	else
		{
		 
		
		 T=(BiTree)malloc(sizeof(BiTNode));	//分配内存 
		 T->data=ch;
		 //T->lchild=NULL;
		 //T->rchild=NULL;
		 T->lchild=CreateBiTree(T->lchild);// 要把T->lchild带出来 
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
 	{	if((Ta->lchild==NULL)&&(Ta->rchild==NULL))//左右孩子都为空 
 		count++;//叶子节点数加1 
		leaf(Ta->lchild);//继续求左孩子的 
		leaf(Ta->rchild);
 	}
 }


void output(BiTree Tb,int depth)//凹入表输出 
{	int i;
	if(Tb!=NULL)
	{
			depth++;//深度加一 
		for(i=1;i<depth;i++)
			printf("  ");//根据深度输出空格 
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
	
	leaf(Tr);//叶子节点个数 
	printf("Leaves number:%d\n",count);
	output(Tr,0);
	system("pause");
	return 0;
 } 
