#include "Book.h"
#include <string>
#include <iostream>


Book::Book(const string& title, const string& author, int publicationYear) {
    this->title = title;
    this->author = author;
    this->publicationYear = publicationYear;
}

string Book::getTitle() const {

    return title;
}

string Book::getAuthor() const {

    return author;
}

int Book::getPublicationYear() const {

    return publicationYear;
}

void Book::setTitle(const string& book_title) {
    title = book_title;
}

void Book::setAuthor(const string& book_author) {

    author = book_author;
}

void Book::setPublicationYear(int book_publicationYear) {

    publicationYear = book_publicationYear;
}

string Book::getAuthorLastName() const {

    return author.substr(author.find_last_of(" ") + 1);
}

void Book::display() const {
    std::cout << title << ", " << author << ", " << publicationYear << endl;
}