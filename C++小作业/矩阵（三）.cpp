#include<iostream>
using namespace std;

class matrix
{	private:
		int lines,rows;
		int **mt;
	public:
		matrix(void);//���캯��
		~matrix();//��������
		matrix(int a,int b);//�����Ǿ����С�Ĺ��캯�� 
		matrix(matrix& x);//�������캯��
		void original();
		void output();
		void add(matrix& x,matrix& y);
     	void sub(matrix& a,matrix& b);
		void set(int& e,int& r)
		{	rows=e;
			lines=r;
		}//�û������ֵ ���ݸ��� 
		
		 
		
 } ;
 
 matrix::matrix(void)//�乹�캯����̬�����ڴ� 
{	int a;
	int t,u;
	cout<<"��������������";
	cin>>t;
	cout<<"��������������";
	cin>>u;
	while(cin.fail())
	{   cout<<"����������������������"<<endl;
        cin.clear();
        cin.ignore();
       	cout<<"��������������";
	    cin>>t;
	    cout<<"��������������";
	    cin>>u;
     }
	set(t,u);
	mt=new int* [rows] ;//���伸�� 
	for(a=0;a<t;a++)
	{	mt[a]=new int [lines];//ÿһ���ٷ��伸�� 
	}
	cout<<"void���� OK"<<endl;

	
}

matrix::~matrix()
{	int a;
	for(a=0;a<rows;a++)//�ͷŶ�̬����� 
	{	delete [] mt[a];
	}
	delete [] mt;
	cout<<"��������"<<endl;
}



matrix::matrix(matrix& x)//�������캯�� 
{	int a;
	lines=x.lines;
	rows=x.rows;
	mt=new int* [rows] ;//���伸�� 
	for(a=0;a<rows;a++)
	{	mt[a]=new int [lines];//ÿһ���ٷ��伸�� 
	}
	cout<<"�������� OK"<<endl; 
}

matrix::matrix(int a,int b)//�����С ���캯�� 
{	rows=a;
	lines=b;
	mt=new int* [rows] ;//���伸�� 
	for(int y=0;y<rows;y++)
	{	mt[y]=new int [lines];//ÿһ���ٷ��伸�� 
	}
	cout<<"int���� OK"<<endl;
}



void matrix::original()//��ʼ������ 
{	int q,t;
	cout<<"�������("<<rows<<"*"<<lines<<" ��������"<<endl;
	for(q=0;q<rows;q++)
		{for(t=0;t<lines;t++)
			{	
				cin>>mt[q][t];
			}
		}
	while(cin.fail())
	{	cout<<"����������������������"<<endl;
		cin.clear();
		cin.ignore();
		cout<<"�������"<<rows<<"*"<<lines<<" ��������"<<endl;
		for(q=0;q<rows;q++)
			{for(t=0;t<lines;t++)
				{	
					cin>>mt[q][t];
				}
			}
	 } 
}


void matrix::output()//������� 
{	int q,t;
	cout<<"��������:"<<endl;
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
	{	cout<<"������������ж���Ȳ��ܼӼ�"<<endl;
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
	{		cout<<"������������ж���Ȳ��ܼӼ�"<<endl;
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
	cout<<"�������������";
	cin>>x1;
	cout<<"�������������";
	cin>>y1;
	while(cin.fail())
    {    cout<<"����������������������"<<endl;
         cin.clear();
         cin.ignore();
         cout<<"A1:"<<endl;
	     cout<<"�������������";
       	 cin>>x1;
	     cout<<"�������������";
	     cin>>y1;
    }
	matrix A1(x1,y1);//����þ����С���캯��  
	A1.original();
	
	cout<<"A2:"<<endl;
	cout<<"�������������";
	cin>>x2;
	cout<<"�������������";
	cin>>y2;
	while(cin.fail())
	{     cout<<"����������������������"<<endl;
	      cin.clear();
	      cin.ignore();
      	  cout<<"A2:"<<endl;
	      cout<<"�������������";
	      cin>>x2;
      	  cout<<"�������������";
	      cin>>y2;
    }
	matrix A2(x2,y2);
	A2.original();	
	
	
	
	matrix A3(A1); //���󿽱����캯�� 
	if((x1!=x2)||(y1!=y2))
	{	cout<<"�����С��ͬ������Ӽ�"<<endl;
	    
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
	cout<<"�������������";
	cin>>x3;
	cout<<"�������������";
	cin>>y3;
	while(cin.fail())
	{    cout<<"����������������������"<<endl;
         cin.clear();
         cin.ignore();
         cout<<"pA1:"<<endl;
       	 cout<<"�������������";
	     cin>>x3;
	     cout<<"�������������";
	     cin>>y3;
    }
	matrix *pA1=new matrix (x3,y3);//new��̬�������� new���ص��ǵ�ַ����ָ�� 
	if(pA1==NULL)
	{cout<<"����"<<endl;}
	else
	{cout<<"�ɹ���"<<endl;}
    
    pA1->original();
	
	cout<<"pA2:"<<endl;
	cout<<"�������������";
	cin>>x4;
	cout<<"�������������";
	cin>>y4;
	while(cin.fail())
	{     cout<<"����������������������"<<endl;
          cin.clear();
          cin.ignore();
          cout<<"pA2:"<<endl;
	      cout<<"�������������";
	      cin>>x4;
	      cout<<"�������������";
	      cin>>y4;
    }
	matrix *pA2=new matrix (x4,y4);
	if(pA2==NULL)
	{cout<<"����"<<endl;}
	else
	{cout<<"�ɹ���"<<endl;}
	
	pA2->original();

	matrix *pA3=pA1;//���� 
	if(pA3==NULL)
	{cout<<"����"<<endl;}
	else
	{cout<<"�ɹ���"<<endl;}
	
	if((x3!=x4)||(y3!=y4))
	{	cout<<"�����С��ͬ������Ӽ�"<<endl;
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
	//�ͷ�pA1,pA2.pA3; 
/*	delete pA1;
	delete pA2;
	delete pA3;
*/ //�����������Ѿ��ͷ��ˣ��������ͷŻ����ֹͣ����	
	system("pause");
	return 0;
	 
}
