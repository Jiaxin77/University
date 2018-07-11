#include<iostream>
#include<fstream>
#include<iomanip> 
using namespace std;

main()
{	char c;
	int ai,bi,i;
	unsigned int ui;
	long int li;
	float f;
	
	ofstream File("io_output.txt");
	if(File.is_open())
		cout<<"文件成功打开"<<endl;
	else
		cout<<"文件打开失败"<<endl; 
	
	cout<<"字符串:"<<endl;
	cout<<"请输入字符串 #结束："<<endl;
	cin>>c;
	File<<"字符串："; 
	while(c!='#')
	{	File.write((char*)&c,sizeof(c));
		cin>>c;
		 
	}
	File<<endl; 
	
	cout<<"浮点数："<<endl;
	cout<<"请输入浮点数 回车结束"<<endl;
	cin>>f;
	while(cin.fail())
	File<<"浮点数："<<f<<endl; 

	File<<"换精度:"<<endl;
	File<<setprecision(2)<<f<<endl;//要加头文件iomanip 
	File.precision(2);File<<f; //两种换精度的方法 
	 
	File<<endl; 
	
	cout<<"长整型:"<<endl;
	cout<<"请输入长整型 回车结束 "<<endl;
	cin>>li;
	File<<"长整型:"<<li<<endl;
	
	File<<endl; 
	
	cout<<"无符号整型"<<endl;
	cout<<"请输入无符号整型 回车结束"<<endl;
	cin>>ui;
	File<<"无符号整型:"<<ui<<endl;
	
	cout<<"整型"<<endl;
	cout<<"请输入整型 回车结束"<<endl;
	cin>>ai;
	 
	File<<"十进制为："<<ai<<endl;
	File<<"八进制为："<<oct<<ai<<endl;
	File<<"十六进制为："<<hex<<ai<<endl;
	
	
	File.close(); 
	
	system("pause");
	return 0;	
}
