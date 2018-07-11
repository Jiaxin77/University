#ifndef DELBOOKDIALOG_H
#define DELBOOKDIALOG_H

#include <QDialog>
#include "BOOKCLASS.h"
#include "ADMCLASS.h"

namespace Ui {
class DelBookDialog;
}

class DelBookDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DelBookDialog(class Book* ab,class Administration* aa,QWidget *parent = 0);
    ~DelBookDialog();
    int *dbooktotal;

private slots:
    void on_exitpushButton_clicked();

    void on_okpushButton_clicked();

private:
    Ui::DelBookDialog *ui;
    class Book* bp;
    class Administration* ap;

};

#endif // DELBOOKDIALOG_H
