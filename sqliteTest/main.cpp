
#include <QApplication>
#include <QDebug>
#include "adminDB.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    AdminDB admin;
    admin.test();

    return a.exec();
}
