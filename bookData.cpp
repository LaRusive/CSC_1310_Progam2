/*
    Book class implementation
    10/11/24
    J Seger
*/

#include "bookData.h"

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

std::string operator<<(const& Book b){
    //how to overload stream? 
    return "string";
}
bool operator<(const& Book b){
    //
}
bool operator>(const& Book b){
    //
}
bool operator==(const& Book b){
    //
}