#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>

class AdminDB {
private:
    static AdminDB *instancia;
    QSqlDatabase db;
    AdminDB();
public:
    static AdminDB *getInstancia();
    QSqlQuery execQuery(const QString &queryStr);
};

#endif // ADMINDB_H
