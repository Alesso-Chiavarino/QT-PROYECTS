#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class AdminDB : public QObject
{
    Q_OBJECT

public:
    static AdminDB& instance();
    bool createUser(const QString& username, const QString& password);
    bool authenticateUser(const QString& username, const QString& password);
    QSqlQuery getAllUsers();

private:
    explicit AdminDB(QObject *parent = nullptr);
    AdminDB(const AdminDB&) = delete;
    AdminDB& operator=(const AdminDB&) = delete;

    QSqlDatabase db;
};

#endif // ADMINDB_H
