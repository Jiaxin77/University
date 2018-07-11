/******************************************************************
文件名: search.cpp
创建人:刘佳鑫
日　期:2017.4.20
修改人:刘佳鑫
日　期:2017.5.3
描　述:搜索函数，包含按类别搜索，按出版社搜索，按图书名称搜索，按作者搜索和按编号搜索。
版　本: v050601 Copyright(c).
******************************************************************/
#include <iostream> 
#include"BOOKCLASS.h"
#include"READERCLASS.h"
//定为50 

using namespace std;
/*****************************************************************
函数名：int SearchReader(Reader *r,long int readerid,const int Readertotal)
功能：获得该读者id对应的读者类数组下标
返回值：
返回搜索到的读者类数组下标，搜索不到时返回-1
参数：
Reader *r：[in] 读者类数组
long int readerid：[in] 要搜索的读者id
const int Readertotal：[in] 读者总数
int ：[out] 搜索到的读者类数组下标，搜索不到时返回-1
备注：无
****************************************************************/
int SearchReader(Reader *r,long int readerid,const int Readertotal)//通过读者编号找读者类下标 
{	int i; 
	for(i=0;i<Readertotal;i++)
	{	
		if(r[i].GetReaderID()==readerid)
			{	
				return i;
			}
			
	}
	return -1;//没找到 
} 


/*****************************************************************
函数名：int SearchBookID(Book *p,long long bookid,const int Booktotal)
功能：获得该图书id对应的图书类数组下标
返回值：
返回搜索到的图书类数组下标，搜索不到时返回-1
参数：
Book *p：[in] 图书类数组
long long bookid：[in] 要搜索的图书id
const int Booktotal：[in] 图书总数
int ：[out] 搜索到的图书类数组下标，搜索不到时返回-1
备注：无
****************************************************************/

int SearchBookID(Book *p,long long bookid,const int Booktotal)//通过图书id找图书类下标
{	int i; 
    for(i=0;i<Booktotal;i++)
	{	
		if(p[i].GetBookID()==((bookid/100)*100))
			{
				return i;
			}
	} 
	return -1;//都没找到 
 } 
 
/*****************************************************************
函数名：void  SearchBookAuthor(int *BAS,Book *p,string Author,const int Booktotal)
功能：搜索该作者的全部图书
返回值：无返回值
参数：
int *BAS：[in] 盛放该作者所有图书对应的图书类下标的数组
Book *p：[in] 图书类数组
string Author：[in] 作者姓名，以‘\0’结尾的字符串
const int Booktotal：[in] 图书总数
备注：无
****************************************************************/
void  SearchBookAuthor(int *BAS,Book *p,string Author,const int Booktotal)
{	int i;
	int BAScount=0;
	string SAuthor;

	for(int j=0;j<BSearch;j++)
	{	BAS[j]=-1;
	 } 

	for(i=0;i<Booktotal;i++)
	{	SAuthor=p[i].GetAuthor();
		if(Author.compare(SAuthor)==0)
			{	
				BAS[BAScount]=i;
				BAScount++;
			}
	}
	

		 
}

/*****************************************************************
函数名：void  SearchBookPublish(int *BPS,Book *p,string Publish,const int Booktotal)
功能：搜索该出版社的全部图书
返回值：无返回值
参数：
int *BPS：[in] 盛放该出版社所有图书对应的图书类下标的数组
Book *p：[in] 图书类数组
string Publish：[in] 出版社名字，以‘\0’结尾的字符串
const int Booktotal：[in] 图书总数
备注：无
****************************************************************/
void  SearchBookPublish(int *BPS,Book *p,string Publish,const int Booktotal)
{	int i;
	int BPScount=0;
	string SPublish;
	for(int j=0;j<BSearch;j++)
	{	BPS[j]=-1;
	} 

	for(i=0;i<Booktotal;i++)
	{	SPublish=p[i].GetPublish();
		if(Publish.compare(SPublish)==0)
			{	
				BPS[BPScount]=i;
				BPScount++;
			}
	}
	
	
		 
}

/*****************************************************************
函数名：void   SearchBookName(int *BNS,Book *p,string Name,const int Booktotal)
功能：搜索书名为Name的全部图书
返回值：无返回值
参数：
int *BNS：[in] 盛放该书名所有图书对应的图书类下标的数组
Book *p：[in] 图书类数组
string Name：[in] 图书名字，以‘\0’结尾的字符串
const int Booktotal：[in] 图书总数
备注：无
****************************************************************/
void   SearchBookName(int *BNS,Book *p,string Name,const int Booktotal)
{	int i;
	int BNScount=0;
	string SName;
	for(int j=0;j<BSearch;j++)
	{	BNS[j]=-1;
	 } 

	for(i=0;i<Booktotal;i++)
	{	SName=p[i].GetBookName();
		if(Name.compare(SName) == 0)
			{	
				BNS[BNScount]=i;
				BNScount++;
			}
	}
	
	
		 
}

/*****************************************************************
函数名：void  SearchBookType(int *BTS,Book *p ,BookType bt,const int Booktotal)
功能：搜索该类型的全部图书
返回值：无返回值
参数：
int *BTS：[in] 盛放该类型所有图书对应的图书类下标的数组
Book *p：[in] 图书类数组
BookType bt：[in] 图书类型，为枚举类型中的一种
const int Booktotal：[in] 图书总数
备注：使用图书类型时，需先看下用不用调用字符串转枚举类型函数。
****************************************************************/
void  SearchBookType(int *BTS,Book *p ,BookType bt,const int Booktotal)//BTS用于存所有这个类型的下标 
{
	int i;
	int BTScount=0;
	for(int j=0;j<BSearch;j++)
	{	BTS[j]=-1;
	 } 
	for(i=0;i<Booktotal;i++)
	{	
		if(p[i].GetBT()==bt)
			{
				BTS[BTScount]=i;
				BTScount++;
			}
	}
	
	
}
