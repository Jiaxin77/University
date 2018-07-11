#include<stdio.h>
#include<stdlib.h>
#define OK 1

#define MAXSIZE 12500
//三元组存储稀疏矩阵 
typedef struct{
	int i,j;//该非零元的行下标和列下标 
	int e;//数值 
}Triple,*TriplePtr; 

typedef struct{
	Triple data[MAXSIZE+1];//非零元三元组表，data[0]未用 
	int mu,nu,tu;//矩阵的行数、列数和非零元个数 
}TSMatrix,*TSPtr;

int initial(int a,int b,TSPtr A)//初始化 
{	A->mu=a;//行数初始化 
	A->nu=b;//列数 
	A->tu=0;
	return OK;
}

int enter(int u,int a,int b,int n,TSPtr A)//输入存储 
{	A->data[u].i=a;
	A->data[u].j=b;
	A->data[u].e=n;
	return OK;
}



int addMa(TSPtr A,TSPtr B,TSPtr C)//加法 
{	C->mu=A->mu;//行 
	C->nu=A->nu;//列 
	C->tu=A->tu+B->tu;//非零元素个数 
	int ca=1,cb=1,cc=1,count;
	for(count=1;count<=C->tu;count++)
		{	if(ca<=A->tu&&cb>B->tu)//B中非零元素先完 
				{	C->data[cc]=A->data[ca];
					ca++;
					cc++;
				}
		else if(ca>A->tu&&cb<=B->tu)//A中非零元素先完 
				{	C->data[cc]=B->data[cb];
					cb++;
					cc++;
				}
		else if(ca>A->tu&&cb>B->tu)//AB中非零元素都完 
				{	break;
				}
		else //AB中非零元素都没有完 
			{	if(A->data[ca].i<B->data[cb].i)//A的行小于B的行 
					{	C->data[cc]=A->data[ca];//A传入C 
						ca++;
						cc++;
					}
			else if(A->data[ca].i>B->data[cb].i)//B的行小于A的行 
					{	C->data[cc]=B->data[cb];//B传入C 
						cb++;
						cc++;
					 } 
			else //A的行等于B的行 
					{	if(A->data[ca].j<B->data[cb].j)//A的列小于B的列 
							{	C->data[cc]=A->data[ca];//A传入C 
								ca++;
								cc++;
							}
					else if(A->data[ca].j>B->data[cb].j)//B的列小于A的列 
							{	C->data[cc]=B->data[cb];//B传入C 
								cb++;
								cc++;
							}
					else//AB行列相等，进行相加 
					{		C->data[cc].i=A->data[ca].i;
							C->data[cc].j=A->data[ca].j;
							C->data[cc].e=B->data[cb].e+A->data[ca].e;
							cc++;
							ca++;
							cb++;
						}	
					}
			}
			if(C->data[cc].e==0)//AB都为0或为相反数 
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
					if(Q->data[count].i==row&&Q->data[count].j==line)//对应位置有数 
					{	printf("%d ",Q->data[count].e);//打印数据 
						flag=1;
					}
					if(flag==0)
					{	printf("0 ");//否则打印0 
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
	scanf("%d",&b1);//读取Qa行列 
	initial(a1,b1,Qa);//初始化Qa 
	printf("Please input Qa:\n");
	for(i=1;i<=a1*b1;)//存储Qa矩阵 
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
	scanf("%d",&b2);//读取Qb行列 
	
	initial(a2,b2,Qb);//初始化Qb 
	printf("Please input Qb:\n");
	for(i=1;i<=a2*b2;)//存储Qb矩阵 
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
	
	if(Qa->mu==Qb->mu&&Qa->nu==Qb->nu)//判断Qa，Qb是否行列相同 
		{	printf("可以相加\n");
		
			initial(a1,b1,Qc);
			addMa(Qa,Qb,Qc);//相加运算 
		}
	else 
		{	printf("ERROR!\n");
		}
		
	output(Qc);
	
	system("pause");
	return 0;
	
		
}

