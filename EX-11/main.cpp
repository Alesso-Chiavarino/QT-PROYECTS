#include <QCoreApplication>
#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Crear objetos de las clases QLabel, QWidget, QPushButton y QLineEdit
    QLabel label("Etiqueta");
    QWidget widget;
    QPushButton button("Botón");
    QLineEdit lineEdit;

    // Mostrar cada objeto llamando al método show()
    label.show();
    widget.show();
    button.show();
    lineEdit.show();

    return a.exec();
}
