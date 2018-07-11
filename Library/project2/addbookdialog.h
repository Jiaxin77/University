#ifndef ADDBOOKDIALOG_H
#define ADDBOOKDIALOG_H

#include <QDialog>
#include "BOOKCLASS.h"
#include "ADMCLASS.h"

namespace Ui {
class AddBookDialog;
}

class AddBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddBookDialog(class Book* ab,class Administration* aa,PubCodeList *pl,AuCodeList *al,QWidget *parent = 0);
    ~AddBookDialog();
    int *abbooktotal;

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::AddBookDialog *ui;
    class Book* bp;
    class Administration* ap;
    PubCodeList *abpl;
    AuCodeList *abal;
};

#endif // ADDBOOKDIALOG_H
