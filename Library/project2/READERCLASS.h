#pragma once
#include "BOOKCLASS.h"
//#include <string>
//using namespace std;
 
class Reader{
	private:
	long int ReaderID;
	string ReaderName;
	int Rank;//��ʼ״̬Ϊ0��ѧ��1����ʦ2 
	int Time;//�ɽ���ʱ�� 
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
	void GetBoBookID(long long* bookid);//���Ѿ����ĵ�ͼ���ſ�������
	int GetBoBookPo(long long bookid);//���ؽ���Ȿ����±� 
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
	bool ReportLoss(Reader* p,long int readerid,Book* q,long long bookid,const int Readertotal,const int Booktotal);//��ʧ���� Report the loss 
	int FindBoBookFirEmp();////���ѽ�ͼ������Ŀ�λ�� 
 
};


