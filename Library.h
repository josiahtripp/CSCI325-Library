/**
 * @file Library.h
 * @author Josiah Tripp, Elise Lightner
 * @date 2024-11-08
 * @brief Defines the Library class and its associated methods
 * 
 * 
 */
#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <list>

/**
 * Holds information about a book
 *
 * @class struct Library.h "l-copy/Library.h"
 * @brief Defines a book struct to be used within the library
 *
 * @std::string title The title of the book.
 * @std::string author The author of the book.
 * @int year The year of publication of the book.
 * @std::string isbn The isbn number of the book.
 * @int pages The number of pages in the book.
 * @float cover_price The price of the book (in USD $)
 *
 */
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
  std::list<book> books;// The "library" list of books
    public:

/**
 * Default constructor
 *
 * @pre
 * @post 
 * 
 */
  Library();

/**
 * Adds a book to the front of the library list
 *
 * @param book __book The book to add
 * @pre
 * @return void 
 * @post The book has been added to the front of the library list
 * 
 */
  void push_front(book __book);

/**
 * Adds a book to the back of the library list 
 *
 * @param book __book The book to add
 * @pre 
 * @return void 
 * @post the book has been added to the back of the library list
 * 
 */
  void push_back(book __book);

/**
 * Reads in a library (properly formatted list of books) from a file
 *
 * @param std::string filename The name of the library file
 * @pre 
 * @return bool Whether the file could be read in or not
 * @post All books within the library file specified by filename have been read into the current library list
 * 
 */
  bool read_from_file(std::string filename);

/**
 * Writes out the current library (list of books) to a properly formatted, sorted file
 *
 * @param std::string filename The name of the file to write out
 * @pre 
 * @return bool Whether the file could be created/written out or not
 * @post All books in the current library list have been written out the file specified by filename
 * 
 */
  bool write_to_file(std::string filename);
  void insert_sorted(book __book);
  bool find_author(std::string author);// Return true if author's name is found, false if not
  bool find_album(std::string title);// Return true if book title is found, false if not

/**
 * Prints out all books in the current library and their associated information 
 *
 * @pre 
 * @return void 
 * @post All books in the current library and their associated information have been printed to stdout
 * 
 */
  void print();

/**
 * Removes a book from the current library list
 *
 * @param std::string title The title of the book to remove
 * @param std::string author the author of the book to remove
 * @pre 
 * @return bool Whether the book could be found and removed or not
 * @post The book specified by title & author name has been removed from the current library list
 * 
 */
  bool delete_book(std::string title, std::string author);

/**
 * Accessor for the current library list books,size() method
 *
 * @pre 
 * @return int The value returned by the library list books.size() method
 * @post 
 * 
 */
  int count();
};
#endif
