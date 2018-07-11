/******************************************************************
文件名: rankdialog.cpp
创建人:张宇、刘佳鑫
日　期:2017.5.1
修改人:张宇
日　期:2017.5.3
描　述:图书排行界面，打印图书排行。
版　本: v050601 Copyright(c).
******************************************************************/
#include "rankdialog.h"
#include "ui_rankdialog.h"
#include "Stats.h"

RankDialog::RankDialog(class Book* ub,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RankDialog)
{
    bp=ub;

    rbooktotal=NULL;

    ui->setupUi(this);

    //准备数据模型
    rankinfo_model = new QStandardItemModel();
    rankinfo_model->setHorizontalHeaderItem(0, new QStandardItem(QObject::tr("图书编号")));
    rankinfo_model->setHorizontalHeaderItem(1, new QStandardItem(QObject::tr("图书名称")));
    rankinfo_model->setHorizontalHeaderItem(2, new QStandardItem(QObject::tr("作者")));
    rankinfo_model->setHorizontalHeaderItem(3, new QStandardItem(QObject::tr("出版社")));
    rankinfo_model->setHorizontalHeaderItem(4, new QStandardItem(QObject::tr("类型")));
    rankinfo_model->setHorizontalHeaderItem(5, new QStandardItem(QObject::tr("库存")));
    rankinfo_model->setHorizontalHeaderItem(6, new QStandardItem(QObject::tr("借阅次数")));
    //利用setModel()方法将数据模型与QTableView绑定
    ui->tableView->setModel(rankinfo_model);

    //设置选中时为整行选中
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    //设置表格的单元为只读属性，即不能编辑
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


}

RankDialog::~RankDialog()
{
    delete ui;
}

void RankDialog::on_pushButton_clicked()
{
    close();
}

void RankDialog:: OutputRank()
{
    Stats(bp,*rbooktotal,rankinfo_model);
}
