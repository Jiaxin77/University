#pragma once


void InitiateCodeList(PubCodeList *pl,AuCodeList *al);
long long CreateBookID(Book* p,BookType t,string Author,string Publish,int index,PubCodeList *pl,AuCodeList *al);
int BookTypeEncode(enum BookType t);
int PublishEecode(string s,PubCodeList *pl);
int AuthorEncode(string s,AuCodeList *al);
int GetBookInformation(Book *p);
bool UpdateBookInformation(Book *p,int amount,const int Booktotal);
int GetReaderInformation(Reader *p);
bool UpdateReaderInformation(Reader *p,const int Readertotal,int ReaderNum);
void UpdateJournalFile(string filename,string bookname,long long bookid,string readername,long int readerid);
void CreateReserveList(Book *p,const int Booktotal);
void GetReserveInformation(Book *p,int i);
bool  UpdateFineFile(long int readerid,long long bookid,float fine,int reason);
string CreateFileName(long long bookid);
string TransOBState(OneBookState s);
OneBookState _TransOBState(string s);
string TransBookType(BookType t);
BookType _TransBookType(string s);
void UpdateCodeList(PubCodeList *pl,AuCodeList *al);


