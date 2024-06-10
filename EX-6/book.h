#ifndef BOOK_H
#define BOOK_H

#include <QString>
#include <iostream>

class Book {
public:
    // Constructores
    Book();
    Book(const QString& title, const QString& author, int year);

    // Métodos
    QString getTitle() const;
    void setTitle(const QString& title);

    QString getAuthor() const;
    void setAuthor(const QString& author);

    int getYear() const;
    void setYear(int year);

    void printDetails() const;

private:
    // Atributos
    QString m_title;
    QString m_author;
    int m_year;
};

#endif // BOOK_H
