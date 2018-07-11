#pragma once
//#include <string>
//using namespace std;
#include "READERCLASS.h"
//#include "BOOKCLASS.h"

int SearchReader(Reader *r,long int readerid,const int Readertotal);
int SearchBookID(Book *p,long long bookid,const int Booktotal);
void  SearchBookAuthor(int *BAS,Book *p,string Author,const int Booktotal);
void  SearchBookPublish(int *BPS,Book *p,string Publish,const int Booktotal);
void  SearchBookName(int *BNS,Book *p,string Name,const int Booktotal);
void  SearchBookType(int *BTS,Book *p ,BookType bt,const int Booktotal); 

