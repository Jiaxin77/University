#include<iostream>
using namespace std;

int main()
{	cout << "How many carrots do you have?" <<endl;
	int carrots;
	cin >> carrots;
	cout << "Now you have two more carrots."<<endl;
	carrots=carrots+2;
	cout << "So you have "<<carrots<<" carrots"<<endl;
	return 0;
}
