#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct LIST {
	int a;
	struct LIST *next;
	}list;
	
void Creatc1c2(list *p1,list *p2);
void Freelist(list *ptr1);
	
list *AlastPtr,*BlastPtr,*C1lastPtr,*C2lastPtr,*AheadPtr,*BheadPtr,*C1headPtr,*C2headPtr,*AcurrentPtr,*BcurrentPtr,*Ptr1,*Ptr2,*C1currentPtr,*C2currentPtr,*Ptr;
 

void Creatc1c2(list *p1,list *p2)
{	while(p1!=NULL&&p2!=NULL)
	{	if(p1->a<p2->a)
		{	C1currentPtr=malloc(sizeof(list));
			C1currentPtr->a=p1->a;
			if(C1lastPtr!=NULL)
		 		C1lastPtr->next=C1currentPtr;
		 	else
		 		C1headPtr=C1currentPtr;
		 	C1lastPtr=C1currentPtr;
		 	
		 	p1=p1->next;
		}
		if(p1->a==p2->a)
		{	C2currentPtr=malloc(sizeof(list));
			C2currentPtr->a=p1->a;
			if(C2currentPtr!=NULL)
				C2lastPtr->next=C2currentPtr;
			else
				C2headPtr=C2currentPtr;
			C2lastPtr=C2currentPtr;
			
			p1=p1->next;
			p2=p2->next;	
			
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
		}
	}
	while(p1!=NULL)
	{		C1currentPtr=malloc(sizeof(list));
			C1currentPtr->a=p1->a;
			if(C1lastPtr!=NULL)
		 		C1lastPtr->next=C1currentPtr;
		 	else
		 		C1headPtr=C1currentPtr;
		 	C1lastPtr=C1currentPtr;
	}
	while(p2!=NULL)
	{		C1currentPtr=malloc(sizeof(list));
			C1currentPtr->a=p2->a;
			if(C1lastPtr!=NULL)
		 		C1lastPtr->next=C1currentPtr;
		 	else
		 		C1headPtr=C1currentPtr;
		 	C1lastPtr=C1currentPtr;
	}
	if(C1lastPtr!=NULL)
		C1lastPtr->next=NULL;
	if(C2lastPtr!=NULL)
		C2lastPtr->next=NULL;
			
	if(C1headPtr==NULL)
		printf("There is no item in C1 list.");
	else
	{	printf("The list C1:");
		while(C1headPtr!=NULL)
		{	Ptr=C1headPtr;
			printf("%d ",Ptr->a);
			C1headPtr=C1headPtr->next;
			free(Ptr);
		}
	}
		
	if(C2headPtr==NULL)
		printf("There is no item in C2 list.");
	else
	{	printf("The list C2:");
		while(C2headPtr!=NULL)
		{	Ptr=C2headPtr;
			printf("%d ",Ptr->a);
			C2headPtr=C2headPtr->next;
			free(Ptr);
		}
	}
}

void Freelist(list *ptr1)
{	while(ptr1!=NULL)
	{	Ptr=ptr1;
		ptr1=ptr1->next;
		free(Ptr);
	}
}


int main()
{	int b;
    printf("Please input the element of list A:");
    scanf("%d",&b);
    while(b!=-1)
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
	if(AlastPtr!=NULL)
		AlastPtr->next=NULL;
	
	printf("Please input the element of list B:");
    scanf("%d",&b);
    while(b!=-1)
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
	if(BlastPtr!=NULL)
		BlastPtr->next=NULL;
	void Creatc1c2(AheadPtr,BheadPtr);	
	void freelist(AheadPtr);
	void freelist(BheadPtr);
	system("pause");
	return 0;	
}


