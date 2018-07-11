#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW -1
#define OK 1
#define ERROR 0

/*2. 假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾元素结点而不设头指针，试编写相应的队列初始化、入队列、出队列和判断队列状态的算法。
　利用上述算法完成下面的各操作，并在每一操作后输出队列状态。
　1)下列元素逐一入队：5,7,3,8,55  状态：5个元素
　2)3个元素出队　　　  状态：２个元素
    3)再２个元素出队　　状态：队空
　4)再１个元素出队　　状态：队空（指示下溢）
*/
 

typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*QueuePtr; 


QueuePtr p;

typedef struct{
//	QueuePtr front;//不设头指针
	QueuePtr rear;//队尾指针 
	int lenth; //队列长度 
}LinkQueue,*LinkQuPtr;

 

int InitQueue(LinkQuPtr W);
int EnQueue(LinkQuPtr W,int e);
int DeQueue(LinkQuPtr W);
void output(LinkQuPtr W);
 
int InitQueue(LinkQuPtr W)//构造一个空队列Q 
{	W->rear=(QueuePtr)malloc(sizeof(QNode));
	W->rear->next=(QueuePtr)malloc(sizeof(QNode));

	if(!W->rear) exit(OVERFLOW);
	W->rear=W->rear->next; //将队尾指针指向头结点 
//	(W->rear)->next=NULL;

	W->lenth=0;//长度归零 
	return OK; 
}

int EnQueue(LinkQuPtr W,int e)//插入元素e为Q的新的队尾元素
{	QNode *j=(QueuePtr)malloc(sizeof(QNode));
	if(!j) exit(OVERFLOW);
	j->data=e;//值传入j 
	
	W->rear=j;
	W->lenth++;//长度加一 
	return OK;
	
 } 
 
 int DeQueue(LinkQuPtr W)
 //若队列不空，则删除Q的队头元素，用e返回其值，并返回OK；
 //否则返回ERROR 
 {	if(W->lenth==0) 
 		return ERROR;
 	QueuePtr p;
 	p=W->rear->next;
 	
 	if(W->rear==p)//只剩一个结点 
 	{	W->rear=W->rear->next;
	 	W->rear->next=p->next; 
	 }
	 else 
	 	W->rear->next->next=p->next;
	 W->lenth--;
	 free(p);
	 return OK;
 }
 
 void output(LinkQuPtr W)
 {
 	int count;
 	count=W->lenth;
 	 printf("The queue is:\n");
	 while(count>0)
		{printf("%d ",(W->rear-2*count+2)->data); count--;
		}//输出队列 
		printf("\n");
 	//QNode p;
 	if(W->lenth==0)
 		printf("NULL\n");
 	else
 		printf("have %d elements.\n",W->lenth);

 }
 
 
 

main()
{	LinkQuPtr Q;
	QueuePtr A;
	Q=(LinkQuPtr)malloc(sizeof(LinkQueue)); 
	int a,b,c,d,count,f,l;
	char n;
	a=InitQueue(Q);//初始化队列 
	if(a==0)
		printf("InitQueue Error!\n");
	else
	{	printf("please input the number you want to save:\n");
		
		count=0;
		
		while(count<5)//按照题目要求，一共输入五个数 
		{	scanf("%d",&n); 
			EnQueue(Q,n); 
			
			count++; 
		}//元素依次入队 		
		output(Q);
		printf("\n");printf("\n");
		
		count=0;
		printf("3 elements out!\n"); 
		while(count<3)
		{	b=DeQueue(Q);
			
			if(b==1) count++;
			else printf("ERROR!\n");
		}//三个元素出队	
		output(Q);
		printf("\n");printf("\n");
		
		count=0; 
		printf("2 elements out!\n"); 
		while(count<2)
		{	c=DeQueue(Q);
			if(c==1) count++;
			else printf("ERROR!\n");
		}//两个元素出队 
		output(Q);
		printf("\n");printf("\n");
		
		
		count=0;
		printf("1 element out!\n"); 
		while(count<1)
		{	d=DeQueue(Q);
			if(d==1) count++;
			else if(d==0) {printf("OVERFLOW!\n"); count++;}//删除返回ERROR，提示下溢 
			else printf("ERROR!\n");
		}//一个元素出队
		output(Q); 
		
		
		
	 } 
	 system("pause");
	 return 0;
}
