#ifndef PINTURA_H
#define PINTURA_H

#include <QWidget>
#include <QMouseEvent>

class Pintura : public QWidget {
    Q_OBJECT

public:
    Pintura(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    bool drawing;
    int brushSize;
    QColor brushColor;
    QPoint lastPoint;
    QList<QLineF> lines; // Declaración de la lista de trazos

    void clearCanvas();
};

#endif // PINTURA_H
