//读取用户文件
#include"file.h"
using namespace std;

int ReadPlayerFile(Player *c)//从文件中读取作者信息 
{	string NAME,PASSWORD,AMOUNT,STAGE,PASSEDNUM,EXP;
	string pname,ppassword;
	int Amount,Stage=-1,PassedNum=-1,Exp=-1;//排名 ??
	ifstream playerfile;
	playerfile.open("player.txt",ios::in);
	if(!playerfile.is_open())
	{	cout<<"读者文件打开失败!\n"; 
	}
	playerfile>>AMOUNT;
	playerfile>>Amount;//读取玩家总数
	for(int i=0;i<Amount;i++)
	{	playerfile>>NAME;
		playerfile>>pname;
		c[i].setname(pname);
		
		playerfile>>PASSWORD;
		playerfile>>ppassword;
		c[i].setpassword(ppassword);
		
		playerfile>>STAGE;
		playerfile>>Stage;
		c[i].setWStage(Stage);
		
		playerfile>>PASSEDNUM;
		playerfile>>PassedNum;
		c[i].setWPassedNum(PassedNum);
		
		playerfile>>EXP;
		playerfile>>Exp;
		c[i].setWExp(Exp);
	
	 } 
	 
	 playerfile.close();
	 return Amount;
 } 
 
 
 int ReadAdminFile(Admin *c)//从文件中读取出题人信息 
{	string NAME,PASSWORD,CSTAGE,CCOUNT,AMOUNT;
	string name,password;
	int CStage=-1,CCount,Amount;//排名 ??
	ifstream adminfile;
	adminfile.open("admin.txt",ios::in);
	if(!adminfile.is_open())
	{	cout<<"出题人文件打开失败!\n"; 
	}
	adminfile>>AMOUNT;
	adminfile>>Amount;//读取玩家总数
	for(int i=0;i<Amount;i++)
	{	adminfile>>NAME;
		adminfile>>name;
		c[i].setname(name);
		
		adminfile>>PASSWORD;
		adminfile>>password;
		c[i].setpassword(password);
		
		adminfile>>CSTAGE;
		adminfile>>CStage;
		c[i].setCStage(CStage);
		
		adminfile>>CCOUNT;
		adminfile>>CCount;
		c[i].setCCount(CCount);
	 } 
	 
	 adminfile.close();
	 return Amount;
 } 
 
 
 void updatePlayerFile(Player *c,const int Ptotal)
 {	string AMOUNT="总数" ,NAME="姓名",PASSWORD="密码",STAGE="等级",PASSEDNUM="过关数",EXP="经验值";
 	int stage,passednum;
	string name,password;
	ofstream playerfile("player.txt");
	
	playerfile<<AMOUNT<<"\t";
	playerfile<<Ptotal<<"\n";
	
	for(int i=0;i<Ptotal;i++)
	{	playerfile<<NAME<<"\t";
		playerfile<<c[i].getname()<<endl;
		playerfile<<PASSWORD<<"\t";
		playerfile<<c[i].getpassword()<<endl;
		playerfile<<STAGE<<"\t";
		playerfile<<c[i].getWStage()<<endl;
		playerfile<<PASSEDNUM<<"\t";
		playerfile<<c[i].getWPassedNum()<<endl;
		playerfile<<EXP<<"\t";
		playerfile<<c[i].getWExp()<<endl; 
		playerfile<<endl; 
	 } 
	 cout<<"player文件更新完毕！"; 
 }
 
 void updateAdminFile(Admin *a,const int Atotal)
 {	string AMOUNT="总数" ,NAME="姓名",PASSWORD="密码",STAGE="等级",COUNT="出题数";
 	int stage,count;
	string name,password;
	ofstream adminfile("admin.txt");
	
	adminfile<<AMOUNT<<"\t";
	adminfile<<Atotal<<"\n";
	
	for(int i=0;i<Atotal;i++)
	{	adminfile<<NAME<<"\t";
		adminfile<<a[i].getname()<<endl;
		adminfile<<PASSWORD<<"\t";
		adminfile<<a[i].getpassword()<<endl;
		adminfile<<STAGE<<"\t";
		adminfile<<a[i].getCStage()<<endl;
		adminfile<<COUNT<<"\t";
		adminfile<<a[i].getCCount()<<endl;
	
		adminfile<<endl; 
	 } 
	 cout<<"admin文件更新完毕！"; 
 }
