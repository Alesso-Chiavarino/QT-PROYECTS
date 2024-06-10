#include <QApplication>
#include "admin.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    bool connected = AdminDB::get_instance()->connect("base_poo.sqlite");
    if (!connected) {
        qDebug() << "Failed to connect to the database";
        return -1;
    }
    Admin admin;
    return a.exec();
}
