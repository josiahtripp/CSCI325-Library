/**
 * @file Library.cpp
 * @author Josiah Tripp, Elise Lightner
 * @date 2024-10-31
 * @brief Defines the method implementations for the Library class in "Library.h"
 * 
 * 
 */

#include "Library.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void Library::push_front(book __book){

    books.push_front(__book);
}

void Library::push_back(book __book){

    books.push_back(__book);
}

bool Library::read_from_file(string filename){

    ifstream read_in;
    read_in.open(filename);

    // Check if not open
    if(!read_in){
        return false;
    }

    // Load in a book (passed to insert/push method)
    book tmp_book;

    // Used to determine if the file is already sorted (only works when no entries have been loaded)
    string last_read_author;
    bool file_is_still_sorted = (count() == 0);

    // Priming read
    getline(read_in, tmp_book.title);
    getline(read_in, tmp_book.author);
    read_in >> tmp_book.year >> tmp_book.isbn >> tmp_book.pages >> tmp_book.cover_price;
    read_in.get();

    while(read_in){

        if(count() == 0){// First entry in the list
            push_front(tmp_book);
        }

        else if(file_is_still_sorted){// File is still considered sorted

            if(last_read_author > tmp_book.author){// Case where author's names are not sorted
                insert_sorted(tmp_book);// Needs to be sorted
                file_is_still_sorted = false;// All remaining entries must be sorted in
            }

            else{// Author's names are still sorted
                push_back(tmp_book);// Insert at end since file is already sorted
            }
        }

        else{// File is not sorted, proceed with sorting read entries
            insert_sorted(tmp_book);
        }
        
        last_read_author = tmp_book.author;
        // Read in again
        getline(read_in, tmp_book.title);
        getline(read_in, tmp_book.author);
        read_in >> tmp_book.year >> tmp_book.isbn >> tmp_book.pages >> tmp_book.cover_price;
        read_in.get();
    }
    
    read_in.close();
    return true;
}

bool Library::write_to_file(string filename){

    ofstream write_out;
    write_out.open(filename);

    // Check if not open
    if(!write_out){
        return false;
    }

    // Print out all
    for(list<book>::iterator it = books.begin(); it != books.end(); it++){

        write_out << it->title << '\n' << it->author << '\n';
        write_out << it->year << ' ' << it->isbn << ' ';
        write_out << it->pages << ' ' << it->cover_price;

        list<book>::iterator tmp_it = it;

        if(++tmp_it != books.end()){// Add newline if not the last entry
            write_out << '\n';
        }
    }
    
    write_out.close();
    return true;
}

void Library::insert_sorted(book __book){

}

bool Library::find_author(string author){

}

bool Library::find_album(string title){

}

void Library::print(){

    for(book current : books){

        cout << "'" << current.title << "' by " << current.author << endl;
        cout << "\tYear of Publication: " << current.year << endl;
        cout << "\tISBN: " << current.isbn << endl;
        cout << "\tPages: " << current.pages << endl;
        cout << "\tCover Price: " << current.cover_price << "\n\n";
    }
}

bool Library::delete_book(string title, string author){

    for(list<book>::iterator it = books.begin(); it != books.end(); it++){// Iterare through books

        // Book is found, delete
        if(it->title == title && it->author == author){

            books.erase(it);
            return true;
        }
    }
    return false;
}

int Library::count(){

    return (int) books.size();
}