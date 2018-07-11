/******************************************************************
文件名: moneydialog.cpp
创建人:张宇、刘佳鑫
日　期:2017.5.1
修改人:刘佳鑫
日　期:2017.5.3
描　述:充值缴费界面。
版　本: v050601 Copyright(c).
******************************************************************/

#include "moneydialog.h"
#include "ui_moneydialog.h"
#include "bruteinput.h"
#include <QString>
#include <QtGui>
#include <QtCore>

MoneyDialog::MoneyDialog(class Reader* oreader,class Administration* oa,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MoneyDialog)
{
    ui->setupUi(this);
    imoney = -1;
    rp=oreader;
    ap=oa;
    mreadertotal=NULL;
}

MoneyDialog::~MoneyDialog()
{
    delete ui;
}

void MoneyDialog::on_exitpushButton_clicked()
{
    emit sendMoneyclose();
    close();

}

void MoneyDialog::on_okpushButton_clicked()
{
    QString qmoney;
    qmoney = ui->lineEdit->text();
   if(isFloatBruteInput(qmoney))
   { float fmoney;
    fmoney=qmoney.toFloat();
    int ok;
    long int id=rp[imoney].GetReaderID();
    ok=ap->HandinFine(rp,id,fmoney,*mreadertotal);//调缴费充值函数
    if(ok==1)
        {
             QMessageBox::information(this,tr("成功"),tr("缴费成功"));

        }

    else{
             QMessageBox::warning(this,tr("失败"),tr("缴费失败"));
         }
   }
   else
   {
       QMessageBox::warning(this,tr("警告"),tr("您输入的内容有误！"));

   }
}
