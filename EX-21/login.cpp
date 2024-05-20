#include "login.h"

Login::Login(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);

    usernameLabel = new QLabel("Username:");
    layout->addWidget(usernameLabel);

    usernameLineEdit = new QLineEdit;
    layout->addWidget(usernameLineEdit);

    passwordLabel = new QLabel("Password:");
    layout->addWidget(passwordLabel);

    passwordLineEdit = new QLineEdit;
    passwordLineEdit->setEchoMode(QLineEdit::Password);
    layout->addWidget(passwordLineEdit);

    loginButton = new QPushButton("Login");
    layout->addWidget(loginButton);

    connect(loginButton, &QPushButton::clicked, this, &Login::onLoginButtonClicked);

    databaseManager = new DatabaseManager; // Inicializamos DatabaseManager
}

Login::~Login()
{
    delete layout;
    delete databaseManager; // Liberamos la memoria asignada a DatabaseManager
}

void Login::onLoginButtonClicked()
{
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    // Lógica de autenticación con la base de datos
    if (databaseManager->authenticate(username, password))
    {
        // Acceso concedido
        QMessageBox::information(this, "Success", "Login successful.");
    }
    else
    {
        // Acceso denegado
        QMessageBox::warning(this, "Error", "Invalid username or password.");
    }
}
