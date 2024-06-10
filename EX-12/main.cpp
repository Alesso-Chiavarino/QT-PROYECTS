#include <QCoreApplication>
#include <QLabel>
#include <QPixmap>
#include <QTimer>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Crear un objeto QLabel
    QLabel label;

    // Cargar la imagen desde el archivo JPG
    QPixmap pixmap("ruta/a/tu/imagen.jpg");

    // Configurar la imagen en el QLabel
    label.setPixmap(pixmap.scaled(label.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    // Mostrar el QLabel maximizado
    label.showMaximized();

    // Configurar un temporizador para cerrar la aplicación después de 3 segundos
    QTimer::singleShot(3000, [&](){
        label.close();
        qApp->quit();
    });

    return a.exec();
}
