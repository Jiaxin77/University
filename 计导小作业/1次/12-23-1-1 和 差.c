#include<stdio.h> 
#include<stdlib.h>
main() 
{ 
printf("Please input two integers:");
  int a,b,c,d; 
  
scanf("%d%d",&a,&b);
c=a+b;
d=a-b;
printf("The sum is %d",c); 
printf(" and the difference is %d",d);
system("pause");
return 0;
}

