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
        //attributes
        std::string title;
        std::string author;
        int year;
    public:
        //constructors
        Book();
        Book(std::string, std::string, int);

        //Getters
        std::string getTitle();
        std::string getAuthor();
        int getYear();

        //Setters
        void setTitle(std::string);
        void setAuthor(std::string);
        void setYear(int);

        //Used for comparisons by author name
        std::string lastWord(std::string);

        //Operator overloads
        friend std::ostream& operator<<(std::ostream& out, Book const& c);
        bool operator<(Book&);
        bool operator>(Book&);
        bool operator==(Book&);
};

#endif