#ifndef RANKDIALOG_H
#define RANKDIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include "BOOKCLASS.h"

namespace Ui {
class RankDialog;
}

class RankDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RankDialog(class Book* ub,QWidget *parent = 0);
    ~RankDialog();
    void OutputRank();
    int *rbooktotal;


private slots:
    void on_pushButton_clicked();

private:
    Ui::RankDialog *ui;
    QStandardItemModel *rankinfo_model ;
    class Book *bp;

};

#endif // RANKDIALOG_H
