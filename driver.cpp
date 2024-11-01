/*
    J Seger
    Driver for Library program
    11/1
*/

#include "bookData.h"
#include "linkedList.h"
#include <iostream>

void inpVer(int& out, int lowerBound, int upperBound, string qText = "Enter choice:   ", string invText = "Input invalid.");
void addBook(LinkedList<Book>&);
void removeNode(LinkedList<Book>&);

int main()
{
    /*
    To do:
        In LinkedList, add Friend  << overload (use displayList())

        Give LinkedList a cpp?

        If time allows, would be cool to also add sorts for different attributes -- right now it defaults to
            sort by author, maybe add a sort by year?

        Implement either class list node or smart pointer. List node should be easy to just remove the list node struct from LinkedList and 
            make it its own thing so I'd reccomend that
        
        Figure out MakeFile -- shouldn't be too hard

        Write test case

        Fill out bookData.txt

        File import/export -- figure out if this is required. If not, probably don't do it
    */

    LinkedList<Book> list;

    /*list.appendNode(Book("Moby Dick", "Herman Melville", 1870));
    list.appendNode(Book("King Lear", "William Shakespeare", 1610));
    list.appendNode(Book("Magnets", "Francis Bitter", 1959));
    
    std::cout << "\n";

    list.displayList();

    list.insertionSort();*/

    bool exitBool = false;

    do{

        std::cout << "\n\n";
        list.displayList();

        std::cout << "\n\nWelcome to your Library!";
        std::cout << "\nMenu:";
        std::cout << "\n\t1. Add book";
        std::cout << "\n\t2. Remove book";
        std::cout << "\n\t3. Sort books A - Z"; //implement
        std::cout << "\n\t4. Sort book Z - A";
        std::cout << "\n\t5. Exit Library";

        int choice = -1;
        inpVer(choice, 1, 5);

        switch(choice){
            case 1: addBook(list); break;
            case 2: removeNode(list); break;
            case 3: list.insertionSort(false); break;
            case 4: list.insertionSort(true); break;
            case 5: exitBool = true; break;
            default: break; // no action
        }

    }while(!exitBool);

    std::cout << "\n\nGood bye!";

    return 0;
}

/*
    Name:       inpVer
    Args:       int& out, int lowerBound, int upperBound, string qText, string invText
    Purpose:    Take user input and ensure it is an int that is within given bounds. Takes optional prompt and invalid strings to personalize
*/
//Only for int input verification!
void inpVer(int& out, int lowerBound, int upperBound, string qText, string invText){
    bool works;
    do{ 
        works = false;
        cout << "\n" << qText;
        cin >> out;
        if(cin.fail()){ 
            cin.clear();
            cin.ignore(100000000000000000, '\n'); 
            cout << "\n" << invText;
        }else if(out > upperBound || out < lowerBound){
            cout << "\n" << invText;
        }else{
            works = true;
        }
    }while(!works);
}

void addBook(LinkedList<Book>& list){
    string title, author;
    int year;
    
    cin.clear();
    cin.ignore(100000000000000000, '\n'); 
    std::cout << "\n\tWhat is the title of the new book? ";
    getline(cin, title);
    std::cout << "\n\tWho is the author of the new book? ";
    getline(cin, author);
    std::cout << "\n\tWhen was the new book published? ";
    cin >> year;

    list.appendNode(Book(title, author, year));
}

void removeNode(LinkedList<Book>& list){
    int ind;
    std::cout << "\n\tWhat is the index of the book you would like to remove? ";
    cin >> ind;
    list.deleteNode(list.getNodeValue(ind));//Easier than writing a delete function that takes an index
}