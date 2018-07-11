#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 


clock_t start1,stop1,start2,stop2;
double duration1,duration2;

int MaxSubsequenceSum_one(const int A[],int N)
 {	int ThisSum,MaxSum,i,j,k;
 	MaxSum=0;
 	for(i=0;i<N;i++)
 		for(j=i;j<N;j++)
		 {
 			ThisSum=0;
 			for(k=i;k<=j;k++)
 				ThisSum+=A[k];
 			if(ThisSum>MaxSum)
 				MaxSum=ThisSum;
 				
		 }
		 return MaxSum;
 }
 
 
 int MaxSubsequenceSum_four(const int A[],int N)
 {	int ThisSum,MaxSum,j;
 	ThisSum=MaxSum=0;
	 for(j=0;j<N;j++)
	 {
	 	ThisSum+=A[j];
	 	if(ThisSum>MaxSum)
	 		MaxSum=ThisSum;
	 	else if (ThisSum<0)
	 		ThisSum=0;
	}
	return MaxSum;
	 
 }
 
 




int main()
{	printf("please input MAX:");
	int MAX;
	scanf("%d",&MAX);
	int number[10000]={0};
	int i,k;
	int Sum;
	//生成测试数据集 
	//FILE *fp;
	//fp=fopen("data.txt","a");
	
	for(i=0;i<MAX;i++)
	 	{	number[i]=i-MAX/2;//顺序数组（数据集） 
	    	//fprintf(fp,"%d ",number[i]);
		}
	printf("%d",MAX); 
	//fclose(fp); 
	 	 
	start2=clock(); 
	for(k=0;k<10000;k++)
   	 {
		Sum=MaxSubsequenceSum_four(number,MAX); 
	 }
	stop2=clock();
	printf("\n%d\n",Sum);
	
	duration2=((double)(stop2-start2))/CLK_TCK;
	 
	printf("\ndurationFour:%f",duration2);
	  
	start1=clock(); 
	for(k=0;k<2;k++)
   	 	Sum=MaxSubsequenceSum_one(number,MAX); 
	 
	stop1=clock();
    printf("\n%d\n",Sum);
	duration1=((double)(stop1-start1))/CLK_TCK;
	 
	printf("\ndurationOne:%f",duration1);
	 

	
	system("pause");
	return 1;
 } 
 
 



