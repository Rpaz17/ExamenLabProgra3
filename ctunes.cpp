#include "ctunes.h"
#include <QTextStream>
#include <QDebug>
#include "invalidrateexception.h"
#include "genero.h"
#include "managerarch.h"
#include <QFile>
#include <QDataStream>

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
    long codigo = getCodigo(0);
    QFile songsArch("songs.itn");
    if(songsArch.open(QIODevice::Append | QIODevice::Text)){
        QTextStream out(&songsArch);
        out << codigo << "\n"; // Código de la canción
        out << nombre << "\n"; // Nombre de la canción
        out << cantante << "\n"; // Nombre del cantante
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
        }
        out << generoString << "\n"; // Género
        out << precio << "\n"; // Precio para download
        out << "0\n"; // Suma total de estrellas (inicialmente 0)
        out << "0\n"; // Cantidad de reviews (inicialmente 0)
        songsArch.close();
        qDebug() << "Canción agregada exitosamente.";
    } else {
        qWarning() << "Error al abrir el archivo 'songs.itn'.";
    }
}

void ctunes::reviewSong(int codigo, int estrellas)
{
    bool existe = false;
    for(const auto&song: songs){

    }
}

void ctunes::downloadSong(int codigoC, QString cliente)
{

}

void ctunes::songs(QString txtFile)
{

}

void ctunes::infoSong(int codigoCancion)
{

}

Genero ctunes::stringToGenero(const QString &generoStr)
{
    if (generoStr == "rock") {
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
