/******************************************************************
文件名: addreaderdialog.cpp
创建人:张宇、刘佳鑫
日　期:2017.5.1
修改人:万诗婕
日　期:2017.5.3
描　述:新增读者界面。
版　本: v050601 Copyright(c).
******************************************************************/
#include "addreaderdialog.h"
#include "ui_addreaderdialog.h"
#include "bruteinput.h"
#include <QString>
#include <string>
#include <QtGui>
#include <QtCore>
using namespace std;

AddReaderDialog::AddReaderDialog(class Reader* ar,class Administration* aa,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddReaderDialog)
{
    ui->setupUi(this);
    rp=ar;
    ap=aa;
    arreadertotal=NULL;
}

AddReaderDialog::~AddReaderDialog()
{
    delete ui;
}

void AddReaderDialog::on_exitpushButton_clicked()//退出槽函数
{
    close();
}

void AddReaderDialog::on_okpushButton_clicked()//新增读者确定按钮槽函数
{
    QString qname,qid;
    string sname;
    long int id;
    bool inname=false,inid=false;

    qname=ui->namelineEdit->text();
    inname=isStringBruteInput(qname,RNlen);//防止暴力输入

    qid=ui->idlineEdit->text();
    inid=isDigitBruteInput(qid,ReIDLen);//防止暴力输入

  if(inname==true&&inid==true)
   {
    QByteArray cdata = qname.toLocal8Bit();//中文字符转换
    sname=string(cdata);

    id=qid.toLong();


     if(ap->NewReader(rp,id,sname,arreadertotal))//调用新增读者函数，根据返回值弹提示框
      {
        QMessageBox::information(this,tr("提示"),tr("新增读者成功"));
      }
    else
      {
        QMessageBox::warning(this,tr("提示"),tr("新增读者失败"));
      }

    }
  else
    {
      QMessageBox::warning(this,tr("警告"),tr("您的输入有误！"));
    }

}
