#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H
#include <qtimer.h>
#include <QTime>
#include <QDialog>
#include <QString>
#include "logon.h"
#include "BOOKCLASS.h"
#include "READERCLASS.h"
#include "ADMCLASS.h"
using namespace std;

namespace Ui {
class DigitalClock;
}

class DigitalClock : public QDialog
{
    Q_OBJECT

public:
    explicit DigitalClock(class Book* mb,class Reader* mr,class Administration* ma,int *booktotal,int *readertotal,PubCodeList *pl,AuCodeList *al,QWidget *parent = 0);
    ~DigitalClock();
    void timestart();


private:
    Ui::DigitalClock *ui;
    QTimer *timer;
    class log * dlg;
    class Book *bp;
    class Reader *rp;
    class Administration *ap;
    PubCodeList *dpl;
    AuCodeList *dal;

    int * Booktotal;
    int * Readertotal;

public slots:
    void showTime();//显示时间
    void showChild();//显示登录界面
    void starttime();//开启计时器

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // DIGITALCLOCK_H
