#include<iostream>
using namespace std;
#define PI 3.14


class Shape
{
	public:
		
	virtual	float area()=0;//���麯�� ʹ����Ϊ������ ����֮ǰ�����𣬿�ʼʱ�ٵ���һ��Shape���캯���� 
	Shape()
	{	cout<<"Shape���캯��"<<endl;
	}
	~Shape()
	{	cout<<"Shape��������"<<endl; 
	}
};
 
 


class rectangle: public Shape
{	private:
	int lenSide,widSide;
	public:
	rectangle(int a,int b)//�в����Ĺ��캯�� 
	{	lenSide=a;
 		widSide=b;
 		cout<<"rectangle int ���캯��"<<endl; 
	}
//	void set(int a,int b);
	float area();//������� 
	rectangle()
	{	cout<<"rectangle���캯��"<<endl;
	}
	~rectangle()
	{	cout<<"rectangle��������"<<endl; 
	}	
 };
 
 
 
 float rectangle::area()//��������� 
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
		{	cout<<"circle���캯��"<<endl;
		}	
		circle(int a)
		{	R=a;
		    cout<<"circle int���캯��"<<endl;
		}
		
		~circle()
		{	cout<<"circle��������"<<endl;
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
 	{	set(a,a);//rectangle�еĺ��� 
	 }
 */	 
	 square(int a);
	 
 	square()
	 {	cout<<"square���캯��"<<endl;
	 }
 	~square()
 	{	cout<<"square��������"<<endl; 
	}
 };
   square::square(int a):rectangle(a,a)//�����๹�캯�� 
   {cout<<"square int���캯��"<<endl;}

 
 main()
 {	
 	int len,wid;
 	cout<<"���볤���εĳ�:";
 	cin>>len;
 	cout<<"���볤���εĿ�:";
 	cin>>wid;
 	while((cin.fail())||(len<=0)||(wid<=0))//���������� 
    {     cout<<"����������������������"<<endl;
          cin.clear();
          cin.ignore();
 	      cout<<"���볤���εĳ�:";
 	      cin>>len;
       	  cout<<"���볤���εĿ�:";
 	      cin>>wid;
    } 
 	Shape *b=new rectangle(len,wid);//��ʼ��ʱ��ֱ��Shape �ᱨ�� ������ ���಻���������������Ϣ 
 	if(b==NULL)
       {cout<<"����ʧ��"<<endl;}
    else
       {cout<<"�����ɹ�"<<endl;}
     
     //rectangle b(len,wid);
 	//b.set(len,wid);
 	cout<<"���������Ϊ:"<<b->area()<<endl<<endl;//Ҫ��-> 
 	int R;
 	cout<<"����Բ�ΰ뾶:";
 	cin>>R;
 	while((cin.fail())||(R<=0))
 	{     cout<<"����������������������"<<endl;
          cin.clear();
          cin.ignore();
          cout<<"����Բ�ΰ뾶:";
          cin>>R;
     }
 	circle c(R);
 //	c.set1(R);
 	cout<<"Բ�����Ϊ"<<c.area()<<endl<<endl;
 	int bian;
 	cout<<"���������α߳���";
	cin>>bian;
	while((cin.fail())||(bian<=0))
	{     cout<<"����������������������"<<endl;
          cin.clear();
          cin.ignore();
          cout<<"���������α߳���";
	      cin>>bian;
    }
	square d(bian);
//	d.set2(bian);
	cout<<"���������Ϊ"<<d.area()<<endl<<endl;
	
	system("pause");
	return 0;
	 
 	
 	
 }
 
 
 
 
