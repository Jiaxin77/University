#include<iostream>

using namespace std;

class matrix
{	private:
	int mt[4][5];
	public:
	void original();
	void output();
	void add(matrix& x,matrix& y);
	void sub(matrix& a,matrix& b);
	matrix(){}//构造和析构函数 不放内容也要加大括号 
	
	~matrix(){}
	
};

void matrix::original()//初始化 
{	int i,j;
	cout<<"输入矩阵（4*5 整数）："<<endl;
	for(i=0;i<=3;i++)//格式？ 
		{for(j=0;j<=4;j++)
			{	
				cin>>mt[i][j];
			}
		}
	while(cin.fail())//防暴力输入 
	{	cout<<"您的输入有误，请重新输入"<<endl;
		cin.clear();
		cin.ignore();
		cout<<"输入矩阵（4*5 整数）："<<endl;
		for(i=0;i<=3;i++)
			{for(j=0;j<=4;j++)
				{	
					cin>>mt[i][j];
				}
			}
			
	 } 
}

void matrix::output()//输出 
{	int i,j;
	cout<<"矩阵如下:"<<endl;
	for(i=0;i<=3;i++)
		{	for(j=0;j<=4;j++)
			{	
				cout<<mt[i][j]<<" ";
			 } 
			cout<<endl;
		}
	cout<<endl;
}

void matrix::add(matrix& x,matrix& y)//加法 
{	int i,j;
	for(i=0;i<=3;i++)
	{	for(j=0;j<=4;j++)
		{	
			mt[i][j]=x.mt[i][j]+y.mt[i][j];
		}//对应元素相加 
	}
}
		
void matrix::sub(matrix& a,matrix& b)//减法 
{	int i,j;
	for(i=0;i<=3;i++)
	{	for(j=0;j<=4;j++)
		{	
			mt[i][j]=a.mt[i][j]-b.mt[i][j];
		}//对应元素相减 
	}
}

main()
{	matrix A1,A2,A3;
    cout<<"A1:"<<endl;
	A1.original();
	cout<<"A2:"<<endl;
	A2.original();
	A3.add(A1,A2);
	cout<<"A1+A2="<<endl; 
	A3.output();
	A3.sub(A1,A2);
	cout<<"A1-A2="<<endl;
	A3.output();
	system("pause");
	return 0;
}
