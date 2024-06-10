#include "AdminDB.h"

AdminDB::AdminDB(QObject *parent) : QObject(parent)
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("usuarios.db");

    if (!db.open()) {
        qDebug() << "Error: Failed to connect to the database";
    } else {
        qDebug() << "Database connected successfully";

        QSqlQuery query;
        query.exec("CREATE TABLE IF NOT EXISTS usuarios ("
                   "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                   "nombreUsuario TEXT NOT NULL, "
                   "contrasena TEXT NOT NULL)");
    }
}

AdminDB& AdminDB::instance()
{
    static AdminDB instance;
    return instance;
}

bool AdminDB::createUser(const QString& username, const QString& password)
{
    QSqlQuery query;
    query.prepare("INSERT INTO usuarios (nombreUsuario, contrasena) VALUES (:nombreUsuario, :contrasena)");
    query.bindValue(":nombreUsuario", username);
    query.bindValue(":contrasena", password);
    return query.exec();
}

bool AdminDB::authenticateUser(const QString& username, const QString& password)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM usuarios WHERE nombreUsuario = :nombreUsuario AND contrasena = :contrasena");
    query.bindValue(":nombreUsuario", username);
    query.bindValue(":contrasena", password);
    query.exec();
    return query.next();
}

QSqlQuery AdminDB::getAllUsers()
{
    QSqlQuery query;
    query.exec("SELECT * FROM usuarios");
    return query;
}
