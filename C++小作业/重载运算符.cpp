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
		Point(){}//不加这个{}， 后面的Point l会报错，要有内容 
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
	cout<<"请输入点的横坐标；";
	cin>>t;
	cout<<"请输入点的纵坐标：";
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
	 

