#include<stdio.h>
#include<stdlib.h>

#define INFINITY 1000//���ֵ����
#define MAX_VERTEX_NUM 20//��󶥵����
#define ERROR 0
#define OK 1
typedef enum{DG,DN,UDG,UDN}GraphKind; //{����ͼ��������������ͼ��������}


typedef struct{
	char vexs[MAX_VERTEX_NUM];//��������
	int arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ���
	int vexnum,arcnum;//ͼ�ĵ�ǰ�������ͻ���
	GraphKind kind; 
}MGraph,*MGPtr;

typedef struct{
	int stop[MAX_VERTEX_NUM+1]; 
	int ListLen; 
}DisMatrix,*Dis;//���Ա�洢·�� 
 
 
int insert(Dis p,int i,int e)//���Ա��в����� 
 {	int j;
 	if((i<0)||(i>p->ListLen))//i������Ҫ�� 
 		return ERROR;
	for(j=p->ListLen-1;j>=i-1;j--) 
		{	p->stop[j+1]=p->stop[j];}//��������� 
			p->stop[i]=e;//���� 
			p->ListLen++;//���ȼ�һ 
			return OK;
		 
  } 
  
  
  
  int contact(Dis p1,Dis p2,Dis p3)//·������ 
  {	int i=0,j;
  	int flag; 
    int p1count=0,p2count=0;
    for(p1count=0;p1count<p1->ListLen;p1count++)
    	{	p3->stop[p1count]=p1->stop[p1count];
    		i++;
		}//��·��1��P[v][k]���ȴ���Ҫ���µ�·�� 
	while(p2count<p2->ListLen)
		{	flag=0;
			for(j=0;j<p1count;j++)
			{	if(p3->stop[j]==p2->stop[p2count])
					{flag=1;
					}//���·��2(p[k][w])����·��1�ظ��Ĳ��֣����ظ��洢 
			}
			if(flag==0)
				{
				p3->stop[i]=p2->stop[p2count];
				i++;
				}//����·��2���ظ����� 
			p2count++;
					
		}
		p3->ListLen=i;//����·�����Ա��� 

  }
 
void FLOYD(MGPtr G1,int D1 [][MAX_VERTEX_NUM],Dis P1[][MAX_VERTEX_NUM])
	{	int v,w,k;
		int count;
		for(v=0;v<G1->vexnum;v++)
			for(w=0;w<G1->vexnum;w++)
			{	count=0;
				D1[v][w]=G1->arcs[v][w];//���볤�ȿ�ʼΪȨֵ 
				P1[v][w]=(Dis)malloc(sizeof(DisMatrix));
				P1[v][w]->stop[0]=-1;//�����޷���ͨ 
			
				P1[v][w]->ListLen=1;//��ʼ�������ã����������·��ʱ���� 
				// 
				if(D1[v][w]<INFINITY)
					{P1[v][w]->stop[0]=v;
					 P1[v][w]->stop[1]=w;
					 P1[v][w]->ListLen=2; 
					}//��Ȩֵ�ĵط�·��Ԥ�� 
			
			}
		for(k=0;k<G1->vexnum;k++)
			for(v=0;v<G1->vexnum;v++)
				for(w=0;w<G1->vexnum;w++)
					if(D1[v][k]+D1[k][w]<D1[v][w])//���ָ��̾��� 
					{	D1[v][w]=D1[v][k]+D1[k][w];//���볤�ȸ��� 
					//	
						if(P1[v][w]->stop[0]==-1)//�����ʼΪ��������·�� 
							{	P1[v][w]->stop[0]=v;
					 			P1[v][w]->stop[1]=w;
					 			P1[v][w]->ListLen=2; 
								insert(P1[v][w],1,k);
							}
						else{
							
				
						contact(P1[v][k],P1[k][w],P1[v][w]);//·������ 
					}
						//
						 
						//P1[v][w]->stop=P1[v][k]+P1[k][w];
					}
	}
	

	
void Printf(MGPtr G1,int D2[][MAX_VERTEX_NUM],Dis P2[][MAX_VERTEX_NUM])//��ӡ 
{	int v,w,k;
	for(v=0;v<G1->vexnum;v++)
		for(w=0;w<G1->vexnum;w++)
			{if(v!=w&&D2[v][w]<INFINITY)//����ӡ�Լ����Լ��Լ��޷���ͨ�� 
			 {
			 printf("%c��%c�����·����",65+v,65+w);//ת��Ϊ��ĸ 
			 for(k=0;k<=P2[v][w]->ListLen-1;k++)
			 	{printf(" %c ",P2[v][w]->stop[k]+65);
				 }
			 printf("������%d",D2[v][w]);
			 printf("\n");
			}
			}
	}	
 
 
 

 main()
 {	MGPtr G;
 	G=(MGPtr)malloc(sizeof(MGraph));
 	Dis Path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
 	
 	int D[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
 	printf("������ͼ�Ķ�������");
	scanf("%d",&G->vexnum);
	printf("������ͼ�Ļ�����");
	scanf("%d",&G->arcnum);
	printf("�������ڽӾ���\n");
	int i,j;
	//��ȡ�ڽӾ��� 
	for(i=0;i<G->vexnum;i++)
		for(j=0;j<G->vexnum;j++)
		 	{scanf("%d",&G->arcs[i][j]);}
			 

	FLOYD(G,D,Path); 
	Printf(G,D,Path);
	

	system("pause");
	return 0;
 }
