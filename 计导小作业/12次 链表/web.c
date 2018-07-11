#include<stdio.h>

#include<string.h>

 

//�ַ�������ַ�����

#define N 25

typedef struct Student

{

    char name[N];

    char id[N];

    int score;

    struct Student *next;

} stu;

 

//pΪ��ǰ�ڵ㣬HeadAΪListA��ͷ�ڵ㣬HeadBΪListB��ͷ�ڵ�

//ListA��ListBָ��β�ڵ�

stu *ListA,*ListB,*p,*HeadA,*HeadB;

 

//��һ���ַ���

void read(char *s)

{

    char c;

    while((c=getchar())!='\n')

        *s++=c;

}

 

int solve()

{

 

    //tgΪĿ��ֵ

    //ansΪ�ﵽtg������

    int tg=1400;

    int ans=0;

 

    //�ȴ���ǰ��Ľڵ�

    while(HeadA->score>=tg)

    {

        ans++;

 

        //���뵽ListB�ĺ���

        if(ListB!=NULL)

            ListB->next=HeadA;

        else

            HeadB=HeadA;

        ListB=HeadA;

 

        //������һ��

        HeadA=HeadA->next;

    }

 

    /*

    ��Ϊɾ���������Ԫ�أ���ɾ����ǰ�ڵ����һ������p->next

    ���ԶԵ�һ�����ܲ���ListB��Ԫ�أ������ڵ�HeadA����ʼ����nx��������һ��������Ҫ��Ҫɾ����

    */

    p=HeadA;

    stu *nx=p->next;

    while(nx!=NULL)

    {

        if(nx->score>=tg)

        {

            ans++;

 

            //p���뵽ListB�ĺ���

            if(ListB!=NULL)

                ListB->next=nx;

            else

                HeadB=nx;

            ListB=nx;

            p->next=nx->next;//ɾ��ListA��Ԫ��

        }

        nx=nx->next;

    }

 

    //ListB���һ����next����ΪNULL��������ҵ���BUG��

    ListB->next=NULL;

    return ans;

}

int main()

{

    printf("Please input the information of the students:\n");

    char s[N];

    while(1)

    {

        //�ǵ�Ҫ��������ٶ�

        memset(s,0,sizeof s);

        read(s);

        if(strcmp(s,"#####")==0)

        {

            //ȫ�������ˣ���ʼ������ListA���һ���ڵ��next��ΪNULL��

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

 

        //����ռ����ǰ�ڵ�

        p=malloc(sizeof(stu));

        if(p!=NULL)

        {

            strcpy(p->name,s);

            memset(p->id,0,sizeof (p->id));

            read(p->id);

            scanf("%d ",&p->score);

 

            //p���뵽ListA�ĺ���

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
