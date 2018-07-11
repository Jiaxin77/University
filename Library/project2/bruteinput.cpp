/******************************************************************
文件名:bruteinput.cpp
创建人:万诗婕
日　期:2017-05-05
修改人:万诗婕、张宇、高楠、刘佳鑫
日　期:2017-05-05
描　述:本文件中包含了对用户暴力输入处理的相关函数，实现了防止各类输入框暴力输入的功能
版　本: v050602
******************************************************************/
#include "bruteinput.h"

  /*****************************************************************
  函数名：bool isStringBruteInput(QString src,int length)
  功能：判断字符串输入是否符合要求
  返回值：
  bool型变量，符合要求为true，不符合要求为false
  参数：
      QString src，从对话框中读入的字符串
  int length，相应对话框输入要求的字符串长度的最大长度
  ****************************************************************/

bool isStringBruteInput(QString src,int length){
    if(src.length() <= length){
        return true;
    }
    else{
        return false;
    }
}

/*****************************************************************
函数名：bool isDigitBruteInput(QString src,int length)
功能：判断编号输入是否符合要求
返回值：
bool型变量，符合要求为true，不符合要求为false
参数：
    QString src，从对话框中读入的数字串
int length，相应对话框输入要求的数字串长度
****************************************************************/

bool isDigitBruteInput(QString src,int length){
    if(src.length() == length){
        if(isDigitStr(src)){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

/*****************************************************************
函数名：bool isDigitStr(QString src)
功能：判断src是否为纯数字
返回值：
bool型变量，符合要求为true，不符合要求为false
参数：
    QString src，从对话框中读入的数字串
****************************************************************/

bool isDigitStr(QString src)
{
    QByteArray ba = src.toLatin1();//QString 转换为 char*
    const char *s = ba.data();

    while(*s && *s>='0' && *s<='9') s++;

    if (*s)
    { //不是纯数字
        return false;
    }
    else
    { //纯数字
        return true;
    }
}

/*****************************************************************
函数名：bool isFloatBruteInput(QString src)
功能：判断src是否为浮点数
返回值：
bool型变量，符合要求为true，不符合要求为false
参数：
    QString src，从对话框中读入的数字串
****************************************************************/

bool isFloatBruteInput(QString src){
    QByteArray ba = src.toLatin1();//QString 转换为 char*
    const char *s = ba.data();
    while((*s && *s>='0' && *s<='9')||(*s == '.')) {
        s++;
    }
    if (*s)
    { //不是纯数字
        return false;
    }
    else
    { //纯数字
        return true;
    }
}
