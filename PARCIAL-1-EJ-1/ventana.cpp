#include "ventana.h"
#include <QVBoxLayout>

Ventana::Ventana(const QString& username, QWidget *parent)
    : QWidget(parent)
{
    label = new QLabel(this);
    label->setText("Hola " + username);
    label->setAlignment(Qt::AlignCenter);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(label);
    setLayout(layout);
}
