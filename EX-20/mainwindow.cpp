#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), parser(new HTMLParser(this))
{
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *urlLayout = new QHBoxLayout();
    QLabel *urlLabel = new QLabel("Website URL:", this);
    urlLineEdit = new QLineEdit(this);
    fetchButton = new QPushButton("Fetch Resources", this);
    urlLayout->addWidget(urlLabel);
    urlLayout->addWidget(urlLineEdit);
    urlLayout->addWidget(fetchButton);

    imageSelectButton = new QPushButton("Select Image", this);

    downloadButton = new QPushButton("Download Resources", this);

    mainLayout->addLayout(urlLayout);
    mainLayout->addWidget(imageSelectButton);
    mainLayout->addWidget(downloadButton);

    setCentralWidget(centralWidget);

    connect(fetchButton, &QPushButton::clicked, this, &MainWindow::onFetchButtonClicked);
    connect(parser, &HTMLParser::urlsExtracted, this, &MainWindow::onUrlsExtracted);
    connect(imageSelectButton, &QPushButton::clicked, this, &MainWindow::onImageSelectButtonClicked);
    connect(downloadButton, &QPushButton::clicked, this, &MainWindow::onDownloadButtonClicked);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onFetchButtonClicked()
{
    QString urlString = urlLineEdit->text();
    QUrl url(urlString);
    QNetworkRequest request(url);

    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply = manager->get(request);

    connect(reply, &QNetworkReply::finished, [=]() {
        if (reply->error() == QNetworkReply::NoError) {
            QByteArray data = reply->readAll();
            parser->parseHtml(QString(data));
        } else {
            qDebug() << "Error fetching HTML:" << reply->errorString();
        }
        reply->deleteLater();
        manager->deleteLater();
    });
}

void MainWindow::onDownloadButtonClicked()
{
    // Solicitar al usuario que seleccione un directorio si saveDir está vacío
    if (saveDir.isEmpty()) {
        saveDir = QFileDialog::getExistingDirectory(this, "Select Directory to Save Resources", QDir::homePath());
        if (saveDir.isEmpty()) {
            qDebug() << "No directory selected. Aborting download.";
            return;
        }
    }

    // Iterar sobre las URLs de recursos y descargar cada recurso en el directorio seleccionado
    for (const QUrl &url : resourceUrls) {
        if (!url.isValid()) {
            qDebug() << "Invalid URL:" << url.toString();
            continue;
        }

        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        QNetworkRequest request(url);
        QNetworkReply *reply = manager->get(request);

        connect(reply, &QNetworkReply::finished, [=]() {
            if (reply->error() == QNetworkReply::NoError) {
                QByteArray data = reply->readAll();
                QString fileName = url.fileName();
                QString filePath = saveDir + QDir::separator() + fileName;

                QFile file(filePath);
                if (file.open(QIODevice::WriteOnly)) {
                    file.write(data);
                    file.close();
                    qDebug() << "Resource downloaded:" << filePath;
                } else {
                    qDebug() << "Error saving resource:" << file.errorString();
                }
            } else {
                qDebug() << "Error downloading resource:" << reply->errorString();
            }
            reply->deleteLater();
            manager->deleteLater();
        });
    }
}

void MainWindow::onImageSelectButtonClicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Select Image", QString(), "Images (*.png *.jpg *.bmp)");
    if (!fileName.isEmpty()) {
        selectedImage.load(fileName);
        update();
    }
}

void MainWindow::onUrlsExtracted(const QList<QUrl> &urls)
{
    resourceUrls = urls;
    for (const QUrl &url : urls) {
        qDebug() << "Resource URL:" << url;
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QMainWindow::paintEvent(event);

    if (!selectedImage.isNull()) {
        QPainter painter(this);
        painter.drawPixmap(10, 50, selectedImage);
    }
}
