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
	}//�û������ֵ ���ݸ��� 
	matrix();
	~matrix();
};

matrix::matrix()//�乹�캯����̬�����ڴ� 
{	int a;
	int t,u;
	cout<<"��������������";
	cin>>t;
	cout<<"��������������";
	cin>>u;
	set(t,u);
	mt=new int* [t] ;//���伸�� 
	for(a=0;a<t;a++)
	{	mt[a]=new int [u];//ÿһ���ٷ��伸�� 
	}
	cout<<"����OK"<<endl;

	
}

matrix::~matrix()
{	int a;
	for(a=0;a<i;a++)//�ͷŶ�̬����� 
	{	delete [] mt[a];
	}
	delete [] mt;
	cout<<"��������"<<endl;
}




void matrix::original()
{	int q,t;
	cout<<"�������("<<i<<"*"<<j<<" ��������"<<endl;
	for(q=0;q<i;q++)
		{for(t=0;t<j;t++)
			{	
				cin>>mt[q][t];
			}
		}
	while(cin.fail())//���������� 
	{	cout<<"����������������������"<<endl;
		cin.clear();
		cin.ignore();
		cout<<"�������4*5 ��������"<<endl;
	    
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
	cout<<"��������:"<<endl;
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
	cout<<"�������4*5 ��������"<<endl;
	for(i=0;i<=3;i++)
		{for(j=0;j<=4;j++)
			{	
				cin>>mt[i][j];
			}
		}
	while(cin.fail())
	{	cout<<"����������������������"<<endl;//���������ʽ�䲻�ᱨ���� 
		cin.clear();
		cin.ignore();
		cout<<"�������4*5 ��������"<<endl;
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
	cout<<"��������:"<<endl;
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
      {cout<<"A1����ʧ��"<<endl;}
    else
      {cout<<"A1�����ɹ�"<<endl;}
    if(A2==NULL)
      {cout<<"A2����ʧ��"<<endl;}
    else
      {cout<<"A2�����ɹ�"<<endl;}
    if(A3==NULL)
      {cout<<"A3����ʧ��"<<endl;}
    else
      {cout<<"A3�����ɹ�"<<endl;}
	cout<<"A1:"<<endl;
	A1=new matrix;//��̬������� 
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
