#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
using namespace std;
 

 
struct person
{	char name[50];
	char number[20];
	struct person *next;
	
	
 };//定义结构体 储存信息 用链表 
 
 
 
 typedef struct person List;
 typedef struct person*ListPtr;
 
 class Phone
 {
 	private:
	 	ListPtr HeadPtr;
	 	int sel;
		 	
 
 	public:
 		Phone(){HeadPtr=NULL;}
 		~Phone(){}
 		void add();//添加 
 		void search();//搜索 
 		void deleteNum();//删除 
 		void setList(ListPtr x=NULL)
 		{	HeadPtr=x;
		 }//头指针设置 （链表设置） 
 		void save();//存入文件 
		void read();//读取文件 
		void output(ListPtr a);//输出一条信息 
	    void select();//选择功能 
	    void set(int a);//值传递 
	    void outBook();//输出电话本 
 };
 
 
/*void Phone::initList(ListPtr &L);
{    L=HeadPtr;
     L->next=NULL;
     cout<<"ok"<<endl;
}*/

void Phone ::output(ListPtr a)
{   
	
		cout<<a->name<<":"<<a->number<<endl;
} 


void Phone::outBook()//输出整个电话本 
{	ListPtr currentPtr=NULL,prePtr=NULL;
	currentPtr=HeadPtr;
	cout<<endl<<"电话本：" <<endl; 
	if(HeadPtr==NULL)
	{	cout<<"空"<<endl<<endl; 
	}//电话本为空 
	while(currentPtr!=NULL)
	{	cout<<"姓名："<<currentPtr->name<<" 号码"<<currentPtr->number<<endl;
		prePtr=currentPtr;
		currentPtr=currentPtr->next;
	}
	cout<<endl; 
}
 
 void Phone::set(int a)
{	sel=a;
}

 void Phone::select()
 {	
 	Phone a;

	switch(sel)
	{	case 1:
			search();
			break;
		case 2:
			add();
			outBook();
			break;
		case 3:
			deleteNum();
			outBook();
			break;
		case 4:
			save();
			break;
		case 5:
			read();
			outBook();
			break;
		default:
			break;
	 } 
 }
 
 void Phone::add()
 {	char Name[50]={'\0'};
 	char Num[20]={'\0'};
 	int a=0,b=0;
    ListPtr newPtr=NULL;
    ListPtr currentPtr=NULL;
    ListPtr prePtr=NULL;
 	cout<<"姓名："<<endl;
	cin>>Name; 
	
	cout<<"电话号码："<<endl;
	cin>>Num;
	int flag=0;

	
	newPtr=new List;
	//newPtr=(ListPtr)malloc(sizeof(List));//
	if(newPtr==NULL)
	{	cout<<"动态内存申请失败！"<<endl; 
	}
    else 
	       {	while(Name[a]!='\0'&&flag==0)
	             	 {newPtr->name[a]=Name[a];
	              	 a++;
	              	 
					  
	              	 }
	              	  newPtr->name[a]='\0';
	        //	newPtr->name=Name;
            //要加结束符，不然输出时名字后面会有奇怪的符号 
       	    while(Num[b]!='\0')
              	{	newPtr->number[b]=Num[b];
              		b++;
              		if(b>20)
              		{break;}
			 	}
			newPtr->number[b]='\0';
        	currentPtr=HeadPtr;
       		prePtr=NULL;
   //     currentPtr->next=NULL;
       		if(currentPtr==NULL)//头指针为空 
       		 {  HeadPtr=newPtr;//存入头指针 
           		HeadPtr->next=NULL;//next要置为空！！ 
       		 }
       		else
        	{ 	while(currentPtr!=NULL)
           		 { prePtr=currentPtr;
           		 	if(currentPtr->next==NULL)
           		 	{
						
           		 	currentPtr->next=(ListPtr)malloc(sizeof(List));
              	   	break;
					 }
					 currentPtr=currentPtr->next;
           		  }//不为空时 向后找空的 
        	output(newPtr);
        	prePtr->next=newPtr;  
        	newPtr->next=NULL;//
			}
       }	
 }
 
 void Phone::search()
 {    
 	char Name[50];
      cout<<"输入要搜索的姓名：";
      cin>>Name;
      int i=0,j=0;
      bool flag;//是否相同 
      ListPtr currentPtr=NULL,prePtr=NULL;
      currentPtr=HeadPtr;
      if(HeadPtr==NULL)
      {	cout<<"该电话本为空，无法进行搜索！"<<endl; 
	  }
	  else
	  {
	  
     	 while(currentPtr!=NULL)
      	{ 
	  		while((currentPtr->name[i]!='\0')&&(currentPtr->number[i]!='\0'))
       	       {  if(currentPtr->name[i]==Name[i])
                    {  flag=true;}
                 else
                    {  flag=false;//只要有一个字符不一致就退出比较 
						break;}//不加break会出现最后一位相同也会认为相同的情况 
                 i++;
              	}//依次看每个字符是否都一致 
         	if(flag==1)
         	 { output(currentPtr);
          	
           		 j++;
          	 }
          	 prePtr=currentPtr;
          	 currentPtr=currentPtr->next;
		  	 flag=0; i=0;//别忘归零！！ 
        }
      	if(j==0)
      	{cout<<"没有该联系人！"<<endl;}        
                                    
  	  }
      
      
 }
 
 void Phone::deleteNum()
 {    char Name[50];
      cout<<"输入要删除的姓名：";
      cin>>Name;
      int i=0,j=0;
      ListPtr currentPtr=NULL,prePtr=NULL;
      currentPtr=HeadPtr;
     // prePtr->next=NULL;
      if(HeadPtr==NULL)
	  {	cout<<"该电话本为空，无法进行删除！"<<endl; 
	  }
	  else
	  {
	  
    	bool flag;
      	while(currentPtr!=NULL)//同 查找 
      	{ 
	  	 while((currentPtr->name[i]!='\0')&&(currentPtr->number[i]!='\0'))
              {  if(currentPtr->name[i]==Name[i])
                    {  flag=true;}
                 else
                    {  flag=false;
					break;}
                 i++;
              }
         if(flag==1)
          { output(currentPtr);
       	 	if(HeadPtr==currentPtr)
         	 {	prePtr=HeadPtr;
          		HeadPtr=HeadPtr->next;
			  }//头指针必须有指向之后的，不然会停止工作 
            prePtr->next=currentPtr->next;//类似与把b存到a，prePtr起暂存传递的作用 
            free(currentPtr); 
            currentPtr=prePtr->next;
            
            j++;
			break; 
          }
          prePtr=currentPtr;
          currentPtr=currentPtr->next;
          i=0;flag=0;
       	 }
 	  
     	 if(j==0)
      	{cout<<"没有该联系人！"<<endl;}        
	  }
}
 
 
 
 void Phone::save()
 {    ofstream Numbook("NumberBook.txt");
 	  if(Numbook.is_open())
	   	cout<<"文件成功打开"<<endl;
	  else
	  	cout<<"文件打开失败"<<endl;
		   
      ListPtr currentPtr=NULL,prePtr=NULL;
      currentPtr=HeadPtr;
      /*if(HeadPtr==NULL)
      {	Numbook<<"空"<<endl; 
	  }*/
      while(currentPtr!=NULL)
           {    if((currentPtr->next)!=NULL)
           		{	Numbook<<currentPtr->name<<":"<<currentPtr->number<<endl;
		   		}
		   		if((currentPtr->next)==NULL)
		   		{	Numbook<<currentPtr->name<<":"<<currentPtr->number;
				}
		   		
                prePtr=currentPtr;
                currentPtr=currentPtr->next;
           }
      Numbook.close();
      
 }
 
 void Phone::read()
 {  string str;
 	char filename[20]={0}; 
 	cout<<"输入一个文件名"<<endl<<"(步骤4存入文件名为：NumberBook.txt  测验用文件名为：NumberBook1.txt)："<<endl;
   
    cin>>filename; 
	ifstream Numbook;
    Numbook.open(filename);//要读入的文件 
    while(!Numbook.is_open())
	{	cout<<"文件打开失败"<<endl;
		cin.clear();
		cin.ignore();
		cout<<"输入一个文件名"<<endl<<"(步骤4存入文件名为：NumberBook.txt  测验用文件名为：NumberBook1.txt)："<<endl;
   		cin>>filename; 
	
    	Numbook.open(filename);//要读入的文件 
	 } 
	 
	if(Numbook.is_open())//判断文件是否打开 
		cout<<"文件成功打开"<<endl;

	
     // ifstream Numbook("NumberBook1.txt");
 //读取文件内信息 
		ListPtr currentPtr=NULL,prePtr=NULL;
		currentPtr=(ListPtr)malloc(sizeof(List));    
	  	Numbook.getline(currentPtr->name,10,':');
	  	Numbook.getline(currentPtr->number,20);
		HeadPtr=currentPtr;	   
		
		
      while(!(Numbook.eof()))
      { prePtr=currentPtr;
        currentPtr->next=(ListPtr)malloc(sizeof(List));
        currentPtr=currentPtr->next;
        Numbook.getline(currentPtr->name,10,':');//文件内存储格式 按照 姓名：号码 存储 
	  	Numbook.getline(currentPtr->number,20);
	  }
      currentPtr->next=NULL;		
        
            
      
      
      Numbook.close();
 }
                             
 
 
 
 main()
 {	Phone pBook;
 	ListPtr B=NULL;
 	int s;
 	cout<<"电话本功能如下："<<endl; 
 	cout<<"1 姓名搜索"<<endl<<"2 添加联系人"<<endl<<"3 删除联系人"<<endl<<"4 保存电话本"<<endl<<"5 读取电话本"<<endl<<"0 退出"<<endl;
 	cout<<"请选择要使用的功能：" <<endl;
 	cin>>s;
 	while(cin.fail()||(s<0)||(s>5))
 	{	cin.clear();
		cin.ignore();
		cout<<"您的输入有误，请重新输入：";
	 	cin>>s; 
	 }
 	pBook.setList(B);//不加的话会停止运行 ！！ 
 	while((s>=1)&&(s<=5))
 	{	pBook.set(s);
 		pBook.select();
 		cout<<"请选择要使用的功能:"<<endl;
 		cin>>s;
 		while(cin.fail()||(s<0)||(s>5))
 	{	cin.clear();
		cin.ignore();
	 	cout<<"您的输入有误，请重新输入：";
	 	cin>>s; 
	 }
 		
	 }
	 if(s==0)
	 {	free(B);
	 	B->next=NULL;
	 }
	 
	 
	 

 
 	system("pause");
 	return 0;
 }
