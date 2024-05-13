#include "acceso.h"
#include "ventana.h"
#include <QVBoxLayout>
#include <QMessageBox>
#include <QBuffer>
#include <QDataStream>

Acceso::Acceso(QWidget *parent)
    : QWidget(parent), loginAttempts(0)
{
    // Crear widgets
    backgroundLabel = new QLabel(this);
    userEdit = new QLineEdit(this);
    passEdit = new QLineEdit(this);
    passEdit->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Ingresar", this);

    // Configurar el layout
    QVBoxLayout *layout = new QVBoxLayout(this);

    QHBoxLayout *userLayout = new QHBoxLayout;
    QLabel *userLabel = new QLabel("Usuario:", this);
    userLayout->addWidget(userLabel);
    userLayout->addWidget(userEdit);

    QHBoxLayout *passLayout = new QHBoxLayout;
    QLabel *passLabel = new QLabel("Clave:", this);
    passLayout->addWidget(passLabel);
    passLayout->addWidget(passEdit);

    layout->addLayout(userLayout);
    layout->addLayout(passLayout);
    layout->addWidget(loginButton);
    layout->setAlignment(Qt::AlignCenter);
    setLayout(layout);

    // Descargar la imagen
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(handleNetworkData(QNetworkReply*)));
    QUrl url("https://previews.123rf.com/images/alenalihacheva69/alenalihacheva691801/alenalihacheva69180100081/93063551-difuminar-bosque-de-invierno-congelado-con-%C3%A1rboles-nevados-paisaje-en-blanco-y-negro.jpg");
    manager->get(QNetworkRequest(url));

    // Conectar señales y slots
    connect(loginButton, SIGNAL(clicked()), this, SLOT(login()));
}

void Acceso::handleNetworkData(QNetworkReply *reply)
{
    if (reply->error()) {
        qDebug() << "Error al descargar la imagen:" << reply->errorString();
        return;
    }

    QByteArray imageData = reply->readAll();
    QBuffer buffer(&imageData);
    buffer.open(QIODevice::ReadOnly);

    // Crear un stream de datos para leer la imagen
    QDataStream dataStream(&buffer);
    dataStream.setVersion(QDataStream::Qt_5_15); // Establecer la versión adecuada

    // Crear un mapa de bits de la imagen desde los datos
    QImage image;
    dataStream >> image;

    if (image.isNull()) {
        qDebug() << "Error al cargar la imagen";
        return;
    }

    // Escalar la imagen al tamaño de la ventana
    image = image.scaled(this->size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);

    // Establecer la imagen como fondo de la ventana
    QPalette palette;
    palette.setBrush(this->backgroundRole(), QBrush(image));
    this->setPalette(palette);

    this->show();
}

void Acceso::login()
{
    QString username = userEdit->text();
    QString password = passEdit->text();

    if ((username == "admin" && password == "1234") || (username == "user" && password == "4321")) {
        emit loginSuccessful(username);
        hide();
        Ventana *ventana = new Ventana(username, this); // Creamos la ventana de bienvenida
        ventana->show();
    } else {
        passEdit->clear();
        QMessageBox::warning(this, "Error", "Usuario o contraseña incorrectos.");
        loginAttempts++;
        if (loginAttempts >= 3) {
            QMessageBox::critical(this, "Error", "Se han alcanzado 3 intentos fallidos. La aplicación se cerrará.");
            emit closeApp();
        }
    }
}
