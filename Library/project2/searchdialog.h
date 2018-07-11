#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "BOOKCLASS.h"
#include "READERCLASS.h"

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(class Book* ub,class Reader * ur,QWidget *parent = 0);
    ~SearchDialog();
    int isearch;
    int *sbooktotal;

private slots:
    void on_existpushButton_clicked();

    void on_searchpushButton_clicked();

    void on_bopushButton_clicked();

    void on_respushButton_clicked();

signals:
    void sendsearchclosenotice();

private:
    Ui::SearchDialog *ui;
    QStandardItemModel *searchinfo_model;
    class Book* bp;
    class Reader* rp;
};

#endif // SEARCHDIALOG_H
