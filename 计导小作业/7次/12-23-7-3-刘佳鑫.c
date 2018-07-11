#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int countBinary(int n);

int countBinary(int n)
{	int count;
	count=0;
	while(n!=0)
	{n=n/2;
	count=count+1;
	}
	return count;
}

main()
{     int n,digit;
      printf("Input an integer:");
      scanf("%d",&n);
      digit=countBinary(n);
      printf("The binary form of number %d has %d digits.",n,digit);
      system("pause");
      return 0;
}
