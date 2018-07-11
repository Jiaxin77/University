#include<iostream>

using namespace std;

class Car;//因为Boat中 友元函数要用到Car，所以提前声明 
class Boat
{	private:
		double weight;
	public:
		friend	double TotalWeight(Boat& b, Car& c);
	Boat()
    {     weight=10;
          cout<<"Boat构造"<<endl;
    }
	~Boat(){cout<<"Boat析构"<<endl;}
 } ; 
 
class Car
{	private:
		double weight;
	public:
		friend	double TotalWeight(Boat& b, Car& c);
	Car()
    {    weight=20;
         cout<<"Car构造"<<endl;
    }
	~Car(){cout<<"Car析构"<<endl;}
};

double TotalWeight(Boat& b,Car& c)
{	double wei;
    cout<<"输入船重：";//因为重量为私用，所以要在友元函数中读取数值 
	cin>>b.weight;
	cout<<"输入车重：";
	cin>>c.weight;
	while((b.weight<0)||(c.weight<0)||(cin.fail()))//输入有误 
	{	cout<<"\n您的输入有误，请重新输入"<<endl;
	    cin.clear();
        cin.ignore();                                                      
	    cout<<"输入船重：";
	    cin>>b.weight;
        cout<<"输入车重：";
	    cin>>c.weight;
	 } 

	
	wei=b.weight+c.weight;
	return wei;
}

main()
{	Boat x;
	Car y;

	cout<<"船和车的总重："<<TotalWeight(x,y)<<endl;
	system("pause");
	return 0;	 
}

