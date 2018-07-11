/******************************************************************
文件名: noticedialog.cpp
创建人:张宇、刘佳鑫
日　期:2017.5.1
修改人:张宇
日　期:2017.5.3
描　述:读取消息文件，界面输出。
版　本: v050601 Copyright(c).
******************************************************************/


#include "noticedialog.h"
#include "ui_noticedialog.h"
#include "mytype.h"
#include <fstream>
#include <iostream>
#include <QtCore>
#include <QtGui>
using namespace std;

NoticeDialog::NoticeDialog(long int readerid,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NoticeDialog)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);

    inotice=-1;
    RID=readerid;

    OutputNotice();


}

NoticeDialog::~NoticeDialog()
{
    delete ui;
}

void NoticeDialog::OutputNotice()
{
    long int temp=RID;
    const int DIVIDER=1000000;
    int divider=DIVIDER;
    char filename[ReIDLen+30]="..\\project2\\ReaderNotice\\0000000.txt";//文件初始路径

    for(int i=0, j=25; i<ReIDLen ;i++,j++) //将长整型的读者编号存入字符数组的相应位置，计算文件名
    {
        filename[j]=temp/divider+'0';
        temp=temp%divider;
        divider=divider/10;
    }

    ifstream fptr;
    fptr.open(filename,ios::in);//以读和尾部追加的方式打开文件

    if(!fptr)
    {
        QMessageBox::warning(this,tr("提示"),tr("暂无消息"));
    }

    string line;
    QString Line;

    while (getline(fptr, line)) {

        Line=Line.fromLocal8Bit(line.data());
        ui->textEdit->append(Line);

    }



}

void NoticeDialog::on_pushButton_clicked()
{
    close();
}
