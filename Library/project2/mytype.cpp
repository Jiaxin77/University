/******************************************************************
�ļ���: mytype.cpp
������:��������Ρ���ʫ漡����
�ա���:2017.4.20
�޸���:
�ա���:
�衡��:ȫ�ֱ�����ȫ�ֳ����Ķ���
�桡��: v050601 Copyright(c).
******************************************************************/
#include <fstream>
#include<string>
#include<iostream>
using namespace std;

int TIME = 1;

const int MaxPub = 100;

const int MaxAu = 150;
const int pass = 0;
const int lost = 1;
//file.cpp

const int BSearch = 50;
//search.cpp

const int MaxReNoticeDay = 5;//ԤԼ�������� 
//search.cpp

const int RNlen = 11;
const int BIlen = 11;//�ѽ�����ı��� 
const float MaxFine = -20;//���Ƿ����

const float OverdueFine = 1 ;//����һ��ķ����� 
//OverduMgt.cpp


const int ReIDLen = 7;//����id�ĳ��� 
const int BookIDLen = 12;
//Notice.cpp

const int BNlen = 51;//��һ���ض���'\0' 
const int AUlen = 11;
const int PBlen = 21;
const int OBlen = 10;
// ����֪ͨ���ͼ���������� 
//BOOKCLASS.cpp

const string AdminName = "����Ա";
const int AdminID = 7;
const int ANlen = 4;
const int StuTime = 3;//ѧ���ɽ������� 
const int TeaTime = 7;//��ʦ�ɽ������� 
const int StuBookNum = 5;//ѧ���ɽ��鱾�� 
const int TeaBookNum = 10;//��ʦ�ɽ��鱾�� 
//ADMCLASS.cpp

