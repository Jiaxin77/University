#pragma once
//#include <string>
#include "BOOKCLASS.h"
//using namespace std;

bool SendReserveNotice(Book* p,int n);//���͵���֪ͨ
bool SendPassDayNotice(long int readerid,long long bookid,string bookname);//��������֪ͨ ,����û������ 
bool SendMaxReNotice(long int readerid,long long bookid,string bookname);//������ԤԼʱ�䳬��ʱ����ȡ��ԤԼ�ʸ�


