#include<iostream>
void simon (int);
int main()
{	using namespace std;
	simon(3);
	cout <<"Please input an integer:";
	int num;
	cin  >>num;//��ȡ���� 
	simon(num);
	cout <<"Done!"<<endl;
	return 0;
}

void simon(int n)
{	using namespace std;//������ҲҪд������� 
	cout <<"Simon says touch your toes "<<n<<" times"<<endl;
}
