/*
    Book class header file
    10/11/24
    J Seger
*/

#ifndef BOOKDATA_H
#define BOOKDATA_H

#include <string>
#include <iostream>

class Book{
    private:
        std::string title;
        std::string author;
        int year;
    public:
        Book(std::string, std::string, int);
        std::string getTitle();
        std::string getAuthor();
        int getYear();
        void setTitle(std::string);
        void setAuthor(std::string);
        void setYear(int);
        /*
        operator <<
        operator <
        operator >
        operator ==
        */
        friend std::ostream& operator<<(std::ostream& out, Book const& c);
        bool operator<(Book&);
        bool operator>(Book&);
        bool operator==(Book&);
};

#endif