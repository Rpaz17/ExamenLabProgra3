#include "cframe.h"
#include "ui_cframe.h"
#include <QString>
#include <QDebug>
#include "invalidrateexception.h"
#include "ctunes.h"
#include "genero.h"

cframe::cframe(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::cframe)
{
    ui->setupUi(this);
}

cframe::~cframe()
{
    delete ui;
}


void cframe::on_Add_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void cframe::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void cframe::on_Review_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}


void cframe::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void cframe::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void cframe::on_Download_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void cframe::on_Songs_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}


void cframe::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void cframe::on_InfoSongs_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}


void cframe::on_pushButton_6_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void cframe::on_backA_clicked()
{
    ui->cantante->setText("");
    ui->nombreC->setText("");
    ui->genero->setText("");
    ui->precio->setText("");
    ui->stackedWidget->setCurrentIndex(0);
}


void cframe::on_AddButton_clicked()
{
    QString nombre = ui->nombreC->text();
    QString cantante = ui->cantante->text();
    Genero genero = Ctunes.stringToGenero(ui->genero->text());
    double precio = ui->precio->text().toDouble();

    try {
        Ctunes.addSong(nombre, cantante, genero, precio);
    }  catch (const InvalidRateException& e) {
        QString errorMessage = "Error: " + QString::fromUtf8(e.what());
        qDebug() << errorMessage;
    }
}

