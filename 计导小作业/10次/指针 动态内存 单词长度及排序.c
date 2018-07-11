#include<stdio.h>
#include<stdlib.h>

char **readWord(int n);
void sort(char **ptr,int size,int *minlenPtr,int *maxlenPtr);
void output(char **ptr,int size);
void freeMemory(char **ptr,int size);
int mystrlen(char *str);
//定义函数 
main()
{	int n,i;
	int lenth,lenth1;
	char **Word;
	int *minlenPtr=&lenth;//指针调用lenth 
	int *maxlenPtr=&lenth1;
	printf("Please input the number of words:");
	scanf("%d",&n);
	printf("Please input the words: \n"); 
	Word=readWord(n);
	sort(Word,n,minlenPtr,maxlenPtr);
	printf("Min length is %d and max length is %d\n",lenth,lenth1);//输出被赋值的lenth
	printf("After sort，the words are:\n");
	output(Word,n); 
	freeMemory(Word,n);
	system("pause");
	return 0;
		
	
}

char **readWord(int n)
{	int i;
	char **words;
	getchar();//读取回车符，否则系统会认为输入的第一个串会是空串 
	words=malloc(sizeof(char *)*n);//动态内存 
	if(words==NULL)
			printf("指针数组内存分配失败"); 
	else
		{	for(i=0;i<n;i++)
			{	words[i]=malloc(sizeof(char *)*20);//分配动态内存	
				if(words[i]==NULL)
					printf("第%d个字符串内存分配失败",i+1);
				else
					gets(words[i]);//读取字符串 
			}
		}
	return words;
}

int mystrlen(char *str)
{	int count;
	count=0;
	while(str[count]!='\0')
		count++;
	return count;
}

void sort(char **ptr,int size,int *minlenPtr,int *maxlenPtr)
{	int i,j;
	char *a;
	for(i=1;i<size;i++)
	 { 	j=0;
      	 while(j<=i)  
         { 		if(mystrlen(ptr[i])<mystrlen(ptr[j]))  //冒泡排序 
		   		{	a=ptr[i];
           			ptr[i]=ptr[j];
           			ptr[j]=a;
           		}
        		j++;
		 }
	}
	*minlenPtr=mystrlen(ptr[0]);
	*maxlenPtr=mystrlen(ptr[size-1]);
}

void output(char ** ptr,int size)
{	int i;
	for(i=0;i<size;i++)
		printf("%s\n",ptr[i]); 
}

void freeMemory(char ** ptr,int size)
{	int i;
	for(i=0;i<size;i++)
	{	free(ptr[i]);
		ptr[i]=NULL;
	}
	free(ptr);
	ptr=NULL;//释放内存 
}

