#ifndef BOTON_H
#define BOTON_H

#include <QPushButton>

class Boton : public QPushButton
{
    Q_OBJECT

public:
    Boton(QWidget *parent = nullptr);
    void setNombre(const QString &nombre);

signals:
    void clicked();

private slots:
    void onBotonClicked();

private:
    QString nombre;
};

#endif // BOTON_H
