#include<stdio.h>
#include<stdlib.h>
void InsertSort(int a[],int n);  //����������//

main()
{	int n,count;
	printf("Please input the number of intergers:");
	scanf("%d",&n);
	printf("Please input the integers:");
	count=0;
	int line[1000]={0};//�����ʼ�� 
	while(count<n)
	{	scanf("%d",&line[count]);
		count++;
	}//��ȡ���ִ������� 
	printf("The result is:");
	InsertSort(line,n);//���ú��� 
	printf("\n");
	system("pause");
	return 0;
}

void InsertSort(int a[],int n)
{  int i,j,num,count;
   for(i=1;i<n;i++)  
     { 	j=0;
      	 while(j<=i)  
         { 		if(a[i]<a[j])  //�Ƚϵ�i��������֮ǰ���� 
		   		{	num=a[i];
           			a[i]=a[j];
           			a[j]=num;
           		}//��С�ڣ�����λ�� 
        		j++;
		 }
     	
	 }
	for(count=0;count<n;count++)
	{	printf("%d ",a[count]);//��������� 
	}
}
