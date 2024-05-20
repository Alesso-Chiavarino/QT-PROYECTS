#include "boton.h"

Boton::Boton(QWidget *parent)
    : QPushButton(parent)
{
    connect(this, &QPushButton::clicked, this, &Boton::onBotonClicked);
}

void Boton::setNombre(const QString &nombre)
{
    this->nombre = nombre;
    setText(nombre);
}

void Boton::onBotonClicked()
{
    emit clicked();
}
