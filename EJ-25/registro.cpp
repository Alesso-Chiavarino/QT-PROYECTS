#include "Registration.h"
#include "AdminDB.h"
#include <QVBoxLayout>
#include <QMessageBox>

Registration::Registration(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);

    usernameLineEdit = new QLineEdit(this);
    usernameLineEdit->setPlaceholderText("Username");

    passwordLineEdit = new QLineEdit(this);
    passwordLineEdit->setPlaceholderText("Password");
    passwordLineEdit->setEchoMode(QLineEdit::Password);

    registerButton = new QPushButton("Register", this);

    layout->addWidget(usernameLineEdit);
    layout->addWidget(passwordLineEdit);
    layout->addWidget(registerButton);

    // Connecting using the new signal-slot syntax
    connect(registerButton, &QPushButton::clicked, this, [=]() {
        handleRegistration();
    });
}

void Registration::handleRegistration()
{
    QString username = usernameLineEdit->text();
    QString password = passwordLineEdit->text();

    if (AdminDB::instance().createUser(username, password)) {
        QMessageBox::information(this, "Successful Registration", "User registered successfully");
        this->close();
    } else {
        QMessageBox::warning(this, "Registration Failed", "Failed to register user");
    }
}
