#include "principal.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Especifica la ruta de tu archivo rectangles.sqlite aquí
    QString dbPath = "./rectangles.sqlite";

    // Iniciar la conexión a la base de datos
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    if (!db.open()) {
        qDebug() << "Error: No se puede conectar a la base de datos.";
        return -1;
    } else {
        qDebug() << "Conexion exitosa";
    }

    Principal w;
    w.show();
    return a.exec();
}
