#include<iostream>

using namespace std;

class Car;//��ΪBoat�� ��Ԫ����Ҫ�õ�Car��������ǰ���� 
class Boat
{	private:
		double weight;
	public:
		friend	double TotalWeight(Boat& b, Car& c);
	Boat()
    {     weight=10;
          cout<<"Boat����"<<endl;
    }
	~Boat(){cout<<"Boat����"<<endl;}
 } ; 
 
class Car
{	private:
		double weight;
	public:
		friend	double TotalWeight(Boat& b, Car& c);
	Car()
    {    weight=20;
         cout<<"Car����"<<endl;
    }
	~Car(){cout<<"Car����"<<endl;}
};

double TotalWeight(Boat& b,Car& c)
{	double wei;
    cout<<"���봬�أ�";//��Ϊ����Ϊ˽�ã�����Ҫ����Ԫ�����ж�ȡ��ֵ 
	cin>>b.weight;
	cout<<"���복�أ�";
	cin>>c.weight;
	while((b.weight<0)||(c.weight<0)||(cin.fail()))//�������� 
	{	cout<<"\n����������������������"<<endl;
	    cin.clear();
        cin.ignore();                                                      
	    cout<<"���봬�أ�";
	    cin>>b.weight;
        cout<<"���복�أ�";
	    cin>>c.weight;
	 } 

	
	wei=b.weight+c.weight;
	return wei;
}

main()
{	Boat x;
	Car y;

	cout<<"���ͳ������أ�"<<TotalWeight(x,y)<<endl;
	system("pause");
	return 0;	 
}

