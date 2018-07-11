/******************************************************************
文件名: OverdueMgt.cpp
创建人:张宇
日　期:2017.4.20
修改人:万诗婕、高楠
日　期:2017.5.3
描　述:逾期处理。
版　本: v050601 Copyright(c).
******************************************************************/
#include "search.h"
#include "Notice.h"
#include "file.h"


/*****************************************************************
函数名：void OverdueMgt(Reader* rptr,Book* bptr,const int Booktotal,const int Readertotal)
功能：完成逾期处理。根据时间限制判断是否逾期，逾期进行相应处罚。
返回值：无
参数：
    int i,j,rank;//循环变量
    int readerpos;//对应读者内存中的位置
    int passday;//记录逾期天数
    int readerid;//读者id
    const int DIVIDEND=1000000;
****************************************************************/

void OverdueMgt(Reader* rptr,Book* bptr,const int Booktotal,const int Readertotal)//逾期处理，Booktotal是内存中书的总数，包括注销状态的 
{
	int i,j,rank;//循环变量
	int readerpos;//对应读者内存中的位置 
	int passday;//记录逾期天数 
	int readerid;//读者id 
	const int DIVIDEND=1000000;
	for(i=0;i<Booktotal;i++)
	{
		if(bptr[i].GetBBS()==instore&&bptr[i].GetExist()<bptr[i].GetTotal())//大书在库且有书借出 
		{   for(j=0;j<bptr[i].GetTotal();j++)//小书本数 
            {
              if(bptr[i].GetOBState(j)==borrowed)
              {	readerid= bptr[i].GetOBReID(j);
				rank=readerid/DIVIDEND;
				if(1==rank)//学生
				{
                    if(TIME>=bptr[i].GetOBBoTime(j)+StuTime)//系统当前时间，逾期了 ,TIME系统当前时间
					{
						readerpos=SearchReader(rptr,readerid,Readertotal);//找到读者在内存中对应的下标 
						rptr[readerpos].SetFine(rptr[readerpos].GetFine()-OverdueFine);//修改罚款金额 
						passday=bptr[i].GetOBPassDay(j)+1;
						bptr[i].SetOBPassDay(j,passday);//修改逾期天数 
						if(1==passday)
                        {
                          SendPassDayNotice(readerid,bptr[i].GetBookID()+j,bptr[i].GetBookName());//发送逾期通知
                          UpdateFineFile(rptr[readerpos].GetReaderID(),bptr[i].GetBookID(),OverdueFine,pass);//输出逾期1天1元钱
                        }

					} 
				}
				if(2==rank)//教师
				{
                    if(TIME>=bptr[i].GetOBBoTime(j)+TeaTime)//系统当前时间，逾期了 ,TIME系统当前时间
					{
						readerpos=SearchReader(rptr,readerid,Readertotal);//找到读者在内存中对应的下标
						rptr[readerpos].SetFine(rptr[readerpos].GetFine()-OverdueFine);//修改罚款金额 
						passday=bptr[i].GetOBPassDay(j)+1;
						bptr[i].SetOBPassDay(j,passday);//修改逾期天数
						if(1==passday)  
                        {
                            SendPassDayNotice(readerid,bptr[i].GetBookID()+j,bptr[i].GetBookName());//发送逾期通知
                            UpdateFineFile(rptr[readerpos].GetReaderID(),bptr[i].GetBookID(),OverdueFine,pass);//输出逾期1天1元钱
                        }

					} 
				} 
					
              }
           }
		}
	} 
	
	
} 
