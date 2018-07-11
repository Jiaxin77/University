/******************************************************************
文件名: cancelredialog.cpp
创建人:张宇、刘佳鑫
日　期:2017.5.1
修改人:万诗婕
日　期:2017.5.3
描　述:注销读者界面。
版　本: v050601 Copyright(c).
******************************************************************/
#include "cancelredialog.h"
#include "ui_cancelredialog.h"
#include "search.h"
#include "bruteinput.h"
#include <QString>
#include <QDebug>
#include <QtCore>
#include <QtGui>

CancelReDialog::CancelReDialog(class Book* ub,class Reader* ur,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CancelReDialog)
{
    ui->setupUi(this);
    icancel=-1;
    bp=ub;
    rp=ur;
    cbooktotal=NULL;
}

CancelReDialog::~CancelReDialog()
{
    delete ui;
}

void CancelReDialog::on_exitpushButton_clicked()//退出按钮槽函数
{
    close();
}

void CancelReDialog::on_okpushButton_clicked()//确定按钮槽函数
{
    QString qstr;
    long long int id;

    qstr=ui->lineEdit->text();
  if(isDigitBruteInput(qstr,ReIDLen))//判断输入
   {
    id=qstr.toLongLong();

    int i=SearchBookID(bp,id,*cbooktotal); //调用按编号搜索函数

    if(rp[icancel].CancelReserve(bp,i)){  //调取消预约函数,根据返回值弹消息框
            QMessageBox::information(this,tr("成功"),tr("取消预约成功!"));
        }
    else{
            QMessageBox::warning(this,tr("警告"),tr("取消预约失败!"));
        }
    }
  else
    {
        QMessageBox::warning(this,tr("警告"),tr("您输入的内容有误！"));
    }


}
