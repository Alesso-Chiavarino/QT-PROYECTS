#ifndef ADMINDB_H
#define ADMINDB_H

#include <QSqlDatabase>
#include <QString>
#include <QObject>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStringList>
#include <QSqlError>
#include <QCryptographicHash>
#include <QVector>

class AdminDB : public QObject {
    Q_OBJECT

private:
    static AdminDB* instance;
    AdminDB();
    QSqlDatabase db;

public:
    static AdminDB* get_instance();

    bool connect(QString db_path);
    void close();
    QStringList validate_user(QString table, QString user, QString password);
    QStringList register_user(QString table, QString name, QString family_name, QString user, QString password);
    QVector<QStringList> select(QString query);
    bool insert(QString query);
};

#endif // ADMINDB_H
