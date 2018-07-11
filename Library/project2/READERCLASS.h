#pragma once
#include "BOOKCLASS.h"
//#include <string>
//using namespace std;
 
class Reader{
	private:
	long int ReaderID;
	string ReaderName;
	int Rank;//初始状态为0，学生1，教师2 
	int Time;//可借书时长 
	int BookNum;
	int BoedNum;
	float Fine;
	long long BoBookID[BIlen];
	ReaderState RS;
	
	public:
	Reader();
	~Reader();
	
	long int GetReaderID();
	string GetReaderName();
	int GetRank();
	int GetTime();
	int GetBookNum();
	int GetBoedNum();
	float GetFine();
	void GetBoBookID(long long* bookid);//将已经借阅的图书编号拷贝出来
	int GetBoBookPo(long long bookid);//返回借的这本书的下标 
	ReaderState GetRS();
	
	void SetReaderID(long int id);
	void SetReaderName(string Name);
	void SetRank(int rank);
	void SetTime(int time);
	void SetBookNum(int num);
	void SetBoedNum(int num);
	void SetFine(float fine);
	void SetBoBookID(long long bookid);
	void SetRS(ReaderState a);
	
	bool Reserve(Book* p,int n);
	bool CancelReserve(Book* p,int n);
	bool BorrowBook(Book* p,int n);
	bool ReturnBook(Book* p,long long BookID,const int Booktotal);
	bool ReportLoss(Reader* p,long int readerid,Book* q,long long bookid,const int Readertotal,const int Booktotal);//挂失功能 Report the loss 
	int FindBoBookFirEmp();////找已借图书数组的空位置 
 
};


