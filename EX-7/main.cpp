#include <QCoreApplication>
#include "book.h"
#include <vector>
#include <algorithm>

bool compareBooksByYear(const Book& a, const Book& b) {
    return a.getYear() < b.getYear();
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Crear un vector de libros
    std::vector<Book> books;

    // Agregar algunos libros al vector
    books.push_back(Book("The Catcher in the Rye", "J.D. Salinger", 1951));
    books.push_back(Book("To Kill a Mockingbird", "Harper Lee", 1960));
    books.push_back(Book("1984", "George Orwell", 1949));
    books.push_back(Book("Pride and Prejudice", "Jane Austen", 1813));
    books.push_back(Book("The Great Gatsby", "F. Scott Fitzgerald", 1925));

    // Ordenar los libros por año de publicación
    std::sort(books.begin(), books.end(), compareBooksByYear);

    // Imprimir los detalles de los libros ordenados
    std::cout << "Libros ordenados por año de publicación:" << std::endl;
    for (const auto& book : books) {
        book.printDetails();
    }

    return a.exec();
}
