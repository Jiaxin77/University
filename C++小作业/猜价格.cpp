#include<iostream>
#include<stdlib.h>
#include<time.h>
#define a 1
#define b 1000
main()
{	using namespace std;
	int number,x,userNum,compare;
	int i;
	bool flag;//布尔型判断对错 
	flag=0;
	srand((unsigned)time(NULL)); //初始化随机数，使每次不同 
	number=(rand() % (b-a+1))+ a;//取 a-b之间的整数
	cout<<"Please input your number(1-1000 integer):";
	cin>>x;
	
	while((x<a)||(x>b)||cin.fail())//判断输入数字是否超出范围或者输入为字母 
	{    cout<<"您的输入有误，请注意范围"<<endl; 
	     cin.clear();//将流状态重置为良好 
	     cin.ignore();//清空流 
	     cout<<"Please input your number(1-1000 integer):";
       	 cin>>x;
    }
    userNum=x;
	if(userNum==number)//如果猜对了 
	{	flag=true;
		cout<<"Congratulations!You are right!"<<endl;
	}
	while(0==flag)
	{	cout<<"Sorry,your number is wrong."<<endl;
	    flag=false;
		if(userNum>number)
			{cout<<"Your number is bigger than true number."<<endl;
			}
		if(userNum<number)
			{cout<<"Your number is smaller than true number."<<endl;
			}
		
		cout<<"\nPlease try again:";
		cin>>userNum; 
		if(userNum==number)
		{	flag=true;
			cout<<"Congratulations!You are right!"<<endl;
			break;
		}
	}
	system("pause");
	return 0;
}
