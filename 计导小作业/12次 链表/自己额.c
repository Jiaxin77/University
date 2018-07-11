#include<stdio.h>
#include<stdlib.h>

struct student{
               char name[20];
               char num[20];
               int score;
               struct student*nextPtr;
               }stu;
main()
{     struct student *ptr;
      char name[20];
      printf("Please input the information of the students:\n");
      gets(name);
      
      
      
Create ListA() 
{      char name[20];
       student headptr=NULL,currentptr=NULL,lastptr=NULL:
       while(strcmp(name,"####")!=0)
       {    currentptr=malloc(sizeof(struct student));
            if(currentptr!=NULL)      
            {  strcpy(currentptr->name);
               gets(currentptr->num);
               gets(currentptr->score);
               if(headptr==NULL)
                 { headptr=currentptr;
                   lastptr=currentptr;}
               else
               {lastptr->nextptr=currentptr;
               lastptr=currentptr;}
               gets(name);
       }
       lastptr->nextptr=NULL;
       return headptr;
}

void insertListB(struct student *sPtr)
{    struct student newPtr=NULL,previousPtr=NULL,currentPtr=NULL;
     newPtr=malloc(sizeof(struct student));
     if(newPtr!=NULL)
     
               
               
Find(struct student currentptr,int Score)
{    
     while(currentptr!=NULL&&currentptr->score<Score)
     {     currentptr=currentptr->nextptr;}
     return currentptr;
}
     
            

       
      
      

      
