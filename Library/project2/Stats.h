#pragma once
//#include "BOOKCLASS.h"//����book���.h 
#include "READERCLASS.h"//����reader���.h 
#include "userdialog.h"

typedef struct BookRanking
{ 
	int position;//��¼��class�������λ��
	int bocount;//��¼���Ĵ��� 	
 }BookRanking; 
 
void Stats(Book* p,const int index,QStandardItemModel *rankinfo_model);


