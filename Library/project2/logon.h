#ifndef LOG_H
#define LOG_H
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include "BOOKCLASS.h"
#include "READERCLASS.h"
#include "ADMCLASS.h"

namespace Ui {
class log;
}

class log : public QDialog
{
    Q_OBJECT

public:
    explicit log(class Book* mb,class Reader* mr,class Administration* ma,PubCodeList *pl,AuCodeList *al,QWidget *parent = 0);
    ~log();
    int ilog;
    int *lbooktotal;
    int *lreadertotal;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

signals:
    void sendclosenotice();

private:
    Ui::log *ui;
    class Book *bp;
    class Reader *rp;
    class Administration *ap;
    PubCodeList *lpl;
    AuCodeList *lal;

};

#endif // LOG_H
