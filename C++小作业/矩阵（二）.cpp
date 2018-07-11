#include<iostream>
#include<iomanip>
//#include<stdlib.h>
using namespace std;

class matrix
{	
		private:
		int **mt;
		int i,j;
	public:
		void original();
	void output();
	void add(matrix& x,matrix& y);
	void sub(matrix& a,matrix& b);
	void set(int& e,int& r)
	{	i=e;
		j=r;
	}//用户输入的值 传递给类 
	matrix();
	~matrix();
};

matrix::matrix()//输构造函数动态申请内存 
{	int a;
	int t,u;
	cout<<"输入矩阵的行数：";
	cin>>t;
	cout<<"输入矩阵的列数：";
	cin>>u;
	set(t,u);
	mt=new int* [t] ;//分配几行 
	for(a=0;a<t;a++)
	{	mt[a]=new int [u];//每一行再分配几列 
	}
	cout<<"构造OK"<<endl;

	
}

matrix::~matrix()
{	int a;
	for(a=0;a<i;a++)//释放动态申请的 
	{	delete [] mt[a];
	}
	delete [] mt;
	cout<<"析构函数"<<endl;
}




void matrix::original()
{	int q,t;
	cout<<"输入矩阵("<<i<<"*"<<j<<" 整数）："<<endl;
	for(q=0;q<i;q++)
		{for(t=0;t<j;t++)
			{	
				cin>>mt[q][t];
			}
		}
	while(cin.fail())//防暴力输入 
	{	cout<<"您的输入有误，请重新输入"<<endl;
		cin.clear();
		cin.ignore();
		cout<<"输入矩阵（4*5 整数）："<<endl;
	    
		for(q=0;q<i;q++)
			{for(t=0;t<j;t++)
				{	
					cin>>mt[q][t];
				}
			}
		
	 } 
}

void matrix::output()
{	int q,t;
	cout<<"矩阵如下:"<<endl;
	for(q=0;q<i;q++)
		{	for(t=0;t<j;t++)
			{	
				cout<<mt[q][t]<<" ";
			 } 
			cout<<endl;
		}
	cout<<endl;
}

void matrix::add(matrix& x,matrix& y)
{	int q,t;
	for(q=0;q<i;q++)
	{	for(t=0;t<j;t++)
		{	
			mt[q][t]=x.mt[q][t]+y.mt[q][t];
		}
	}
}
		
void matrix::sub(matrix& a,matrix& b)
{	int q,t;
	for(q=0;q<i;q++)
	{	for(t=0;t<j;t++)
		{	
			mt[q][t]=a.mt[q][t]-b.mt[q][t];
		}
	}
}

/*void matrix::original()
{	int i,j;
	cin.clear();
	cin.ignore();
	cout<<"输入矩阵（4*5 整数）："<<endl;
	for(i=0;i<=3;i++)
		{for(j=0;j<=4;j++)
			{	
				cin>>mt[i][j];
			}
		}
	while(cin.fail())
	{	cout<<"您的输入有误，请重新输入"<<endl;//不按矩阵格式输不会报错？？ 
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

void matrix::output()
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

void matrix::add(matrix& x,matrix& y)
{	int i,j;
	for(i=0;i<=3;i++)
	{	for(j=0;j<=4;j++)
		{	
			mt[i][j]=x.mt[i][j]+y.mt[i][j];
		}
	}
}
		
void matrix::sub(matrix& a,matrix& b)
{	int i,j;
	for(i=0;i<=3;i++)
	{	for(j=0;j<=4;j++)
		{	
			mt[i][j]=a.mt[i][j]-b.mt[i][j];
		}
	}
}
*/

main()
{	matrix *A1,*A2 ,*A3;
    if(A1==NULL)
      {cout<<"A1创建失败"<<endl;}
    else
      {cout<<"A1创建成功"<<endl;}
    if(A2==NULL)
      {cout<<"A2创建失败"<<endl;}
    else
      {cout<<"A2创建成功"<<endl;}
    if(A3==NULL)
      {cout<<"A3创建失败"<<endl;}
    else
      {cout<<"A3创建成功"<<endl;}
	cout<<"A1:"<<endl;
	A1=new matrix;//动态申请矩阵 
	cout<<"A2:"<<endl;
	A2=new matrix;
	cout<<"A3:"<<endl;
	A3=new matrix;
	cout<<"A1:"<<endl;
	A1->original();
	cout<<"A2:"<<endl;
	A2->original();
	A3->add(*A1,*A2);
	cout<<"A1+A2:"<<endl;
	A3->output();
	A3->sub(*A1,*A2);
	cout<<"A1-A2"<<endl;
	A3->output();
	system("pause");
	return 0;
}
