/******************************************************************
文件名: main.cpp
创建人:张宇、刘佳鑫、万诗婕、高楠
日　期:2017.5.1
修改人:张宇、刘佳鑫、万诗婕、高楠
日　期:2017.5.3
描　述:主函数，定义需要用的量，显示界面。
版　本: v050601 Copyright(c).
******************************************************************/


#include <QApplication>
#include "digitalclock.h"
#include "file.h"
#include "BOOKCLASS.h"
#include "ADMCLASS.h"
#include "READERCLASS.h"
#include<QTextCodec>
#include <QDebug>
#include <QtGui>
#include <QtCore>
#include <QFont>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForTr(QTextCodec::codecForName("UTF-8"));//转换中文字符

    class Reader reader[150];//新建读者类 图书类 管理员类
    class Book book[100];
    class Administration adm;

    PubCodeList pl[MaxPub]; //存出版社编码
    AuCodeList al[MaxAu];   //存读者编码

    InitiateCodeList(pl,al);

    int readertotal=GetReaderInformation(reader); //读取文件中读者信息
    int booktotal=GetBookInformation(book); //读取文件中图书信息
    adm.SetBookNum(booktotal);  //将图书总数和读者总数传给管理员
    adm.SetReaderNum(readertotal);

    QFont font;
    font.setPixelSize(12);
    a.setFont(font);

    DigitalClock dlg(book,reader,&adm,&booktotal,&readertotal,pl,al);//电子时钟窗口显示
    dlg.show();


    return a.exec();
}
