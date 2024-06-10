#include <QCoreApplication>
#include "book.h"

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Crear algunos objetos de la clase Book
    Book book1;
    book1.setTitle("The Catcher in the Rye");
    book1.setAuthor("J.D. Salinger");
    book1.setYear(1951);

    Book book2("To Kill a Mockingbird", "Harper Lee", 1960);

    // Imprimir los detalles de los libros
    book1.printDetails();
    book2.printDetails();

    return a.exec();
}
