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
            BlastPtr->next=AheadPtr;//��A����1400�Ĳ��뵽B�� 
          else
            BheadPtr=AheadPtr;
          BlastPtr=AheadPtr;//������ 
          AheadPtr=AheadPtr->next;//��ȡ����� 
    }
	p=AheadPtr;
	stu *sPtr=p->next;//������һ����� 

    while(sPtr!=NULL)
    { if(sPtr->score>=score)
       	{  count++;
           if(BlastPtr!=NULL)
            BlastPtr->next=sPtr;
           else
            BheadPtr=sPtr;
            BlastPtr=sPtr;
            p->next=sPtr->next;//ɾ��ListA��Ԫ��
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
	  {		memset(Name,0,sizeof Name);//�������
	  		read(Name); 
        	if(strcmp(Name,"#####")==0)//�ַ�����ͬ 
        	{ AlastPtr->next=NULL;
          	  num=selectAtoB();      
         	  printf("There are %d students' score highter than 1400.They are:\n",num);
          	  p=BheadPtr;
          	  while(p!=NULL)//����ListB 
          	  { printf("Name: %s ID:%s Score:%d\n",p->name,p->id,p->score);
             	stu* q=p;
             	p=p->next;
             	free(q);//���֮���ͷ�ListB��λ�� 
          	  }
          		p=AheadPtr;
          		while(p!=NULL)
          		{     stu* q=p;
            		  p=p->next;
                  	free(q);
          		}//�ͷ�ListA�ڵ�ռ�õĿռ� 
        	break;
        	}
        

        
		p=malloc(sizeof(stu));//����һ������A������ȡ���� 
        if(p!=NULL)
        {  strcpy(p->name,Name);
           memset(p->id,0,sizeof (p->id));//���id 
           read(p->id);
           scanf("%d ",&p->score);
           
 
          if(AlastPtr!=NULL)
             AlastPtr->next=p;//��P�嵽ListA�� 
          else
             AheadPtr=p;
          AlastPtr=p;
           
         
         } 

      }
    system("pause");
    return 0;

}
