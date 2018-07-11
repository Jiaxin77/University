#include<stdio.h>
#include<stdlib.h>
#define MAX_SEQ 100 
typedef  struct {
  int maxkey;//�ӱ����ֵ 
  int stadr;//��һ��Ԫ������λ�� 
}indexItem,*inPtr;// ������

typedef  struct {
  indexItem elem[20];//ÿ����ʼλ�ú����Ԫ�� (0����)
  int    blocknum;//�����Ŀ 
}indexTable,*TablePtr;//������


int Initial(int Seq[MAX_SEQ],TablePtr L,int Bcount,int TotalNum)//��ʼ�������� 
{	int p,q;
	int i=1;
	int BlockNum;//�����Ŀ ����������ã� 
	if(TotalNum%Bcount==0)//������Ŀ 
		{	L->blocknum=TotalNum/Bcount;
		 } 
	else
		{	L->blocknum=TotalNum/Bcount+1; 
		}

	BlockNum=1;	
	//���Ϊ0�Ŀ鲻�ã���Ϊ0,0
	//���Ϊ1�Ŀ��ʼ�� 
	L->elem[1].stadr=1;
	L->elem[1].maxkey=Seq[0];
	L->elem[0].stadr=0;
	L->elem[0].maxkey=0;
					
		for(p=0;p<=TotalNum;p++)
				{	if(i==1)
						{	
							L->elem[BlockNum].stadr=p+1; //�洢��ʼ��ַ 
						    L->elem[BlockNum].maxkey=Seq[p];//�ȰѸÿ��һ������Ϊ����� 
						    
						}
					if(i==Bcount)
						{
						if(L->elem[BlockNum].maxkey<Seq[p])
								{	L->elem[BlockNum].maxkey=Seq[p];
								}//��ʼû�ӣ�����©���һ������ 
						 i=1;
						 BlockNum++;//��ʼ������һ�� 
						 
						}
					else
						{	if(L->elem[BlockNum].maxkey<Seq[p])
								{	L->elem[BlockNum].maxkey=Seq[p];
								}//�ҿ�����ֵ 
							i++;
						}
				
				}
	printf("\n");
	/*printf("%d  ",L->blocknum);
	printf("%d",BlockNum);
	for(i=1;i<=L->blocknum;i++)
	{	printf("\ni->Maxkey=%d  i->Stadr=%d \n",L->elem[i].maxkey,L->elem[i].stadr);
	      
	}*/
	
	
	
}	

void Find(int Seq[MAX_SEQ],TablePtr L,int AD,int SNum,int B1count)//֪������ҿ��е�Ԫ�� 
{	int count;
	int Num,flag=0;
	Num=L->elem[AD].stadr;//��ʼλ�� 
	for(count=Num-1;count<Num-1+B1count;count++)
	//�����ÿ�Ԫ�� ����ʼNUM����-1�����Բ�����ҵ�һ��Ԫ�أ���ΪNum��1��ʼ�ƣ�����Seq��0��ʼ�棩 
		{	if(SNum==Seq[count])
			{	printf("�ҵ��ˣ��ڵ�%d���У�λ����%d\n",AD,count+1);
				flag=1;
			}
		}
	if(flag==0)//û���ҵ� 
	{	printf("�Ҳ�����\n");
	}
}


void Binary(int Seq[MAX_SEQ],TablePtr L,int head,int tail,int Snum,int Bcount)//�۰���� 
{	int mid;
	mid=(head+tail)/2;//ȡ�м�λ�� 
	if(mid==0)
		{	printf("�Ҳ���\n");
		}
	
	if(head<tail)
	{	if(Snum<L->elem[mid].maxkey)
			Binary(Seq,L,head,mid,Snum,Bcount);
		else if(Snum>L->elem[mid].maxkey)
			Binary(Seq,L,mid+1,tail,Snum,Bcount);
		else
			Find(Seq,L,mid,Snum,Bcount);
			
	}
		else
			Find(Seq,L,head,Snum,Bcount);
			
			//���µ��㷨������ֲ��� 
	
	/*if(Snum>L->elem[mid-1].maxkey&&Snum<=L->elem[mid].maxkey)
	//������Ԫ��С�ڵ����м���Max���Ҵ��� ǰһ���Max����ʾ��Χ�ڴ˿��� 
		{	
			Find(Seq,L,mid,Snum,Bcount);//���ú���Ѱ�� 
			
		 } 
	if(Snum>L->elem[mid].maxkey)//������Ԫ�ش����м���Max����ʾ����֮��Ŀ��� 
		{	Binary(Seq,L,mid+1,tail,Snum,Bcount);
		}
	if(Snum<=L->elem[mid-1].maxkey)//С�ڵ���ǰһ���Max����ʾ����֮ǰ�Ŀ��� 
	{	Binary(Seq,L,head,mid,Snum,Bcount);
	}*/
}




main()
{	int numCount,block;
	int i;
	TablePtr LA;
	LA=(TablePtr)malloc(sizeof(indexTable));
	int seq[MAX_SEQ]={0};
	printf("������洢�����ָ�����");
	scanf("%d",&numCount);
	printf("������ÿ�����ָ�����"); 
	scanf("%d",&block);
	printf("������Ҫ�洢��˳���\n");
	for(i=0;i<numCount;i++)
	{	scanf("%d",&seq[i]);
	}
	
   Initial(seq,LA,block,numCount);
   int Findnum;
   while(1)//�����ظ��������� 
   {
   	printf("������Ҫ���ҵ����֣�");
    scanf("%d",&Findnum);
    Binary(seq,LA,1,LA->blocknum,Findnum,block);
	
 	}
	 
	system("pause");
	return 0; 
}
