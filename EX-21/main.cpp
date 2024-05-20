#include <QApplication>
#include "ventana.h"
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Ventana ventana;
    Login login;

    // Conectar la señal backButtonClicked de la Ventana con el slot show del Login
    QObject::connect(&ventana, &Ventana::backButtonClicked, &login, &Login::show);

    ventana.show();

    return a.exec();
}
