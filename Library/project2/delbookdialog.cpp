/******************************************************************
文件名: delbookdialog.cpp
创建人:张宇、刘佳鑫
日　期:2017.5.1
修改人:高楠
日　期:2017.5.3
描　述:注销图书界面。
版　本: v050601 Copyright(c).
******************************************************************/
#include "delbookdialog.h"
#include "ui_delbookdialog.h"
#include "bruteinput.h"
#include <QString>
#include <QtCore>
#include <QtGui>

DelBookDialog::DelBookDialog(class Book* ab,class Administration* aa,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DelBookDialog)
{
    ui->setupUi(this);

    bp=ab;
    ap=aa;
    dbooktotal=NULL;
}

DelBookDialog::~DelBookDialog()
{
    delete ui;
}

void DelBookDialog::on_exitpushButton_clicked()//退出按钮槽函数
{
    close();
}

void DelBookDialog::on_okpushButton_clicked()//确定按钮槽函数
{
    QString qid;
    long long int id;

    qid = ui->idlineEdit->text();
  if(isDigitBruteInput(qid,BookIDLen))//判断输入
   { id = qid.toLongLong();

    //调用注销图书函数，根据返回值弹框
    if(ap->DelBook(bp,id,*dbooktotal))
      {
          QMessageBox::information(this,tr("提示"),tr("注销图书成功"));
      }
      else
       {
          QMessageBox::warning(this,tr("提示"),tr("注销失败"));
      }    if(ap->DelBook(bp,id,*dbooktotal))
      {
          QMessageBox::information(this,tr("提示"),tr("注销图书成功"));
      }
      else
       {
          QMessageBox::warning(this,tr("提示"),tr("注销失败"));
      }

   }
  else
   {
      QMessageBox::warning(this,tr("警告"),tr("您输入的内容有误！"));
  }

}
