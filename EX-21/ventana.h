#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

class Ventana : public QWidget
{
    Q_OBJECT

public:
    explicit Ventana(QWidget *parent = nullptr);

signals:
    void backButtonClicked();

private slots:
    void goToLogin();
};

#endif // VENTANA_H
