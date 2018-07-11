#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LIST {
	int a;
	struct LIST *next;
	}list;
	

	
list *AlastPtr,*BlastPtr,*C1lastPtr,*C2lastPtr,*AheadPtr,*BheadPtr,*C1headPtr,*C2headPtr,*AcurrentPtr,*BcurrentPtr,*Ptr1,*Ptr2,*C1currentPtr,*C2currentPtr,*Ptr,*p1,*p2;
 


int main()
{	int b;
    printf("Please input the element of list A:");
    scanf("%d",&b);
    while(b!=-1)//�����ݴ���list A 
    {	AcurrentPtr=malloc(sizeof(list));
    	if(AcurrentPtr!=NULL)
    	{	AcurrentPtr->a=b;
    		if(AlastPtr!=NULL)
    			AlastPtr->next=AcurrentPtr;
    		else
    			AheadPtr=AcurrentPtr;
    		AlastPtr=AcurrentPtr;
    	}
    	scanf("%d",&b);
	}
	if(AlastPtr!=NULL)//list A ����next��Ϊ�� 
		AlastPtr->next=NULL;
	
	printf("Please input the element of list B:");
    scanf("%d",&b);
    while(b!=-1)//���ݴ���list B 
    {	BcurrentPtr=malloc(sizeof(list));
    	if(BcurrentPtr!=NULL)
    	{	BcurrentPtr->a=b;
    		if(BlastPtr!=NULL)
    			BlastPtr->next=BcurrentPtr;
    		else
    			BheadPtr=BcurrentPtr;
    		BlastPtr=BcurrentPtr;
    	}
    	scanf("%d",&b);
	}
	if(BlastPtr!=NULL)//list B���next��Ϊ�� 
		BlastPtr->next=NULL;
	//����A B���� 
	p1=AheadPtr;
	p2=BheadPtr;
	while(p1!=NULL&&p2!=NULL)
	{	if(p1->a<p2->a)//A��ʱ���ݱ�BС������C1 
		{	C1currentPtr=malloc(sizeof(list));
			C1currentPtr->a=p1->a;
			if(C1lastPtr!=NULL)
		 		C1lastPtr->next=C1currentPtr;
		 	else
		 		C1headPtr=C1currentPtr;
		 	C1lastPtr=C1currentPtr;
		  
		 	p1=p1->next;
		 	continue;
		}
		if(p1->a==p2->a)//A��ʱ���ݵ���B������C2 
		{	C2currentPtr=malloc(sizeof(list));
			C2currentPtr->a=p1->a;
			if(C2lastPtr!=NULL)
				C2lastPtr->next=C2currentPtr;
			else
				C2headPtr=C2currentPtr;
			C2lastPtr=C2currentPtr;
			
			p1=p1->next;
			p2=p2->next;	
			continue;
		}
		if(p1->a>p2->a)
		{	C1currentPtr=malloc(sizeof(list));
			C1currentPtr->a=p2->a;
			if(C1lastPtr!=NULL)
		 		C1lastPtr->next=C1currentPtr;
		 	else
		 		C1headPtr=C1currentPtr;
		 	C1lastPtr=C1currentPtr;
		 	
		 	p2=p2->next;
		 	continue;
		}
	}
	while(p1!=NULL)//��ʣ�µĴ���LIST C1 
	{		C1currentPtr=malloc(sizeof(list));
			C1currentPtr->a=p1->a;
			if(C1lastPtr!=NULL)
		 		C1lastPtr->next=C1currentPtr;
		 	else
		 		C1headPtr=C1currentPtr;
		 	C1lastPtr=C1currentPtr;
		 	p1=p1->next;
	}
	while(p2!=NULL)//��ʣ�µĴ���list C1 
	{		C1currentPtr=malloc(sizeof(list));
			C1currentPtr->a=p2->a;
			if(C1lastPtr!=NULL)
		 		C1lastPtr->next=C1currentPtr;
		 	else
		 		C1headPtr=C1currentPtr;
		 	C1lastPtr=C1currentPtr;
		 	p2=p2->next;
	}
	if(C1lastPtr!=NULL)
		C1lastPtr->next=NULL;
	if(C2lastPtr!=NULL)
		C2lastPtr->next=NULL;
	//C1 C2 ��β��ΪNULL		
	if(C1headPtr==NULL)
		printf("There is no item in C1 list.");
	else
	{	printf("The list C1:");
		while(C1headPtr!=NULL)
		{	Ptr=C1headPtr;
			printf("%d ",Ptr->a);
			C1headPtr=C1headPtr->next;
			free(Ptr);//��������ͬʱ�ͷ��ڴ� 
		}
	}
	printf("\n");	
	if(C2headPtr==NULL)
		printf("There is no item in C2 list.");
	else
	{	printf("The list C2:");
		while(C2headPtr!=NULL)
		{	Ptr=C2headPtr;
			printf("%d ",Ptr->a);
			C2headPtr=C2headPtr->next;
			free(Ptr);//��������ͬʱ�ͷ��ڴ� 
		}
	}	
	
	while(AheadPtr!=NULL)
	{	Ptr=AheadPtr;
		AheadPtr=AheadPtr->next;
		free(Ptr);
	}//�ͷ�list A �ڴ� 
	
	while(BheadPtr!=NULL)
	{	Ptr=BheadPtr;
		BheadPtr=BheadPtr->next;
		free(Ptr);
	}//�ͷ�List B �ڴ� 
	
	system("pause");
	return 0;	
}


