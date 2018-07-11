/******************************************************************
文件名: userdialog.cpp
创建人:张宇、刘佳鑫
日　期:2017.5.1
修改人:
日　期:
描　述:用户界面显示。
版　本: v050601 Copyright(c).
******************************************************************/
#include "userdialog.h"
#include "ui_userdialog.h"
#include "rankdialog.h"
#include "noticedialog.h"
#include "searchdialog.h"
#include "cancelredialog.h"
#include "search.h"
#include "mytype.h"
#include "TimeMgt.h"
#include <QString>
#include "file.h"



UserDialog::UserDialog(class Book* lp,class Reader *lr,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserDialog)
{
    iuser=-1;
    bp=lp;
    rp=lr;

    ubooktotal=NULL;
    ureadertotal=NULL;

    ui->setupUi(this);


    //准备数据模型
    readerinfo_model = new QStandardItemModel();
    readerinfo_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("图书编号")));
    readerinfo_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("图书名称")));
    readerinfo_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("作者")));
    readerinfo_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版社")));
    readerinfo_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("借书时间")));
    readerinfo_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("到期时间")));
    //利用setModel()方法将数据模型与QTableView绑定
    ui->tableView->setModel(readerinfo_model);

    //设置选中时为整行选中
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


}

UserDialog::~UserDialog()
{
    delete ui;
}

void UserDialog::on_existpushButton_clicked()
{
    emit sendcloseuser();//信号需要关联digtaclock
    close();
}

void UserDialog::OutputReader()
{
    //先调一个每本书单独search按id，再输出,单循环
    int boednum=rp[iuser].GetBoedNum();
    int bookpos,obpos;//大书下标和小书下标
    long long int  bookid[BIlen];
    long long int lbookid;
    string bookname,author,publish,sbotime,sduetime;
    int botime,duetime;

    QString qbookid,qbookname,qauthor,qpublish,qbotime,qduetime;

    //设置上部信息
    string readername;
    long int readerid;
    int booknum;
    float fine;
    int rank;

    QString qreadername,qreaderid,qbooknum,qboednum,qfine;

    readername=rp[iuser].GetReaderName();
    qreadername=qreadername.fromLocal8Bit(readername.data());
    ui->namelabel->setText(qreadername);

    readerid=rp[iuser].GetReaderID();
    qreaderid=QString("%1").arg(readerid);
    ui->idlabel->setText(qreaderid);

    booknum=rp[iuser].GetBookNum();
    qbooknum=QString("%1").arg(booknum);
    ui->maxbolabel->setText(qbooknum);

    boednum=rp[iuser].GetBoedNum();
    qboednum=QString("%1").arg(boednum);
    ui->bonumlabel->setText(qboednum);

    fine=rp[iuser].GetFine();
    qfine=QString("%1").arg(fine);
    ui->finelabel->setText(qfine);

    rank=rp[iuser].GetRank();
    if(rank==1)
    {
        ui->typelabel->setText(tr("学生"));
    }
    else if(rank==2)
    {
        ui->typelabel->setText(tr("教师"));
    }



    for(int i=0;i<BIlen;i++)
    {
        bookid[i]=-1;
    }

    rp[iuser].GetBoBookID(bookid);

    for(int i=0,j=0;i<BIlen;i++)//获取每本借阅的图书的信息
    {
        if(bookid[i]!=-1)
        {
        bookpos=SearchBookID(bp,bookid[i],*ubooktotal);

        lbookid=bookid[i];
        qbookid=QString("%1").arg(lbookid);

        bookname=bp[bookpos].GetBookName();
        qbookname=qbookname.fromLocal8Bit(bookname.data());

        author=bp[bookpos].GetAuthor();
        qauthor=qauthor.fromLocal8Bit(author.data());

        publish=bp[bookpos].GetPublish();
        qpublish=qpublish.fromLocal8Bit(publish.data());

        obpos=lbookid%2;
        botime=bp[bookpos].GetOBBoTime(obpos);
        sbotime=TimeConvertConst(botime);
        qbotime=QString::fromStdString(sbotime);

        if(rp[iuser].GetRank()==1)
        duetime=botime+StuTime;
        else
        duetime=botime+TeaTime;

        sduetime=TimeConvertConst(duetime);
        qduetime=QString::fromStdString(sduetime);


        readerinfo_model->setItem(j, 0, new QStandardItem(qbookid));//设置tableview的项目
        readerinfo_model->setItem(j, 1, new QStandardItem(qbookname));
        readerinfo_model->setItem(j, 2, new QStandardItem(qauthor));
        readerinfo_model->setItem(j, 3, new QStandardItem(qpublish));
        readerinfo_model->setItem(j, 4, new QStandardItem(qbotime));
        readerinfo_model->setItem(j, 5, new QStandardItem(qduetime));
        j++;
        }
    }

}

void UserDialog:: OutputReaderslot()
{
    //先调一个每本书单独search按id，再输出,单循环
    int boednum=rp[iuser].GetBoedNum();
    int bookpos,obpos;//大书下标和小书下标
    long long int  bookid[BIlen];
    long long int lbookid;
    string bookname,author,publish,sbotime,sduetime;
    int botime,duetime;

    QString qbookid,qbookname,qauthor,qpublish,qbotime,qduetime;

    //设置上部信息
    string readername;
    long int readerid;
    int booknum;
    float fine;
    int rank;

    QString qreadername,qreaderid,qbooknum,qboednum,qfine;

    readername=rp[iuser].GetReaderName();
    qreadername=qreadername.fromLocal8Bit(readername.data());
    ui->namelabel->setText(qreadername);

    readerid=rp[iuser].GetReaderID();
    qreaderid=QString("%1").arg(readerid);
    ui->idlabel->setText(qreaderid);

    booknum=rp[iuser].GetBookNum();
    qbooknum=QString("%1").arg(booknum);
    ui->maxbolabel->setText(qbooknum);

    boednum=rp[iuser].GetBoedNum();
    qboednum=QString("%1").arg(boednum);
    ui->bonumlabel->setText(qboednum);

    fine=rp[iuser].GetFine();
    qfine=QString("%1").arg(fine);
    ui->finelabel->setText(qfine);

    rank=rp[iuser].GetRank();
    if(rank==1)
    {
        ui->typelabel->setText(tr("学生"));
    }
    else if(rank==2)
    {
        ui->typelabel->setText(tr("教师"));
    }



    for(int i=0;i<BIlen;i++)
    {
        bookid[i]=-1;
    }

    rp[iuser].GetBoBookID(bookid);

    for(int i=0,j=0;i<BIlen;i++)
    {
        if(bookid[i]!=-1)
        {
        bookpos=SearchBookID(bp,bookid[i],*ubooktotal);

        lbookid=bookid[i];
        qbookid=QString("%1").arg(lbookid);

        bookname=bp[bookpos].GetBookName();
        qbookname=qbookname.fromLocal8Bit(bookname.data());

        author=bp[bookpos].GetAuthor();
        qauthor=qauthor.fromLocal8Bit(author.data());

        publish=bp[bookpos].GetPublish();
        qpublish=qpublish.fromLocal8Bit(publish.data());

        obpos=lbookid%2;
        botime=bp[bookpos].GetOBBoTime(obpos);
        sbotime=TimeConvertConst(botime);
        qbotime=QString::fromStdString(sbotime);

        if(rp[iuser].GetRank()==1)
        duetime=botime+StuTime;
        else
        duetime=botime+TeaTime;

        sduetime=TimeConvertConst(duetime);
        qduetime=QString::fromStdString(sduetime);


        readerinfo_model->setItem(j, 0, new QStandardItem(qbookid));
        readerinfo_model->setItem(j, 1, new QStandardItem(qbookname));
        readerinfo_model->setItem(j, 2, new QStandardItem(qauthor));
        readerinfo_model->setItem(j, 3, new QStandardItem(qpublish));
        readerinfo_model->setItem(j, 4, new QStandardItem(qbotime));
        readerinfo_model->setItem(j, 5, new QStandardItem(qduetime));
        j++;
        }
    }

}

void UserDialog::on_returnpushButton_clicked()
{
    int row = ui->tableView->currentIndex().row();//得到选定行
    QString str=readerinfo_model->data(readerinfo_model->index(row,0)).toString();//得到图书编号
    QString qbookname=readerinfo_model->data(readerinfo_model->index(row,1)).toString();
    string bookname;
    QByteArray cdata = qbookname.toLocal8Bit();//中文字符转换
    bookname=string(cdata);



    long long int id=str.toLongLong();//转换数据类型得图书id longlongint

    if(row != -1 )
   {

    if(rp[iuser].ReturnBook(bp,id,*ubooktotal)){//还书成功和还书失败的提醒
          QMessageBox::information(this,tr("提示"),tr("还书成功！"));
          UpdateJournalFile("..\\project2\\initiate\\ReturnLog.txt",bookname, id,rp[iuser].GetReaderName(),rp[iuser].GetReaderID());
      }
    else{
          QMessageBox::warning(this,tr("警告"),tr("还书失败！"));
      }

    readerinfo_model->removeRow(row);//删除指定行

    int boednum=rp[iuser].GetBoedNum();
    QString qboednum=QString("%1").arg(boednum);
    ui->bonumlabel->setText(qboednum);
   }

    else
    {
        QMessageBox::information(this,tr("提示"),tr("您无法进行该操作！"));

    }


}

void UserDialog::on_losepushButton_clicked()
{
    int row = ui->tableView->currentIndex().row();//得到选定行
    QString str=readerinfo_model->data(readerinfo_model->index(row,0)).toString();//得到图书编号

    long long int id=str.toLongLong();//转换数据类型得图书id longlongint

    if(row != -1)
    {
    if(rp[iuser].ReportLoss(rp,rp[iuser].GetReaderID(),bp,id,*ureadertotal,*ubooktotal)){ //挂失成功和挂失失败的提醒
            QMessageBox::information(this,tr("提示"),tr("挂失成功！"));

        }
    else{
            QMessageBox::warning(this,tr("警告"),tr("挂失失败！"));
        }

    readerinfo_model->removeRow(row);//删除指定行

    float fine=rp[iuser].GetFine();
    QString qfine=QString("%1").arg(fine);
    ui->finelabel->setText(qfine);

    int boednum=rp[iuser].GetBoedNum();
    QString qboednum=QString("%1").arg(boednum);
    ui->bonumlabel->setText(qboednum);
    }

    else
    {
         QMessageBox::information(this,tr("提示"),tr("您无法进行该操作！"));
    }

}

void UserDialog::on_rankpushButton_clicked()
{
    RankDialog* rdlg = new RankDialog(bp,this);
    rdlg->rbooktotal = ubooktotal;
    rdlg->OutputRank();
    rdlg->show();
}

void UserDialog::on_noticepushButton_clicked()
{
    NoticeDialog *ndlg = new NoticeDialog(rp[iuser].GetReaderID(),this);
    ndlg->inotice=iuser;
    ndlg->show();
}

void UserDialog::on_searchpushButton_clicked()
{
    SearchDialog *sdlg = new SearchDialog(bp,rp,this);
    sdlg->isearch=iuser;
    sdlg->sbooktotal=ubooktotal;
    sdlg->show();
    connect(sdlg,SIGNAL(sendsearchclosenotice()),this,SLOT(OutputReaderslot()));
}

void UserDialog::on_cancelrepushButton_clicked()
{
    CancelReDialog *cdlg = new CancelReDialog(bp,rp,this);
    cdlg->icancel=iuser;
    cdlg->cbooktotal=ubooktotal;
    cdlg->show();
}
