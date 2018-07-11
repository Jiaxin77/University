
#pragma once
#include <fstream>

#include <iostream>
#include <string>
#include<string.h> 
#include<stdlib.h>
#include<stdio.h>

#include"PlayerClass.h"
#include "file.h"


void regist(Player *c,Admin *a,int *Atotal,int *Ptotal,int idFlag);
int logo(int Playertotal,int Admtotal,Player *c,Admin *a,int idFlag);
