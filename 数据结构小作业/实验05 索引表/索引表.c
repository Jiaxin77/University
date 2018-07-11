#include<stdio.h>
#include<stdlib.h>
#define MAX_SEQ 100 
typedef  struct {
  int maxkey;//子表最大值 
  int stadr;//第一个元素所在位置 
}indexItem,*inPtr;// 索引项

typedef  struct {
  indexItem elem[20];//每块起始位置和最大元素 (0不用)
  int    blocknum;//块的数目 
}indexTable,*TablePtr;//索引表


int Initial(int Seq[MAX_SEQ],TablePtr L,int Bcount,int TotalNum)//初始化索引表 
{	int p,q;
	int i=1;
	int BlockNum;//块的数目 （后面计数用） 
	if(TotalNum%Bcount==0)//求块的数目 
		{	L->blocknum=TotalNum/Bcount;
		 } 
	else
		{	L->blocknum=TotalNum/Bcount+1; 
		}

	BlockNum=1;	
	//标号为0的块不用，设为0,0
	//标号为1的块初始化 
	L->elem[1].stadr=1;
	L->elem[1].maxkey=Seq[0];
	L->elem[0].stadr=0;
	L->elem[0].maxkey=0;
					
		for(p=0;p<=TotalNum;p++)
				{	if(i==1)
						{	
							L->elem[BlockNum].stadr=p+1; //存储初始地址 
						    L->elem[BlockNum].maxkey=Seq[p];//先把该块第一个数设为最大数 
						    
						}
					if(i==Bcount)
						{
						if(L->elem[BlockNum].maxkey<Seq[p])
								{	L->elem[BlockNum].maxkey=Seq[p];
								}//开始没加，会遗漏最后一个数据 
						 i=1;
						 BlockNum++;//开始处理下一块 
						 
						}
					else
						{	if(L->elem[BlockNum].maxkey<Seq[p])
								{	L->elem[BlockNum].maxkey=Seq[p];
								}//找块的最大值 
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

void Find(int Seq[MAX_SEQ],TablePtr L,int AD,int SNum,int B1count)//知道块后，找块中的元素 
{	int count;
	int Num,flag=0;
	Num=L->elem[AD].stadr;//起始位置 
	for(count=Num-1;count<Num-1+B1count;count++)
	//遍历该块元素 （开始NUM忘了-1，所以不会查找第一个元素，因为Num从1开始计，但是Seq从0开始存） 
		{	if(SNum==Seq[count])
			{	printf("找到了！在第%d块中，位置是%d\n",AD,count+1);
				flag=1;
			}
		}
	if(flag==0)//没有找到 
	{	printf("找不到！\n");
	}
}


void Binary(int Seq[MAX_SEQ],TablePtr L,int head,int tail,int Snum,int Bcount)//折半查找 
{	int mid;
	mid=(head+tail)/2;//取中间位置 
	if(mid==0)
		{	printf("找不到\n");
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
			
			//底下的算法不算二分查找 
	
	/*if(Snum>L->elem[mid-1].maxkey&&Snum<=L->elem[mid].maxkey)
	//当所找元素小于等于中间块的Max，且大于 前一块的Max，表示范围在此块中 
		{	
			Find(Seq,L,mid,Snum,Bcount);//调用函数寻找 
			
		 } 
	if(Snum>L->elem[mid].maxkey)//当所找元素大于中间块的Max，表示在这之后的块中 
		{	Binary(Seq,L,mid+1,tail,Snum,Bcount);
		}
	if(Snum<=L->elem[mid-1].maxkey)//小于等于前一块的Max，表示在这之前的块中 
	{	Binary(Seq,L,head,mid,Snum,Bcount);
	}*/
}




main()
{	int numCount,block;
	int i;
	TablePtr LA;
	LA=(TablePtr)malloc(sizeof(indexTable));
	int seq[MAX_SEQ]={0};
	printf("请输入存储的数字个数：");
	scanf("%d",&numCount);
	printf("请输入每块数字个数："); 
	scanf("%d",&block);
	printf("请输入要存储的顺序表：\n");
	for(i=0;i<numCount;i++)
	{	scanf("%d",&seq[i]);
	}
	
   Initial(seq,LA,block,numCount);
   int Findnum;
   while(1)//可以重复查找数字 
   {
   	printf("请输入要查找的数字：");
    scanf("%d",&Findnum);
    Binary(seq,LA,1,LA->blocknum,Findnum,block);
	
 	}
	 
	system("pause");
	return 0; 
}
