#include<stdio.h>
#include<stdlib.h>
#define OK 1

#define MAXSIZE 12500
//��Ԫ��洢ϡ����� 
typedef struct{
	int i,j;//�÷���Ԫ�����±�����±� 
	int e;//��ֵ 
}Triple,*TriplePtr; 

typedef struct{
	Triple data[MAXSIZE+1];//����Ԫ��Ԫ���data[0]δ�� 
	int mu,nu,tu;//����������������ͷ���Ԫ���� 
}TSMatrix,*TSPtr;

int initial(int a,int b,TSPtr A)//��ʼ�� 
{	A->mu=a;//������ʼ�� 
	A->nu=b;//���� 
	A->tu=0;
	return OK;
}

int enter(int u,int a,int b,int n,TSPtr A)//����洢 
{	A->data[u].i=a;
	A->data[u].j=b;
	A->data[u].e=n;
	return OK;
}



int addMa(TSPtr A,TSPtr B,TSPtr C)//�ӷ� 
{	C->mu=A->mu;//�� 
	C->nu=A->nu;//�� 
	C->tu=A->tu+B->tu;//����Ԫ�ظ��� 
	int ca=1,cb=1,cc=1,count;
	for(count=1;count<=C->tu;count++)
		{	if(ca<=A->tu&&cb>B->tu)//B�з���Ԫ������ 
				{	C->data[cc]=A->data[ca];
					ca++;
					cc++;
				}
		else if(ca>A->tu&&cb<=B->tu)//A�з���Ԫ������ 
				{	C->data[cc]=B->data[cb];
					cb++;
					cc++;
				}
		else if(ca>A->tu&&cb>B->tu)//AB�з���Ԫ�ض��� 
				{	break;
				}
		else //AB�з���Ԫ�ض�û���� 
			{	if(A->data[ca].i<B->data[cb].i)//A����С��B���� 
					{	C->data[cc]=A->data[ca];//A����C 
						ca++;
						cc++;
					}
			else if(A->data[ca].i>B->data[cb].i)//B����С��A���� 
					{	C->data[cc]=B->data[cb];//B����C 
						cb++;
						cc++;
					 } 
			else //A���е���B���� 
					{	if(A->data[ca].j<B->data[cb].j)//A����С��B���� 
							{	C->data[cc]=A->data[ca];//A����C 
								ca++;
								cc++;
							}
					else if(A->data[ca].j>B->data[cb].j)//B����С��A���� 
							{	C->data[cc]=B->data[cb];//B����C 
								cb++;
								cc++;
							}
					else//AB������ȣ�������� 
					{		C->data[cc].i=A->data[ca].i;
							C->data[cc].j=A->data[ca].j;
							C->data[cc].e=B->data[cb].e+A->data[ca].e;
							cc++;
							ca++;
							cb++;
						}	
					}
			}
			if(C->data[cc].e==0)//AB��Ϊ0��Ϊ�෴�� 
			continue;
		 }
		 
		 C->tu=cc; 
	 
}







void output(TSPtr Q)
{	int row,line,count,flag;
	for(row=1;row<=Q->mu;row++)
	{	for(line=1;line<=Q->nu;line++)
			{	flag=0;
				for(count=1;count<=Q->tu;count++)
					if(Q->data[count].i==row&&Q->data[count].j==line)//��Ӧλ������ 
					{	printf("%d ",Q->data[count].e);//��ӡ���� 
						flag=1;
					}
					if(flag==0)
					{	printf("0 ");//�����ӡ0 
					}
				
			}
			printf("\n");
	}
 
	
	
}

main()
{	int i,a1,b1,a2,b2,e,r,l;
	TSPtr Qa,Qb,Qc;
	Qa=(TSPtr)malloc(sizeof(TSMatrix));
	Qb=(TSPtr)malloc(sizeof(TSMatrix));
	Qc=(TSPtr)malloc(sizeof(TSMatrix));
	printf("Qa row:");
	scanf("%d",&a1);
	printf("Qa line:");
	scanf("%d",&b1);//��ȡQa���� 
	initial(a1,b1,Qa);//��ʼ��Qa 
	printf("Please input Qa:\n");
	for(i=1;i<=a1*b1;)//�洢Qa���� 
	{
		
		for(r=1;r<=a1;r++)
			{for(l=1;l<=b1;l++)

				{	scanf("%d",&e);
					if(e!=0)
						 {
						  Qa->tu++;
						 enter(Qa->tu,r,l,e,Qa);
						
						}
				
					i++;
				
				}
			}
	}
	
	
//	output(Qa);
	
	printf("\n\nQb row:");
	scanf("%d",&a2);
	printf("Qb line:");
	scanf("%d",&b2);//��ȡQb���� 
	
	initial(a2,b2,Qb);//��ʼ��Qb 
	printf("Please input Qb:\n");
	for(i=1;i<=a2*b2;)//�洢Qb���� 
	{
		
		for(r=1;r<=a2;r++)
			{for(l=1;l<=b2;l++)
				{	scanf("%d",&e);
					if(e!=0)
						 {
						 Qb->tu++;	
					     enter(Qb->tu,r,l,e,Qb);
						 
						}
				
					i++;
				}
			}
	}
	
	if(Qa->mu==Qb->mu&&Qa->nu==Qb->nu)//�ж�Qa��Qb�Ƿ�������ͬ 
		{	printf("�������\n");
		
			initial(a1,b1,Qc);
			addMa(Qa,Qb,Qc);//������� 
		}
	else 
		{	printf("ERROR!\n");
		}
		
	output(Qc);
	
	system("pause");
	return 0;
	
		
}

