#pragma once
#include <string>
#include"mytype.h"
using namespace std;

class Book
{	private:
		long long BookID;
		string BookName;
		BookType BT;//枚举？
		string Author;
		string Publish;
		float Price;
		int Exist;//在库可借阅本数 
		int Total;//图书馆馆藏总数 
		int BoCount;
		int ReBook;//已预约本数 
		RePeople *head;
		
		BigBookState BBS;
		OneBook OB[OBlen];

	public:
	Book();//构造函数
	~Book();//析构函数
	long long GetBookID();
	string GetBookName();
	BookType GetBT();//枚举？
	string GetAuthor();
	string GetPublish();
	float GetPrice();
	int GetExist(); 
	int GetTotal();
	int GetBoCount();
	int GetReBook();
	RePeople *&GetRePePo();//得到预约单的头指针 
	OneBookState GetOBState(int i);//i:子书的下标，s:更改后的状态 
	long int GetOBReID(int i);
	int GetOBPassDay(int i);
	int GetOBBoTime(int i);
	BigBookState GetBBS();
	
	void SetBookID(long long id);
	void SetBookName(string Name);//？？
	void SetBT(BookType bt);//枚举？
	void SetAuthor(string Name);
	void SetPublish(string Name);
	void SetPrice(float price);
	void SetExist(int exist);
	void SetTotal(int total);
	void SetBoCount(int count);
	void SetBBS(BigBookState bbs);
	void SetReBook(int rebook); 
	void SetRePeople(long int ReaderID);
	void SetOBState(int i,OneBookState s);//i:子书的下标，s:更改后的状态 
	void SetOBReID(int i,long int ReaderID);
	void SetOBPassDay(int i,int PaTime);
	void SetOBBoTime(int i,int BoTime);
	void DelRePeople(long int ReaderID);
	long int FirstNNPeople();//返回第一个未被通知的人是谁 ,如果都被通知了返回-1 
	bool TraReList(long int ReaderID); //判断读者是否预约该书 
	int FindTheInBook();//查询在库的具体图书编号 ,返回值为下标 
	

};

