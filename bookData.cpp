/*
    Book class implementation
    10/11/24
    J Seger
*/

#include "bookData.h"
//#include <iostream>

Book::Book(std::string t, std::string a, int y){
    title = t;
    author = a;
    year = y;
}

std::string Book::getTitle(){
    return title;
}

std::string Book::getAuthor(){
    return author;
}

int Book::getYear(){
    return year;
}

void Book::setTitle(std::string x){
    title = x;
}

void Book::setAuthor(std::string x){
    author = x;
}

void Book::setYear(int x){
    year = x;
}

//friend of Book
std::ostream& operator<<(std::ostream& out, Book const& c)
{
    out << c.title << " by " << c.author << " (" << c.year << ")";
    return out;
}

bool Book::operator<(Book& b){
    return (b.getAuthor() < author);
}
bool Book::operator>(Book& b){
    return (b.getAuthor() > author);
}
bool Book::operator==(Book& b){
    return (b.getAuthor() == author);
}