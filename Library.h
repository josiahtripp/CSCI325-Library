#ifndef LIBRARY_H
#define LIBRARY_H

#include <string>
#include <list>

typedef std::string __string;

typedef struct book{

    __string title;
    __string author;
    int pages;
    __string isbn;
    float cover_price;
    int year;
} book;

class Library{

    private:
        std::list<book> books;
        int book_count;
    public:
        Library();
        ~Library();
        void push_front(book __book);
        void push_back(book __book);
        bool read_from_file(__string filename);// Return false if file can't be opened
        bool write_to_file(__string filename);// Return false if the file can't be opened
        void insert_sorted(book __book);
        bool find_author(__string author);// Return true if author's name is found, false if not
        bool find_album(__string title);// Return true if book title is found, false if not
        void print();
        bool delete_book(__string title, __string author);// Return true if book was found and delete, false if not found (and not deleted)
};
#endif