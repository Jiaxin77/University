#pragma once
//#include "BOOKCLASS.h"//包含book类的.h 
#include "READERCLASS.h"//包含reader类的.h 
#include "userdialog.h"

typedef struct BookRanking
{ 
	int position;//记录在class类里面的位置
	int bocount;//记录借阅次数 	
 }BookRanking; 
 
void Stats(Book* p,const int index,QStandardItemModel *rankinfo_model);


