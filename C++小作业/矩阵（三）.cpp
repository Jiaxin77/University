#include<iostream>
using namespace std;

class matrix
{	private:
		int lines,rows;
		int **mt;
	public:
		matrix(void);//构造函数
		~matrix();//析构函数
		matrix(int a,int b);//参数是矩阵大小的构造函数 
		matrix(matrix& x);//拷贝构造函数
		void original();
		void output();
		void add(matrix& x,matrix& y);
     	void sub(matrix& a,matrix& b);
		void set(int& e,int& r)
		{	rows=e;
			lines=r;
		}//用户输入的值 传递给类 
		
		 
		
 } ;
 
 matrix::matrix(void)//输构造函数动态申请内存 
{	int a;
	int t,u;
	cout<<"输入矩阵的行数：";
	cin>>t;
	cout<<"输入矩阵的列数：";
	cin>>u;
	while(cin.fail())
	{   cout<<"您的输入有误，请重新输入"<<endl;
        cin.clear();
        cin.ignore();
       	cout<<"输入矩阵的行数：";
	    cin>>t;
	    cout<<"输入矩阵的列数：";
	    cin>>u;
     }
	set(t,u);
	mt=new int* [rows] ;//分配几行 
	for(a=0;a<t;a++)
	{	mt[a]=new int [lines];//每一行再分配几列 
	}
	cout<<"void构造 OK"<<endl;

	
}

matrix::~matrix()
{	int a;
	for(a=0;a<rows;a++)//释放动态申请的 
	{	delete [] mt[a];
	}
	delete [] mt;
	cout<<"析构函数"<<endl;
}



matrix::matrix(matrix& x)//拷贝构造函数 
{	int a;
	lines=x.lines;
	rows=x.rows;
	mt=new int* [rows] ;//分配几行 
	for(a=0;a<rows;a++)
	{	mt[a]=new int [lines];//每一行再分配几列 
	}
	cout<<"拷贝构造 OK"<<endl; 
}

matrix::matrix(int a,int b)//矩阵大小 构造函数 
{	rows=a;
	lines=b;
	mt=new int* [rows] ;//分配几行 
	for(int y=0;y<rows;y++)
	{	mt[y]=new int [lines];//每一行再分配几列 
	}
	cout<<"int构造 OK"<<endl;
}



void matrix::original()//初始化矩阵 
{	int q,t;
	cout<<"输入矩阵("<<rows<<"*"<<lines<<" 整数）："<<endl;
	for(q=0;q<rows;q++)
		{for(t=0;t<lines;t++)
			{	
				cin>>mt[q][t];
			}
		}
	while(cin.fail())
	{	cout<<"您的输入有误，请重新输入"<<endl;
		cin.clear();
		cin.ignore();
		cout<<"输入矩阵（"<<rows<<"*"<<lines<<" 整数）："<<endl;
		for(q=0;q<rows;q++)
			{for(t=0;t<lines;t++)
				{	
					cin>>mt[q][t];
				}
			}
	 } 
}


void matrix::output()//输出矩阵 
{	int q,t;
	cout<<"矩阵如下:"<<endl;
	for(q=0;q<rows;q++)
		{	for(t=0;t<lines;t++)
			{	
				cout<<mt[q][t]<<" ";
			 } 
			cout<<endl;
		}
	cout<<endl;
}

void matrix::add(matrix& x,matrix& y)
{	int q,t;
	if((x.lines!=y.lines)||(x.rows!=y.rows))
	{	cout<<"两矩阵必须行列都相等才能加减"<<endl;
	}
	else
	{
		for(q=0;q<rows;q++)
		{	for(t=0;t<lines;t++)
			{	
				mt[q][t]=x.mt[q][t]+y.mt[q][t];
			}
		}
	}
}
		
void matrix::sub(matrix& a,matrix& b)
{	int q,t;
	if((a.lines!=b.lines)||(a.rows!=b.rows))
	{		cout<<"两矩阵必须行列都相等才能加减"<<endl;
	}
	else
	{
		for(q=0;q<rows;q++)
		{	for(t=0;t<lines;t++)
			{	
				mt[q][t]=a.mt[q][t]-b.mt[q][t];
			}
		}
	}
}

main()
{	

	int x1,y1,x2,y2;
	cout<<"A1:"<<endl;
	cout<<"输入矩阵行数：";
	cin>>x1;
	cout<<"输入矩阵列数：";
	cin>>y1;
	while(cin.fail())
    {    cout<<"您的输入有误，请重新输入"<<endl;
         cin.clear();
         cin.ignore();
         cout<<"A1:"<<endl;
	     cout<<"输入矩阵行数：";
       	 cin>>x1;
	     cout<<"输入矩阵列数：";
	     cin>>y1;
    }
	matrix A1(x1,y1);//会调用矩阵大小构造函数  
	A1.original();
	
	cout<<"A2:"<<endl;
	cout<<"输入矩阵行数：";
	cin>>x2;
	cout<<"输入矩阵列数：";
	cin>>y2;
	while(cin.fail())
	{     cout<<"您的输入有误，请重新输入"<<endl;
	      cin.clear();
	      cin.ignore();
      	  cout<<"A2:"<<endl;
	      cout<<"输入矩阵行数：";
	      cin>>x2;
      	  cout<<"输入矩阵列数：";
	      cin>>y2;
    }
	matrix A2(x2,y2);
	A2.original();	
	
	
	
	matrix A3(A1); //矩阵拷贝构造函数 
	if((x1!=x2)||(y1!=y2))
	{	cout<<"矩阵大小不同不能相加减"<<endl;
	    
	}
	else
	{
	A3.add(A1,A2);
	cout<<"A1+A2"<<endl;
	A3.output();
	A3.sub(A1,A2);
	cout<<"A1-A2"<<endl;
	A3.output();
	}


	
	
	int x3,y3,x4,y4;
	cout<<"pA1:"<<endl;
	cout<<"输入矩阵行数：";
	cin>>x3;
	cout<<"输入矩阵列数：";
	cin>>y3;
	while(cin.fail())
	{    cout<<"您的输入有误，请重新输入"<<endl;
         cin.clear();
         cin.ignore();
         cout<<"pA1:"<<endl;
       	 cout<<"输入矩阵行数：";
	     cin>>x3;
	     cout<<"输入矩阵列数：";
	     cin>>y3;
    }
	matrix *pA1=new matrix (x3,y3);//new动态创建矩阵 new返回的是地址，给指针 
	if(pA1==NULL)
	{cout<<"有误！"<<endl;}
	else
	{cout<<"成功！"<<endl;}
    
    pA1->original();
	
	cout<<"pA2:"<<endl;
	cout<<"输入矩阵行数：";
	cin>>x4;
	cout<<"输入矩阵列数：";
	cin>>y4;
	while(cin.fail())
	{     cout<<"您的输入有误，请重新输入"<<endl;
          cin.clear();
          cin.ignore();
          cout<<"pA2:"<<endl;
	      cout<<"输入矩阵行数：";
	      cin>>x4;
	      cout<<"输入矩阵列数：";
	      cin>>y4;
    }
	matrix *pA2=new matrix (x4,y4);
	if(pA2==NULL)
	{cout<<"有误！"<<endl;}
	else
	{cout<<"成功！"<<endl;}
	
	pA2->original();

	matrix *pA3=pA1;//拷贝 
	if(pA3==NULL)
	{cout<<"有误！"<<endl;}
	else
	{cout<<"成功！"<<endl;}
	
	if((x3!=x4)||(y3!=y4))
	{	cout<<"矩阵大小不同不能相加减"<<endl;
	}
	else
	{
	
	pA3->add(*pA1,*pA2);
	cout<<"pA1+pA2:"<<endl;
	pA3->output();
	pA3->sub(*pA1,*pA2);
	cout<<"pA1-pA2:"<<endl;
	pA3->output();
	}
	//释放pA1,pA2.pA3; 
/*	delete pA1;
	delete pA2;
	delete pA3;
*/ //析构函数中已经释放了，这里再释放会程序停止运行	
	system("pause");
	return 0;
	 
}
