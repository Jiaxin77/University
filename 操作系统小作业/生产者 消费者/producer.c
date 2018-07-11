#include<stdio.h>
#include<stdlib.h> 

#include<time.h>
#include<windows.h>
#define BUFFER_SIZE 5

typedef int buffer_item;
//二进制信号量或互斥信号量mutex,计数信号量empty,full 

/*the buffer*/
buffer_item buffer[BUFFER_SIZE+1];
buffer_item front=0,rear=0;//环形队列 
HANDLE mutex,empty,full;

int insert_item(buffer_item item)//6.10
{
	/*insert item into buffer return 0 if successful,otherwise return -1*/ 
	if((rear+1)%(BUFFER_SIZE+1)==front)
		return -1;
	buffer[rear]=item;
	rear=(rear+1)%(BUFFER_SIZE+1);
	return 0; 
 
 }
  
 
 int remove_item(buffer_item *item)//6.11
 {
 	/*remove an object from buffer placing it in item,return 0 if successful,otherwise return 0*/
	if(front==rear)
		return -1;
	*item=buffer[front];
	front=(front+1)%(BUFFER_SIZE+1);
	return 0;
 }
 
DWORD WINAPI producer(PVOID Param)
{
	buffer_item rand1;
	int data=*(int*)Param;
	srand((unsigned)time(0));//时间随机
	while(TRUE)
	{
		Sleep((rand()%10)*100);
		WaitForSingleObject(empty,INFINITE);//等空 =wait(empty) 
		WaitForSingleObject(mutex,INFINITE);//互斥锁 =wait(mutex)
		rand1=rand();//生产出rand1 
		printf("producer produced %d \n",rand1);
		if(insert_item(rand1)==-1)
			{
				printf("insert error!\n"); 
			} 
		ReleaseMutex(mutex);//=signal(mutex)
		ReleaseSemaphore(full,1,NULL);//=signal(full)
	 } 
}

DWORD WINAPI consumer(PVOID Param)
{
	buffer_item rand1;
	int data=*(int*)Param;
	srand((unsigned)time(0));
	while(TRUE)
	{
		Sleep((rand()%10)*100);
		WaitForSingleObject(full,INFINITE);//=wait(full)
		WaitForSingleObject(mutex,INFINITE);//=wait(mutex)
		if(remove_item(&rand1)==-1)
			{
				printf("remove data error!\n");
			}
		else
			printf("consumer consumed %d \n",rand1);
		ReleaseMutex(mutex);//=signal(mutex)
		ReleaseSemaphore(empty,1,NULL);//=signal(empty)
	}
}

int main(int argc,char *argv[])
{
	int sleeptime,pnum,snum;
	DWORD *ThreadIdp,*ThreadIds,i;
	int *countp,*counts;
	HANDLE	*ThreadHandleP,*ThreadHandleS;
	/*Get command line arguments argv[1],argv[2],argv[3]*/

	sleeptime=atoi(argv[1]);
	pnum=atoi(argv[2]);
	snum=atoi(argv[3]);
	
	ThreadHandleP=(HANDLE*)malloc(pnum*sizeof(HANDLE));
	ThreadHandleS=(HANDLE*)malloc(snum*sizeof(HANDLE));
	
	ThreadIdp=(DWORD*)malloc(pnum*sizeof(DWORD));
	ThreadIds=(DWORD*)malloc(pnum*sizeof(DWORD));
	
	countp=(int*)malloc((pnum+1)*sizeof(int));
	countp=(int*)malloc((snum+1)*sizeof(int));
	
	mutex=CreateMutex(NULL,FALSE,NULL);
	empty=CreateSemaphore(NULL,BUFFER_SIZE,BUFFER_SIZE,NULL);
	full=CreateSemaphore(NULL,0,BUFFER_SIZE+1,NULL);
	
	/*Create producer threads*/
	for(i=0;i<pnum;i++)
	{
		countp[i+1]=i+1;
		ThreadHandleP[i]=CreateThread(NULL,0,producer,&countp[i+1],0,&ThreadIdp[i]);
	
	}	
	/*Create consumer threads*/
	for(i=0;i<snum;i++)
	{
		counts[i+1]=i+1;
		ThreadHandleS[i]=CreateThread(NULL,0,consumer,&counts[i+1],0,&ThreadIds[i]);
	}
	/*Sleep*/
	Sleep(sleeptime);
	/*Exit*/
	return 0;
}
