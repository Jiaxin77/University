#pragma once
//#include <string>
#include "BOOKCLASS.h"
//using namespace std;

bool SendReserveNotice(Book* p,int n);//发送到书通知
bool SendPassDayNotice(long int readerid,long long bookid,string bookname);//发送逾期通知 ,测试没有问题 
bool SendMaxReNotice(long int readerid,long long bookid,string bookname);//发送因预约时间超过时长而取消预约资格


