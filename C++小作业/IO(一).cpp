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
		cout<<"�ļ��ɹ���"<<endl;
	else
		cout<<"�ļ���ʧ��"<<endl; 
	
	cout<<"�ַ���:"<<endl;
	cout<<"�������ַ��� #������"<<endl;
	cin>>c;
	File<<"�ַ�����"; 
	while(c!='#')
	{	File.write((char*)&c,sizeof(c));
		cin>>c;
		 
	}
	File<<endl; 
	
	cout<<"��������"<<endl;
	cout<<"�����븡���� �س�����"<<endl;
	cin>>f;
	while(cin.fail())
	File<<"��������"<<f<<endl; 

	File<<"������:"<<endl;
	File<<setprecision(2)<<f<<endl;//Ҫ��ͷ�ļ�iomanip 
	File.precision(2);File<<f; //���ֻ����ȵķ��� 
	 
	File<<endl; 
	
	cout<<"������:"<<endl;
	cout<<"�����볤���� �س����� "<<endl;
	cin>>li;
	File<<"������:"<<li<<endl;
	
	File<<endl; 
	
	cout<<"�޷�������"<<endl;
	cout<<"�������޷������� �س�����"<<endl;
	cin>>ui;
	File<<"�޷�������:"<<ui<<endl;
	
	cout<<"����"<<endl;
	cout<<"���������� �س�����"<<endl;
	cin>>ai;
	 
	File<<"ʮ����Ϊ��"<<ai<<endl;
	File<<"�˽���Ϊ��"<<oct<<ai<<endl;
	File<<"ʮ������Ϊ��"<<hex<<ai<<endl;
	
	
	File.close(); 
	
	system("pause");
	return 0;	
}
