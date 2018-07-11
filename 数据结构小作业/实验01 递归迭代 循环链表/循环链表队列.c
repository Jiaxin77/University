#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW -1
#define OK 1
#define ERROR 0

/*2. �����Դ�ͷ����ѭ�������ʾ���У�����ֻ��һ��ָ��ָ���βԪ�ؽ�������ͷָ�룬�Ա�д��Ӧ�Ķ��г�ʼ��������С������к��ж϶���״̬���㷨��
�����������㷨�������ĸ�����������ÿһ�������������״̬��
��1)����Ԫ����һ��ӣ�5,7,3,8,55  ״̬��5��Ԫ��
��2)3��Ԫ�س��ӡ�����  ״̬������Ԫ��
    3)�٣���Ԫ�س��ӡ���״̬���ӿ�
��4)�٣���Ԫ�س��ӡ���״̬���ӿգ�ָʾ���磩
*/
 

typedef struct QNode{
	int data;
	struct QNode *next;
}QNode,*QueuePtr; 


QueuePtr p;

typedef struct{
//	QueuePtr front;//����ͷָ��
	QueuePtr rear;//��βָ�� 
	int lenth; //���г��� 
}LinkQueue,*LinkQuPtr;

 

int InitQueue(LinkQuPtr W);
int EnQueue(LinkQuPtr W,int e);
int DeQueue(LinkQuPtr W);
void output(LinkQuPtr W);
 
int InitQueue(LinkQuPtr W)//����һ���ն���Q 
{	W->rear=(QueuePtr)malloc(sizeof(QNode));
	W->rear->next=(QueuePtr)malloc(sizeof(QNode));

	if(!W->rear) exit(OVERFLOW);
	W->rear=W->rear->next; //����βָ��ָ��ͷ��� 
//	(W->rear)->next=NULL;

	W->lenth=0;//���ȹ��� 
	return OK; 
}

int EnQueue(LinkQuPtr W,int e)//����Ԫ��eΪQ���µĶ�βԪ��
{	QNode *j=(QueuePtr)malloc(sizeof(QNode));
	if(!j) exit(OVERFLOW);
	j->data=e;//ֵ����j 
	
	W->rear=j;
	W->lenth++;//���ȼ�һ 
	return OK;
	
 } 
 
 int DeQueue(LinkQuPtr W)
 //�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK��
 //���򷵻�ERROR 
 {	if(W->lenth==0) 
 		return ERROR;
 	QueuePtr p;
 	p=W->rear->next;
 	
 	if(W->rear==p)//ֻʣһ����� 
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
		}//������� 
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
	a=InitQueue(Q);//��ʼ������ 
	if(a==0)
		printf("InitQueue Error!\n");
	else
	{	printf("please input the number you want to save:\n");
		
		count=0;
		
		while(count<5)//������ĿҪ��һ����������� 
		{	scanf("%d",&n); 
			EnQueue(Q,n); 
			
			count++; 
		}//Ԫ��������� 		
		output(Q);
		printf("\n");printf("\n");
		
		count=0;
		printf("3 elements out!\n"); 
		while(count<3)
		{	b=DeQueue(Q);
			
			if(b==1) count++;
			else printf("ERROR!\n");
		}//����Ԫ�س���	
		output(Q);
		printf("\n");printf("\n");
		
		count=0; 
		printf("2 elements out!\n"); 
		while(count<2)
		{	c=DeQueue(Q);
			if(c==1) count++;
			else printf("ERROR!\n");
		}//����Ԫ�س��� 
		output(Q);
		printf("\n");printf("\n");
		
		
		count=0;
		printf("1 element out!\n"); 
		while(count<1)
		{	d=DeQueue(Q);
			if(d==1) count++;
			else if(d==0) {printf("OVERFLOW!\n"); count++;}//ɾ������ERROR����ʾ���� 
			else printf("ERROR!\n");
		}//һ��Ԫ�س���
		output(Q); 
		
		
		
	 } 
	 system("pause");
	 return 0;
}
