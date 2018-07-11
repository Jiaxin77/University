#include<stdio.h>
#include<stdlib.h>
main()
{printf("Please input seven parts:\n");
char a;
scanf("%c",&a);
short b;
scanf("%hd",&b);
int c;
scanf("%d",&c);
long d;
scanf("%ld",&d);
long long e;
scanf("%lld",&e);
float f;
scanf("%f",&f);
double g;
scanf("%lf",&g);
printf("The result is:\n");
printf("The 'char' variable is %c,it takes %dbyte\n ",a,sizeof(char));
printf("The 'short' variable is %hd,it takes %dbyte\n ",b,sizeof(short));
printf("The 'int' variable is %d,it takes %dbyte\n ",c,sizeof(int));
printf("The 'long' variable is %ld,it takes %dbyte\n ",d,sizeof(long));
printf("The 'long long' variable is %lld,it takes %dbyte\n ",e,sizeof(long long));
printf("The 'float' variable is %f,it takes %dbyte\n ",f,sizeof(float));
printf("The 'double' variable is %lf,it takes %dbyte\n",g,sizeof(double));
system("pause");
return 0;
}
