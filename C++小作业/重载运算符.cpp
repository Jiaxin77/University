#include<iostream>
using namespace std;

class Point
{	private:
		int x,y;
	public:
		Point(int a,int b)
		{	x=a;
			y=b;
		}
		Point(){}//�������{}�� �����Point l�ᱨ��Ҫ������ 
		~Point(){}
	Point operator++(int);//p++ 
	Point operator++();//++p 
	Point operator--(int);//p--
	Point operator--();//--p
	void output();
}; 

void Point::output()
{	cout<<"("<<x<<","<<y<<")";
}

Point Point::operator++(int)
{	Point l;
	l.x=x+1;
	l.y=y+1;
	return l;
}

Point Point::operator--(int)
{	Point l;
	l.x=x-1;
	l.y=y-1;
	return l;
}

Point Point::operator++()
{	Point l;
	x=x+1;
	l.x=x;
	y=y+1;
	l.y=y;
	return l;
}

Point Point::operator--()
{	Point l;
	x=x-1;
	y=y-1;
	l.x=x;
	l.y=y;
	return l;
	
}

main()
{	
	int t,u;
	cout<<"�������ĺ����ꣻ";
	cin>>t;
	cout<<"�������������꣺";
	cin>>u;
	Point a(t,u);
	Point b;
	
	
	 
	cout<<"a++:"<<endl;
	b=(a++);
	//cout<<"a:";
	a.output();
	cout<<"++ =";
	b.output();
	//a.output();
	cout<<endl;
	
	cout<<"a--:"<<endl;
	b=(a--);

	a.output();
	cout<<"-- =";
	b.output();
	//a.output();
	cout<<endl;
	
	cout<<"++a:"<<endl;
	cout<<"++";
	a.output();
	cout<<" ="; 
	b=(++a);
	b.output();
	//a.output();
	cout<<endl;
	
	cout<<"--a:"<<endl;
	cout<<"--";
	a.output();
	cout<<" = ";
	b=(--a);
	b.output();
	//a.output();
	cout<<endl;
		
	system("pause");
	return 0;
}
	 

