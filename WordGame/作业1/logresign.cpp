#include "logresign.h"

using namespace std;

void regist(Player *c,Admin *a,int *Atotal,int *Ptotal,int idFlag)
  {  //ע��
      string password;
	  string passwordCom;				
      string name;
     
	 //cout<<"�������������,1������ң�2���������\n";
	 //int idFlag;
	 //cin>>idFlag; 
	 int okFlag=0;
	 int nameFlag=0;
	 if(idFlag==1)
	 {	
	 	
	 	
	 	while(okFlag==0)
		{	cin.clear();
			cin.ignore(); 
			nameFlag=0;
			cout<<"���������û���\n";
	 		cin>>name;
	 		for(int j=0;j<*Ptotal&&nameFlag==0;j++)
	 		{	if(name.compare(c[j].getname())==0)//j=1ʱ��ֹͣ�����ˣ� 
	 				{	cout<<"��������û����Ѵ��ڣ�\n"; 
						nameFlag=1;//����ѭ�� 
				 	}
			}
			
			if(nameFlag==0)
			{	c[*Ptotal].setname(name);//���Ǽ�һ�� 
				cout<<"������������\n";
				cin>>passwordCom;
				cout<<"�����ٴ���������\n";
				cin>>password;
				while(password.compare(passwordCom)!=0)
				{	cout<<"��������������벻һ��\n";
					cout<<"������������\n";
					cin>>passwordCom;
					cout<<"�����ٴ���������\n";
					cin>>password;
				}
				okFlag=1;
				c[*Ptotal].setpassword(password);
				
			}
		  
		  
	    }
		(*Ptotal)++;
	    cout << "���ע��ɹ�";
 	}
 	
     
     else if(idFlag==2)
	 {	
	 	
	 	
	 	while(okFlag==0)
		{	cin.clear();
			cin.ignore(); 
			nameFlag=0;
			cout<<"���������û���\n";
	 		cin>>name;
	 		for(int j=0;j<*Atotal&&nameFlag==0;j++)
	 		{	if(name.compare(a[j].getname())==0)
	 				{	cout<<"��������û����Ѵ��ڣ�\n"; 
						nameFlag=1;//����ѭ�� 
				 	}
			}
			
			if(nameFlag==0)
			{	a[*Atotal].setname(name);//���Ǽ�һ�� 
				cout<<"������������\n";
				cin>>passwordCom;
				cout<<"�����ٴ���������\n";
				cin>>password;
				while(password.compare(passwordCom)!=0)
				{	cout<<"��������������벻һ��\n";
					cout<<"������������\n";
					cin>>passwordCom;
					cout<<"�����ٴ���������\n";
					cin>>password;
				}
				okFlag=1;
				a[*Atotal].setpassword(password);
				
			}
		  
		  
	    }
		(*Atotal)++;
	    cout << "������ע��ɹ�"<<endl;
 	}
 	
    
         
    
  
     
 }

 int logo(int Playertotal,int Admtotal,Player *c,Admin *a,int idFlag)
 {//��¼
     string password; 
     string name;
    // int idFlag;
     int logFlag=0;
     cin.clear();
     cin.ignore();
     //cout<<"�������������,1������ң�2���������\n";
     //cin>>idFlag;
	 cout << "�û�����\n";
     cin>>name;
     cout <<"���룺\n";
     cin>>password;
     if(idFlag==1)
     {	for(int i=0;i<Playertotal&&logFlag==0;i++)
   	 	 {	if(c[i].getname().compare(name)==0)
   	 	 		{	if(c[i].getpassword().compare(password)==0)
   	 	 				{
							 cout<<"��¼�ɹ���" ;
							 logFlag=1;
   	 	 					 return i;
   	 	 				}
   	 	 			else
						 {  cout<<"��������û�������������\n";
						  	return -1;
							 }	
					 }
   	 	 
		 }
		 if(logFlag==0)
		 {	cout<<"���û������ڣ�\n";
		 	
		 }
		 return -1; 
		 
	 }  
	 
	 else if(idFlag==2)
     {	for(int i=0;i<Admtotal&&logFlag==0;i++)
   	 	 {	if(a[i].getname().compare(name)==0)
   	 	 		{	if(a[i].getpassword().compare(password)==0)
   	 	 				{
							 cout<<"��¼�ɹ���" ;
							 logFlag=1;
   	 	 					 return i;
   	 	 				}
   	 	 			else
						 {  cout<<"��������û�������������\n";
						  	return -1;
							 }	
					 }
   	 	 
		 }
		 if(logFlag==0)
		 {	cout<<"���û������ڣ�\n";
		 	
		 }
		 return -1; 
		 
	 }
 
 
 	     

}

