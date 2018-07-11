/******************************************************************
�ļ���:file.c
������:��ʫ�
�ա���:2017-04-20
�޸���:��ʫ漡������骡�������
�ա���:2017-05
�衡��:���ļ��а��������г������漰�ļ������ĺ�����ʵ�������ļ���ʼ�����򣬴洢���н���������ļ���Ϣ�����ļ�������ص����й��ܡ�
�桡��: v050602
******************************************************************/

#include<fstream>
#include"mytype.h"
#include <string>
#include <QString>
#include <iostream>
#include "BOOKCLASS.h"
#include "READERCLASS.h" 
#include "file.h" 
#include<windows.h>
#include <QDebug>
#include <QFile>
#include <stdio.h>
#include "TimeMgt.h"
using namespace std;


/*****************************************************************
��������void InitiateCodeList(PubCodeList *pl,AuCodeList *al)
���ܣ����ļ��ж�ȡ��Ϣ����ʼ������������߱���ı����
����ֵ��
    ��
������
�Զ���Ľṹ�������PubCodeList* pl��AuCodeList* al
�ֱ�洢���������Ƽ����Ӧ������������Ƽ����Ӧ����
****************************************************************/

void InitiateCodeList(PubCodeList *pl,AuCodeList *al){//���ļ��ж�ȡ����������߱�����Ϣ 
    ifstream pubfile("..\\project2\\initiate\\PubCode.txt");
    ifstream aufile("..\\project2\\initiate\\AuCode.txt");
	 
	
	if(NULL==pl||NULL==al){
		printf("�ڴ����ʧ�ܣ���\n");
	} 
	else{
		int i; 
		for(i=0;!pubfile.eof();i++){
			pubfile>>pl[i].pub;
			pubfile>>pl[i].code;
		}
		pl[i].pub='\0';//Ϊ�����β����� 
		pl[i].code=-1;
	/*	for(i=0;pl[i].code!=-1;i++){
			cout<<pl[i].pub<<endl;
			cout<<pl[i].code<<endl;
		}*/
		for(i=0;!aufile.eof();i++){
			aufile>>al[i].Au;
			aufile>>al[i].code;
		}
		al[i].Au='\0';//Ϊ�����β����� 
		al[i].code=-1;
	/*	for(i=0;al[i].code!=-1;i++){
			cout<<al[i].Au<<endl;
			cout<<al[i].code<<endl;
		}*/
	}
	pubfile.close();
	aufile.close();
} 

/*****************************************************************
��������long long CreateBookID(Book* p,BookType t ,string Author,string Publish,int index,PubCodeList *pl,AuCodeList *al)
���ܣ�����ͼ������ͣ����ߺͳ�������������ͼ���ͼ����
����ֵ��
    ����ͼ���ͼ����
������
�Զ�����������Book* p
�洢ͼ��ݹݲ�ͼ�����ϸ��Ϣ�Ķ������飬Book��ͼ����
�Զ���Ľṹ�������PubCodeList*��AuCodeList*
�ֱ�洢���������Ƽ����Ӧ������������Ƽ����Ӧ���룬������Ǳ�����������ṹ�����飩
�Զ����ö�����ͣ�BookType t����������ͼ�������
enum BookType{humanity,science,social,art,compre}; //���ģ�������ƣ��������ۺ�
string Author,string Publish
��������ͼ������ߺͳ�����
int index
��ǰ�ڴ��д洢��ͼ�����������ڵ���ʵ�ʿ����������Ϊ������ע��ͼ��ʱֻ�ǽ�ͼ��״̬��Ϊ��ע������
****************************************************************/

long long CreateBookID(Book* p,BookType t,string Author,string Publish,int index,PubCodeList *pl,AuCodeList *al)//index����ǰ�ڴ��д��е�ͼ�鱾�������������б�ɾ���ģ�
{
	long long type,pub,aut,flow,lastflow;
	long long newid,lastid;
	
	lastid=p[index-1].GetBookID();//�ڴ������һ�������ˮ���ǲ���һ�������ģ������������������������������� 
	lastflow=(lastid%100000)/100;//��ȡ�����ˮ��
	flow=lastflow+1;//�����µ���ˮ�� 
	type=BookTypeEncode(t);//���õ���ǰ���͵ı���
	pub=PublishEecode(Publish,pl);//���õ���ǰ������ı��룬������д���ֱ�ӷ���ֵ������������Ҫ����׷�ӱ��� 
	aut=AuthorEncode(Author,al);//���õ���ǰ���ߵı��� ��������д���ֱ�ӷ���ֵ������������Ҫ����׷�ӱ��� 
	newid=type*10000000000+pub*100000000+aut*100000+flow*100;//�õ��µ�ͼ����
	
	return newid; 
 }
/*****************************************************************
��������int BookTypeEncode(enum BookType t)
���ܣ� ��ͼ�����ͽ��б���
����ֵ��
    ���ͱ���
������
�Զ����ö�����ͣ�BookType t����������ͼ�������
enum BookType{humanity,science,social,art,compre}; //���ģ�������ƣ��������ۺ�
****************************************************************/
int BookTypeEncode(enum BookType t){//��ͼ�����ͽ��б��� 
	return (int)t+10;//��֤���ͱ�������λ�� 
} 
/*****************************************************************
�������� int PublishEecode(string s,PubCodeList *pl){
���ܣ� ����Ѱ�Ѵ��ڵĳ�������������������Ѵ��ڣ�ֱ�ӷ��ظó�����ı��룬��������粻�������������룬�����ر���
����ֵ��
    ���������
������
    string s�����������ͼ��������ַ���
�Զ���Ľṹ�������PubCodeList* pl
�洢���������Ƽ����Ӧ���룬������Ǳ�������ṹ�����飩
****************************************************************/

int PublishEecode(string s,PubCodeList *pl){//�Գ�������б��� 
	int i;
	
	for(i=1;i<=pl[0].code;i++){//�ȱ������ҵ���Ӧ�ĳ�����ֱ�ӷ��ر��뼴�� 
		if(pl[i].pub.compare(s) == 0){
			return pl[i].code;
		}
	}
	pl[i].pub=s;//û�ҵ��ĳ����磬��Ҫ���������磬��Ϊ����� 
	pl[i].code=pl[i-1].code+1;
    pl[0].code++;

	return pl[i].code; 
} 
/*****************************************************************
�������� int AuthorEncode(string s,AuCodeList *al)
���ܣ� ����Ѱ�Ѵ��ڵ����߱������������Ѵ��ڣ�ֱ�ӷ��ظ����ߵı��룬������߲��������������룬�����ر���
����ֵ��
    ���߱���
������
    string s�����������ͼ�������ַ���
�Զ���Ľṹ�������AuCodeList *al
�洢�������Ƽ����Ӧ���룬������Ǳ�������ṹ�����飩
****************************************************************/

int AuthorEncode(string s,AuCodeList *al){//�����߽��б��� 
	int i;
	
	for(i=1;i<=al[0].code;i++){
		if(al[i].Au==s){
			return al[i].code;
		}
	}
	al[i].Au=s;
	al[i].code=al[i-1].code+1;
    al[0].code++;
	
	return al[i].code;
}
/*****************************************************************
�������� int GetBookInformation(Book *p)
���ܣ� ���ļ��ж�ȡ�ڿ�ͼ�����ϸ��Ϣ�Լ���һ���˳�ϵͳʱ��ϵͳʱ��
����ֵ��
    ��ǰ�ڿ�ͼ�������
������
�Զ�����������Book* p
�洢ͼ��ݹݲ�ͼ�����ϸ��Ϣ�Ķ��������׵�ַ��Book��ͼ����
****************************************************************/

int GetBookInformation(Book *p)
{
	
	int num;
	string ID,BName,Type,Aname,Pub,Price,Enum,Total,Bnum,Rnum,Num,Time;//�ݴ��ļ���ÿһ�е���ʾ���� 
	int exnum,total,bnum,rnum;
	long long id=0;
	float price;
	string bname,aname,pub,type,temp;
	OneBook ob[10];//�ݴ�������Ϣ������ 
	
    ifstream bookfile("..\\project2\\initiate\\BookInfo.txt");//��ֻ����ʽ��һ���ļ�
	bookfile>>Time;
	bookfile>>TIME;
	bookfile>>Num;//�ɡ�ͼ���������ĸ��ֶ����� 
	bookfile>>num;//��ͼ������������

	for(int i=0;i<num&&(! bookfile.eof() ) ;i++){
		p[i].SetBBS(begin);
		bookfile>>ID;//��ȡ��i�����ͼ���� 
		bookfile>>id;
		p[i].SetBookID(id);

		bookfile>>BName;//��ȡ��i�����ͼ������ 
		bookfile>>bname;

		p[i].SetBookName(bname);

		bookfile>>Type;//��ȡ��i�����ͼ������ 
		bookfile>>type;
		enum BookType t;
        t=_TransBookType(type);//���ת�����ͺ���
		p[i].SetBT(t); 

		bookfile>>Aname;//��ȡ��i������������� 
		bookfile>>aname;

		p[i].SetAuthor(aname); 

		bookfile>>Pub;//��ȡ��i����ĳ����� 
		bookfile>>pub;

		p[i].SetPublish(pub); 

		bookfile>>Price;//��ȡ��i����ļ۸� 
		bookfile>>price;
		p[i].SetPrice(price); 

		bookfile>>Enum;//��ȡ��i������ڿ�ɽ豾�� 
		bookfile>>exnum;
		p[i].SetExist(exnum); 

		bookfile>>Total;//��ȡ��i����Ĺݲ����� 
		bookfile>>total;
		p[i].SetTotal(total); 

		bookfile>>Bnum;//��ȡ��i����Ľ������ 
		bookfile>>bnum;
		p[i].SetBoCount(bnum); 

		bookfile>>Rnum;//��ȡ��i�����ԤԼ���� 
		bookfile>>rnum;
		p[i].SetReBook(rnum); 

		GetReserveInformation(p,i);//��ȡԤԼ���е���Ϣ 

		for(int j = 0;j<6;j++){
			bookfile>>temp;
			//��ȡ��ʾ���֡�������Ϣ��
		}

		int tid;
		string state;
		for(int j=0;j<total;j++){//��ȡ�������Ϣ���ݶ����10�� 
			bookfile>>tid;
			bookfile>>state;

			//���ת��״̬����/////////////////////////////
            ob[j].OBS=_TransOBState(state);
            if(ob[j].OBS == initiate){
                            ob[j].OBS=Oinstore;
                        }
            p[i].SetOBState(j,ob[j].OBS);
			bookfile>>ob[j].ReaderID;
			p[i].SetOBReID(j,ob[j].ReaderID);
			bookfile>>ob[j].PassDays;
			p[i].SetOBPassDay(j,ob[j].PassDays);
			bookfile>>ob[j].BoTime;
			p[i].SetOBBoTime(j,ob[j].BoTime);
		}
		p[i].SetBBS(instore);
	}
	
	bookfile.close();
	
	return num;
}
/*****************************************************************
�������� bool UpdateBookInformation(Book *p,int amount,const int Booktotal)
���ܣ� ����ͼ��ݹݲ�ͼ�����Ϣ�仯
����ֵ��
bool�ͱ�����������Ǹ����Ƿ�ɹ�
������
�Զ�����������Book* p
�洢ͼ��ݹݲ�ͼ�����ϸ��Ϣ�Ķ��������׵�ַ��Book��ͼ����
int amount����ǰͼ����ڹݲ�ͼ���ʵ�ʱ���
const int Booktotal
��ǰ�ڴ��д洢��ͼ�����������ڵ���ʵ�ʿ����������Ϊ������ע��ͼ��ʱֻ�ǽ�ͼ��״̬��Ϊ��ע������
****************************************************************/

bool UpdateBookInformation(Book *p,int amount,const int Booktotal){//Booktotal:�ڴ���ͼ������� ,��Ч��ͼ������ 
	char buffer[]="������	����״̬	��ض��߱��	��������	����ʱ��";//����ʾ���֡� ������	����״̬	��ض��߱��	��������	����ʱ�䡱 
	string Amount="ͼ������",ID="ͼ����",BName="ͼ������",Type="ͼ������",Time="ϵͳʱ��",
			Aname="ͼ������",Pub="ͼ�������",Price="ͼ��۸�",Enum="�ڿ�ɽ豾��",
			Total="ͼ��ݲ�����",Bnum="�������",Rnum="��ԤԼ����",temp="������Ϣ";//�ݴ��ļ���ÿһ�е���ʾ���� 
	int exnum,total,bnum,rnum;
	long long id;
	float price;
	string bname,aname,pub,type;
    ofstream bookfile("..\\project2\\initiate\\BookInfo.txt");
	
	bookfile<<Time<<"\t";
	bookfile<<TIME<<"\n";
	bookfile<<Amount<<"\t";
	bookfile<<amount<<"\n\n";
	
	for(int i=0;i<Booktotal;i++){
        if(p[i].GetBBS()!=del){
			bookfile<<ID<<"\t";//���ļ���д���i�����ͼ���� 
			id=p[i].GetBookID();
			bookfile<<id<<"\n";
			bname=p[i].GetBookName();
			bookfile<<BName<<"\t";//���ļ���д���i�����ͼ������ 
			bookfile<<bname<<"\n";
            type=TransBookType(p[i].GetBT());//�������ת������
			bookfile<<Type<<"\t";//���ļ���д���i�����ͼ������ 
			bookfile<<type<<"\n";
			aname=p[i].GetAuthor();
			bookfile<<Aname<<"\t";//���ļ���д���i�����ͼ������ 
			bookfile<<aname<<"\n";
			pub=p[i].GetPublish();
			bookfile<<Pub<<"\t";//���ļ���д���i�����ͼ������� 
			bookfile<<pub<<"\n";
			price=p[i].GetPrice();
			bookfile<<Price<<"\t";//���ļ���д���i����ļ۸� 
			bookfile<<price<<"\n";
			exnum=p[i].GetExist();
			bookfile<<Enum<<"\t";//���ļ���д���i������ڿ�ɽ��ı��� 
			bookfile<<exnum<<"\n";
			total=p[i].GetTotal();
			bookfile<<Total<<"\t";//���ļ���д���i�����ͼ��ݲ����� 
			bookfile<<total<<"\n";
			bnum=p[i].GetBoCount();
			bookfile<<Bnum<<"\t";//���ļ���д���i����Ľ������ 
			bookfile<<bnum<<"\n";
			rnum=p[i].GetReBook();
			bookfile<<Rnum<<"\t";//���ļ���д���i�����ԤԼ���� 
			bookfile<<rnum<<"\n";
			bookfile<<temp<<"\n"; 
			bookfile<<buffer<<"\n";
			for(int j=0;j<total;j++){
				bookfile<<j+1<<"\t\t";
				string state;
				state=TransOBState(p[i].GetOBState(j));
				bookfile<<state<<"\t\t";//���״̬ת������ 
				bookfile<<p[i].GetOBReID(j)<<"\t\t";
				bookfile<<p[i].GetOBPassDay(j)<<"\t\t";
				bookfile<<p[i].GetOBBoTime(j)<<"\n"; 
			}
			bookfile<<"\n";
		} 
	}
  return true;
} 
/*****************************************************************
��������int GetReaderInformation(Reader *p)
���ܣ� ���ļ��ж�ȡע���û�����ϸ��Ϣ
����ֵ��
    ��ǰע���û�������
������
�Զ�����������Reader* p
�洢ͼ���ע���û�����ϸ��Ϣ�Ķ��������׵�ַ��Reader��ͼ����
****************************************************************/

int GetReaderInformation(Reader *p){
    string Amount,ID,Name,Rank,Time,Ability,Num,Boed,Fine;
	string name; 
    long long id,boed;
    int amount=-1,rank=-1,time=-1,ability=-1,num=-1;
	float fine=-1;
    ifstream readerfile;
    readerfile.open("..\\project2\\initiate\\ReaderInfo.txt",ios::in);//xiangduilujingduwenjian

	readerfile>>Amount;
	readerfile>>amount;

	for(int i=0;i<amount;i++){
		p[i].SetRS(available);
		readerfile>>ID;//��ȡ��i�����ߵı�� 
		readerfile>>id;
		p[i].SetReaderID(id); 
		readerfile>>Name;//��ȡ��i�����ߵ����� 
		readerfile>>name;
		p[i].SetReaderName(name);
		readerfile>>Rank;//��ȡ��i�����ߵĵȼ� 
		readerfile>>rank;
		p[i].SetRank(rank);
		readerfile>>Time;//��ȡ��i�����ߵĿɽ���ʱ�� 
		readerfile>>time;
		p[i].SetTime(time);
		readerfile>>Ability;//��ȡ��i�����ߵĿɽ��鱾�� 
		readerfile>>ability;
		p[i].SetBookNum(ability);
		readerfile>>Num;//��ȡ��i�����ߵ��ѽ��鱾�� 
		readerfile>>num;
		p[i].SetBoedNum(num);
		readerfile>>Boed;//��ȡ��i�����ߵĽ���ͼ��ı�� 
        if(num==0)
        {
            for(int j=0;j<num+1;j++){
                readerfile>>boed;
                p[i].SetBoBookID(boed);
            }

        }
        else
        {
            for(int j=0;j<num;j++){
                readerfile>>boed;
                p[i].SetBoBookID(boed);
            }
        }

		readerfile>>Fine;//��ȡ��i�����ߵ��˻���� 
		readerfile>>fine;
		p[i].SetFine(fine);
	}
	
	readerfile.close();
	return amount;
}
/*****************************************************************
�������� bool UpdateReaderInformation(Reader *p,const int Readertotal,int ReaderNum)
���ܣ� ����ͼ���ע���û�����Ϣ�仯
����ֵ��
bool�ͱ�����������Ǹ����Ƿ�ɹ�
������
�Զ�����������Reader* p
�洢ͼ���ע���û�����ϸ��Ϣ�Ķ��������׵�ַ��Reader��ͼ����
int ReaderNum����ǰͼ�����ע���û���ʵ������
,const int Readertotal,
��ǰ�ڴ��д洢���û����������ڵ���ʵ���û���������Ϊ������ע���û�ʱֻ�ǽ��û�״̬��Ϊ��ע������
****************************************************************/

bool UpdateReaderInformation(Reader *p,const int Readertotal,int ReaderNum) {//Readertotal�ڴ��ж��ߵ�������ReaderNum�������� 
	string Amount="��������",ID="���߱��",Name="��������",Rank="�û��ȼ�",
			Time="�ɽ���ʱ��",Ability="�ɽ��鱾��",Num="�ѽ��鱾��",
			Boed="�ѽ���ͼ��",Fine="�û����";
	string name;
	long long id,boedid[BIlen]={-1};
    int rank,time,ability,num;
	float fine;
    ofstream readerfile("..\\project2\\initiate\\ReaderInfo.txt");
	
	readerfile<<Amount<<"\t";
	readerfile<<ReaderNum<<"\n\n";
	for(int i=0;i<Readertotal;i++){
        if(p[i].GetRS()!=cancel){
			id=p[i].GetReaderID();
			readerfile<<ID<<"\t";//���ļ���д���i�����ߵı�� 
			readerfile<<id<<"\n";
			name=p[i].GetReaderName();
			readerfile<<Name<<"\t";//���ļ���д���i�����ߵ����� 
			readerfile<<name<<"\n";
			rank=p[i].GetRank();
			readerfile<<Rank<<"\t";//���ļ���д���i�����ߵĵȼ� 
			readerfile<<rank<<"\n";
			time=p[i].GetTime();
			readerfile<<Time<<"\t";//���ļ���д���i������ �Ŀɽ���ʱ�� 
			readerfile<<time<<"\n";
			ability=p[i].GetBookNum();
			readerfile<<Ability<<"\t";//���ļ���д���i������ �ɽ��鱾�� 
			readerfile<<ability<<"\n";
			num=p[i].GetBoedNum();
			readerfile<<Num<<"\t";//���ļ���д���i�������ѽ��ı��� 
			readerfile<<num<<"\n";
			readerfile<<Boed<<"\t";
			p[i].GetBoBookID(boedid);//////////////////////////////////////////
			if(num == 0){
				readerfile<<"-1";
			}
			else{
                for(int j=0;j<BIlen;j++){//���ļ���д���i�����ߵ��ѽ���ͼ��ı��
                    if(boedid[j]!=-1)
                    {
                     readerfile<<boedid[j]<<"\t";
                    }

				}
			}
			readerfile<<"\n";
			fine=p[i].GetFine();
			readerfile<<Fine<<"\t";//���ļ���д���i�����ߵ��û���� 
			readerfile<<fine<<"\n\n";
		}
		
	}
	
    return true;
} 
/*****************************************************************
�������� void UpdateJournalFile(string filename,string bookname,long long bookid,string readername,long int readerid)
���ܣ� ������־�ļ�
����ֵ��
��
������
string filename����ǰ��Ҫ���µ��ļ�������
string bookname��ͼ�������
long long bookid��ͼ��ı��
string readername����������
long int readerid�����߱��
****************************************************************/

void UpdateJournalFile(string filename,string bookname,long long bookid,string readername,long int readerid){

	ofstream file(filename.c_str(),ios::app);
	file<<bookid<<"\t";
	file<<bookname<<"\t";
	file<<readerid<<"\t";
	file<<readername<<"\t";
    file<<TimeConvert()<<"\n";
	
}

/*****************************************************************
�������� void CreateReserveList(Book *p,const int Booktotal)
���ܣ� Ϊÿһ��������ԤԼ��
����ֵ��
��
������
�Զ�����������Book* p
�洢ͼ��ݹݲ�ͼ�����ϸ��Ϣ�Ķ��������׵�ַ��Book��ͼ����
const int Booktotal
��ǰ�ڴ��д洢��ͼ�����������ڵ���ʵ�ʿ����������Ϊ������ע��ͼ��ʱֻ�ǽ�ͼ��״̬��Ϊ��ע������
****************************************************************/

void CreateReserveList(Book *p,const int Booktotal){
	RePeople *q;
	long long bid;
	int renum;
	string Renum="ԤԼ����";
	
	for(int i=0;i<Booktotal;i++){//дÿ��ͼ���ԤԼ�� 
			renum=p[i].GetReBook(); 
			RePeople * &head=p[i].GetRePePo();//��ȡԤԼ����ͷָ�� 
			q=head->nextPtr;
			bid=p[i].GetBookID();
			string filename;
			filename=CreateFileName(bid);/////////////�ñ�������ļ����� ,�ǵñ�ע����·�� 
		if(p[i].GetBBS()!=del){//����û�û�б�ע�� 
			ofstream file(filename.c_str());
			file<<Renum<<"\t";
			file<<renum<<"\n";
			for(int j=0;j<renum;j++){
				file<<j+1<<"\t";
				file<<q->ReaderID<<"\t\t";
				file<<q->Notice<<"\n";
				q=q->nextPtr;
			}
			file.close();
		} 
		else{//�û���ע��ʱ��Ҫ���ļ�����ɾ����Ӧ���ļ� 
            const char *fn=filename.c_str();
                        remove(fn);
		}
	}
}

/*****************************************************************
�������� void GetReserveInformation(Book *p,int i)
���ܣ� ��ȡԤԼ������ȡÿһ��ͼ���ԤԼ��Ϣ
����ֵ��
��
������
�Զ�����������Book* p
�洢ͼ��ݹݲ�ͼ�����ϸ��Ϣ�Ķ��������׵�ַ��Book��ͼ����
int i����ȡԤԼ����ͼ���������е�λ��
****************************************************************/
void GetReserveInformation(Book *p,int i){//��ȡԤԼ���е���Ϣ 
	RePeople *q,*r;
	string filename;
    int tid;
    int renum;//ԤԼ���� 
    string Renum;
	 
    RePeople *&head=p[i].GetRePePo();
	filename=CreateFileName(p[i].GetBookID());
	ifstream file(filename.c_str());

    file>>Renum;
    file>>renum;
	    for(int j=0;j<renum;j++){
			r=new RePeople;
			r->nextPtr=NULL;
			if(0 == j){
				head->nextPtr=r;
				q=r;
			}
			else{
				q->nextPtr=r;
				q=q->nextPtr;
			}
			file>>tid;
			file>>q->ReaderID;
			file>>q->Notice;
		}	

	file.close(); 
}
/*****************************************************************
�������� bool  UpdateFineFile(long int readerid,long long bookid,float fine,int reason)
���ܣ� ���·�����־�ļ�
����ֵ��
bool�ͱ�����������Ǹ����Ƿ�ɹ�
������
long int readerid�����߱��
long long bookid��ͼ����
float fine��������
int reason������ԭ�򣨶�ʧ�����ڣ�
****************************************************************/
bool  UpdateFineFile(long int readerid,long long bookid,float fine,int reason){//const int pass 0,const int lost 1
    ofstream file("..\\project2\\initiate\\FineLog.txt",ios::app);
	
	file<<bookid<<"\t";
	file<<readerid<<"\t";
	if(reason==pass){
		file<<"����"<<"\t"; 
	}
	else{
		file<<"��ʧ"<<"\t";
	}
	file<<fine<<"\n";
    return true;
}

/*****************************************************************
��������string CreateFileName(long long bookid)
���ܣ�����ͼ����Ϣ�����ļ���
����ֵ��
string�ͱ����������ļ���
������
long long bookid��ͼ����
****************************************************************/

string CreateFileName(long long bookid){//��ͼ���������ļ��� 
    string name="..\\project2\\initiate\\ReserveList\\";//���·��
	string t; 
	char temp;
	int l;

	for(int i=0;i<12;i++){
		temp=(char)(bookid%10+48);
		if(0==i)
			t=temp;
		else{
			t+=temp;
		}
		bookid=bookid/10;
		
	} 
	l=t.length();
	for (int i = 0; i<l/2; i++)
	{
	  	temp = t[i];
	 	t[i] = t[l-i-1];
	  	t[l-i-1] = temp;
	}
	name=name+t+".txt";
	
	return name;
}

/*****************************************************************
��������string TransOBState(enum OneBookState s)
���ܣ���������״̬��ö������ת��Ϊ��Ӧ�������ַ����������ļ����
����ֵ��
    string���ͱ��������ݶ�Ӧ�����ַ���
������
�Զ���ö�����ͣ�OneBookState s
enum OneBookState{initiate,Oinstore,borrowed,restored,lose};
//��ʼ���ڿ⣬ԤԼ��������黹����ʧ
****************************************************************/

string TransOBState(enum OneBookState s){//ʵ������״̬�Ͷ�Ӧ����֮���ת�� 
	int n;
	n=(int)s;
	string state;
	
	switch(n){
		case 1:
			state="�ڿ�";
			break;
		case 2:
			state="���";
			break; 
		case 3:
			state="ԤԼ";
			break; 
		case 4:
			state="��ʧ";
			break; 
		default:
			state="��ʼ";
			break;
	}
	
	return state; 
}

/*****************************************************************
��������OneBookState _TransOBState(string s)
���ܣ������ļ����������������״̬ת��Ϊ��Ӧ��ö������
����ֵ��
�Զ���ö�����ͣ�OneBookState
enum OneBookState{initiate,Oinstore,borrowed,restored,lose};
//��ʼ���ڿ⣬ԤԼ��������黹����ʧ
������
    string s���ļ���״̬�����������ַ���
****************************************************************/

OneBookState _TransOBState(string s){//ʵ�����ֺ�����״̬֮���ת�� 
	enum OneBookState state;
	
	if (s.compare("��ʧ") == 0)
	{
		state=lose;
	}
    else if (s.compare("�ڿ�") == 0)	
    {
    	state=Oinstore;
	}
	else if (s.compare("���") == 0)	
    {
    	state=borrowed;
	}
	else if (s.compare("�黹") == 0)	
    {
    	state=restored;
	}
	else
	{
		state=initiate;
	}

	return state;
}

/*****************************************************************
��������string TransBookType(enum BookType t)
���ܣ�����ͼ�����͵�ö������ת��Ϊ��Ӧ�������ַ����������ļ����
����ֵ��
    string���ͱ��������ݶ�Ӧ�����ַ���
������
�Զ���ö�����ͣ�enum BookType t
enum BookType{humanity,science,social,art,compre};//���ģ�������ƣ��������ۺ�
****************************************************************/

string TransBookType(enum BookType t){//ʵ��ͼ�����ͺͶ�Ӧ����֮���ת��
	int n;
	n=(int)t;
	string type;
	
	switch(n){
		case 0:
			type="����";
			break;
		case 1:
			type="��";
			break;
		case 2:
			type="���";
			break;
		case 3:
			type="����";
			break;
		default:
			type="�ۺ�";
			break;	
	} 
	
	return type; 
} 

/*****************************************************************
��������BookType _TransBookType(string s)
���ܣ������ļ���ͼ�����͵���������״̬ת��Ϊ��Ӧ��ö������
����ֵ��
�Զ���ö�����ͣ�enum BookType t
enum BookType{humanity,science,social,art,compre};//���ģ�������ƣ��������ۺ�
������
    string s���ļ���ͼ�����͵����������ַ���
****************************************************************/

BookType _TransBookType(string s){//ʵ�����ֺ�ͼ������֮���ת�� 
	enum BookType type;
	
	if (s.compare("����") == 0)
	{
		type=humanity;
	}
	else if (s.compare("��") == 0)
	{
		type=science;
	}
	else if (s.compare("���") == 0)
	{
		type=social;
	}
	else if (s.compare("����") == 0)
	{
		type=art;
	}
	else
	{
		type=compre;
	}

	return type;
}

/*****************************************************************
��������void UpdateCodeList(PubCodeList *pl,AuCodeList *al)
���ܣ� ���³����������ļ��Ͷ��߱�����ļ�
����ֵ��
��
������
�Զ���Ľṹ�������PubCodeList* pl��AuCodeList* al
�ֱ�洢���������Ƽ����Ӧ������������Ƽ����Ӧ����
****************************************************************/

void UpdateCodeList(PubCodeList *pl,AuCodeList *al)
{
    ofstream pubfile("..\\project2\\initiate\\PubCode.txt");
    ofstream aufile("..\\project2\\initiate\\AuCode.txt");

    pubfile<<pl[0].pub<<"\t"<<pl[0].code<<endl<<endl;
    for(int i = 1;i<=pl[0].code;i++){
        pubfile<<pl[i].pub<<"\t"<<pl[i].code<<endl;
    }

    aufile<<al[0].Au<<"\t"<<al[0].code<<endl<<endl;
    for(int i = 1;i<=al[0].code;i++){
        aufile<<al[i].Au<<"\t"<<al[i].code<<endl;
    }

    pubfile.close();
    aufile.close();

}
