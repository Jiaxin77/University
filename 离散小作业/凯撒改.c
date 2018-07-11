#include<stdio.h>
main()
{	int n,k=0,j=0;
    char p;
    char str01[800]={0};
    char str02[800]={0};
    char str11[800]={0};
    char str12[800]={0};
  	char b[800]={0};
  	char c[800]={0};
  	char a[800]={0};
    n=0;
    int k1,k2;
    char g;
   // scanf("%d,%d",&k1,&k2);
	scanf("%d",&k1);
	scanf("%c",&g);
	scanf("%d",&k2);//读取k1,k2 
  
   gets(a);
    
    
	gets(b);
	gets(c);
    //scanf("%c",&c);
    while(b[k]!='\0')
    {	if((b[k]>='A')&&(b[k]<='Z'))//大写字母转换 
		{
			str01[n]=b[k];
        	str02[n]=b[k]+k1;//k1
     
       		 if((b[k]+k1)>'Z')
        		str02[n]=b[k]-26+k1;//若超出范围，则减去26 

        		n++;
		}
		if((b[k]>='a')&&(b[k]<='z'))//小写字母转换成大写字母 再加密 
		{	str02[n]=b[k]+k1-32;
			if((b[k]+k1-32)>'Z')
        		str02[n]=b[k]-26+k1-32;

        		n++;
		    
		}
        k++;
	}
	n=0;
	
   // gets(c);
    
	while(c[j]!='\0')
	{	if((c[j]>='A')&&(c[j]<='Z'))//大写字母解密 
		{
	
			str11[n]=c[j];
	    	str12[n]=c[j]-k2;
	    	if((c[j]-k2)<'A')
	    		str12[n]=c[j]+26-k2;
	    	n++;
		}
		if((c[j]>='a')&&(c[j]<='z'))//小写转大写再解密 
		{		str12[n]=c[j]-k2-32;
	    	if((c[j]-k2-32)<'A')
	    		str12[n]=c[j]+26-k2-32;
	    	n++;
		}
		
	    j++;
	}

	for(n=0;n<80;n++)//输出加密后 
	{	if(str02[n]!='\0')
	         {printf("%c",str02[n]);
			 }
	}
	
	printf("\n");	
	for(n=0;n<80;n++)//输出解密后 
	{	if(str12[n]!='\0')
	         {printf("%c",str12[n]);
			 }
	}
	//system("pause");
	return 0; 
}
