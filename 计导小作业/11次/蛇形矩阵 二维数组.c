#include<stdio.h>
#include<stdlib.h>
void creatMatrix(int array[][100], int n);
void printMatrix(int array[][100], int n);

void creatMatrix(int array[][100], int n)
{	int row,cols;
	for(row=0;row<n;row++)//ѭ���� 
	{	if(row==0)
			array[row][0]=1;//ȷ����һ���� 
		if((row%2!=0)&&(row!=0))
			array[row][0]=array[row-1][0]+1;
		if((row%2==0)&&(row!=0))
			array[row][0]=array[row-1][0]+2*row;
	//��������ż����ȷ��ÿ�е�һ���� 
		for(cols=0;cols<n;cols++)
		{	if(cols<(n-row))//���Խ��߷�Ϊ�������� 
			{
				if(row%2==0)//rowΪż������ 
				{	
					if((cols%2==0)&&(cols!=0))//colsΪż����λ�� 
						array[row][cols]=array[row][cols-1]+2*row+1;
					if((cols%2!=0)&&(cols!=0))//colsΪ������λ�� 
						array[row][cols]=array[row][cols-1]+2*cols;
				}
				if(row%2!=0)//rowΪ�������� 
				{	if((cols%2==0)&&(cols!=0))
						array[row][cols]=array[row][cols-1]+2*cols;
					if((cols%2!=0)&&(cols!=0))
						array[row][cols]=array[row][cols-1]+2*row+1;	
				}	
			}
			else//��һ���� 
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
	for(row=0;row<n;row++)//��ӡ 
	{	for(cols=0;cols<n;cols++)
			printf("%d ",array[row][cols]);
		printf("\n");//ÿ��ӡ��һ�� �س� 
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
