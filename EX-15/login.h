#ifndef LOGIN_H
#define LOGIN_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QKeyEvent>

class Login : public QWidget {
    Q_OBJECT
public:
    explicit Login(QWidget *parent = nullptr);

signals:
    void loginExitoso();
    void mostrarFormulario();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void verificarCredenciales();

private:
    QLineEdit *lineEditClave;
};

#endif // LOGIN_H
