#pragma once
#include <iostream>
#include <string>
using namespace std;

const int MaxPub = 100;

const int MaxAu = 150;
const int pass = 0;
const int lost = 1;
//file.cpp

const int BSearch = 50;
//search.cpp

const int MaxReNoticeDay = 5;//ԤԼ�������� 
//search.cpp

const int RNlen = 11;
const int BIlen = 11;//�ѽ�����ı��� 
const float MaxFine = -20;//���Ƿ����

const float OverdueFine = 1 ;//����һ��ķ����� 
//OverduMgt.cpp


const int ReIDLen = 7;//����id�ĳ��� 
const int BookIDLen = 12;//ͼ���ų���
//Notice.cpp

const int BNlen = 51;//��һ���ض���'\0' 
const int AUlen = 11;
const int PBlen = 21;
const int OBlen = 10;
// ����֪ͨ���ͼ���������� 
//BOOKCLASS.cpp

const string AdminName = "����Ա";
const int AdminID = 7;
const int ANlen = 4;
const int StuTime = 3;//ѧ���ɽ������� 
const int TeaTime = 7;//��ʦ�ɽ������� 
const int StuBookNum = 5;//ѧ���ɽ��鱾�� 
const int TeaBookNum = 10;//��ʦ�ɽ��鱾�� 


extern int TIME;
 
enum ReaderState{start,available,cancel};
enum BookType{humanity,science,social,art,compre};//���ģ�������ƣ��������ۺ�
enum BigBookState{begin,instore,del};//���� �ڿ⣬ע��
enum OneBookState{initiate,Oinstore,borrowed,restored,lose};//������  ��ʼ���ڿ⣬ԤԼ��������黹����ʧ
//READERCLASS.cpp


typedef struct RePeople{
	long int ReaderID;
	int Notice;//����֪ͨ�˵����� 
	struct RePeople * nextPtr;
}RePeople; 



typedef  struct OneBook
{	long int ReaderID;//�Ȿ�鱻˭����
	OneBookState OBS;//״̬
	int PassDays;//��������
	int BoTime;//����ʱ��
}OneBook;


typedef struct PubCodeList{//���ڴ洢������Ķ�Ӧ���� 
	string pub;
	int code;
}PubCodeList;

typedef struct AuCodeList{//���ڴ洢���߶�Ӧ���� 
	string Au;
	int code;
}AuCodeList;

