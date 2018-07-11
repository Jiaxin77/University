#ifndef NOTICEDIALOG_H
#define NOTICEDIALOG_H

#include <QDialog>

namespace Ui {
class NoticeDialog;
}

class NoticeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NoticeDialog(long int readerid,QWidget *parent = 0);
    ~NoticeDialog();
    void OutputNotice();
    int inotice;

private slots:
    void on_pushButton_clicked();

private:
    Ui::NoticeDialog *ui;
    long int RID;
};

#endif // NOTICEDIALOG_H
