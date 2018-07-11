#include<iostream>
using namespace std;
#define PI 3.14


class Shape
{
	public:
		
	float area();
	Shape()
	{	cout<<"Shape构造函数"<<endl;
	}
	~Shape()
	{	cout<<"Shape析构函数"<<endl; 
	}
};
 
 
float Shape::area()
	{	return 1;
	}

class rectangle: public Shape
{	private:
	int lenSide,widSide;
	public:
	rectangle(int a,int b)//有参数的构造函数 
	{	lenSide=a;
 		widSide=b;
 		cout<<"rectangle int 构造函数"<<endl; 
	}
//	void set(int a,int b);
	float area();//计算面积 
	rectangle()
	{	cout<<"rectangle构造函数"<<endl;
	}
	~rectangle()
	{	cout<<"rectangle析构函数"<<endl; 
	}	
 };
 
 
 
 float rectangle::area()//长方形面积 
 {	float ar;
 	ar=lenSide*widSide;
 	return ar;
 }
 
 /*void rectangle::set(int a,int b)
 {	lenSide=a;
 	widSide=b;
 }
*/

 class circle:public Shape
 {	private:
 		int R;
 	public:
 		
 	//	void set1(int a); 
 		float area();
 		circle()
		{	cout<<"circle构造函数"<<endl;
		}	
		circle(int a)
		{	R=a;
		    cout<<"circle int构造函数"<<endl;
		}
		
		~circle()
		{	cout<<"circle析构函数"<<endl;
		}
  } ;
  
 /* void circle::set1(int a)
  {	R=a;
  }*/
  
 float circle::area()
 {	float ar;
 	ar=PI*R*R;
 	return ar;
 }

 class square:public rectangle
 {	private : 
 		int side;
 	public:
 /*	void set2(int a)
 	{	set(a,a);//rectangle中的函数 
	 }
*/
	 square(int a);

	
	 
 	square()
	 {	cout<<"square构造函数"<<endl;
	 }
 	~square()
 	{	cout<<"square析构函数"<<endl; 
	}
 };
 
 
   square::square (int a):rectangle(a,a)//派生类的构造函数 也调用了基类的构造函数 
   {  cout<<"square int构造函数"<<endl; }
 main()
 {	Shape a;
 	int len,wid;
 	cout<<"输入长方形的长:";
 	cin>>len;
 	cout<<"输入长方形的宽:";
 	cin>>wid;
 	while((cin.fail())||(len<=0)||(wid<=0))
     {   cout<<"您的输入有误，请重新输入"<<endl;
         cin.clear();
         cin.ignore();
         cout<<"输入长方形的长:";
 	     cin>>len;
 	     cout<<"输入长方形的宽:";
 	     cin>>wid;
     } 
 	rectangle b(len,wid);
 	//b.set(len,wid);
 	cout<<"长方形面积为:"<<b.area()<<endl<<endl;
 	int R;
 	cout<<"输入圆形半径:";
 	cin>>R;
 	while((cin.fail())||(R<=0))
 	{     cout<<"您的输入有误，请重新输入"<<endl;
          cin.clear();
          cin.ignore();    
          cout<<"输入圆形半径:";
 	      cin>>R;
     }
 	circle c(R);
 //	c.set1(R);
 	cout<<"圆形面积为"<<c.area()<<endl<<endl;
 	int bian;
 	cout<<"输入正方形边长：";
	cin>>bian;
	while((cin.fail())||(bian<=0))
	{     cout<<"您的输入有误，请重新输入"<<endl;
	      cin.clear();
	      cin.ignore();
	      cout<<"输入正方形边长：";
	      cin>>bian;
    }
	square d(bian);
	//d.set2(bian); 构造函数中传值 不需要set 
	cout<<"正方形面积为"<<d.area()<<endl<<endl;
	
	system("pause");
	return 0;
	 
 	
 	
 }
 
 
 
 
