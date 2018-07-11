/******************************************************************
文件名: ADMCLASS.cpp
创建人:高楠 万诗婕 刘佳鑫 张宇
日　期:2017-04-18
修改人:高楠
日　期:2017-04-26
描　述:该文件中包含了管理员类数据成员所有Get和Set的具体函数，以及对管理员类进行的所有操作（新建图书，新建读者，删除读者等）-成员函数的具体实现
版　本: 050602
******************************************************************/


#include "ADMCLASS.h"
#include "search.h"
#include "Notice.h" 
#include "file.h"


void  Administration::SetReaderNum(int readernum)
{
	ReaderNum=readernum;
}

void  Administration::SetBookNum(int booknum)
{
	BookNum=booknum;
}

void Administration::SetAllBooks(int allbooks)
{
	AllBooks=allbooks;
}

int Administration::GetBookNum()
{
	return BookNum;
}

int Administration::GetReaderNum() 
{
	return ReaderNum;
}

int Administration::GetAllBooks()
{
	return AllBooks;
}

Administration::Administration(){
	AdmID=AdminID;
	AdmName='\0';
	ReaderNum=0;
	BookNum=0;
	AllBooks=0; 
	
}

Administration::~Administration(){
	;
}

/******************************************************************
函数名bool Administration::NewReader(Reader* p,long int readerid,string readername,int* Readertotal)
功能：新建一个读者
返回值：
    0 or 1 //新建成功返回1，新建失败返回0
参数：
p, readerid, readername,Readertotal //图书类指针p，图书id，读者姓名readername，读者总数Readertotal
****************************************************************/

bool Administration::NewReader(Reader* p,long int readerid,string readername,int* Readertotal)
{	
    int i;
    i=SearchReader(p,readerid,*Readertotal);
     if(i!=-1||*Readertotal>=150)//先遍历这个人在不在,超出数组最大值
	 {
	 	return false;	 
	 }
	 
	int rank;
	rank=readerid/1000000;//获取身份信息 
	if(1==rank) 
	{
		p[ReaderNum].SetRank(rank);
		p[ReaderNum].SetTime(StuTime);
		p[ReaderNum].SetBookNum(StuBookNum);	
		
	}
	else if(2==rank)
	{	p[ReaderNum].SetRank(rank);
		p[ReaderNum].SetTime(TeaTime);
		p[ReaderNum].SetBookNum(TeaBookNum);
		
	}
	p[ReaderNum].SetReaderID(readerid);
	p[ReaderNum].SetReaderName(readername);
	
	ReaderNum++;
    (*Readertotal)++;
	return true;
	
}

/******************************************************************
函数名bool Administration::DelReader(Reader* p,long int readerid,string readername,const int Readertotal)
功能：删除读者
返回值：
    0 or 1 //删除成功返回1，删除失败返回0
参数：
p, readerid, readername,Readertotal //图书类指针p，图书id，读者姓名readername，读者总数Readertotal
****************************************************************/

bool Administration::DelReader(Reader* p,long int readerid,string readername,const int Readertotal)
{
	int i;//存输入id对应的读者的下标
	i=SearchReader(p,readerid,Readertotal);//调用搜索读者的函数 
	
	if(i==-1)//对读者下标进行判断，不存在返回false
	{
		return false;
	 } 
	
	if(readername.compare(p[i].GetReaderName()) == 0){
		p[i].SetRS(cancel);
		ReaderNum--;
	}
		
	
	return true;
}

/******************************************************************
函数名NewBook(Book* p,BookType bt,string bookname,string author,string publish,float price,int* Booktotal,PubCodeList *pl,AuCodeList *al)
功能：新建图书
返回值：
    0 or 1 //新建成功返回1，新建失败返回0
参数：
p, bt,bookname,author,publish,price,Booktotal,pl,al //图书类指针p，图书姓名booknamae，图书作者author，图书出版社publish，图书价格price，图书总数Booktotal,出版社编码指针pl,作者编码指针al
****************************************************************/

bool Administration::NewBook(Book* p,BookType bt,string bookname,string author,string publish,float price,int* Booktotal,PubCodeList *pl,AuCodeList *al)
{

    if(*Booktotal>=100)//超出数组最大值
    {
        return false;
    }

	int bopos=-1;//遍历book类，返回书的下标
	int i;//记小书的下标 
	int BNS[50]={-1};
	int BNSAU[50]={-1};//书名作者都匹配 
	for(int j = 0;j<50;j++){
		BNS[j]=-1;
		BNSAU[j]=-1;
	}
    SearchBookName(BNS,p,bookname,*Booktotal);//根据图书名称搜索到的图书
	for(int j=0,k=0;j<50&&BNS[j]!=-1;j++)
	{
		if(author.compare(p[BNS[j]].GetAuthor()) == 0)
		{
			BNSAU[k]=BNS[j];
			k++;
		} 
	 } 
	 for(int j=0;j<50&&BNSAU[j]!=-1;j++)
	 {
	 	if(publish.compare(p[BNSAU[j]].GetPublish()) == 0)
		{
			bopos=BNSAU[j];
		} 
	 }
	if(bopos!=-1)//若果有这本书
    {   if(p[bopos].GetTotal()>=OBlen)
        {
            return false;
        }
        for(i=0;i<OBlen&&(p[bopos].GetOBState(i)!=lose&&p[bopos].GetOBState(i)!=initiate);i++);//需要向用户说明小书的本数不能超过10
		p[bopos].SetOBState(i,Oinstore);
		int e=-1,t=-1;
		e=p[bopos].GetExist()+1;
		t=p[bopos].GetTotal()+1;
		p[bopos].SetExist(e);//在库可借阅本数 
		p[bopos].SetTotal(t);//图书馆馆藏总数 
		if(!SendReserveNotice(p,bopos))//到书通知 
		{ 
		    cout<<"未成功发出到书通知"<<endl;//打印未成功发出到书通知
		};
	} 
	else
	{	
        long long bookid=CreateBookID(p,bt,author,publish,*Booktotal,pl,al);//包含过程中被删除的//调用一个编码函数
        p[*Booktotal].SetBookID(bookid);
        p[*Booktotal].SetBookName(bookname);
        p[*Booktotal].SetBT(bt);
        p[*Booktotal].SetAuthor(author);
        p[*Booktotal].SetPublish(publish);
        p[*Booktotal].SetPrice(price);
        p[*Booktotal].SetExist(p[*Booktotal].GetExist()+1);
        p[*Booktotal].SetTotal(p[*Booktotal].GetTotal()+1);
        p[*Booktotal].SetOBState(0,Oinstore);
        p[*Booktotal].SetBBS(instore);
        (*Booktotal)++;
	    BookNum++;
	}
	
	return true;
}

/******************************************************************
函数名bool Administration::DelBook(Book* p,long long bookid,const int Booktotal)
功能：删除图书
返回值：
    0 or 1 //删除成功返回1，删除失败返回0
参数：
p, bookid,bookBooktotal //图书类指针p，图书id，图书总数Booktotal
****************************************************************/

bool Administration::DelBook(Book* p,long long bookid,const int Booktotal)
{
	int i;//定位这本书下标
	i=SearchBookID(p,bookid,Booktotal);//调用按编号搜索图书的函数
	
    if(i==-1||p[i].GetExist()<p[i].GetTotal())//若这本书不在, 或者有借出

	{
		return false; 
	} 
	
	p[i].SetBBS(del);
	BookNum--;
	
	return true; 	
}
/******************************************************************
函数名bool Administration::HandinFine(Reader* p,long int readerid,float fine,const int Readertotal)
功能：缴纳罚金
返回值：
    0 or 1 //缴纳成功返回1，缴纳失败返回0
参数：
p,readerid,fine,Readertotal //图书类指针p，读者id，罚金fine，读者总数Readertotal
******************************************************************/


bool Administration::HandinFine(Reader* p,long int readerid,float fine,const int Readertotal) //缴纳罚金
{
	int i;//定位这个人的下标 
	i=SearchReader(p,readerid,Readertotal);    //调用按编号搜索读者的函数
    if(i==-1)//如果这个人不存在 
	{
		return false;
	}
    p[i].SetFine(p[i].GetFine()+fine);
    return true;
}



 
