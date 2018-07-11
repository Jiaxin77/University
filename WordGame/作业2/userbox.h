#pragma once
#include<iostream>
#include"PlayerClass.h" 
#include"rank.h" 
#include"userbox.h"
#include"mytype.h"

int PlayerBox(int i,const int PTotal,const int ATotal,const int WTotal,Admin *a,Player *c,word *w);
int AdminBox(int i,const int PTotal,const int ATotal,int *WTotal,Admin *a,Player *c,word *w); 
int SearchPlayer(Player *c,const int PTotal); 
int SearchAdmin(Admin *a,const int ATotal);

