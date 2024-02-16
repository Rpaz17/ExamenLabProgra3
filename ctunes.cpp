#include "ctunes.h"
#include <QTextStream>
#include <QDebug>
#include "invalidrateexception.h"
#include "genero.h"
#include "managerarch.h"
#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include <QString>

QFile song("songs.itn");
QFile downloads("downloads.itn");
QFile codes("codes.itn");

QDataStream canc(&song);
QDataStream desc(&downloads);
QDataStream cod(&codes);

ctunes::ctunes()
{
    codes.open(QIODevice::ReadWrite);
    if(codes.size() == 0)
    {
        cod<<1<<1;
    }
    song.open(QIODevice::ReadWrite);
    downloads.open(QIODevice::ReadWrite);

    if (!codes.isOpen()){
        qDebug() <<"No se abrio el archivo de codigos";
    }else if(!song.isOpen()){
        qDebug() <<"No fue posible abrir el archivo de canciones";
    }else if(!downloads.isOpen()){
        qDebug() <<"No fue posible abrir el archivo de descargas";
    }
}

long ctunes::getCodigo(long offset)
{
    codes.seek(offset);
    int codigoAct;
    cod>>codigoAct;
    int next=codigoAct;
    codigoAct+=1;
    codes.seek(offset);
    cod<<codigoAct;
    return next;
}

void ctunes::addSong(QString nombre, QString cantante, Genero generoCantante, double precio)
{
    songsArch structFormato;
    int nuevo = getCodigo(0);
    structFormato.codigo=nuevo;
    structFormato.cancion=nombre;
    structFormato.cantante=cantante;

    QString generoString;
    switch (generoCantante) {
    case POP:
        generoString = "pop";
        break;
    case ROCK:
        generoString = "rock";
        break;
    case DANCE:
        generoString = "dance";
    case RAP:
        generoString = "rap";
    case REGGAE:
        generoString = "reggae";
    case ELECTRONICA:
        generoString = "electronica";
    case RANCHERA:
        generoString = "ranchera";
    default:
        generoString = "Desconocido";

        structFormato.genero=generoString;
        structFormato.precio=precio;
        structFormato.estrellas=0;
        structFormato.reviews=0;
        song.seek(song.size());
        canc<<structFormato.codigo<<structFormato.cancion<<structFormato.cantante<<structFormato.genero<<structFormato.precio
           <<structFormato.estrellas<<structFormato.reviews;
        song.flush();

    }
}

void ctunes::reviewSong(int codigo, int estrellas)
{
    song.seek(0);
    while(!song.atEnd()){
        long pos = song.pos();
        int code;
        QString nombre;
        QString cantante;
        QString genero;
        double precio;
        int stars;
        int rev;

        canc>>code>>nombre>>cantante>>genero>>precio>>stars>>rev;
        QMessageBox::information(nullptr, "Message", "Diste el review correctamente");
        return;
    }
    QMessageBox::warning(nullptr,"ADVERTENCIA", "No se pudo hacer el review");

}

void ctunes::downloadSong(int codigoC, QString cliente)
{

}

QString ctunes::songs(QString txtFile)
{
    QFile archivo(txtFile+".txt");
    archivo.open(QIODevice::ReadWrite);
    QTextStream write(&archivo);
    ctunes::songsArch s;
    song.seek(0);
    QString mensaje;
    while(!song.atEnd()){
        canc>>s.codigo>>s.cancion>>s.cantante>>s.genero>>s.precio>>s.estrellas>>s.reviews;
        double est = static_cast<double>(s.estrellas);
        double rev = static_cast<double>(s.reviews);
        double rate = est/rev;

        qDebug()<<QString::number(rate,'s',1);
        write<<QString::number(s.codigo)+"-"<<s.cancion+"-"<<s.cantante+"-"<<QString::number(s.precio)+"-"<<QString::number(rate,'s',1)+" \n";
        mensaje+="\n --Codigo: "+QString::number(s.codigo)+" -- Cancion: "+s.cancion+" -- Cantante: "+s.cantante+" --Precio: "+QString::number(s.precio)+
                " --Rate: "+QString::number(rate,'s',1);
    }
}

void ctunes::infoSong(int codigoCancion)
{

}

Genero ctunes::stringToGenero(const QString &generoStr)
{
    if (generoStr == "pop") {
        return POP;
    } else if (generoStr == "rock") {
        return ROCK;
    } else if (generoStr == "rap") {
        return RAP;
    } else if (generoStr == "dance") {
        return DANCE;
    } else if (generoStr == "reggae") {
        return REGGAE;
    } else if (generoStr == "electronica") {
        return ELECTRONICA;
    } else if (generoStr == "ranchera") {
        return RANCHERA;
    } else {
        throw std::invalid_argument("Género desconocido: " + generoStr.toStdString());
    }
}
