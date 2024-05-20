// databasemanager.cpp

#include "databasemanager.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

DatabaseManager::DatabaseManager()
{
    // Configurar la conexión a la base de datos
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("tu_base_de_datos.db"); // Reemplaza "tu_base_de_datos.db" con el nombre de tu base de datos SQLite

    // Intentar abrir la base de datos
    if (!db.open()) {
        // Manejar error de apertura de la base de datos
    }
}

bool DatabaseManager::isValidUser(const QString &username, const QString &password)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM usuarios WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);
    query.exec();

    if (query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false;
}
