#include<iostream>

int stonetolb(int);

int main()
{	using namespace std;
	int stone;
	cout << "Enter the weight in stone:";
	cin >>stone;
	int pounds;
	pounds=stonetolb(stone);
	cout <<stone<<" stone = "<<pounds<<" pounds"<<endl;
	return 0;
	
 } 
 
 int stonetolb(int n)
 {	using namespace std;
 	return 14*n;
  } 
