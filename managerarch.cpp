#include "managerarch.h"
#include "invalidrateexception.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
managerArch::managerArch()
{

}

void managerArch::createCodigos()
{
    QFile archivo("codigos.itn");
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
           QTextStream out(&archivo);
           out << "0\n"; // Código disponible para una nueva canción
           out << "0\n"; // Código disponible para un nuevo download
           archivo.close();
           qDebug() << "Archivo 'codigos.itn' creado exitosamente.";
       } else {
           qWarning() << "Error al abrir el archivo 'codigos.itn'.";
       }
}

void managerArch::createSongs()
{
    QFile archivo("songs.itn");
    if(archivo.open(QIODevice::WriteOnly | QIODevice::Text)){
        QTextStream out(&archivo);
                out << "1234\n"; // Código de la canción
                out << "Mi Canción\n"; // Nombre de la canción
                out << "Artista\n"; // Nombre del cantante
                out << "Pop\n"; // Género
                out << "1.99\n"; // Precio para download
                out << "10\n"; // Suma total de estrellas
                out << "3\n"; // Cantidad de reviews
                archivo.close();
                qDebug() << "Archivo 'songs.itn' creado exitosamente.";
            } else {
                qWarning() << "Error al abrir el archivo 'songs.itn'.";
    }
}

void managerArch::createDownloads()
{
    QFile archivo("downloads.itn");
    if (archivo.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&archivo);
            out << "9876\n"; // Código del download
            out << "2024-02-15\n"; // Fecha de descarga
            out << "1234\n"; // Código de la canción descargada
            out << "Usuario1\n"; // Nombre del cliente
            out << "1.99\n"; // Precio de la canción descargada
            archivo.close();
            qDebug() << "Archivo 'downloads.itn' creado exitosamente.";
        } else {
            qWarning() << "Error al abrir el archivo 'downloads.itn'.";
        }
}
