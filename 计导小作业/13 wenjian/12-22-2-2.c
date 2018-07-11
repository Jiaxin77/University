#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct commodity
{	int ID;
	char Name[36];
	int num;
	float price;
}com;//�ռ�¼ 

double read()//��ȡ�ַ�ʱʹ�ã����ǻس�������-1 
{
    double k=10,a=0,ok=0;
    char c;
    while((c=getchar())!='\n')
    {
        ok=1;
        if(isdigit(c))
        {
            if(k==10)
                a=a*k+c-'0';
            else
            {
                a=a+(c-'0')*k;
                k*=0.1;
            }
        }
        else if(c=='.')
            k=0.1;
    };
    if(ok) return a;
    else return -1;
}

void output (FILE *f,int id)//���������Ϣ 
{	int i;
	com a;
    fseek(f,id*sizeof(com),SEEK_SET);
	fread(&a,sizeof(com),1,f);
	printf("��Ʒ��Ϣ����:\n");
	printf("��¼�ţ���ƷID��   ��Ʒ��\t\t\t   ����  �۸�  \n");
	printf("%-10d %-35s  %-4d  %-4.2f",a.ID,a.Name,a.num,a.price);
	 
}
void output1(FILE *f,int id[],int n)//���ѭ����Ϣ 
{
    int i;
    com a[105];
    memset(a,0,sizeof a);
    
    rewind(f);
    fread(a,sizeof(com),100,f);
 
    printf("��Ʒ��Ϣ���£�\n");
    printf("��¼�ţ���ƷID)\t\t��Ʒ��\t\t\t\t����\t�۸�\n");
 
    for(i=1; i<=n; i++)
        printf("%-10d\t  %-35s\t%-4d\t%-4.2f\n",
               id[i],a[id[i]].Name,a[id[i]].num,a[id[i]].price);
}

void foundRecord(FILE *f)//�����ռ�¼ 
{	int n;
	FILE *ptr;
	com a[105];
	memset(a,0,sizeof a);//���� 
	for(n=0;n<100;n++)
		 a[n].ID=n;
	rewind(f);//�ļ�ָ��ָ���ļ�ͷ 
	fwrite(a,sizeof(com),100,f);
	if(ptr!=NULL)
		printf("100���ռ�¼�������\n");

}

void inputRecord(FILE *f)//������Ϣ����Ҫ�����ļ����� 
{
	
	
	com a[105];
	memset(a,0,sizeof a);

	rewind(f);
	fread(a,sizeof(com),100,f);
	int m=0,n=0,count=0;
	int ID[101];
	
	while(1)//������Ʒ��Ϣ 
    {
        printf("��������Ʒ��Ϣ[��¼��Ϊ-1�����������]��\n��ƷID��");
        scanf("%d",&m);
        if(m==-1)
		break;
        printf("��Ʒ����");
        scanf("%s",&a[m].Name);
        printf("������");
        scanf("%d",&a[m].num);
        printf("�۸�");
        scanf("%f",&a[m].price);
        ID[++count]=m;//ID���������� 
    }
	rewind(f);//��ָ��ָ���ļ���ͷ
    fwrite(a,sizeof(com),100,f);
    output1(f,ID,count);//�����Ϣ


}
	


void updateRecord(FILE *f)//������Ϣ 
{	int n;
	com a[100];
	memset(a,0,sizeof a);
	rewind(f);
	fread(a,sizeof(com),100,f);
	printf("�������������ƷID:\n");
	scanf("%d",&n);
	if(n==-1)
		return;
	if(strlen(a[n].Name)==0)
		printf("�Բ��𣬲����ڸ���Ʒ���޷����и��²���\n");
	else
	{	printf("ԭ��Ʒ��Ϣ���£�\n");
		output(f,n);//�����Ϣ 
	
		 printf("�����������Ϣ[��ĳ�������ֱ�Ӱ��س���]��\n");
        printf("��Ʒ����");
 
        char c;
        getchar();
         
        memset(a[n].Name,0,sizeof(a[n].Name));
        int j=0;
        while((c=getchar())!='\n')
            a[n].Name[j++]=c;
 
        double tmp;//��ȡ�ַ��ж��Ƿ��ǻس� 
 
        printf("������");
        tmp=read();
        if(tmp!=-1)
			a[n].num=(int)tmp;//ǿ��ת�� 
 
        printf("�۸�");
        tmp=read();
        if(tmp!=-1)
			a[n].price=tmp;
 
        fseek(f,n*sizeof(com),SEEK_SET);
        fwrite(&a[n],sizeof(com),1,f);//д�������� 
        printf("���º���Ʒ��Ϣ���£�\n");//������º����Ʒ��Ϣ
        output(f,n);
		
		
		 
	}
}

void delete(FILE *f)//ɾ����Ʒ��Ϣ 
{	int n;
	com a[100];
	memset(a,0,sizeof a);
	printf("�������ɾ����ƷID:\n");
	scanf("%d",&n);
	if(n==-1)
		return;
	if(strlen(a[n].Name)==0)
		printf("�Բ��𣬲����ڸ���Ʒ���޷�����ɾ������\n");
		else
		{	memset(a[n].Name,0,sizeof(a[n].Name));
			a[n].num=0;
			a[n].price=0;
			fseek(f,n*sizeof(com),SEEK_SET);
			fwrite(&a[n],sizeof(com),1,f);
			printf("ɾ��%d�ɹ�\n",n);
		}
}


void OUTPUT(FILE *f)//�����Ʒ��Ϣ 
{	int n;
	com a[100];
	rewind(f);
	fread(a,sizeof(com),100,f);
	printf("��Ʒ��Ϣ���£�\n");
	printf("��¼�ţ���ƷID��   ��Ʒ��\t\t\t   ����  �۸�  \n"); 
	for(n=0;n<=100;n++)
	{	if((a[n].num==0)&&(a[n].price==0))
			continue;
		else
		{	printf("%-10d  %-35s  %-4d  %-4.2f ",a[n].ID,a[n].Name,a[n].num,a[n].price);
			
		}
	}
 } 
 
 
 main()
 {	
 	FILE *f=fopen("commodity.dat","rb+");
 	if(f==NULL)
 		printf("�ļ���ʧ��\n");
 	while(1)
 	{	int i;
 		printf("����������ѡ��\n");
		printf("1--����һ��100���ռ�¼���ļ�\n2--������Ʒ��¼\n3--������Ʒ��¼\n4--ɾ����Ʒ��¼\n5--�����Ʒ��¼\n"); 
	 	printf("[ѡ��]");
		scanf("%d",&i);
		if(i==-1)
			break;
		if(i==1)
			foundRecord(f);
		if(i==2)
			inputRecord(f);
		if(i==3)
			updateRecord(f);
		if(i==4)
			delete(f);
		if(i==5)
			OUTPUT(f);
		else continue;
		getchar();
		getchar();
		printf("\n");
	}
	fclose(f);
	system("pause");
	return 0; 
 }

	
