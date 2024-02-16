#ifndef CTUNES_H
#define CTUNES_H
#include "invalidrateexception.h"
#include <QString>
#include <QFile>
#include <QDate>

class ctunes
{
public:
    ctunes();
    long getCodigo(long offset);
    void addSong(QString nombre, QString cantante, Genero generoCantante, double precio);
    void reviewSong(int codigo, int estrellas);
    void downloadSong(int codigoC, QString cliente);
    QString songs(QString txtFile);
    void infoSong(int codigoCancion);
    Genero stringToGenero(const QString& generoStr);

    struct songsArch{
        int codigo;
        QString cancion;
        QString cantante;
        QString genero;
        double precio;
        int estrellas;
        int reviews;
    };

    struct downloadArch{
        int codigoDes;
        QDate dia;
        int codigoCan;
        QString cliente;
        double precioCan;
    };

private:
    long sigCancionC;
    long sigDownload;
    QString generoToString(Genero genero) const {
            switch (genero) {
                case POP:
                    return "Pop";
                case ROCK:
                    return "Rock";
                case RAP:
                    return "Rap";
                case DANCE:
                    return "Dance";
                case REGGAE:
                    return "Reggae";
                case ELECTRONICA:
                    return "Electrónica";
                case RANCHERA:
                    return "Ranchera";
                default:
                    return "Desconocido";
            }
        }
};

#endif // CTUNES_H
