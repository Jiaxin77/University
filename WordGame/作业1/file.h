#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<string.h> 
#include <windows.h>
#include<stdlib.h>
#include<stdio.h>
#include"PlayerClass.h"

int ReadPlayerFile(Player *c);
int ReadAdminFile(Admin *c);
void updatePlayerFile(Player *c,const int Ptotal);
 void updateAdminFile(Admin *a,const int Atotal);
