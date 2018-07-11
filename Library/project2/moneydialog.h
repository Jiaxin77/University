#ifndef MONEYDIALOG_H
#define MONEYDIALOG_H

#include <QDialog>
#include "READERCLASS.h"
#include "ADMCLASS.h"

namespace Ui {
class MoneyDialog;
}

class MoneyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MoneyDialog(class Reader* oreader, class Administration* oa, QWidget *parent = 0);
    ~MoneyDialog();
    int imoney;
    int *mreadertotal;
signals:
    void sendMoneyclose();
private slots:
    void on_exitpushButton_clicked();

    void on_okpushButton_clicked();

private:
    Ui::MoneyDialog *ui;
    class Reader* rp;
    class Administration* ap;

};

#endif // MONEYDIALOG_H
