 #include<iostream>
 #include"PlayerClass.h"
 #include"mytype.h"
 using namespace std;
 Admin::Admin()
 {		name="\0";
		password="\0";
		CStage=1;//�ȼ�
		CCount=0;
 }
 
 
 int Admin::getCCount()
 {
 	return CCount;
 }
 
 int Admin::getCStage()
 {
 	return CStage;
 }
 
 void Admin::setCCount(int count)
 {
 	CCount=count;
 }
 
 void Admin::setCStage(int stage)
 {
 	CStage=stage;
 }
 
 
 void Admin::AddWord(word *w,int *WTotal)
 {
 	system("cls");
 	if(*WTotal+1>=wordNum)//������������
	 {
		 cout<<"�޷�¼�룬�ʿ��Ѵ����ޣ�\n"; 
	 }
	else
	{
		string newword;
 		int okFlag=1;
 		int Flag=0;
		 int CINFLAG;
 		while(Flag==0)
 		{	okFlag=1;
 			CINFLAG=0;
 			while(CINFLAG==0)
 			{
			 
		 		cout<<"��������Ҫ��ӵĵ���"<<endl;
 				cin>>newword;
 				if(cin.fail())
				 {	cout<<"�������벻����Ҫ��"<<endl;
				 	CINFLAG=0;
				  }
				else
				{
					CINFLAG=1;
				}
 			}
 			for(int i=0;i<*WTotal&&okFlag==1;i++)
 			{
 				if(newword.compare(w[i].getdata())==0)
 				{	cout<<"������ĵ������ڿ��У����������룡"<<endl;
 					okFlag=0;
				 }	
			}
			if(okFlag==1)
			{
				Flag=1;
			}

		}
		w[*WTotal].setdata(newword);
		CINFLAG=0;
		int length;
		while(CINFLAG==0)
		{
		
			cout<<"�������뵥�ʳ���:"<<endl;
			cin>>length;
			if(cin.fail())
			{	
				cout<<"�������벻����Ҫ��\n";
				CINFLAG=0;
			}
			else
			{
				CINFLAG=1;
			}
		}
		w[*WTotal].setlength(length);
	
		(*WTotal)++;
		
		cout<<"���ѳɹ�¼�룡"<<endl;
		CCount++;//�����˳�������һ 
		changeCStage();
	}
	


 }
 
 void Admin::changeCStage()
 {
 	CStage=CCount/5+1;
 	
 }
 
