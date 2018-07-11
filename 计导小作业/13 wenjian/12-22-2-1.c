#include<stdio.h>
#include<stdlib.h>
main()
{	FILE *fp1,*fp2;
	char ch1,ch2;
	fp1=fopen("1.c","r");//打开文件1 
	if(fp1==NULL)//若打开失败 
		printf("FILE 1.c count not be opened.\n");
	else
	{	fp2=fopen("2.c","w");//打开文件2 
		if(fp2==NULL)
			printf("FILE 2.c count not be opened.\n");
		else
		{	fscanf(fp1,"%c%c",&ch1,&ch2);//读取文件1 
			
			while((ch1!=EOF)&&(ch2!=EOF))//两个文件都没读取完毕 
			{	if(ch1=='/'&&ch2=='/')//"//"符代表注释 
				{	while(ch1!='\n')//这一整行都是注释 
					{	ch1=fgetc(fp1);// 
					}
					fprintf(fp2,"\n");//换行 
					fscanf(fp1,"%c%c",&ch1,&ch2);//继续读取下一个 
				}
				if((ch1=='/')&&(ch2=='*'))
				{	while(ch1!='*'||ch2!='/')
					{	ch1=ch2;
						ch2=fgetc(fp1);
					}
					fscanf(fp1,"%c%c",&ch1,&ch2);
				}
				else
				{	fprintf(fp2,"%c",ch1); 
					ch1=ch2;
					ch2=fgetc(fp1);
				}//打印非注释区域内容 
			}
			fclose(fp2);//关闭文件 
			fclose(fp1);
		}
	}
	return 0;
	system("pause");
}
