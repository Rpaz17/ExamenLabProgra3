#ifndef CFRAME_H
#define CFRAME_H
#include "ctunes.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class cframe; }
QT_END_NAMESPACE

class cframe : public QMainWindow
{
    Q_OBJECT

public:
    cframe(QWidget *parent = nullptr);
    ~cframe();

private slots:
    void on_Add_clicked();

    void on_pushButton_clicked();

    void on_Review_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_Download_clicked();

    void on_Songs_clicked();

    void on_pushButton_5_clicked();

    void on_InfoSongs_clicked();

    void on_pushButton_6_clicked();

    void on_backA_clicked();

    void on_AddButton_clicked();
    void on_pushButton_7_clicked();

private:
    Ui::cframe *ui;
};
#endif // CFRAME_H
