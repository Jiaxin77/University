#include<iostream>
void simon (int);
int main()
{	using namespace std;
	simon(3);
	cout <<"Please input an integer:";
	int num;
	cin  >>num;//读取数字 
	simon(num);
	cout <<"Done!"<<endl;
	return 0;
}

void simon(int n)
{	using namespace std;//函数中也要写这个！！ 
	cout <<"Simon says touch your toes "<<n<<" times"<<endl;
}
