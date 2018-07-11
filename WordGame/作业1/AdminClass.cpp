 #include<iostream>
 #include"PlayerClass.h"
 using namespace std;
 Admin::Admin()
 {		name="\0";
		password="\0";
		CStage=1;//µÈ¼¶
		CCount=0;
 }
 
 
 int Admin::getCCount()
 {
 	return CCount;
 }
 
 int Admin::getCStage()
 {
 	return CStage;
 }
 
 void Admin::setCCount(int count)
 {
 	CCount=count;
 }
 
 void Admin::setCStage(int stage)
 {
 	CStage=stage;
 }
 
