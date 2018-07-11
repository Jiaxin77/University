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

const int MaxReNoticeDay = 5;//预约提醒天数 
//search.cpp

const int RNlen = 11;
const int BIlen = 11;//已借阅书的编码 
const float MaxFine = -20;//最大欠款额度

const float OverdueFine = 1 ;//逾期一天的罚款金额 
//OverduMgt.cpp


const int ReIDLen = 7;//读者id的长度 
const int BookIDLen = 12;//图书编号长度
//Notice.cpp

const int BNlen = 51;//有一个地儿放'\0' 
const int AUlen = 11;
const int PBlen = 21;
const int OBlen = 10;
// 到书通知发送几天放在哪里 
//BOOKCLASS.cpp

const string AdminName = "管理员";
const int AdminID = 7;
const int ANlen = 4;
const int StuTime = 3;//学生可借书天数 
const int TeaTime = 7;//教师可借书天数 
const int StuBookNum = 5;//学生可借书本数 
const int TeaBookNum = 10;//教师可借书本数 


extern int TIME;
 
enum ReaderState{start,available,cancel};
enum BookType{humanity,science,social,art,compre};//人文，理工，社科，艺术，综合
enum BigBookState{begin,instore,del};//大类 在库，注销
enum OneBookState{initiate,Oinstore,borrowed,restored,lose};//单本书  初始，在库，预约，借出，归还，丢失
//READERCLASS.cpp


typedef struct RePeople{
	long int ReaderID;
	int Notice;//到书通知了的天数 
	struct RePeople * nextPtr;
}RePeople; 



typedef  struct OneBook
{	long int ReaderID;//这本书被谁借走
	OneBookState OBS;//状态
	int PassDays;//逾期天数
	int BoTime;//借书时间
}OneBook;


typedef struct PubCodeList{//用于存储出版社的对应编码 
	string pub;
	int code;
}PubCodeList;

typedef struct AuCodeList{//用于存储作者对应编码 
	string Au;
	int code;
}AuCodeList;

