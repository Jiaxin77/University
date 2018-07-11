/******************************************************************
文件名: readeropdialog.cpp
创建人:张宇、刘佳鑫
日　期:2017.5.1
修改人:刘佳鑫、万诗婕、高楠
日　期:2017.5.3
描　述:管理员界面中的子界面——用户操作界面，包括充值缴费，删除读者，搜索读者功能。
版　本: v050601 Copyright(c).
******************************************************************/
#include "readeropdialog.h"
#include "ui_readeropdialog.h"
#include "moneydialog.h"
#include "TimeMgt.h"
#include "bruteinput.h"
#include <QString>
#include <string>
#include <QtGui>
#include <QtCore>
#include "search.h"
#include "mytype.h"
using namespace std;


ReaderopDialog::ReaderopDialog(class Book* ab,class Reader* ar,class Administration* aa,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReaderopDialog)
{
    ui->setupUi(this);
    ireader=-1;
    bp=ab;
    rp=ar;
    ap=aa;
    rebooktotal=NULL;
    rereadertotal=NULL;

    //准备数据模型
    sreaderinfo_model = new QStandardItemModel();
    sreaderinfo_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("图书编号")));
    sreaderinfo_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("图书名称")));
    sreaderinfo_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("作者")));
    sreaderinfo_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版社")));
    sreaderinfo_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("借书时间")));
    sreaderinfo_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("到期时间")));
    //利用setModel()方法将数据模型与QTableView绑定
    ui->tableView->setModel(sreaderinfo_model);

    //设置选中时为整行选中
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

ReaderopDialog::~ReaderopDialog()
{
    delete ui;
}

void ReaderopDialog::on_exitpushButton_clicked()
{
    close();
}

void ReaderopDialog::on_searchpushButton_clicked()
{
    QString qname,qid,qbuff;
    int ibuff;
    float fbuff;
    bool inname=false,inid=false;

    qname=ui->namelineEdit->text();
    qid=ui->idlineEdit->text();

    inname=isStringBruteInput(qname,RNlen);
    inid=isDigitBruteInput(qid,ReIDLen);

  if(inname==true&&inid==true)
   {
    long int id;


    string sname;
    QByteArray cdata = qname.toLocal8Bit();//中文字符转换
    sname=string(cdata);

    id=qid.toLong();

    ireader=SearchReader(rp,id,*rereadertotal);
    if(ireader==-1||sname.compare(rp[ireader].GetReaderName())!=0)
    {
        QMessageBox::warning(this,tr("失败"),tr("未查询到符合要求的读者"));
    }


    //调用根据编号搜索读者,返回下标值存入ireader

    else
    {
        QMessageBox::information(this,tr("成功"),tr("查找成功"));

    ui->namelabel->setText(qname);//姓名
    ui->idlabel->setText(qid);//编号


    fbuff=rp[ireader].GetFine();//读者指针 罚款
    qbuff=QString("%1").arg(fbuff);
    ui->finelabel->setText(qbuff);

    ibuff=rp[ireader].GetBoedNum();//已借数量
    qbuff=QString("%1").arg(ibuff);
    ui->bonumlabel->setText(qbuff);




    if(id/1000000==1)
    {
        ui->typelabel->setText(tr("学生"));
    }
    else if(id/1000000==2)
    {
        ui->typelabel->setText(tr("教师"));
    }


    OutputReader();

    }

  }
  else
  {
      QMessageBox::warning(this,tr("警告"),tr("您输入的内容有误！"));
  }

}

void ReaderopDialog::OutputReader()
{

    int bookpos,obpos;//大书下标和小书下标
    long long int  bookid[BIlen];
    long long int lbookid;
    string bookname,author,publish,sbotime,sduetime;
    int botime,duetime;

    QString qbookid,qbookname,qauthor,qpublish,qbotime,qduetime;

   int row =sreaderinfo_model->rowCount();
    for (int i=0; i<row; i++)
    {
         sreaderinfo_model->removeRow(0);
     }//清空表格

    for(int i=0;i<BIlen;i++)
    {
        bookid[i]=-1;
    }

    rp[ireader].GetBoBookID(bookid);

    for(int i=0,j=0;i<BIlen;i++)
    {
        if(bookid[i]!=-1)
        {
        bookpos=SearchBookID(bp,bookid[i],*rebooktotal);

        lbookid=bookid[i];//得到相应的数据类型进行数据转换
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
        qbotime=qbotime.fromLocal8Bit(sbotime.data());

        if(rp[ireader].GetRank()==1)
        duetime=botime+StuTime;
        else
        duetime=botime+TeaTime;

        sduetime=TimeConvertConst(duetime);
        qduetime=qduetime.fromLocal8Bit(sduetime.data());

        //设置对应的项目
        sreaderinfo_model->setItem(j, 0, new QStandardItem(qbookid));
        sreaderinfo_model->setItem(j, 1, new QStandardItem(qbookname));
        sreaderinfo_model->setItem(j, 2, new QStandardItem(qauthor));
        sreaderinfo_model->setItem(j, 3, new QStandardItem(qpublish));
        sreaderinfo_model->setItem(j, 4, new QStandardItem(qbotime));
        sreaderinfo_model->setItem(j, 5, new QStandardItem(qduetime));
        j++;
        }
    }


}

void ReaderopDialog::on_delreaderpushButton_clicked()
{
    QMessageBox::StandardButton rb = QMessageBox::question(NULL, tr("确认"), tr("是否删除该读者？"), QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if(rb == QMessageBox::Yes)
    {

        if(ap->DelReader(rp,rp[ireader].GetReaderID(),rp[ireader].GetReaderName(),*rereadertotal)){
            QMessageBox::information(NULL, tr("提示"), tr("已注销！"));
        }
        else{
            QMessageBox::warning(NULL, tr("警告"), tr("注销失败！"));
        }
    }

}
void ReaderopDialog::on_moneypushButton_clicked()
{
    MoneyDialog *mdlg = new MoneyDialog(rp,ap,this);//弹缴费充值窗口
    mdlg->imoney = ireader;
    mdlg->mreadertotal=rereadertotal;
    mdlg->show();
    connect(mdlg,SIGNAL(sendMoneyclose()),this,SLOT(updatefine()));//关联退出和更新罚金
}

void ReaderopDialog::updatefine()
{
    QString qbuff;

    float fbuff;

    fbuff=rp[ireader].GetFine();//读者指针 罚款
    qbuff=QString("%1").arg(fbuff);
    ui->finelabel->setText(qbuff);
 }
