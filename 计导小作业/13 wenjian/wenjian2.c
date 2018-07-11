#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct commodity
{	int ID;
	char Name[36];
	int num;
	float price;
}com;

double read()
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

void output (FILE *f,int id)
{	int i;
	com a;
    fseek(f,id*sizeof(com),SEEK_SET);
	fread(&a,sizeof(com),1,f);
	printf("商品信息如下:\n");
	printf("记录号（商品ID）   商品名\t\t\t   数量  价格  \n");
	printf("%d %s  %d  %.2f",a.ID,a.Name,a.num,a.price);
	 
}
void output1(FILE *f,int id[],int n)
{
    int i;
    com a[105];
    memset(a,0,sizeof a);
    
    rewind(f);
    fread(a,sizeof(com),100,f);
 
    printf("商品信息如下：\n");
    printf("记录号（商品ID)\t\t商品名\t\t\t\t数量\t价格\n");
 
    for(i=1; i<=n; i++)
        printf("%-10d\t  %-35s\t%-4d\t%-4.2f\n",
               id[i],a[id[i]].Name,a[id[i]].num,a[id[i]].price);
}

void foundRecord(FILE *f)
{	int n;
	FILE *ptr;
	com a[105];
	memset(a,0,sizeof a);//清零 
	for(n=0;n<100;n++)
		 a[n].ID=n;
	rewind(f);//文件指针指向文件头 
	fwrite(a,sizeof(com),100,f);
	if(ptr!=NULL)
		printf("100条空记录创建完毕\n");

}

void inputRecord(FILE *f)
{
	
	
	com a[105];
	memset(a,0,sizeof a);

	rewind(f);
	fread(a,sizeof(com),100,f);
	int m=0,n=0,count=0;
	int ID[101];
	
	while(1)//直到商品ID输入为-1
    {
        printf("请输入商品信息[记录号为-1代表输入结束]：\n商品ID：");
        scanf("%d",&m);
        if(m==-1)
		break;
        printf("商品名：");
        scanf("%s",&a[m].Name);//增加的商品数据存在a数组中。
        printf("数量：");
        scanf("%d",&a[m].num);
        printf("价格：");
        scanf("%f",&a[m].price);
        ID[++count]=m;//增加的商品ID临时存放在ID数组中
    }
	rewind(f);//将指针指向文件开头
    fwrite(a,sizeof(com),100,f);//全部重新写入文件
    output1(f,ID,count);//输出增加的商品信息


}
	


void updateRecord(FILE *f)
{	int n;
	com a[100];
	memset(a,0,sizeof a);
	rewind(f);
	fread(a,sizeof(com),100,f);
	printf("请输入待更新商品ID:\n");
	scanf("%d",&n);
	if(n==-1)
		return;
	if(strlen(a[n].Name)==0)
		printf("对不起，不存在该商品，无法进行更新操作\n");
	else
	{	printf("原商品信息如下：\n");
		output(f,n);
	
		 printf("请输入更新信息[如某项不更新请直接按回车键]：\n");
        printf("商品名：");
 
        char c;
        getchar();
         
        memset(a[n].Name,0,sizeof(a[n].Name));
        int j=0;
        while((c=getchar())!='\n')
            a[n].Name[j++]=c;
 
        double tmp;
 
        printf("数量：");
        tmp=read();
        if(tmp!=-1)
			a[n].num=(int)tmp;
 
        printf("价格：");
        tmp=read();
        if(tmp!=-1)
			a[n].price=tmp;
 
        fseek(f,n*sizeof(com),SEEK_SET);//跳过前面i块位置，因为i是0-99，所以不用i-1
        fwrite(&a[n],sizeof(com),1,f);//新数据写入文件
        printf("更新后");//输出更新后的商品信息
        output(f,n);
		
		
		 
	}
}

void delete(FILE *f)
{	int n;
	com a[100];
	memset(a,0,sizeof a);
	printf("请输入待删除商品ID:\n");
	scanf("%d",&n);
	if(n==-1)
		return;
	if(strlen(a[n].Name)==0)
		printf("对不起，不存在该商品，无法进行删除操作\n");
		else
		{	memset(a[n].Name,0,sizeof(a[n].Name));
			a[n].num=0;
			a[n].price=0;
			fseek(f,n*sizeof(com),SEEK_SET);
			fwrite(&a[n],sizeof(com),1,f);
			printf("删除%d成功\n",n);
		}
}


void OUTPUT(FILE *f)
{	int n;
	com a[100];
	rewind(f);
	fread(a,sizeof(com),100,f);
	printf("商品信息如下：\n");
	printf("记录号（商品ID）   商品名\t\t\t   数量  价格  \n"); 
	for(n=0;n<=100;n++)
	{	if((a[n].num==0)&&(a[n].price==0))
			continue;
		else
		{	printf("%d  %s  %d  %.2f ",a[n].ID,a[n].Name,a[n].num,a[n].price);
			
		}
	}
 } 
 
 
 main()
 {	
 	FILE *f=fopen("commodity.dat","rb+");
 	if(f==NULL)
 		printf("文件打开失败\n");
 	while(1)
 	{	int i;
 		printf("请输入您的选择：\n");
		printf("1--创建一个100条空记录的文件\n2--输入商品记录\n3--更新商品记录\n4--删除商品记录\n5--输出商品记录\n"); 
	 	printf("[选择]");
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

	
