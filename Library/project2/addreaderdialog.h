#ifndef ADDREADERDIALOG_H
#define ADDREADERDIALOG_H

#include <QDialog>
#include "READERCLASS.h"
#include "ADMCLASS.h"

namespace Ui {
class AddReaderDialog;
}

class AddReaderDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddReaderDialog(class Reader* ar,class Administration* aa,QWidget *parent = 0);
    ~AddReaderDialog();
    int *arreadertotal;

private slots:
    void on_exitpushButton_clicked();

    void on_okpushButton_clicked();

private:
    Ui::AddReaderDialog *ui;
    class Reader* rp;
    class Administration* ap;
};

#endif // ADDREADERDIALOG_H
