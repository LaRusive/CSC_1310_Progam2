#include "bookData.h"
#include "linkedList.h"
#include <iostream>

int main()
{
    /*
    To do:
        In LinkedList, add Friend  << overload (use displayList())

        Add at least one more sort to go the opposite way. 
            If time allows, would be cool to also add sorts for different attributes -- right now it defaults to
            sort by author, maybe add a sort by year?

        Implement either class list node or smart pointer. List node should be easy to just remove the list node struct from LinkedList and 
            make it its own thing so I'd reccomend that
        
        Figure out MakeFile -- shouldn't be too hard

        Write test case

        Fill out bookData.txt

        Put together Driver
            Program flow -- menus and such
            File import/export -- figure out if this is required. If not, probably don't do it

        Driver menu:
            "Welcome to Library"  
            - Add book
            - Remove book
            - Sort library by author, A-Z
            - Sort library by author, Z-A
            - (If implemented) Sort by year, etc
            - Exit
    */

    LinkedList<Book> list;

    list.appendNode(Book("Moby Dick", "Herman Melville", 1870));
    list.appendNode(Book("King Lear", "William Shakespeare", 1610));
    list.appendNode(Book("Magnets", "Francis Bitter", 1959));
    
    std::cout << "\n";

    list.displayList();

    list.insertionSort();

    list.displayList();

    return 0;
}