#include "formulario.h"

Formulario::Formulario(QWidget *parent) : QWidget(parent) {
    QLabel *labelLegajo = new QLabel("Legajo:");
    lineEditLegajo = new QLineEdit();

    QLabel *labelNombre = new QLabel("Nombre:");
    lineEditNombre = new QLineEdit();

    QLabel *labelApellido = new QLabel("Apellido:");
    lineEditApellido = new QLineEdit();

    QPushButton *buttonGuardar = new QPushButton("Guardar");

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(labelLegajo, 0, 0);
    layout->addWidget(lineEditLegajo, 0, 1);
    layout->addWidget(labelNombre, 1, 0);
    layout->addWidget(lineEditNombre, 1, 1);
    layout->addWidget(labelApellido, 2, 0);
    layout->addWidget(lineEditApellido, 2, 1);
    layout->addWidget(buttonGuardar, 3, 1);

    setLayout(layout);

    connect(buttonGuardar, &QPushButton::clicked, this, &Formulario::guardarDatos);
}

void Formulario::guardarDatos() {
    QString legajo = lineEditLegajo->text();
    QString nombre = lineEditNombre->text();
    QString apellido = lineEditApellido->text();

    emit datosGuardados(legajo, nombre, apellido);
}
