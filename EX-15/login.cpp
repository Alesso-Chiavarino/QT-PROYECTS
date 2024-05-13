#include "login.h"

Login::Login(QWidget *parent) : QWidget(parent) {
    QLabel *labelUsuario = new QLabel("Usuario:");
    QLineEdit *lineEditUsuario = new QLineEdit();
    lineEditUsuario->setPlaceholderText("Ingrese su usuario");

    QLabel *labelClave = new QLabel("Clave:");
    lineEditClave = new QLineEdit();
    lineEditClave->setPlaceholderText("Ingrese su clave");
    lineEditClave->setEchoMode(QLineEdit::Password);

    QPushButton *buttonLogin = new QPushButton("Login");

    QGridLayout *layout = new QGridLayout();
    layout->addWidget(labelUsuario, 0, 0);
    layout->addWidget(lineEditUsuario, 0, 1);
    layout->addWidget(labelClave, 1, 0);
    layout->addWidget(lineEditClave, 1, 1);
    layout->addWidget(buttonLogin, 2, 1);

    setLayout(layout);

    connect(buttonLogin, &QPushButton::clicked, this, &Login::verificarCredenciales);
    connect(lineEditClave, &QLineEdit::returnPressed, this, &Login::verificarCredenciales);
}

void Login::keyPressEvent(QKeyEvent *event) {
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
        verificarCredenciales();
    }
}

void Login::verificarCredenciales() {
    QString clave = lineEditClave->text();
    if (clave == "admin:1111") {
        emit loginExitoso();
    } else {
        lineEditClave->clear();
    }
}
