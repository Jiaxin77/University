#include<iostream>
#include<fstream>
#include<string>//要用到string 

using namespace std;

main()
{	
	char filename[50];
	string str;
	int a=1;
	cout<<"输入一个文件名："<<endl;
    //getline(cin,str,'\n') ;
    cin>>filename; 
	ifstream In;
    In.open(filename);//要读入的文件 
	if(In.is_open())//判断文件是否打开 
		cout<<"文件Input成功打开"<<endl;
	while(!(In.is_open()))
	{	cout<<"文件Input打开失败"<<endl; 
		cin.clear();
		cin.ignore();
		cout<<"输入一个文件名："<<endl;
    	cin>>filename; 
		In.open(filename);//要读入的文件 
	}
		
	ofstream Out("output.txt"); //要写入的文件 
	if(Out.is_open())
		cout<<"文件Output成功打开"<<endl;
	else
		cout<<"文件Output打开失败"<<endl;
	while(!In.eof())//是否到文件尾 到文件尾后会eof会返回1 
	{	getline(In,str);//getline读取文件中每一行 
		cout<<str<<endl;//屏幕上输出下每行 
		Out<<a<<"."<<str<<endl;//文件中输出行号 
		a++;
		
	}
	//关闭文件 
	In.close();//要加In. 因为把文件看作的是流对象，close是对象的 
	Out.close();
	system("pause");
	
	return 0;
}

