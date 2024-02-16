#include "cframe.h"
#include "ui_cframe.h"
#include <QString>
#include <QDebug>
#include "invalidrateexception.h"
#include "ctunes.h"
#include "genero.h"
#include <QMessageBox>

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
    ctunes Ctunes;
    QString code = ui->codigo->text();
    QString estrella = ui->estrellas->text();

    bool esNumero;
    bool esNumero2;

    code.toDouble(&esNumero);
    estrella.toInt(&esNumero2);

    if(!esNumero && !esNumero2){
        QMessageBox::warning(nullptr,"ADVERTENCIA", "Ingrese un numero valido");
        ui->codigo->clear();
        ui->estrellas->clear();
    }else if(!esNumero && esNumero2){
        QMessageBox::warning(nullptr,"ADVERTENCIA", "Ingrese un numero valido");
        ui->codigo->clear();
    }else if(esNumero && !esNumero2){
        QMessageBox::warning(nullptr,"ADVERTENCIA", "Ingrese un numero valido");
        ui->estrellas->clear();
    }else{
        int cod=ui->codigo->text().toInt();
        int est=ui->estrellas->text().toInt();

        if(est<0 || est>5){
            QMessageBox::warning(nullptr,"ADVERTENCIA", "Ingrese un numero valido (De 0 a 5)");
            ui->estrellas->clear();
        }else{
           Ctunes.reviewSong(cod,est);
           QMessageBox::information(nullptr, "YOU DID IT", "Se dio el review correctamente");
        }
    }
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
    ctunes Ctunes;
    QString nombre = ui->nombreC->text();
    QString cantante = ui->cantante->text();
    Genero genero = Ctunes.stringToGenero(ui->genero->text());
    double precio = ui->precio->text().toDouble();

    Ctunes.addSong(nombre, cantante, genero, precio);
    QMessageBox::information(nullptr, "YOU DID IT", "La cancion se anadida correctamente");
}


void cframe::on_pushButton_7_clicked()
{
    ctunes Ctunes;
    QString text=Ctunes.songs(ui->lineEdit->text());

    ui->textBrowser->setText(text);
}

