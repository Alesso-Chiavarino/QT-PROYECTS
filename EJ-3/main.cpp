#include <QCoreApplication>
#include <iostream>
#include "version.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QString versionInfo = MiBiblioteca::getVersion();
    std::cout << versionInfo.toStdString() << std::endl;

    return a.exec();
}
