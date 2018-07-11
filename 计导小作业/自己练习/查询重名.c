#include<stdio.h>
#include<stdlib.h>
#include<string.h>
main()
{	char *name[8]={"Alice","Bob","Lucky","Kitty","Tim","Lucy","Jim","Helena"};
	char newName[50]={0},Name;
	char *newline[10]={0};
	int count=0,flag,i,m,n,flag1=0,count1=0;
	int flag3[10]={0};//用于最后判断 

	scanf("%c",&Name);
	while(Name!='\n')
	{	newName[count]=Name;
		scanf("%c",&Name);
		count++;
	}
		newline[count1]=&newName[0];//把读入的存入指针数组中，若输入Alice,此时newline[count1]="Alice" 
	for(n=0;n<=count1;n++)
		{	flag=0;
			for(i=0;i<8;i++)
			{	
				 if(strcmp(name[i],newline[count1])==0)	//判断两字符串相同，不能直接比较！！ 
					flag3[count1]=1;
			}
		}
			while(flag1==0)
			{
				for(m=0;m<count;m++)
					newName[m]='\0';//把字符串清空，注意是'\0'，不是直接为0 
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
		}//用之前存的来输出，不能边存边输出，不然无法读下一个 
	system("pause");
	return 0;
}
