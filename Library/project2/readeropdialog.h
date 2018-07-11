#ifndef READEROPDIALOG_H
#define READEROPDIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "BOOKCLASS.h"
#include "READERCLASS.h"
#include "ADMCLASS.h"


namespace Ui {
class ReaderopDialog;
}

class ReaderopDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReaderopDialog(class Book* ab,class Reader* ar,class Administration* aa,QWidget *parent = 0);
    ~ReaderopDialog();
    void OutputReader();
    int *rebooktotal;
    int *rereadertotal;
public slots:
    void updatefine();
private slots:
    void on_exitpushButton_clicked();

    void on_searchpushButton_clicked();

    void on_delreaderpushButton_clicked();

    void on_moneypushButton_clicked();

private:
    Ui::ReaderopDialog *ui;
    int ireader;
    QStandardItemModel *sreaderinfo_model ;
    class Book* bp;
    class Reader* rp;
    class Administration* ap;
};

#endif // READEROPDIALOG_H
