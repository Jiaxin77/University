/******************************************************************
文件名: logonlog.cpp
创建人:张宇、刘佳鑫
日　期:2017.5.1
修改人:张宇
日　期:2017.5.3
描　述:登录界面。
版　本: v050601 Copyright(c).
******************************************************************/


#include "logon.h"
#include "ui_logon.h"
#include <QtGui>
#include <QtCore>
#include <QDialog>
#include <QString>
#include <string>
#include "userdialog.h"
#include "admdialog.h"
#include "search.h"
#include "bruteinput.h"
#include <QDebug>
using namespace std;


log::log(class Book* mb,class Reader* mr,class Administration* ma,PubCodeList *pl,AuCodeList *al,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::log)
{
    ui->setupUi(this);
    ilog=-1;//遍历搜索得到
    lbooktotal=NULL;
    lreadertotal=NULL;

    bp=mb;
    rp=mr;
    ap=ma;

    lpl=pl;
    lal=al;

}

log::~log()
{
    delete ui;
}



void log::on_pushButton_clicked()
{
    QString qname,qid;
    string sname;
    long int id;
    int i=0;
    int flag=1;
    bool inname=false,inid=false;//检测输入格式是否有误

//管理员part
    if(ui->aradioButton->isChecked())
        {
            if(ui->namelineEdit->text()==tr("管理员")&&ui->idlineEdit->text()==tr("007"))
             {
               AdmDialog *adlg = new AdmDialog(bp,rp,ap,lpl,lal,this);
               adlg->abooktotal=lbooktotal;
               adlg->areadertotal=lreadertotal;
               adlg->OutputARank();
               adlg->show();
             }

            else
            QMessageBox::warning(this,tr("失败"),tr("管理员登录失败"));
        }
    else if(ui->sradioButton->isChecked()||ui->tradioButton->isChecked())//读者，身份判别
    {
        qname=ui->namelineEdit->text();
        inname=isStringBruteInput(qname,RNlen);

        qid=ui->idlineEdit->text();
        inid=isDigitBruteInput(qid,ReIDLen);

        if(inname==true&&inid==true)
        {
            QByteArray cdata = qname.toLocal8Bit();//中文字符转换
            sname=string(cdata);

            id=qid.toLong();
            int rank = id/1000000;

            if((ui->sradioButton->isChecked()&&rank==1)||(ui->tradioButton->isChecked()&&rank==2))
            {
                //调用匹配函数

              for(i=0;i<*lreadertotal&&flag==1;i++)
              {
                if(rp[i].GetReaderID()==id)
                {
                    if(rp[i].GetReaderName()==sname)
                    {
                        ilog=i;
                        if(rp[i].GetRS()==cancel)
                         {      QMessageBox::warning(this,tr("警告"),tr("该用户已被注销"));}
                        else
                         {
                                UserDialog * dlg = new UserDialog(bp,rp,this);
                                dlg->ubooktotal=lbooktotal;
                                dlg->ureadertotal=lreadertotal;
                                dlg->iuser=ilog;
                                dlg->OutputReader();
                                dlg->show();
                                flag=0;
                         }


                    }


                 }

               }

            }
        }
        else
        {
            QMessageBox::warning(this,tr("警告"),tr("您输入信息有误！"));
        }


        if(ilog==-1&&inname==true&&inid==true)
        {
            QMessageBox::warning(this,tr("警告"),tr("您输入的用户不存在！"));

        }


  }



}



void log::on_pushButton_2_clicked()
{
    emit sendclosenotice();
    close();
}
