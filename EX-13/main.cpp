#include <QApplication>
#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // Creamos un QSlider y un QLabel
    QSlider slider(Qt::Horizontal);
    QLabel label;

    // Creamos un layout vertical y agregamos el slider y el label
    QVBoxLayout layout;
    layout.addWidget(&slider);
    layout.addWidget(&label);

    // Conectamos la señal valueChanged del slider con el slot setValue del label
    QObject::connect(&slider, &QSlider::valueChanged, &label, static_cast<void(QLabel::*)(int)>(&QLabel::setNum));

    // Creamos un widget y establecemos el layout
    QWidget window;
    window.setLayout(&layout);

    // Mostramos la ventana
    window.show();

    return a.exec();
}
