/******************************************************************
文件名: addbookdialog.cpp
创建人:张宇、刘佳鑫
日　期:2017.5.1
修改人:高楠
日　期:2017.5.3
描　述:新增图书界面。
版　本: v050601 Copyright(c).
******************************************************************/
#include "addbookdialog.h"
#include "ui_addbookdialog.h"
#include "file.h"
#include "bruteinput.h"
#include <QString>
#include <QtGui>
#include <QtCore>
#include <string>
using namespace std;

AddBookDialog::AddBookDialog(class Book* ab,class Administration* aa,PubCodeList *pl,AuCodeList *al,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBookDialog)
{
    ui->setupUi(this);
    bp=ab;
    ap=aa;
    abal=al;
    abpl=pl;
    ui->comboBox->addItem(tr("综合"));
    ui->comboBox->addItem(tr("理工"));
    ui->comboBox->addItem(tr("人文"));
    ui->comboBox->addItem(tr("社科"));
    ui->comboBox->addItem(tr("艺术"));
    abbooktotal=NULL;
}

AddBookDialog::~AddBookDialog()
{
    delete ui;
}

void AddBookDialog::on_pushButton_2_clicked()//退出按钮槽函数
{
    close();
}

void AddBookDialog::on_pushButton_clicked()//新增图书槽函数
{
        QString qbookname,qauthor,qpublish,qprice,qtype;
        string bookname,author,publish,type;
        float price;
        BookType bt;

        bool inname=false,inauthor=false,inpublish=false,inprice=false,intype=false;


        qbookname=ui->booknamelineEdit->text();//获取输入内容
        qauthor=ui->authorlineEdit->text();
        qpublish=ui->puublishlineEdit->text();
        qprice=ui->pricelineEdit->text();
        qtype=ui->comboBox->currentText();

        if(isStringBruteInput(qbookname,BNlen)) inname=true;
        if(isStringBruteInput(qauthor,AUlen)) inauthor=true;
        if(isStringBruteInput(qpublish,PBlen)) inpublish=true;
        if(isFloatBruteInput(qprice)) inprice=true;
        if(qtype==tr("理工")||qtype==tr("艺术")||qtype==tr("人文")||qtype==tr("社科")||qtype==tr("综合"))
        intype=true;

     if(inname==true&&inauthor==true&&inpublish==true&&inprice==true&&intype==true)
      {
        QByteArray cdata = qbookname.toLocal8Bit();//中文字符转换
        bookname=string(cdata);
        cdata = qauthor.toLocal8Bit();//中文字符转换
        author=string(cdata);   
        cdata = qpublish.toLocal8Bit();//中文字符转换
        publish=string(cdata);
        price=qprice.toFloat();
        cdata = qtype.toLocal8Bit();//中文字符转换
        type=string(cdata);
        bt=_TransBookType(type);//调用类型转换函数得到Type类型

        if(ap->NewBook(bp,bt,bookname,author,publish,price,abbooktotal,abpl,abal)){  //调用新增图书函数根据返回值弹框
             QMessageBox::information(this,tr("提示"),tr("新建图书成功！"));
        }
        else{
            QMessageBox::warning(this,tr("提示"),tr("新建图书失败！"));
        }
      }
     else
      {
            QMessageBox::warning(this,tr("警告"),tr("您输入的内容有误！"));
      }


}
