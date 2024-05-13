#include <QApplication>
#include "pintura.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Pintura pintura;
    pintura.setWindowTitle("Pintura");
    pintura.setGeometry(100, 100, 800, 600);
    pintura.show();

    return app.exec();
}
