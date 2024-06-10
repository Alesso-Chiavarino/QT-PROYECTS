#include "principal.h"
#include "ui_principal.h"
#include "admindb.h"
#include <QVBoxLayout>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QPainter>  // Añadir esta línea

Principal::Principal(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    setFixedSize(300, 300);

    cargarButton = findChild<QPushButton*>("cargarButton");
    tableWidget = findChild<QTableWidget*>("tableWidget");
    tableWidget->setColumnCount(4);
    tableWidget->setHorizontalHeaderLabels(QStringList() << "X" << "Y" << "Ancho" << "Alto");

    connect(cargarButton, &QPushButton::clicked, this, &Principal::cargarRectangulos);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::cargarRectangulos() {
    rectangulos.clear();
    tableWidget->setRowCount(0);

    QSqlQuery query = AdminDB::getInstancia()->execQuery("SELECT * FROM rectangulos");
    int row = 0;
    while (query.next()) {
        int x = query.value("x").toInt();
        int y = query.value("y").toInt();
        int ancho = query.value("ancho").toInt();
        int alto = query.value("alto").toInt();
        rectangulos.append(Rectangulo(x, y, ancho, alto));

        tableWidget->insertRow(row);
        tableWidget->setItem(row, 0, new QTableWidgetItem(QString::number(x)));
        tableWidget->setItem(row, 1, new QTableWidgetItem(QString::number(y)));
        tableWidget->setItem(row, 2, new QTableWidgetItem(QString::number(ancho)));
        tableWidget->setItem(row, 3, new QTableWidgetItem(QString::number(alto)));
        row++;
    }
    update();
}

void Principal::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    for (const auto &rect : rectangulos) {
        painter.drawRect(rect.getX(), rect.getY(), rect.getAncho(), rect.getAlto());
    }
    QWidget::paintEvent(event);
}
