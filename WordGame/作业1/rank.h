
/*rank.h*/
#pragma once
#include<iostream>
#include"PlayerClass.h"
 
typedef struct
{	
	int position;
	int rankdata;
}rankStruct;

void rankPlayer(Player *c,const int PTotal);
void rankAdmin(Admin *a,const int ATotal);
