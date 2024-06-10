#include "admindb.h"

AdminDB *AdminDB::instancia = nullptr;

AdminDB::AdminDB() {
    db = QSqlDatabase::database();
}

AdminDB *AdminDB::getInstancia() {
    if (instancia == nullptr) {
        instancia = new AdminDB;
    }
    return instancia;
}

QSqlQuery AdminDB::execQuery(const QString &queryStr) {
    QSqlQuery query;
    if (db.isOpen()) {
        query.exec(queryStr);
    } else {
        qDebug() << "La base de datos no está abierta";
    }
    return query;
}
