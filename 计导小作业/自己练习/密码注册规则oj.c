#include<stdio.h>




main()
{	int flag[100]={0};//Ҫ���ö��٣�����10���ܹ� 
	
	char password[50]={0};
	char word;
	int count=0,count1=0,count2=0,a=0,b=0,c=0,d=0,i,flag1=0;
	scanf("%c",&word);
	while(word!='\n')
	{	password[count]=word;
		count++;
		scanf("%c",&word);
	}
	
	if((password[0]=='E')&&(password[1]=='N')&&(password[2]=='D'))
				flag1=1;//��Ҫ������������棬��Ȼ���ж�END 
	while(flag1==0)
	{
		
		if(count<8)
			flag[count1]=1;
		else
		{	for(i=0;i<count;i++)
			{	if((password[i]<='Z')&&(password[i]>='A'))
					a++;
				if((password[i]<='z')&&(password[i]>='a'))
					b++;
				if((password[i]<='9')&&(password[i]>='0'))
					c++;
				if((password[i]=='~')||(password[i]=='!')||(password[i]=='@')||((password[i]<='&')&&(password[i]>='#'))||(password[i]=='^')||((password[i]>='(')&&(password[i]<='*'))||(password[i]=='-')||(password[i]=='='))
					d++;	//��û�и��õķ��������� 
			}
			if(a==0)
				count2++;
			if(b==0)
				count2++;
			if(c==0)
				count2++;
			if(d==0)
				count2++;
			if(count2>=2)
				flag[count1]=1;
		}
			//
			for(i=0;i<count;i++)
				password[i]='\0';
			
			count2=0;
			count=0;
			count1++;
			a=0;b=0;c=0;d=0;
			//
			scanf("%c",&word);
			while(word!='\n')
			{	password[count]=word;
				count++;
				scanf("%c",&word);
			}
			
			if((password[0]=='E')&&(password[1]=='N')&&(password[2]=='D'))
				flag1=1;
	
	}	
	for(i=0;i<count1;i++)
	{	if(flag[i]==1)
			printf("NO");
		if(flag[i]==0)
			printf("YES");
		if(i!=count1-1)
			printf("\n");//���һ�������û��\n 
	}

	return 0;
}
