#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{	char *name[8]={"Alice","Bob","Lucky","Kitty","Tim","Lucy","Jim","Helena"};
	char newName[50]={0},Name;
	char *newline[10]={0};
	int count=0,flag,i,m,n,flag1=0,count1=0;
	int flag3[10]={0};//��������ж� 

	scanf("%c",&Name);
	while(Name!='\n')
	{	newName[count]=Name;
		scanf("%c",&Name);
		count++;
	}
		newline[count1]=&newName[0];//�Ѷ���Ĵ���ָ�������У�������Alice,��ʱnewline[count1]="Alice" 
	for(n=0;n<=count1;n++)
		{	flag=0;
			for(i=0;i<8;i++)
			{	
				 if(strcmp(name[i],newline[count1])==0)	//�ж����ַ�����ͬ������ֱ�ӱȽϣ��� 
					flag3[count1]=1;
			}
		}
			while(flag1==0)
			{
				for(m=0;m<count;m++)
					newName[m]='\0';//���ַ�����գ�ע����'\0'������ֱ��Ϊ0 
				count=0;
				scanf("%c",&Name);
				while(Name!='\n')
				{	newName[count]=Name;
					scanf("%c",&Name);
					count++;
				}
				count1++;
				newline[count1]=&newName[0];
				for(n=0;n<=count1;n++)
				{	flag=0;
					for(i=0;i<8;i++)
					{	if(strcmp(name[i],newline[count1])==0)
							flag3[count1]=1;
			
					}	
				}
				if((newName[0]=='E')&&(newName[1]=='N')&&(newName[2]=='D'))
				flag1=1;
			
			}
		
	
		for(i=0;i<count1;i++)
		{	if(flag3[i]==1)
				printf("NO\n");
			if(flag3[i]==0)
				printf("Yes\n");
		}//��֮ǰ�������������ܱߴ���������Ȼ�޷�����һ�� 
	system("pause");
	return 0;
}
