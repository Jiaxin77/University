#include<iostream>
#include<stdlib.h>
#include<time.h>
#define a 1
#define b 1000
main()
{	using namespace std;
	int number,x,userNum,compare;
	int i;
	bool flag;//�������ж϶Դ� 
	flag=0;
	srand((unsigned)time(NULL)); //��ʼ���������ʹÿ�β�ͬ 
	number=(rand() % (b-a+1))+ a;//ȡ a-b֮�������
	cout<<"Please input your number(1-1000 integer):";
	cin>>x;
	
	while((x<a)||(x>b)||cin.fail())//�ж����������Ƿ񳬳���Χ��������Ϊ��ĸ 
	{    cout<<"��������������ע�ⷶΧ"<<endl; 
	     cin.clear();//����״̬����Ϊ���� 
	     cin.ignore();//����� 
	     cout<<"Please input your number(1-1000 integer):";
       	 cin>>x;
    }
    userNum=x;
	if(userNum==number)//����¶��� 
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
