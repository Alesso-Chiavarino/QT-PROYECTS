#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QGroupBox>
#include <QLabel>
#include <QTimer>
#include <QPushButton>

class Window : public QWidget {
    Q_OBJECT
public:
    Window(QWidget *parent = nullptr);
    ~Window();

private slots:
    void actualizarParametros();

private:
    void setupUI();
    void moverBola();

    QGroupBox *groupBox;
    QLabel *bolaLabel;
    QPushButton *updateButton;
    QTimer *timer;

    int diametroBola;
    int velocidad;
    int xBola;
    int direccion;
};

#endif // WINDOW_H
