#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QLabel>

class Ventana : public QWidget
{
    Q_OBJECT

public:
    Ventana(const QString& username, QWidget *parent = nullptr);

private:
    QLabel *label;
};

#endif // VENTANA_H
