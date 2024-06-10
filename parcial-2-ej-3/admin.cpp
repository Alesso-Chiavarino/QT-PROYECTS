#include "admin.h"

Admin::Admin(QObject *parent)
    : QObject(parent), login(new Login), ventana(new Ventana) {
    connect(login, SIGNAL(signal_usuarioValidado()), this, SLOT(slot_usuarioValidado()));
    login->show();
}

void Admin::slot_usuarioValidado() {
    login->hide();
    ventana->show();
}
