#include<stdio.h>
#include<stdlib.h>
main()
{
printf("Please input sex:");
char a;
scanf("%c",&a);
printf("please input age:");
int b;
scanf("%d",&b);
printf("please input height:");
float c;
scanf("%f",&c);
printf("The sex is %c,the age is %d,and the height is %f",a,b,c);
system("pause");
return 0; 
}
