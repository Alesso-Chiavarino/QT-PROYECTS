#include <QApplication>
#include "login.h"
#include "formulario.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    Login login;
    Formulario formulario;

    QObject::connect(&login, &Login::loginExitoso, [&]() {
        login.hide();
        formulario.show();
    });

    QObject::connect(&formulario, &Formulario::datosGuardados, [&](const QString& legajo, const QString& nombre, const QString& apellido) {
        qDebug() << "Legajo:" << legajo << "Nombre:" << nombre << "Apellido:" << apellido;
    });

    login.show();

    return a.exec();
}
