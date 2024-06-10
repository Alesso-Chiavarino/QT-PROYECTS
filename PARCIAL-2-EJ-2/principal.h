#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QWidget>
#include <QPushButton>
#include <QTableWidget>
#include <QVector>
#include "rectangulo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QWidget
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void cargarRectangulos();

private:
    Ui::Principal *ui;
    QPushButton *cargarButton;
    QTableWidget *tableWidget;
    QVector<Rectangulo> rectangulos;
};

#endif // PRINCIPAL_H
