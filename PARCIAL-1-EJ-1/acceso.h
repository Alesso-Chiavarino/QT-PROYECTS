#ifndef ACCESO_H
#define ACCESO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class Acceso : public QWidget
{
    Q_OBJECT

public:
    Acceso(QWidget *parent = nullptr);

signals:
    void loginSuccessful(const QString& username);
    void closeApp();

private slots:
    void login();
    void handleNetworkData(QNetworkReply *reply);

private:
    QLabel *backgroundLabel;
    QLineEdit *userEdit;
    QLineEdit *passEdit;
    QPushButton *loginButton;
    int loginAttempts;
    QNetworkAccessManager *manager;
};

#endif // ACCESO_H
