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
#include <iomanip>
using namespace std;

<<<<<<< HEAD

Library::Library() : book_count(0) {}
 


Library::~Library(){

}

void Library::push_front(book __book){
  books.push_front(__book);
    ++book_count;
}

void Library::push_back(book __book){
books.push_back(__book);
    ++book_count;
=======
void Library::push_front(book __book){

    books.push_front(__book);
}

void Library::push_back(book __book){

    books.push_back(__book);
>>>>>>> 178337795b5552b0e119651b72c226322cd3f453
}

bool Library::read_from_file(string filename){
  ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return false;
    }

<<<<<<< HEAD
    books.clear();
    book __book;
    while (file >> ws && getline(file, __book.title)) {
        getline(file, __book.author);
        file >> __book.pages >> __book.isbn >> __book.cover_price >> __book.year;
        file.ignore(); // Ignore the newline after the year field
        insert_sorted(__book);
    }
    file.close();
    cout << "Library loaded successfully from " << filename << endl;
=======
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
>>>>>>> 178337795b5552b0e119651b72c226322cd3f453
    return true;
}

bool Library::write_to_file(string filename){
ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open the file: " << filename << endl;
        return false;
    } for (const auto &b : books) {
        file << b.title << '\n'
             << b.author << '\n'
             << b.pages << '\n'
             << b.isbn << '\n'
             << fixed << setprecision(2) << b.cover_price << '\n'
             << b.year << '\n';
    }

<<<<<<< HEAD
    file.close();
    cout << "Library saved successfully to " << filename << endl;
=======
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
>>>>>>> 178337795b5552b0e119651b72c226322cd3f453
    return true;
}



void Library::insert_sorted(book __book){
  auto it = books.begin();
    while (it != books.end() && it->author < __book.author) {
        ++it;
    }
    books.insert(it, __book);
    ++book_count;
}

bool Library::find_author(string author){
 bool found = false;
    for (const auto &b : books) {
        if (b.author == author) {
            cout << "Title: " << b.title << " (" << b.year << ")" << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No books found by author: " << author << endl;
    }
    return found;
}

bool Library::find_album(string title){
bool found = false;
    for (const auto &b : books) {
        if (b.title == title) {
            cout << "Title: " << b.title << "\n"
                 << "Author: " << b.author << "\n"
                 << "Pages: " << b.pages << "\n"
                 << "ISBN: " << b.isbn << "\n"
                 << "Price: $" << fixed << setprecision(2) << b.cover_price << "\n"
                 << "Year: " << b.year << "\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No book found with title: " << title << endl;
    }
    return found;
}

void Library::print(){
    if (books.empty()) {
        cout << "Library is empty." << endl;
        return;
    }

<<<<<<< HEAD
    for (const auto &b : books) {
        cout << "Title: " << b.title << ", "
             << "Author: " << b.author << ", "
             << "Pages: " << b.pages << ", "
             << "ISBN: " << b.isbn << ", "
             << "Price: $" << fixed << setprecision(2) << b.cover_price << ", "
             << "Year: " << b.year << endl;
=======
    for(book current : books){

        cout << "'" << current.title << "' by " << current.author << endl;
        cout << "\tYear of Publication: " << current.year << endl;
        cout << "\tISBN: " << current.isbn << endl;
        cout << "\tPages: " << current.pages << endl;
        cout << "\tCover Price: " << current.cover_price << "\n\n";
>>>>>>> 178337795b5552b0e119651b72c226322cd3f453
    }
}

bool Library::delete_book(string title, string author){
<<<<<<< HEAD
 for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->title == title && it->author == author) {
            books.erase(it);
            --book_count;
            cout << "Book deleted successfully.\n";
            return true;
        }
    }
    cout << "Book not found.\n";
=======

    for(list<book>::iterator it = books.begin(); it != books.end(); it++){// Iterare through books

        // Book is found, delete
        if(it->title == title && it->author == author){

            books.erase(it);
            return true;
        }
    }
>>>>>>> 178337795b5552b0e119651b72c226322cd3f453
    return false;
}

int Library::count(){

    return (int) books.size();
}