#include "book.h"

// Constructor por defecto
Book::Book() : m_title(""), m_author(""), m_year(0) {}

// Constructor con parámetros
Book::Book(const QString& title, const QString& author, int year)
    : m_title(title), m_author(author), m_year(year) {}

// Getters y Setters
QString Book::getTitle() const {
    return m_title;
}

void Book::setTitle(const QString& title) {
    m_title = title;
}

QString Book::getAuthor() const {
    return m_author;
}

void Book::setAuthor(const QString& author) {
    m_author = author;
}

int Book::getYear() const {
    return m_year;
}

void Book::setYear(int year) {
    m_year = year;
}

// Método para imprimir los detalles del libro
void Book::printDetails() const {
    std::cout << "Title: " << m_title.toStdString()
              << ", Author: " << m_author.toStdString()
              << ", Year: " << m_year << std::endl;
}
