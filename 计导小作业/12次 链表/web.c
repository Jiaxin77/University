#include<stdio.h>

#include<string.h>

 

//字符串最多字符个数

#define N 25

typedef struct Student

{

    char name[N];

    char id[N];

    int score;

    struct Student *next;

} stu;

 

//p为当前节点，HeadA为ListA的头节点，HeadB为ListB的头节点

//ListA、ListB指向尾节点

stu *ListA,*ListB,*p,*HeadA,*HeadB;

 

//读一行字符串

void read(char *s)

{

    char c;

    while((c=getchar())!='\n')

        *s++=c;

}

 

int solve()

{

 

    //tg为目标值

    //ans为达到tg的人数

    int tg=1400;

    int ans=0;

 

    //先处理前面的节点

    while(HeadA->score>=tg)

    {

        ans++;

 

        //插入到ListB的后面

        if(ListB!=NULL)

            ListB->next=HeadA;

        else

            HeadB=HeadA;

        ListB=HeadA;

 

        //处理下一个

        HeadA=HeadA->next;

    }

 

    /*

    因为删除单链表的元素，是删除当前节点的下一个，即p->next

    所以对第一个不能插入ListB的元素，即现在的HeadA，开始处理nx即它的下一个（看看要不要删除）

    */

    p=HeadA;

    stu *nx=p->next;

    while(nx!=NULL)

    {

        if(nx->score>=tg)

        {

            ans++;

 

            //p插入到ListB的后面

            if(ListB!=NULL)

                ListB->next=nx;

            else

                HeadB=nx;

            ListB=nx;

            p->next=nx->next;//删除ListA的元素

        }

        nx=nx->next;

    }

 

    //ListB最后一个的next设置为NULL（我最后找到的BUG）

    ListB->next=NULL;

    return ans;

}

int main()

{

    printf("Please input the information of the students:\n");

    char s[N];

    while(1)

    {

        //记得要清空数组再读

        memset(s,0,sizeof s);

        read(s);

        if(strcmp(s,"#####")==0)

        {

            //全部读完了，开始处理，把ListA最后一个节点的next置为NULL。

            ListA->next=NULL;

            printf("There are %d students' score highter than 1400.They are:\n",solve());

            p=HeadB;

            while(p!=NULL)

            {

                printf("Name: %s ID:%s Score:%d\n",p->name,p->id,p->score);

                stu* tmp=p;

                p=p->next;

                free(tmp);

            }

            p=HeadA;

            while(p!=NULL)

            {

                stu* tmp=p;

                p=p->next;

                free(tmp);

            }

            break;

        }

 

        //分配空间给当前节点

        p=malloc(sizeof(stu));

        if(p!=NULL)

        {

            strcpy(p->name,s);

            memset(p->id,0,sizeof (p->id));

            read(p->id);

            scanf("%d ",&p->score);

 

            //p插入到ListA的后面

            if(ListA!=NULL)

                ListA->next=p;

            else

                HeadA=p;

            ListA=p;

        }

    }
    system("pause");
    return 0;

}
