/******************************************************************
文件名: searchdialog.cpp
创建人:张宇、刘佳鑫
日　期:2017.4.20
修改人:刘佳鑫
日　期:2017.5.3
描　述:搜索界面。
版　本: v050601 Copyright(c).
******************************************************************/

#include "searchdialog.h"
#include "ui_searchdialog.h"
#include <QString>
#include <string>
#include "search.h"
#include "mytype.h"
#include "bruteinput.h"
#include <QtGui>
#include <QtCore>
#include "file.h"
using namespace std;


SearchDialog::SearchDialog(class Book* ub,class Reader * ur,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchDialog)
{
    ui->setupUi(this);

    isearch=-1;
    bp=ub;
    rp=ur;

    sbooktotal=NULL;

    ui->comboBox->addItem(tr("类型"));
    ui->comboBox->addItem(tr("作者"));
    ui->comboBox->addItem(tr("出版社"));
    ui->comboBox->addItem(tr("图书编号"));
    ui->comboBox->addItem(tr("图书名称"));

    //准备数据模型
    searchinfo_model = new QStandardItemModel();
    searchinfo_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("图书编号")));
    searchinfo_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("图书名称")));
    searchinfo_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("作者")));
    searchinfo_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版社")));
    searchinfo_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("库存量")));
    //利用setModel()方法将数据模型与QTableView绑定
    ui->tableView->setModel(searchinfo_model);
    //设置选中时为整行选中
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    //设置表格的单元为只读属性，即不能编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

SearchDialog::~SearchDialog()
{
    delete ui;
}

void SearchDialog::on_existpushButton_clicked()
{   emit sendsearchclosenotice();
    close();

}



void SearchDialog::on_searchpushButton_clicked()
{
    QString qstr;

    if(ui->comboBox->currentText()==tr("图书名称"))//5个
    {
        string str;
        qstr=ui->lineEdit->text();
      if(isStringBruteInput(qstr,BNlen))
      {

        QByteArray cdata = qstr.toLocal8Bit();//中文字符转换
        str=string(cdata);

        int row =searchinfo_model->rowCount();
        for (int i=0; i<row; i++)
        {
           searchinfo_model->removeRow(0);
        }//清空表格


        int BNS[BSearch];
        long long int lbookid;
        string bookname,author,publish;
        int exist;
        QString qbookid,qbookname,qauthor,qpublish,qexist;
        SearchBookName(BNS,bp,str,*sbooktotal);
        if(BNS[0]==-1)
        {

            QMessageBox::warning(this,tr("失败"),tr("未查询到符合要求的图书"));
        }
        else
        {


            for(int count=0;(count<BSearch)&&(BNS[count]!=-1);count++)
            {

            lbookid=bp[BNS[count]].GetBookID();//得到对应类型的数据，进行数据类型转换
            qbookid=QString("%1").arg(lbookid);

            bookname=bp[BNS[count]].GetBookName();
            qbookname=qbookname.fromLocal8Bit(bookname.data());

            author=bp[BNS[count]].GetAuthor();
            qauthor=qauthor.fromLocal8Bit(author.data());

            publish=bp[BNS[count]].GetPublish();
            qpublish=qpublish.fromLocal8Bit(publish.data());


            exist=bp[BNS[count]].GetExist();
            qexist=QString("%1").arg(exist);

            //设置对应项目
            searchinfo_model->setItem(count, 0, new QStandardItem(qbookid));
            searchinfo_model->setItem(count, 1, new QStandardItem(qbookname));
            searchinfo_model->setItem(count, 2, new QStandardItem(qauthor));
            searchinfo_model->setItem(count, 3, new QStandardItem(qpublish));
            searchinfo_model->setItem(count, 4, new QStandardItem(qexist));


            }
        }
        //调用search,弹messagebox

     }
     else
     {
          QMessageBox::warning(this,tr("警告"),tr("您的输入有误请重新输入！"));
      }

    }

    else if(ui->comboBox->currentText()==tr("图书编号"))//5个
    {
        long long int id;
        qstr=ui->lineEdit->text();
     if(isDigitBruteInput(qstr,BookIDLen))//判断图书编号的长度
      {

        id=qstr.toLongLong();
        int BIS=-1;
        long long int lbookid;
        string bookname,author,publish;
        int exist;
        QString qbookid,qbookname,qauthor,qpublish,qexist;

        int row =searchinfo_model->rowCount();
        for (int i=0; i<row; i++)
        {
           searchinfo_model->removeRow(0);
        }//清空表格

        BIS=SearchBookID(bp,id,*sbooktotal);

        if(BIS==-1)
        {

            QMessageBox::warning(this,tr("失败"),tr("未查询到符合要求的图书"));
        }
        else
        {


            lbookid=bp[BIS].GetBookID();//得到对应类型的数据，进行数据类型转换
            qbookid=QString("%1").arg(lbookid);

            bookname=bp[BIS].GetBookName();
            qbookname=qbookname.fromLocal8Bit(bookname.data());

            author=bp[BIS].GetAuthor();
            qauthor=qauthor.fromLocal8Bit(author.data());

            publish=bp[BIS].GetPublish();
            qpublish=qpublish.fromLocal8Bit(publish.data());


            exist=bp[BIS].GetExist();
            qexist=QString("%1").arg(exist);

             //设置对应项目
            searchinfo_model->setItem(0, 0, new QStandardItem(qbookid));
            searchinfo_model->setItem(0, 1, new QStandardItem(qbookname));
            searchinfo_model->setItem(0, 2, new QStandardItem(qauthor));
            searchinfo_model->setItem(0, 3, new QStandardItem(qpublish));
            searchinfo_model->setItem(0, 4, new QStandardItem(qexist));


            }
        }
     else
     {
       QMessageBox::warning(this,tr("警告"),tr("您的输入有误！"));
     }


    }
    else if(ui->comboBox->currentText()==tr("出版社"))//5个
    {


        string str;
        qstr=ui->lineEdit->text();

      if(isStringBruteInput(qstr,PBlen))
      {
        QByteArray cdata = qstr.toLocal8Bit();//中文字符转换
        str=string(cdata);

        int row =searchinfo_model->rowCount();
        for (int i=0; i<row; i++)
        {
           searchinfo_model->removeRow(0);
        }//清空表格


        int BPS[BSearch];
        long long int lbookid;
        string bookname,author,publish;
        int exist;
        QString qbookid,qbookname,qauthor,qpublish,qexist;

         SearchBookPublish(BPS,bp,str,*sbooktotal);
        if(BPS[0]==-1)
        {

            QMessageBox::warning(this,tr("失败"),tr("未查询到符合要求的图书"));
        }
        else
        {


            for(int count=0;(count<BSearch)&&(BPS[count]!=-1);count++)
            {

            lbookid=bp[BPS[count]].GetBookID();//得到对应类型的数据，进行数据类型转换
            qbookid=QString("%1").arg(lbookid);

            bookname=bp[BPS[count]].GetBookName();
            qbookname=qbookname.fromLocal8Bit(bookname.data());

            author=bp[BPS[count]].GetAuthor();
            qauthor=qauthor.fromLocal8Bit(author.data());

            publish=bp[BPS[count]].GetPublish();
            qpublish=qpublish.fromLocal8Bit(publish.data());


            exist=bp[BPS[count]].GetExist();
            qexist=QString("%1").arg(exist);

            //设置对应项目
            searchinfo_model->setItem(count, 0, new QStandardItem(qbookid));
            searchinfo_model->setItem(count, 1, new QStandardItem(qbookname));
            searchinfo_model->setItem(count, 2, new QStandardItem(qauthor));
            searchinfo_model->setItem(count, 3, new QStandardItem(qpublish));
            searchinfo_model->setItem(count, 4, new QStandardItem(qexist));


            }
        }

        //调用search,弹messagebox

    }
   else
     {
         QMessageBox::warning(this,tr("警告"),tr("您的输入有误！"));
      }
 }

    else if(ui->comboBox->currentText()==tr("作者"))//5个
    {
             string str;
             qstr=ui->lineEdit->text();
         if(isStringBruteInput(qstr,AUlen))
          {
             QByteArray cdata = qstr.toLocal8Bit();//中文字符转换
             str=string(cdata);

             int row =searchinfo_model->rowCount();
             for (int i=0; i<row; i++)
             {
                searchinfo_model->removeRow(0);
             }//清空表格

             int BAS[BSearch];
             long long int lbookid;
             string bookname,author,publish;
             int exist;
             QString qbookid,qbookname,qauthor,qpublish,qexist;

             SearchBookAuthor(BAS,bp,str,*sbooktotal);
             if(BAS[0]==-1)
             {

                 QMessageBox::warning(this,tr("失败"),tr("未查询到符合要求的图书"));
             }
             else
             {


                 for(int count=0;(count<BSearch)&&(BAS[count]!=-1);count++)
                 {

                 lbookid=bp[BAS[count]].GetBookID();//得到对应类型的数据，进行数据类型转换
                 qbookid=QString("%1").arg(lbookid);

                 bookname=bp[BAS[count]].GetBookName();
                 qbookname=qbookname.fromLocal8Bit(bookname.data());

                 author=bp[BAS[count]].GetAuthor();
                 qauthor=qauthor.fromLocal8Bit(author.data());

                 publish=bp[BAS[count]].GetPublish();
                 qpublish=qpublish.fromLocal8Bit(publish.data());


                 exist=bp[BAS[count]].GetExist();
                 qexist=QString("%1").arg(exist);

                 //设置对应项目
                 searchinfo_model->setItem(count, 0, new QStandardItem(qbookid));
                 searchinfo_model->setItem(count, 1, new QStandardItem(qbookname));
                 searchinfo_model->setItem(count, 2, new QStandardItem(qauthor));
                 searchinfo_model->setItem(count, 3, new QStandardItem(qpublish));
                 searchinfo_model->setItem(count, 4, new QStandardItem(qexist));


                 }
             }
        }
        else
         {
             QMessageBox::warning(this,tr("警告"),tr("您的输入有误！"));
         }

    }

    else if(ui->comboBox->currentText()==tr("类型"))//5个
    {
         string str;
         qstr=ui->lineEdit->text();
       if(qstr==tr("理工")||qstr==tr("综合")||qstr==tr("人文")||qstr==tr("艺术")||qstr==tr("社科"))
       {

         QByteArray cdata = qstr.toLocal8Bit();//中文字符转换
         str=string(cdata);

         int row =searchinfo_model->rowCount();
         for (int i=0; i<row; i++)
         {
            searchinfo_model->removeRow(0);
         }//清空表格

        int BTS[BSearch];
        long long int lbookid;
        string bookname,author,publish;
        int exist;
        QString qbookid,qbookname,qauthor,qpublish,qexist;

        SearchBookType(BTS,bp,_TransBookType(str),*sbooktotal);
        if(BTS[0]==-1)
        {

            QMessageBox::warning(this,tr("失败"),tr("未查询到符合要求的图书"));
        }
        else
        {


            for(int count=0;(count<BSearch)&&(BTS[count]!=-1);count++)
            {

            lbookid=bp[BTS[count]].GetBookID();//得到对应类型的数据，进行数据类型转换
            qbookid=QString("%1").arg(lbookid);

            bookname=bp[BTS[count]].GetBookName();
            qbookname=qbookname.fromLocal8Bit(bookname.data());

            author=bp[BTS[count]].GetAuthor();
            qauthor=qauthor.fromLocal8Bit(author.data());

            publish=bp[BTS[count]].GetPublish();
            qpublish=qpublish.fromLocal8Bit(publish.data());


            exist=bp[BTS[count]].GetExist();
            qexist=QString("%1").arg(exist);

             //设置对应项目
            searchinfo_model->setItem(count, 0, new QStandardItem(qbookid));
            searchinfo_model->setItem(count, 1, new QStandardItem(qbookname));
            searchinfo_model->setItem(count, 2, new QStandardItem(qauthor));
            searchinfo_model->setItem(count, 3, new QStandardItem(qpublish));
            searchinfo_model->setItem(count, 4, new QStandardItem(qexist));


            }
        }
      }
     else
      {
        QMessageBox::warning(this,tr("警告"),tr("您的输入有误！"));

      }



    }


}

void SearchDialog::on_bopushButton_clicked()
{
    int row = ui->tableView->currentIndex().row();//得到选定行
    QString str=searchinfo_model->data(searchinfo_model->index(row,0)).toString();//得到图书编号
    QString qbookname=searchinfo_model->data(searchinfo_model->index(row,1)).toString();
    string bookname;
    QByteArray cdata = qbookname.toLocal8Bit();//中文字符转换
    bookname=string(cdata);

    long long int id=str.toLongLong();//转换数据类型得图书id longlongint
    int n=SearchBookID(bp,id,*sbooktotal);

    bool ok=0;
     ok=rp[isearch].BorrowBook(bp,n);
    if(ok==1)
       {
        QMessageBox::information(this,tr("成功"),tr("借书成功"));
        UpdateJournalFile("..\\project2\\initiate\\BorrowLog.txt",bookname,id,rp[isearch].GetReaderName(),rp[isearch].GetReaderID());

       }
    //加借书成功和借书失败的提醒
    else{
        QMessageBox::warning(this,tr("失败"),tr("借书失败"));
        }
    }

void SearchDialog::on_respushButton_clicked()
{
    int row = ui->tableView->currentIndex().row();//得到选定行
    QString str=searchinfo_model->data(searchinfo_model->index(row,0)).toString();//得到图书编号
    QString qbookname=searchinfo_model->data(searchinfo_model->index(row,1)).toString();
    string bookname;
    QByteArray cdata = qbookname.toLocal8Bit();//中文字符转换
    bookname=string(cdata);


    long long int id=str.toLongLong();//转换数据类型得图书id longlongint
    int n=SearchBookID(bp,id,*sbooktotal); //调用按编号搜素函数得到小n

    bool ok=0;
     ok=rp[isearch].Reserve(bp,n);
    if(ok==1)
       {
        QMessageBox::information(this,tr("成功"),tr("预约成功"));
       }

    else{
        QMessageBox::warning(this,tr("失败"),tr("预约失败"));
        }

}
