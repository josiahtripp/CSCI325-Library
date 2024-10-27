/**
 * @file Library.h
 * @author Josiah Tripp, Elise Lightner
 * @date 2024-10-27
 * @brief Defines the Library class and its associated methods
 * 
 * 
 */
#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <list>

typedef struct book{

    std::string title;
    std::string author;
    int year;
    std::string isbn;
    int pages;
    float cover_price;
} book;

/**
 * Holds a linked-list of books. Can search, sort (when loading in), delete, and read in & write out books to a file.
 *
 * @class Library{ Library.h "l-copy/Library.h"
 * @brief Defines a Library object and its associated methods & member variables
 *
 */
class Library{

    private:
        std::list<book> books;
    public:
        Library();
        ~Library();
        void push_front(book __book);
        void push_back(book __book);
        bool read_from_file(std::string filename);// Return false if file can't be opened
        bool write_to_file(std::string filename);// Return false if the file can't be opened
        void insert_sorted(book __book);
        bool find_author(std::string author);// Return true if author's name is found, false if not
        bool find_album(std::string title);// Return true if book title is found, false if not
        void print();
        bool delete_book(std::string title, std::string author);// Return true if book was found and delete, false if not found (and not deleted)
        int count(); // Return the number of books in the current library
};
#endif