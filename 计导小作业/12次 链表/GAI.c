#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Student{
               char name[20];
               char id[20];
               int score;
               struct Student *next;

               } stu;
stu *AlastPtr,*BlastPtr,*p,*AheadPtr,*BheadPtr;

int selectAtoB()
{   int score=1400;
    int count=0;
	while(AheadPtr->score>=score)
    {     count++;
          if(BlastPtr!=NULL)
            BlastPtr->next=AheadPtr;//把A大于1400的插入到B中 
          else
            BheadPtr=AheadPtr;
          BlastPtr=AheadPtr;//？？？ 
          AheadPtr=AheadPtr->next;//读取下面的 
    }
	p=AheadPtr;
	stu *sPtr=p->next;//处理下一个结点 

    while(sPtr!=NULL)
    { if(sPtr->score>=score)
       	{  count++;
           if(BlastPtr!=NULL)
            BlastPtr->next=sPtr;
           else
            BheadPtr=sPtr;
            BlastPtr=sPtr;
            p->next=sPtr->next;//删除ListA的元素
        }
	  sPtr=sPtr->next;
    }
    BlastPtr->next=NULL;
	return count;
}

void read(char *s)
{ char c;
  while((c=getchar())!='\n')
   *s++=c;
}
main()
{     printf("Please input the information of the students:\n");
	  char Name[20]={0};
     
      int num,flag=0; 
      
      while(flag==0) 
	  {		memset(Name,0,sizeof Name);//清空数组
	  		read(Name); 
        	if(strcmp(Name,"#####")==0)//字符串相同 
        	{ AlastPtr->next=NULL;
          	  num=selectAtoB();      
         	  printf("There are %d students' score highter than 1400.They are:\n",num);
          	  p=BheadPtr;
          	  while(p!=NULL)//遍历ListB 
          	  { printf("Name: %s ID:%s Score:%d\n",p->name,p->id,p->score);
             	stu* q=p;
             	p=p->next;
             	free(q);//输出之后释放ListB该位置 
          	  }
          		p=AheadPtr;
          		while(p!=NULL)
          		{     stu* q=p;
            		  p=p->next;
                  	free(q);
          		}//释放ListA节点占用的空间 
        	break;
        	}
        

        
		p=malloc(sizeof(stu));//创建一个链表A。并读取数据 
        if(p!=NULL)
        {  strcpy(p->name,Name);
           memset(p->id,0,sizeof (p->id));//清空id 
           read(p->id);
           scanf("%d ",&p->score);
           
 
          if(AlastPtr!=NULL)
             AlastPtr->next=p;//把P插到ListA后 
          else
             AheadPtr=p;
          AlastPtr=p;
           
         
         } 

      }
    system("pause");
    return 0;

}
