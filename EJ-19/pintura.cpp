#include "pintura.h"
#include <QPainter>
#include <QMouseEvent>

Pintura::Pintura(QWidget *parent)
    : QWidget(parent), drawing(false), brushSize(5), brushColor(Qt::black), lastPoint() {}

void Pintura::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(brushColor, brushSize, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    for (const QLineF &line : lines) {
        painter.drawLine(line);
    }
}

void Pintura::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        drawing = true;
    }
}

void Pintura::mouseMoveEvent(QMouseEvent *event) {
    if ((event->buttons() & Qt::LeftButton) && drawing) {
        lines.append(QLineF(lastPoint, event->pos()));
        lastPoint = event->pos();
        update();
    }
}

void Pintura::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        drawing = false;
    }
}

void Pintura::wheelEvent(QWheelEvent *event) {
    if (event->angleDelta().y() > 0) {
        brushSize += 1;
    } else {
        brushSize -= 1;
        if (brushSize < 1) {
            brushSize = 1;
        }
    }
}

void Pintura::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_R:
        brushColor = Qt::red;
        break;
    case Qt::Key_G:
        brushColor = Qt::green;
        break;
    case Qt::Key_B:
        brushColor = Qt::blue;
        break;
    case Qt::Key_Escape:
        clearCanvas();
        break;
    default:
        QWidget::keyPressEvent(event);
        return;
    }
    update();
}

void Pintura::clearCanvas() {
    lines.clear();
    update();
}
