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
	matrix(){}//������������� ��������ҲҪ�Ӵ����� 
	
	~matrix(){}
	
};

void matrix::original()//��ʼ�� 
{	int i,j;
	cout<<"�������4*5 ��������"<<endl;
	for(i=0;i<=3;i++)//��ʽ�� 
		{for(j=0;j<=4;j++)
			{	
				cin>>mt[i][j];
			}
		}
	while(cin.fail())//���������� 
	{	cout<<"����������������������"<<endl;
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

void matrix::output()//��� 
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

void matrix::add(matrix& x,matrix& y)//�ӷ� 
{	int i,j;
	for(i=0;i<=3;i++)
	{	for(j=0;j<=4;j++)
		{	
			mt[i][j]=x.mt[i][j]+y.mt[i][j];
		}//��ӦԪ����� 
	}
}
		
void matrix::sub(matrix& a,matrix& b)//���� 
{	int i,j;
	for(i=0;i<=3;i++)
	{	for(j=0;j<=4;j++)
		{	
			mt[i][j]=a.mt[i][j]-b.mt[i][j];
		}//��ӦԪ����� 
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
