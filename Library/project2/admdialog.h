#ifndef ADMDIALOG_H
#define ADMDIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "BOOKCLASS.h"
#include "READERCLASS.h"
#include "ADMCLASS.h"

namespace Ui {
class AdmDialog;
}

class AdmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AdmDialog(class Book* lp,class Reader* lr,class Administration* la,PubCodeList *pl,AuCodeList *al,QWidget *parent = 0);
    ~AdmDialog();
    void OutputARank();
    int *abooktotal;
    int *areadertotal;

private slots:
    void on_exitpushButton_clicked();

    void on_readeroppushButton_clicked();

    void on_addreaderpushButton_clicked();

    void on_addbookpushButton_clicked();

    void on_delbookpushButton_clicked();

private:
    Ui::AdmDialog *ui;
    QStandardItemModel *arankinfo_model ;
    class Book* bp;
    class Reader* rp;
    class Administration* ap;
    PubCodeList *apl;
    AuCodeList *aal;
};

#endif // ADMDIALOG_H
