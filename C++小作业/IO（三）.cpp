#include<iostream>
#include<fstream>
#include<string>//Ҫ�õ�string 

using namespace std;

main()
{	
	char filename[50];
	string str;
	int a=1;
	cout<<"����һ���ļ�����"<<endl;
    //getline(cin,str,'\n') ;
    cin>>filename; 
	ifstream In;
    In.open(filename);//Ҫ������ļ� 
	if(In.is_open())//�ж��ļ��Ƿ�� 
		cout<<"�ļ�Input�ɹ���"<<endl;
	while(!(In.is_open()))
	{	cout<<"�ļ�Input��ʧ��"<<endl; 
		cin.clear();
		cin.ignore();
		cout<<"����һ���ļ�����"<<endl;
    	cin>>filename; 
		In.open(filename);//Ҫ������ļ� 
	}
		
	ofstream Out("output.txt"); //Ҫд����ļ� 
	if(Out.is_open())
		cout<<"�ļ�Output�ɹ���"<<endl;
	else
		cout<<"�ļ�Output��ʧ��"<<endl;
	while(!In.eof())//�Ƿ��ļ�β ���ļ�β���eof�᷵��1 
	{	getline(In,str);//getline��ȡ�ļ���ÿһ�� 
		cout<<str<<endl;//��Ļ�������ÿ�� 
		Out<<a<<"."<<str<<endl;//�ļ�������к� 
		a++;
		
	}
	//�ر��ļ� 
	In.close();//Ҫ��In. ��Ϊ���ļ���������������close�Ƕ���� 
	Out.close();
	system("pause");
	
	return 0;
}

