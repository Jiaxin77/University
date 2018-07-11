/******************************************************************
文件名:digitaldialog.cpp
创建人:张宇、刘佳鑫
日　期:2017.5.1
修改人:
日　期:
描　述:欢迎界面，显示时钟和登陆退出。
版　本: v050601 Copyright(c).
******************************************************************/

#include "digitalclock.h"
#include "ui_digitalclock.h"
#include "mytype.h"
#include "OverdueMgt.h"
#include "Notice.h"
#include "ReservationMgt.h"
#include "TimeMgt.h"
#include "file.h"
#include <QtCore>
#include <QtGui>
#include <QDebug>

DigitalClock::DigitalClock(class Book* mb,class Reader* mr,class Administration* ma,int *booktotal,int *readertotal,PubCodeList *pl,AuCodeList *al,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DigitalClock)
{
    ui->setupUi(this);

    string stime=TimeConvert();
    QString qtime=QString::fromStdString(stime);
    ui->lcdNumber->display(qtime);

    timer = new QTimer(this);//计时器
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));//关联计时器和显示时间函数
    timer->start(1000);//启动计时器

    dlg=NULL;

    connect(ui->pushButton,SIGNAL(clicked(bool)),this,SLOT(showChild()));

    bp=mb;
    rp=mr;
    ap=ma;

    Booktotal=booktotal;
    Readertotal=readertotal;

   dpl=pl;
   dal=al;
 }

DigitalClock::~DigitalClock()
{    timer->stop();//停止计时器
     delete timer;//释放计时器内存
     delete ui;
     delete dlg;
}

void DigitalClock::showChild()
{
    dlg = new class log(bp,rp,ap,dpl,dal,this);
    dlg->lbooktotal=Booktotal;
    dlg->lreadertotal=Readertotal;
    dlg->show();
    connect(dlg,SIGNAL(sendclosenotice()),this,SLOT(starttime()));//如果被关闭后重新开启计时器


}

void DigitalClock::starttime()
{
    timer->start();

}


void DigitalClock::showTime()
{
    string stime=TimeConvert();
    QString qtime=QString::fromStdString(stime);
    ui->lcdNumber->display(qtime);

    OverdueMgt(rp,bp,*Booktotal,*Readertotal);//调用逾期处理
    ReservationMgt(bp,*Booktotal);//调用预约处理

   TIME++;


}

void DigitalClock::on_pushButton_clicked()//点击登录按钮
{
    if(timer->isActive())
    {timer->stop();

    }
     else
    {timer->start();}

}

void DigitalClock::timestart()//启动计时器
{
    timer->start(1000);
}


void DigitalClock::on_pushButton_2_clicked()//退出按钮槽函数
{
    UpdateBookInformation(bp,ap->GetBookNum(),*Booktotal);//更新图书信息
    UpdateReaderInformation(rp,*Readertotal,ap->GetReaderNum());//更新读者信息
    CreateReserveList(bp,*Booktotal);//创建预约单
    UpdateCodeList(dpl,dal);//更新编码表
    close();//关闭
}
