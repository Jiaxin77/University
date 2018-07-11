#pragma once
#include "READERCLASS.h" 
#include "BOOKCLASS.h"
#include <string>
#include"mytype.h"

using namespace std;

class Administration
{	
	private:
	int AdmID;
	string AdmName;
	int ReaderNum;
	int BookNum;
	int AllBooks;//书的总本数 
	
	public:
	Administration();
	~Administration();
	
	void SetReaderNum(int readernum);
	void SetBookNum(int booknum);
	void SetAllBooks(int allbooks);
	
	int GetAllBooks();
	int GetBookNum();
	int GetReaderNum();
	 
    bool NewReader(Reader* p,long int readerid,string readername,int* Readertotal);
	bool DelReader(Reader* p,long int readerid,string readername,const int Readertotal);
    bool NewBook(Book* p,BookType bt,string bookname,string author,string publish,float price,int* Booktotal,PubCodeList *pl,AuCodeList *al);//到书通知
	bool DelBook(Book* p,long long bookid,const int Booktotal);
	bool HandinFine(Reader* p,long int readerid,float fine,const int Readertotal); //缴纳罚金
	/*bool ReportLoss(class Reader* p,long int readerid,class Book* q,BookType bt,long int bookid);//挂失功能 Report the loss*/ 
	//文件，书状态，读者的金额，大书的总本书（判断）
	
};
