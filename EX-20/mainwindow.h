#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "boton.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onBotonAzulClicked();
    void onBotonVerdeClicked();
    void onBotonMagentaClicked();

private:
    Ui::MainWindow *ui;
    Boton *botonAzul;
    Boton *botonVerde;
    Boton *botonMagenta;
};
#endif // MAINWINDOW_H
