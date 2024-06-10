#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>
#include "login.h"
#include "ventana.h"

class Admin : public QObject {
    Q_OBJECT

public:
    explicit Admin(QObject *parent = nullptr);

private slots:
    void slot_usuarioValidado();

private:
    Login *login;
    Ventana *ventana;
};

#endif // ADMIN_H
