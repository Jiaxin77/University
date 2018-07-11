#include "logresign.h"

using namespace std;

void regist(Player *c,Admin *a,int *Atotal,int *Ptotal,int idFlag)
  {  //注册
      string password;
	  string passwordCom;				
      string name;
     
	 //cout<<"请输入您的身份,1代表玩家，2代表出题人\n";
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
			cout<<"请您输入用户名\n";
	 		cin>>name;
	 		for(int j=0;j<*Ptotal&&nameFlag==0;j++)
	 		{	if(name.compare(c[j].getname())==0)//j=1时就停止运行了？ 
	 				{	cout<<"您输入的用户名已存在！\n"; 
						nameFlag=1;//不再循环 
				 	}
			}
			
			if(nameFlag==0)
			{	c[*Ptotal].setname(name);//还是加一？ 
				cout<<"请您输入密码\n";
				cin>>passwordCom;
				cout<<"请您再次输入密码\n";
				cin>>password;
				while(password.compare(passwordCom)!=0)
				{	cout<<"您两次输入的密码不一致\n";
					cout<<"请您输入密码\n";
					cin>>passwordCom;
					cout<<"请您再次输入密码\n";
					cin>>password;
				}
				okFlag=1;
				c[*Ptotal].setpassword(password);
				
			}
		  
		  
	    }
		(*Ptotal)++;
	    cout << "玩家注册成功";
 	}
 	
     
     else if(idFlag==2)
	 {	
	 	
	 	
	 	while(okFlag==0)
		{	cin.clear();
			cin.ignore(); 
			nameFlag=0;
			cout<<"请您输入用户名\n";
	 		cin>>name;
	 		for(int j=0;j<*Atotal&&nameFlag==0;j++)
	 		{	if(name.compare(a[j].getname())==0)
	 				{	cout<<"您输入的用户名已存在！\n"; 
						nameFlag=1;//不再循环 
				 	}
			}
			
			if(nameFlag==0)
			{	a[*Atotal].setname(name);//还是加一？ 
				cout<<"请您输入密码\n";
				cin>>passwordCom;
				cout<<"请您再次输入密码\n";
				cin>>password;
				while(password.compare(passwordCom)!=0)
				{	cout<<"您两次输入的密码不一致\n";
					cout<<"请您输入密码\n";
					cin>>passwordCom;
					cout<<"请您再次输入密码\n";
					cin>>password;
				}
				okFlag=1;
				a[*Atotal].setpassword(password);
				
			}
		  
		  
	    }
		(*Atotal)++;
	    cout << "出题人注册成功"<<endl;
 	}
 	
    
         
    
  
     
 }

 int logo(int Playertotal,int Admtotal,Player *c,Admin *a,int idFlag)
 {//登录
     string password; 
     string name;
    // int idFlag;
     int logFlag=0;
     cin.clear();
     cin.ignore();
     //cout<<"请输入您的身份,1代表玩家，2代表出题人\n";
     //cin>>idFlag;
	 cout << "用户名：\n";
     cin>>name;
     cout <<"密码：\n";
     cin>>password;
     if(idFlag==1)
     {	for(int i=0;i<Playertotal&&logFlag==0;i++)
   	 	 {	if(c[i].getname().compare(name)==0)
   	 	 		{	if(c[i].getpassword().compare(password)==0)
   	 	 				{
							 cout<<"登录成功！" ;
							 logFlag=1;
   	 	 					 return i;
   	 	 				}
   	 	 			else
						 {  cout<<"您输入的用户名或密码有误！\n";
						  	return -1;
							 }	
					 }
   	 	 
		 }
		 if(logFlag==0)
		 {	cout<<"该用户不存在！\n";
		 	
		 }
		 return -1; 
		 
	 }  
	 
	 else if(idFlag==2)
     {	for(int i=0;i<Admtotal&&logFlag==0;i++)
   	 	 {	if(a[i].getname().compare(name)==0)
   	 	 		{	if(a[i].getpassword().compare(password)==0)
   	 	 				{
							 cout<<"登录成功！" ;
							 logFlag=1;
   	 	 					 return i;
   	 	 				}
   	 	 			else
						 {  cout<<"您输入的用户名或密码有误！\n";
						  	return -1;
							 }	
					 }
   	 	 
		 }
		 if(logFlag==0)
		 {	cout<<"该用户不存在！\n";
		 	
		 }
		 return -1; 
		 
	 }
 
 
 	     

}

