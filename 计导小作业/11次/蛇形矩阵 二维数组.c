#include<stdio.h>
#include<stdlib.h>
void creatMatrix(int array[][100], int n);
void printMatrix(int array[][100], int n);

void creatMatrix(int array[][100], int n)
{	int row,cols;
	for(row=0;row<n;row++)//循环行 
	{	if(row==0)
			array[row][0]=1;//确定第一个数 
		if((row%2!=0)&&(row!=0))
			array[row][0]=array[row-1][0]+1;
		if((row%2==0)&&(row!=0))
			array[row][0]=array[row-1][0]+2*row;
	//分奇数行偶数行确定每行第一个数 
		for(cols=0;cols<n;cols++)
		{	if(cols<(n-row))//按对角线分为两个部分 
			{
				if(row%2==0)//row为偶数的行 
				{	
					if((cols%2==0)&&(cols!=0))//cols为偶数的位置 
						array[row][cols]=array[row][cols-1]+2*row+1;
					if((cols%2!=0)&&(cols!=0))//cols为奇数的位置 
						array[row][cols]=array[row][cols-1]+2*cols;
				}
				if(row%2!=0)//row为奇数的行 
				{	if((cols%2==0)&&(cols!=0))
						array[row][cols]=array[row][cols-1]+2*cols;
					if((cols%2!=0)&&(cols!=0))
						array[row][cols]=array[row][cols-1]+2*row+1;	
				}	
			}
			else//另一部分 
			{	if(row%2==0)
				{	
					if((cols%2==0)&&(cols!=0))
						array[row][cols]=array[row][cols-1]+2*(n-cols);//+;
					if((cols%2!=0)&&(cols!=0))
						array[row][cols]=array[row][cols-1]+(2*(n-row)-1);
				}
				if(row%2!=0)
				{	if((cols%2==0)&&(cols!=0))
						array[row][cols]=array[row][cols-1]+2*(n-row)-1;
					if((cols%2!=0)&&(cols!=0))
						array[row][cols]=array[row][cols-1]+2*(n-cols);	
				}
            }	
	}	}
}

void printMatrix(int array[][100], int n)
{	int row,cols;
	for(row=0;row<n;row++)//打印 
	{	for(cols=0;cols<n;cols++)
			printf("%d ",array[row][cols]);
		printf("\n");//每打印完一行 回车 
	}
}

main()
{	int snake[100][100]={0};
	int n;
	printf("Please input order of the snake matrix:");
	scanf("%d",&n);
	creatMatrix(snake,n);
	printf("The snake matrix is:\n");
	printMatrix(snake,n); 
	system("pause");
	return 0;
}
