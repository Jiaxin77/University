#include<stdio.h>
#include<stdlib.h>
int countBinary(int n);

int countBinary(int n)
{	if(n/2==0)
		return 1;	
	else
		return 1+countBinary(n/2);
	
} 

main()
{     int n,num2,digit;
      printf("Input an integer:");
      scanf("%d",&n);
      num2=countBinary(n);
      printf("The binary form of number %d has %d digits.\n",n,num2);
      system("pause");
      return 0;
}
