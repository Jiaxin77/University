#include<iostream>
#include<math.h>

using namespace std; 

class Point
{	public://֮��ľ�������õ������꣬����˽�� 
		float x1;
		float y1;
	

friend	float lenth(Point a,Point b);	//�õ���Ԫ���� ����ú�������ĳ�Ա������ͬ�ķ���Ȩ�� 

	Point();//�����캯���Ƿ񱻵��� 
	
	~Point();//�����������Ƿ񱻵��� 
	
			
};
 
Point::Point()
{  x1=0;
   y1=0;
   cout<<"�� ���캯��������"<<endl;}
Point::~Point()
{  cout<<"�� ��������������"<<endl;} 

float lenth(Point a,Point b)//��Ϊ����Ԫ���������ǳ�Ա�������������޶��� 
{	float len;
	float x,y;
	x=pow(a.x1-b.x1,2);
	y=pow(a.y1-b.y1,2);
	len=sqrt(x+y);
	return len;
}//���㳤�Ⱥ��� 

class JUXING
{	private:
		Point left;//�������Ͻǵ� 
		Point right;//�������½ǵ� 
	
	public:
		float area();//������� 
		
		void set(Point a1,Point b1)
		{	left=a1;
			right=b1;
		}//�ѵ�תΪ���ε� ֮��main���õ� 
	     
		JUXING()
		{	cout<<"���� ���캯��������"<<endl;
		    left.x1=0;
		    left.y1=10;
		    right.x1=10;
		    right.y1=0;
		}
        
        
		~JUXING()
		{	cout<<"���� ��������������"<<endl; 
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
{	JUXING t;//����һ�����ζ��� 
	Point l,r;
	
	cout<<"������������Ͻ�����(�ÿո�ֿ�)��";
	cin>>l.x1>>l.y1;//��ȡ���Ͻ����� 
	
	
	cout<<"\n������������½�����(�ÿո�ֿ�)��";
	cin>>r.x1>>r.y1;//��ȡ���½� 
	cout<<endl;
	
	while((l.x1>=r.x1)||(l.y1<=r.y1)||(cin.fail()))//����������²�����Ҫ�� 
	{	cout<<"����������������������"<<endl;
	    cin.clear();
	    cin.ignore();
        cout<<"������������Ͻ�����(�ÿո�ֿ�)��";
	    cin>>l.x1>>l.y1;
	    cout<<"\n������������½�����(�ÿո�ֿ�)��";
	    cin>>r.x1>>r.y1;
	    cout<<endl;
	}
	
	t.set(l,r);

	
	
//	cout<<"��������Ϊ��"<<lenth(l,r)<<endl;
	cout<<"�������Ϊ��"<<t.area()<<endl;
	system("pause");
	return 0;
	 
}
