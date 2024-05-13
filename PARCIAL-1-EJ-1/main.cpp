#include <QApplication>
#include "acceso.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Acceso w;
    w.show();

    QObject::connect(&w, &Acceso::closeApp, &a, &QApplication::quit);

    return a.exec();
}
