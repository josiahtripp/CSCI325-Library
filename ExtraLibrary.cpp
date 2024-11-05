/**
 * @file Library.cpp
 * @author Josiah Tripp, Elise Lightner
 * @date 2024-10-22
 * @brief Defines the method implementations for the Library class in "Library.h"
 * 
 * 
 */

#include "Library.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;


Library::Library(){
  book_count = 0;
}
 


Library::~Library(){
  book_count = 0;
}

void Library::push_front(book __book){
  books.push_front(__book);
    ++book_count;
}

void Library::push_back(book __book){
books.push_back(__book);
    ++book_count;
}

bool Library::read_from_file(string filename){
  ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return false;
    }

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

    file.close();
    cout << "Library saved successfully to " << filename << endl;
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

    for (const auto &b : books) {
        cout << "Title: " << b.title << ", "
             << "Author: " << b.author << ", "
             << "Pages: " << b.pages << ", "
             << "ISBN: " << b.isbn << ", "
             << "Price: $" << fixed << setprecision(2) << b.cover_price << ", "
             << "Year: " << b.year << endl;
    }
}

bool Library::delete_book(string title, string author){
 for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->title == title && it->author == author) {
            books.erase(it);
            --book_count;
            cout << "Book deleted successfully.\n";
            return true;
        }
    }
    cout << "Book not found.\n";
    return false;
}
