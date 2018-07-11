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
	
	
 };//����ṹ�� ������Ϣ ������ 
 
 
 
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
 		void add();//��� 
 		void search();//���� 
 		void deleteNum();//ɾ�� 
 		void setList(ListPtr x=NULL)
 		{	HeadPtr=x;
		 }//ͷָ������ ���������ã� 
 		void save();//�����ļ� 
		void read();//��ȡ�ļ� 
		void output(ListPtr a);//���һ����Ϣ 
	    void select();//ѡ���� 
	    void set(int a);//ֵ���� 
	    void outBook();//����绰�� 
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


void Phone::outBook()//��������绰�� 
{	ListPtr currentPtr=NULL,prePtr=NULL;
	currentPtr=HeadPtr;
	cout<<endl<<"�绰����" <<endl; 
	if(HeadPtr==NULL)
	{	cout<<"��"<<endl<<endl; 
	}//�绰��Ϊ�� 
	while(currentPtr!=NULL)
	{	cout<<"������"<<currentPtr->name<<" ����"<<currentPtr->number<<endl;
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
 	cout<<"������"<<endl;
	cin>>Name; 
	
	cout<<"�绰���룺"<<endl;
	cin>>Num;
	int flag=0;

	
	newPtr=new List;
	//newPtr=(ListPtr)malloc(sizeof(List));//
	if(newPtr==NULL)
	{	cout<<"��̬�ڴ�����ʧ�ܣ�"<<endl; 
	}
    else 
	       {	while(Name[a]!='\0'&&flag==0)
	             	 {newPtr->name[a]=Name[a];
	              	 a++;
	              	 
					  
	              	 }
	              	  newPtr->name[a]='\0';
	        //	newPtr->name=Name;
            //Ҫ�ӽ���������Ȼ���ʱ���ֺ��������ֵķ��� 
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
       		if(currentPtr==NULL)//ͷָ��Ϊ�� 
       		 {  HeadPtr=newPtr;//����ͷָ�� 
           		HeadPtr->next=NULL;//nextҪ��Ϊ�գ��� 
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
           		  }//��Ϊ��ʱ ����ҿյ� 
        	output(newPtr);
        	prePtr->next=newPtr;  
        	newPtr->next=NULL;//
			}
       }	
 }
 
 void Phone::search()
 {    
 	char Name[50];
      cout<<"����Ҫ������������";
      cin>>Name;
      int i=0,j=0;
      bool flag;//�Ƿ���ͬ 
      ListPtr currentPtr=NULL,prePtr=NULL;
      currentPtr=HeadPtr;
      if(HeadPtr==NULL)
      {	cout<<"�õ绰��Ϊ�գ��޷�����������"<<endl; 
	  }
	  else
	  {
	  
     	 while(currentPtr!=NULL)
      	{ 
	  		while((currentPtr->name[i]!='\0')&&(currentPtr->number[i]!='\0'))
       	       {  if(currentPtr->name[i]==Name[i])
                    {  flag=true;}
                 else
                    {  flag=false;//ֻҪ��һ���ַ���һ�¾��˳��Ƚ� 
						break;}//����break��������һλ��ͬҲ����Ϊ��ͬ����� 
                 i++;
              	}//���ο�ÿ���ַ��Ƿ�һ�� 
         	if(flag==1)
         	 { output(currentPtr);
          	
           		 j++;
          	 }
          	 prePtr=currentPtr;
          	 currentPtr=currentPtr->next;
		  	 flag=0; i=0;//�������㣡�� 
        }
      	if(j==0)
      	{cout<<"û�и���ϵ�ˣ�"<<endl;}        
                                    
  	  }
      
      
 }
 
 void Phone::deleteNum()
 {    char Name[50];
      cout<<"����Ҫɾ����������";
      cin>>Name;
      int i=0,j=0;
      ListPtr currentPtr=NULL,prePtr=NULL;
      currentPtr=HeadPtr;
     // prePtr->next=NULL;
      if(HeadPtr==NULL)
	  {	cout<<"�õ绰��Ϊ�գ��޷�����ɾ����"<<endl; 
	  }
	  else
	  {
	  
    	bool flag;
      	while(currentPtr!=NULL)//ͬ ���� 
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
			  }//ͷָ�������ָ��֮��ģ���Ȼ��ֹͣ���� 
            prePtr->next=currentPtr->next;//�������b�浽a��prePtr���ݴ洫�ݵ����� 
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
      	{cout<<"û�и���ϵ�ˣ�"<<endl;}        
	  }
}
 
 
 
 void Phone::save()
 {    ofstream Numbook("NumberBook.txt");
 	  if(Numbook.is_open())
	   	cout<<"�ļ��ɹ���"<<endl;
	  else
	  	cout<<"�ļ���ʧ��"<<endl;
		   
      ListPtr currentPtr=NULL,prePtr=NULL;
      currentPtr=HeadPtr;
      /*if(HeadPtr==NULL)
      {	Numbook<<"��"<<endl; 
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
 	cout<<"����һ���ļ���"<<endl<<"(����4�����ļ���Ϊ��NumberBook.txt  �������ļ���Ϊ��NumberBook1.txt)��"<<endl;
   
    cin>>filename; 
	ifstream Numbook;
    Numbook.open(filename);//Ҫ������ļ� 
    while(!Numbook.is_open())
	{	cout<<"�ļ���ʧ��"<<endl;
		cin.clear();
		cin.ignore();
		cout<<"����һ���ļ���"<<endl<<"(����4�����ļ���Ϊ��NumberBook.txt  �������ļ���Ϊ��NumberBook1.txt)��"<<endl;
   		cin>>filename; 
	
    	Numbook.open(filename);//Ҫ������ļ� 
	 } 
	 
	if(Numbook.is_open())//�ж��ļ��Ƿ�� 
		cout<<"�ļ��ɹ���"<<endl;

	
     // ifstream Numbook("NumberBook1.txt");
 //��ȡ�ļ�����Ϣ 
		ListPtr currentPtr=NULL,prePtr=NULL;
		currentPtr=(ListPtr)malloc(sizeof(List));    
	  	Numbook.getline(currentPtr->name,10,':');
	  	Numbook.getline(currentPtr->number,20);
		HeadPtr=currentPtr;	   
		
		
      while(!(Numbook.eof()))
      { prePtr=currentPtr;
        currentPtr->next=(ListPtr)malloc(sizeof(List));
        currentPtr=currentPtr->next;
        Numbook.getline(currentPtr->name,10,':');//�ļ��ڴ洢��ʽ ���� ���������� �洢 
	  	Numbook.getline(currentPtr->number,20);
	  }
      currentPtr->next=NULL;		
        
            
      
      
      Numbook.close();
 }
                             
 
 
 
 main()
 {	Phone pBook;
 	ListPtr B=NULL;
 	int s;
 	cout<<"�绰���������£�"<<endl; 
 	cout<<"1 ��������"<<endl<<"2 �����ϵ��"<<endl<<"3 ɾ����ϵ��"<<endl<<"4 ����绰��"<<endl<<"5 ��ȡ�绰��"<<endl<<"0 �˳�"<<endl;
 	cout<<"��ѡ��Ҫʹ�õĹ��ܣ�" <<endl;
 	cin>>s;
 	while(cin.fail()||(s<0)||(s>5))
 	{	cin.clear();
		cin.ignore();
		cout<<"���������������������룺";
	 	cin>>s; 
	 }
 	pBook.setList(B);//���ӵĻ���ֹͣ���� ���� 
 	while((s>=1)&&(s<=5))
 	{	pBook.set(s);
 		pBook.select();
 		cout<<"��ѡ��Ҫʹ�õĹ���:"<<endl;
 		cin>>s;
 		while(cin.fail()||(s<0)||(s>5))
 	{	cin.clear();
		cin.ignore();
	 	cout<<"���������������������룺";
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
