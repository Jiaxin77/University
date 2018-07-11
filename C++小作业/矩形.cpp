#include<iostream>
#include<math.h>

using namespace std; 

class Point
{	public://之后的矩形类会用到此坐标，不能私有 
		float x1;
		float y1;
	

friend	float lenth(Point a,Point b);	//用到友元函数 赋予该函数与类的成员函数相同的访问权限 

	Point();//看构造函数是否被调用 
	
	~Point();//看析构函数是否被调用 
	
			
};
 
Point::Point()
{  x1=0;
   y1=0;
   cout<<"点 构造函数被调用"<<endl;}
Point::~Point()
{  cout<<"点 析构函数被调用"<<endl;} 

float lenth(Point a,Point b)//因为是友元函数，不是成员函数，不能用限定符 
{	float len;
	float x,y;
	x=pow(a.x1-b.x1,2);
	y=pow(a.y1-b.y1,2);
	len=sqrt(x+y);
	return len;
}//计算长度函数 

class JUXING
{	private:
		Point left;//矩形左上角点 
		Point right;//矩形右下角点 
	
	public:
		float area();//计算面积 
		
		void set(Point a1,Point b1)
		{	left=a1;
			right=b1;
		}//把点转为矩形点 之后main中用到 
	     
		JUXING()
		{	cout<<"矩形 构造函数被调用"<<endl;
		    left.x1=0;
		    left.y1=10;
		    right.x1=10;
		    right.y1=0;
		}
        
        
		~JUXING()
		{	cout<<"矩形 析构函数被调用"<<endl; 
		}
};

 float JUXING::area()
{	float ar;
    float x,y;
    x=right.x1-left.x1;
    y=left.y1-right.y1;
	ar=x*y;
	
	return ar;
}

main()
{	JUXING t;//创建一个矩形对象 
	Point l,r;
	
	cout<<"请输入矩形左上角坐标(用空格分开)：";
	cin>>l.x1>>l.y1;//读取左上角坐标 
	
	
	cout<<"\n请输入矩形右下角坐标(用空格分开)：";
	cin>>r.x1>>r.y1;//读取右下角 
	cout<<endl;
	
	while((l.x1>=r.x1)||(l.y1<=r.y1)||(cin.fail()))//如果左上右下不符合要求 
	{	cout<<"您的输入有误，请重新输入"<<endl;
	    cin.clear();
	    cin.ignore();
        cout<<"请输入矩形左上角坐标(用空格分开)：";
	    cin>>l.x1>>l.y1;
	    cout<<"\n请输入矩形右下角坐标(用空格分开)：";
	    cin>>r.x1>>r.y1;
	    cout<<endl;
	}
	
	t.set(l,r);

	
	
//	cout<<"两点间距离为："<<lenth(l,r)<<endl;
	cout<<"矩形面积为："<<t.area()<<endl;
	system("pause");
	return 0;
	 
}
