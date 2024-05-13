#ifndef ADMINDB_H
#define ADMINDB_H

#include <QObject>

class AdminDB : public QObject
{
    Q_OBJECT
public:
    explicit AdminDB(QObject *parent = nullptr);

    void test();
};

#endif // ADMINDB_H
