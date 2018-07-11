#pragma once

#include<iostream>
#include<string.h>
#include<string> 
using namespace std;

class word
		{		
			protected:
				string data;
				int length;
				int UseCount;
				int CorrectCount;
			public:
				string getdata();
				int getlength();
				int getUseCount();
				int getCorrectCount();
				
				void setdata(string w);
				void setlength(int len);
			//	void setstage(int sta);
				void setUseCount(int use);
				void setCorrectCount(int correct);
				
				word();
				~word(){};
		};
