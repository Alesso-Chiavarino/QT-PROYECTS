#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QPixmap>
#include <QMessageBox>
#include <QFile>

class Ventana : public QWidget {
public:
    Ventana(QWidget *parent = nullptr) : QWidget(parent) {
        label.setAlignment(Qt::AlignCenter);
        label.setStyleSheet("background-color: black;");

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(&label);

        setLayout(layout);
    }

    void mostrarImagen(const QString &rutaImagen) {
        QPixmap pixmap(rutaImagen);
        label.setPixmap(pixmap.scaled(size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

private:
    QLabel label;
};

class Login : public QWidget {
    Q_OBJECT
public:
    Login(QWidget *parent = nullptr) : QWidget(parent) {
        fondoLabel.setScaledContents(true);
        fondoLabel.setPixmap(QPixmap(":/imagenes/fondo.jpg"));

        QVBoxLayout *layout = new QVBoxLayout(this);
        layout->addWidget(&fondoLabel);

        usuarioLineEdit.setPlaceholderText("Usuario");
        claveLineEdit.setPlaceholderText("Clave");
        claveLineEdit.setEchoMode(QLineEdit::Password);

        layout->addWidget(&usuarioLineEdit);
        layout->addWidget(&claveLineEdit);

        QPushButton *boton = new QPushButton("Ingresar");
        layout->addWidget(boton);

        connect(boton, &QPushButton::clicked, this, &Login::verificarCredenciales);

        setLayout(layout);
    }

private slots:
    void verificarCredenciales() {
        QString usuario = usuarioLineEdit.text();
        QString clave = claveLineEdit.text();

        // Verificar credenciales en la base de datos o en algún otro lugar
        if (usuario == "admin" && clave == "admin") {
            mostrarVentana();
        } else {
            QMessageBox::warning(this, "Error", "Credenciales inválidas");
        }
    }

    void mostrarVentana() {
        ventana.mostrarImagen(":/imagenes/imagen.jpg");
        ventana.showFullScreen();
    }

private:
    QLabel fondoLabel;
    QLineEdit usuarioLineEdit;
    QLineEdit claveLineEdit;
    Ventana ventana;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Cargar las imágenes desde el archivo .qrc
    QFile::copy(":/imagenes/fondo.jpg", "fondo.jpg");
    QFile::copy(":/imagenes/imagen.jpg", "imagen.jpg");

    Login login;
    login.show();

    return app.exec();
}

#include "main.moc"
