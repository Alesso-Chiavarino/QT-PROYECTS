#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QFileDialog>
#include <QPainter>
#include "htmlparser.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *event) override;

private slots:
    void onFetchButtonClicked();
    void onDownloadButtonClicked();
    void onImageSelectButtonClicked();
    void onUrlsExtracted(const QList<QUrl> &urls);

private:
    QLineEdit *urlLineEdit;
    QPushButton *fetchButton;
    QPushButton *downloadButton;
    QPushButton *imageSelectButton;
    QPixmap selectedImage;
    HTMLParser *parser;
    QList<QUrl> resourceUrls;
    QString saveDir; // Variable para almacenar el directorio seleccionado
};

#endif // MAINWINDOW_H
