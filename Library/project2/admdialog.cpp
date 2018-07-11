/******************************************************************
文件名: admdialog.cpp
创建人:张宇、刘佳鑫
日　期:2017.5.1
修改人:刘佳鑫、高楠、万诗婕
日　期:2017.5.3
描　述:管理员界面。
版　本: v050601 Copyright(c).
******************************************************************/
#include "admdialog.h"
#include "ui_admdialog.h"
#include "readeropdialog.h"
#include "addreaderdialog.h"
#include "addbookdialog.h"
#include "delbookdialog.h"
#include "Stats.h"

AdmDialog::AdmDialog(class Book* lp,class Reader* lr,class Administration* la,PubCodeList *pl,AuCodeList *al,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdmDialog)
{
    bp=lp;
    rp=lr;
    ap=la;

    apl=pl;
    aal=al;

    abooktotal=NULL;
    areadertotal=NULL;

    ui->setupUi(this);

    //准备数据模型
    arankinfo_model = new QStandardItemModel();
    arankinfo_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("图书编号")));
    arankinfo_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("图书名称")));
    arankinfo_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("作者")));
    arankinfo_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版社")));
    arankinfo_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("类型")));
    arankinfo_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("库存")));
    arankinfo_model->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("借阅次数")));
    //利用setModel()方法将数据模型与QTableView绑定
    ui->tableView->setModel(arankinfo_model);

    //设置选中时为整行选中
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


}

AdmDialog::~AdmDialog()
{
    delete ui;
}

void AdmDialog::on_exitpushButton_clicked()//退出按钮槽函数
{
    close();
}

void AdmDialog::on_readeroppushButton_clicked()//用户操作槽函数
{
    ReaderopDialog *rdlg = new ReaderopDialog(bp,rp,ap,this);
    rdlg->rebooktotal=abooktotal;
    rdlg->rereadertotal=areadertotal;
    rdlg->show();
}

void AdmDialog::on_addreaderpushButton_clicked()//新增读者槽函数
{
    AddReaderDialog * adlg = new AddReaderDialog(rp,ap,this);
    adlg->arreadertotal=areadertotal;
    adlg->show();
}

void AdmDialog::on_addbookpushButton_clicked()//新增图书槽函数
{
    AddBookDialog *bdlg = new AddBookDialog(bp,ap,apl,aal,this);
    bdlg->abbooktotal=abooktotal;
    bdlg->show();
}

void AdmDialog::on_delbookpushButton_clicked()//注销图书槽函数
{
    DelBookDialog *ddlg = new DelBookDialog(bp,ap,this);
    ddlg->dbooktotal=abooktotal;
    ddlg->show();
}

void AdmDialog::OutputARank()//打印图书排行
{

    Stats(bp,*abooktotal,arankinfo_model);

}
