#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class VentanaPrincipal : public QWidget {
    Q_OBJECT
public:
    VentanaPrincipal() {
        setWindowTitle("Ventana Principal");
        setGeometry(100, 100, 400, 300);

        QVBoxLayout *layout = new QVBoxLayout(this);

        textEdit = new QTextEdit(this);
        layout->addWidget(textEdit);

        urlLineEdit = new QLineEdit(this);
        connect(urlLineEdit, &QLineEdit::returnPressed, this, &VentanaPrincipal::cargarHTML);
        layout->addWidget(urlLineEdit);

        setLayout(layout);
    }

private slots:
    void cargarHTML() {
        QString url = urlLineEdit->text();
        if (!url.startsWith("http://") && !url.startsWith("https://")) {
            url = "http://" + url;
        }

        QNetworkAccessManager *manager = new QNetworkAccessManager(this);
        connect(manager, &QNetworkAccessManager::finished, this, &VentanaPrincipal::respuestaRecibida);
        manager->get(QNetworkRequest(QUrl(url)));
    }

    void respuestaRecibida(QNetworkReply *reply) {
        if (reply->error() == QNetworkReply::NoError) {
            QString html = QString(reply->readAll());
            textEdit->setHtml(html);
        } else {
            textEdit->setPlainText("Error al cargar la página");
        }

        reply->deleteLater();
    }

private:
    QTextEdit *textEdit;
    QLineEdit *urlLineEdit;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    VentanaPrincipal ventana;
    ventana.show();

    return app.exec();
}

#include "main.moc"
