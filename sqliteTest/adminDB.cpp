#include "adminDB.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>

AdminDB::AdminDB(QObject *parent) : QObject(parent) {}

void AdminDB::test() {
    QSqlDatabase db = QSqlDatabase::database();
    if (!db.isOpen()) {
        qDebug() << "La base de datos no está abierta.";
    } else {
        QSqlQuery query(db);
        if (!query.exec("SELECT * FROM table")) {
            qDebug() << "Error al ejecutar la consulta:" << query.lastError().text();
        }
    }
}
