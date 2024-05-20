#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox> // Se añade para el uso de QMessageBox

#include "databasemanager.h"

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void onLoginButtonClicked();

private:
    QPushButton *loginButton;
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QLabel *usernameLabel;
    QLabel *passwordLabel;
    QVBoxLayout *layout;
    DatabaseManager *databaseManager; // Agregamos un puntero a DatabaseManager
};

#endif // LOGIN_H
