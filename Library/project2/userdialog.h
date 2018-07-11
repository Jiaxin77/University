#ifndef USERDIALOG_H
#define USERDIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "BOOKCLASS.h"
#include "READERCLASS.h"

namespace Ui {
class UserDialog;
}

class UserDialog : public QDialog
{
    Q_OBJECT

public:
    explicit UserDialog(class Book* lp,class Reader* lr,QWidget *parent = 0);
    ~UserDialog();
    void OutputReader();
    int iuser;
    int *ubooktotal;
    int *ureadertotal;

signals:
    void sendcloseuser();

private slots:
    void on_existpushButton_clicked();

    void on_returnpushButton_clicked();

    void on_losepushButton_clicked();

    void on_rankpushButton_clicked();

    void on_noticepushButton_clicked();

    void on_searchpushButton_clicked();

    void on_cancelrepushButton_clicked();

 public slots:
     void OutputReaderslot();

private:
    Ui::UserDialog *ui;
    QStandardItemModel *readerinfo_model ;
    class Book* bp;
    class Reader* rp;

};

#endif // USERDIALOG_H
