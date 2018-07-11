/******************************************************************
文件名: mytype.cpp
创建人:张宇、刘佳鑫、万诗婕、高楠
日　期:2017.4.20
修改人:
日　期:
描　述:全局变量和全局常量的定义
版　本: v050601 Copyright(c).
******************************************************************/
#include <fstream>
#include<string>
#include<iostream>
using namespace std;

int TIME = 1;

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
const int BookIDLen = 12;
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
//ADMCLASS.cpp

