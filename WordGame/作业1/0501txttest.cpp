#include <fstream>

#include <iostream>
#include <string>
#include<string.h> 
#include<stdlib.h>
#include<stdio.h>
#include"logresign.h"
#include"PlayerClass.h"
#include "file.h"
#include "userbox.h" 
using namespace std;
/*
struct user
       {
           string password;
           string name;
        };
 */ 

main()
{	int choose=-1;
	int flag=1;
	int logoFlag=0;
	Player c[150];//const��һ��
	Admin a[100];
	int PTotal=0,ATotal=0;
	int PlayFlag=1;
	int AdminFlag=1;
	PTotal=ReadPlayerFile(c);
	ATotal=ReadAdminFile(a);
	/*for(int j=0;j<PTotal;j++)
	{	cout<<j<<endl<<endl<<c[j].getname()<<endl<<c[j].getpassword()<<endl<<c[j].getWStage()<<endl<<c[j].getWPassedNum()<<endl<<c[j].getWrank()<<endl;
	 }*/ 
	ATotal=ReadAdminFile(a);
	int *PTotalptr=&PTotal;
	int *ATotalptr=&ATotal;
	while(flag)
	{//	cout<<"�������"<<*PTotalptr; 
	/*	for(int j=0;j<*PTotalptr;j++)
		{	cout<<endl<<endl<<c[j].getname()<<endl<<c[j].getpassword()<<endl<<c[j].getWStage()<<endl<<c[j].getWPassedNum()<<endl<<c[j].getWExp()<<endl;
	 	} 
	 	for(int w=0;w<*ATotalptr;w++)
	 	{	cout<<endl<<endl<<a[w].getname()<<endl<<a[w].getpassword()<<endl<<a[w].getCCount()<<endl<<a[w].getCStage()<<endl;
		 }
	*/
		cout<<"����ѡ����Ҫ���еĲ�����\n";
		cout<<"0-�˳� 1-��¼ 2-ע�� "<<endl;
		cin>>choose;
		if(cin.fail()||(choose!=0&&choose!=1&&choose!=2))
		{
			cout<<"������������"<<endl;
			cin.clear();
			cin.ignore(); 
			
		}
		else if(choose==0)
		{	flag=0;
			updatePlayerFile(c,*PTotalptr);
			updateAdminFile(a,*ATotalptr);
		}
		else if(choose==1)
		{	cout<<"�������������,1������ң�2���������\n";
			int idFlag;
	 		cin>>idFlag; 
	 		if(cin.fail()||idFlag!=1&&idFlag!=2)
	 		{
	 			cout<<"������������"<<endl;
				cin.clear();
				cin.ignore(); 
			 }
			else
			{
				
			
				logoFlag=logo(*PTotalptr,*ATotalptr,c,a,idFlag);
				if(logoFlag!=-1)
				{	flag=0;
					 PlayFlag=1;
					 AdminFlag=1;
					if(idFlag==1)
					{	cout<<"��Ϸ��ҳ"<<endl; 
						PlayFlag=PlayerBox(logoFlag,*PTotalptr,*ATotalptr,a,c);
						if(PlayFlag==0)
						{flag=1;	}//int�� 
					}
					else if(idFlag==2)
					{
						cout<<"��������ҳ"<<endl;
						AdminFlag=AdminBox(logoFlag,*PTotalptr,*ATotalptr,a,c); 
						if(AdminFlag==0)
						{	flag=1;
						}
					}
					//ת��֮������//logoflag���������±� 
					
				}
			}
			
		}
		else if(choose==2)
		{	cout<<"�������������,1������ң�2���������\n";
			int idFlag;
	 		cin>>idFlag; 
	 		if(cin.fail()||idFlag!=1&&idFlag!=2)
	 		{
	 			cout<<"������������"<<endl; 
	 			cin.clear();
			    cin.ignore();
			 }
			 else
			 {
			 			 
			regist(c,a,ATotalptr,PTotalptr,idFlag);
			}
		//	cout<<*PTotalptr; 
		 } 
	}
	system("pause");
	return 0;
}
