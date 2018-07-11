#include<stdio.h>
#include<stdlib.h>
void putS();
struct STUDENT{
               char name[20];
               char number[20];
               int score[5];
               double average;
               int sum;
               }test;//结构 

void putS()
{
     char ch;
     int i;
     scanf("%c",&ch);//读取第一个字符 
     
     for (i=0;ch!='\n';i++)
     {   test.name[i]=ch;
         scanf("%c",&ch);
     }
     test.name[i]='\0';//姓名结束加\0 
     scanf("%s",test.number);//读取学号 
     for (i=0;i<5;i++)
	 scanf("%d",&test.score[i]);//读取分数 
}
     
     
     
     
     
     
   main()
   {    int n,i,m;
        printf("Please inout the number of the students:");
        scanf("%d",&n);
        struct STUDENT a[n];
        char ch1;
        double ave[n];
        int sum[n];
        printf("Please input the students' information:\n");
        scanf("%c",&ch1);//读取\n 
        
        for(i=0;i<n;i++)
        {   putS();//读取数据 
            a[i]=test;//结构数组 
            sum[i]=a[i].score[0]+a[i].score[1]+a[i].score[2]+a[i].score[3]+a[i].score[4];
            ave[i]=sum[i]/5;
            scanf("%c",&ch1);//读取\n 
            
        }
        printf("The students' information:\n");
        for(i=0;i<n;i++)
        {   printf("Name:");
            for(m=0;a[i].name[m]!='\0';m++)
              { printf("%c",a[i].name[m]);}
            printf("\n");
            printf("ID:");
            printf("%s",a[i].number);
            printf("\n");
            printf("Score:");
            for(m=0;m<5;m++)
                printf("%d ",a[i].score[m]);
            printf("\n");
            printf("average:%.2lf total:%d",ave[i],sum[i]);
            printf("\n");
            
        }//打印结果 
        system("pause");
        return 0;
   }
                
