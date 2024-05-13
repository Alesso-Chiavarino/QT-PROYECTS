#include "window.h"
#include <QVBoxLayout>
#include <QPixmap>

Window::Window(QWidget *parent) : QWidget(parent), diametroBola(50), velocidad(1000), xBola(0), direccion(1) {
    setupUI();
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Window::moverBola);
    timer->start(10); // Intervalo de actualización de la bola
}

Window::~Window() {
    delete timer;
}

void Window::setupUI() {
    QVBoxLayout *layout = new QVBoxLayout(this);

    groupBox = new QGroupBox("Configuración de la bola", this);
    QVBoxLayout *groupBoxLayout = new QVBoxLayout;

    bolaLabel = new QLabel(this);
   // QPixmap bolaPixmap(u"bola8.jpeg");

    QString imagePath = QCoreApplication::applicationDirPath() + "/test.png";

    QPixmap bolaPixmap(imagePath);

    //QPixmap bolaPixmap("./bola8.jpeg"); // Ruta a la imagen de la bola 8 (debes tener un archivo .png en tu proyecto)
    bolaPixmap = bolaPixmap.scaled(diametroBola, diametroBola);
    bolaLabel->setPixmap(bolaPixmap);

    groupBoxLayout->addWidget(bolaLabel);

    updateButton = new QPushButton("Actualizar Parámetros", this);
    connect(updateButton, &QPushButton::clicked, this, &Window::actualizarParametros);
    groupBoxLayout->addWidget(updateButton);

    groupBox->setLayout(groupBoxLayout);
    layout->addWidget(groupBox);

    setFixedSize(400, 200); // Tamaño de la ventana
}

void Window::actualizarParametros() {
    // Aquí puedes agregar lógica para actualizar los parámetros (diámetro y velocidad) de la bola
}

void Window::moverBola() {
    // Mover la bola de izquierda a derecha y viceversa
    xBola += direccion;
    if (xBola <= 0 || xBola >= width() - diametroBola) {
        direccion *= -1;
    }
    bolaLabel->move(xBola, height() / 2 - diametroBola / 2);
}
