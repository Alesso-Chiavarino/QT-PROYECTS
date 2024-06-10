#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

class Registration : public QWidget
{
    Q_OBJECT

public:
    explicit Registration(QWidget *parent = nullptr);

private slots:
    void handleRegistration();

private:
    QLineEdit *usernameLineEdit;
    QLineEdit *passwordLineEdit;
    QPushButton *registerButton;
};

#endif // REGISTRATION_H
