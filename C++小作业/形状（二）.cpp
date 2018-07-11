#include<iostream>
using namespace std;
#define PI 3.14


class Shape
{
	public:
		
	virtual	float area()=0;//纯虚函数 使该类为抽象类 （与之前的区别，开始时少调用一次Shape构造函数） 
	Shape()
	{	cout<<"Shape构造函数"<<endl;
	}
	~Shape()
	{	cout<<"Shape析构函数"<<endl; 
	}
};
 
 


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
   square::square(int a):rectangle(a,a)//派生类构造函数 
   {cout<<"square int构造函数"<<endl;}

 
 main()
 {	
 	int len,wid;
 	cout<<"输入长方形的长:";
 	cin>>len;
 	cout<<"输入长方形的宽:";
 	cin>>wid;
 	while((cin.fail())||(len<=0)||(wid<=0))//防暴力输入 
    {     cout<<"您的输入有误，请重新输入"<<endl;
          cin.clear();
          cin.ignore();
 	      cout<<"输入长方形的长:";
 	      cin>>len;
       	  cout<<"输入长方形的宽:";
 	      cin>>wid;
    } 
 	Shape *b=new rectangle(len,wid);//开始的时候直接Shape 会报错 抽象类 基类不能描述此类对象信息 
 	if(b==NULL)
       {cout<<"创建失败"<<endl;}
    else
       {cout<<"创建成功"<<endl;}
     
     //rectangle b(len,wid);
 	//b.set(len,wid);
 	cout<<"长方形面积为:"<<b->area()<<endl<<endl;//要用-> 
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
//	d.set2(bian);
	cout<<"正方形面积为"<<d.area()<<endl<<endl;
	
	system("pause");
	return 0;
	 
 	
 	
 }
 
 
 
 
