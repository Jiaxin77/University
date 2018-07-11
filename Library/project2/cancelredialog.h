#ifndef CANCELREDIALOG_H
#define CANCELREDIALOG_H

#include <QDialog>
#include "BOOKCLASS.h"
#include "READERCLASS.h"

namespace Ui {
class CancelReDialog;
}

class CancelReDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CancelReDialog(class Book* ub,class Reader* ur,QWidget *parent = 0);
    ~CancelReDialog();
    int icancel;
    int *cbooktotal;

private slots:
    void on_exitpushButton_clicked();

    void on_okpushButton_clicked();

private:
    Ui::CancelReDialog *ui;
    class Book* bp;
    class Reader* rp;
};

#endif // CANCELREDIALOG_H
