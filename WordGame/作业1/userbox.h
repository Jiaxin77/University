#pragma once
#include<iostream>
#include"PlayerClass.h" 
#include"rank.h" 

int PlayerBox(int i,const int PTotal,const int ATotal,Admin *a,Player *c);
int AdminBox(int i,const int PTotal,const int ATotal,Admin *a,Player *c); 
int SearchPlayer(Player *c,const int PTotal); 
int SearchAdmin(Admin *a,const int ATotal);

