#pragma once
#include <string>
#include"mytype.h"
using namespace std;

class Book
{	private:
		long long BookID;
		string BookName;
		BookType BT;//ö�٣�
		string Author;
		string Publish;
		float Price;
		int Exist;//�ڿ�ɽ��ı��� 
		int Total;//ͼ��ݹݲ����� 
		int BoCount;
		int ReBook;//��ԤԼ���� 
		RePeople *head;
		
		BigBookState BBS;
		OneBook OB[OBlen];

	public:
	Book();//���캯��
	~Book();//��������
	long long GetBookID();
	string GetBookName();
	BookType GetBT();//ö�٣�
	string GetAuthor();
	string GetPublish();
	float GetPrice();
	int GetExist(); 
	int GetTotal();
	int GetBoCount();
	int GetReBook();
	RePeople *&GetRePePo();//�õ�ԤԼ����ͷָ�� 
	OneBookState GetOBState(int i);//i:������±꣬s:���ĺ��״̬ 
	long int GetOBReID(int i);
	int GetOBPassDay(int i);
	int GetOBBoTime(int i);
	BigBookState GetBBS();
	
	void SetBookID(long long id);
	void SetBookName(string Name);//����
	void SetBT(BookType bt);//ö�٣�
	void SetAuthor(string Name);
	void SetPublish(string Name);
	void SetPrice(float price);
	void SetExist(int exist);
	void SetTotal(int total);
	void SetBoCount(int count);
	void SetBBS(BigBookState bbs);
	void SetReBook(int rebook); 
	void SetRePeople(long int ReaderID);
	void SetOBState(int i,OneBookState s);//i:������±꣬s:���ĺ��״̬ 
	void SetOBReID(int i,long int ReaderID);
	void SetOBPassDay(int i,int PaTime);
	void SetOBBoTime(int i,int BoTime);
	void DelRePeople(long int ReaderID);
	long int FirstNNPeople();//���ص�һ��δ��֪ͨ������˭ ,�������֪ͨ�˷���-1 
	bool TraReList(long int ReaderID); //�ж϶����Ƿ�ԤԼ���� 
	int FindTheInBook();//��ѯ�ڿ�ľ���ͼ���� ,����ֵΪ�±� 
	

};

