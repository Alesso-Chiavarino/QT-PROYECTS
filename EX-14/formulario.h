#ifndef FORMULARIO_H
#define FORMULARIO_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QPushButton>

class Formulario : public QWidget {
    Q_OBJECT
public:
    explicit Formulario(QWidget *parent = nullptr);

signals:
    void datosGuardados(const QString& legajo, const QString& nombre, const QString& apellido);

private slots:
    void guardarDatos();

private:
    QLineEdit *lineEditLegajo, *lineEditNombre, *lineEditApellido;
};

#endif // FORMULARIO_H
