#include<stdio.h>
#include<stdlib.h>
main()
{	FILE *fp1,*fp2;
	char ch1,ch2;
	fp1=fopen("1.c","r");//���ļ�1 
	if(fp1==NULL)//����ʧ�� 
		printf("FILE 1.c count not be opened.\n");
	else
	{	fp2=fopen("2.c","w");//���ļ�2 
		if(fp2==NULL)
			printf("FILE 2.c count not be opened.\n");
		else
		{	fscanf(fp1,"%c%c",&ch1,&ch2);//��ȡ�ļ�1 
			
			while((ch1!=EOF)&&(ch2!=EOF))//�����ļ���û��ȡ��� 
			{	if(ch1=='/'&&ch2=='/')//"//"������ע�� 
				{	while(ch1!='\n')//��һ���ж���ע�� 
					{	ch1=fgetc(fp1);// 
					}
					fprintf(fp2,"\n");//���� 
					fscanf(fp1,"%c%c",&ch1,&ch2);//������ȡ��һ�� 
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
				}//��ӡ��ע���������� 
			}
			fclose(fp2);//�ر��ļ� 
			fclose(fp1);
		}
	}
	return 0;
	system("pause");
}
