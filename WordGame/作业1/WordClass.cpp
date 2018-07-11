#include"WordClass.h" 

using namespace std;

string word::getdata()
{
	return data;	
}


int word::getlength()
{	
	return length;
}

int word::getstage()
{
	return stage;
}

int word::getUseCount()
{
	return UseCount;
}

int word::getCorrectCount()
{
	return CorrectCount;
}
	
void word::setdata(string w)
{	
	data=w;
}

void word::setlength(int len)
{
	length=len;
}

void word::setstage(int sta)
{	
	stage=sta;
}
		
void word::setUseCount(int use)
{
	UseCount=use;
}
				
void word::setCorrectCount(int correct)
{
	CorrectCount=correct;
}
				
word::word()
{	
	data="\0";
	length=0;
	stage=0;
	UseCount=0;
	CorrectCount=0;
}
