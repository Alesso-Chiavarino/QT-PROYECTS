// descargador.h
#ifndef DESCARGADOR_H
#define DESCARGADOR_H

#include <QWidget>
#include <QImage>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QProgressBar>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QPalette>

class Descargador : public QWidget
{
    Q_OBJECT
public:
    explicit Descargador(QWidget *parent = nullptr);

signals:
    void descargaCompletada(const QImage& imagen);
    void progresoDescarga(int progreso);

private slots:
    void iniciarDescarga();
    void onDescargaProgreso(qint64 bytesRecibidos, qint64 bytesTotales);
    void onDescargaFinalizada(QNetworkReply *reply); // Modificado para incluir un parámetro

private:
    QLineEdit *urlLineEdit;
    QPushButton *descargarButton;
    QProgressBar *progresoBar;
    QNetworkAccessManager *networkManager;
    QNetworkReply *reply;
    QByteArray imagenData;

    void mostrarImagen(const QImage& imagen);

protected:
    void paintEvent(QPaintEvent *event) override; // Se añade override
};

#endif // DESCARGADOR_H
