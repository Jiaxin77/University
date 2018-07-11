#include<stdio.h>
#include<stdlib.h>
#define PI 3.14159265
main()
{
printf("Please input a float number:");
double r,c,s;
scanf("%lf",&r);
c=2*PI*r;
s=PI*r*r;
printf("The perimeter is %.4lf,the area is %.4lf",c,s);
system("pause");
return 0;
}
