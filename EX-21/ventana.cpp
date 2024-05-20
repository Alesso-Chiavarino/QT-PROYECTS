#include "ventana.h"

Ventana::Ventana(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    // Crear el botón de volver
    QPushButton *backButton = new QPushButton("Volver al login");
    layout->addWidget(backButton);

    // Conectar la señal clicked del botón con el slot correspondiente
    connect(backButton, &QPushButton::clicked, this, &Ventana::goToLogin);
}

void Ventana::goToLogin()
{
    // Emitir la señal para indicar que se quiere volver al login
    emit backButtonClicked();
}
