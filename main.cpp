/**
 * @file main.cpp
 * @author Josiah Tripp, Elise Lightner
 * @date 2024-10-27
 * @brief Driver & test program for the "Library" class
 * 
 * 
 */
#include <iostream>
#include <string>
#include "Library.h"

using namespace std;

void print_options();

int main(){

    Library lib;

    cout << "Welcome to the UTM Library! (Note* we are not in any way endorsed or affiliated with the Paul Meek Library)\n";
    print_options();

    while(true){
        
        // Prompt user
        cout << "Please enter your choice now: ";

        // Get user selection
        char user_input;
        cin >> user_input;

        // Hold user input & are are passed as method arguments
        string filename;
        string title;
        string author;
        book tmp_book;

        switch (user_input){// Perform selected operation

            case '1':// Load library from file
                cout << "Please enter the name of the file to read in: ";
                cin >> filename;

                if(lib.read_from_file(filename)){// File is opened & read
                    cout << "Successfully read file '" << filename << "' into the library.\n";
                }
                else{// File couldn't open
                    cout << "Could not open file '" << filename << "'.\n";
                }
            break;

            case '2':// Write library to file
                cout << "Please enter a name for the file to be written out: ";
                cin >> filename;

                if(lib.write_to_file(filename)){// File is opened & written
                    cout << "Successfully wrote the library to file '" << filename << "'.\n";
                }
                else{// File couldn't be opened
                    cout << "Could not open/create file '" << filename << "'.\n";
                }
            break;

            case '3':// Print all books
                if(lib.count() < 1){// Library is empty
                    cout << "No entries to print (library is empty)\n";
                }
                else{// Library has entry/entries
                    cout << "Printing contents of the library...(" << lib.count() << " entries)\n\n";
                    lib.print();
                }
            break;

            case '4':// Print all books by author
                cout << "Please enter the name of the author you wish to search: ";
                cin >> author;
                cout << endl;
                
                lib.find_author(author);// Print out all of the author's books
            break;

            case '5':// Find all books with a given name
                cout << "Please enter the book title to search: ";
                cin >> title;
                cout << endl;

                lib.find_album(title);// Print out all books with the given name
            break;

            case '6':// Add a book to the library
                cout << "Please enter the title of the book to add: ";
                cin >> tmp_book.title;
                cout << "Please enter the author (full name) of the book to add";
                cin >> tmp_book.author;
                cout << "Please enter the ISBN number of the book to add";
                cin >> tmp_book.isbn;
                cout << "Please enter the number of pages in the book to add: ";
                cin >> tmp_book.pages;
                cout << "Please enter the year of publication of the book to add:";
                cin >> tmp_book.year;
                cout << "Please enter the cover price of the book to add";
                cin >> tmp_book.cover_price;
                cout << endl;

                lib.insert_sorted(tmp_book);// Add to list

                //Print confirmation message
                cout << "Added '" << tmp_book.title << "' by " << tmp_book.author << " to the library.\n";
            break;

            case '7':// Remove a book from the library
                cout << "Please enter the title of the book to remove: ";
                cin >> title;
                cout << "Please enter the author or the book to remove: ";
                cin >> author;
                cout << endl;
            
                if(lib.delete_book(title, author)){// User found & deleted
                    cout << "Removed '" << title << "' by " << author << " from the library.\n";
                }
                else{// User not found & therefore, not deleted
                    cout << "Could not find/delete '" << title << "' by " << author << " in the library.\n";
                }
            break;

            case '8':// Exit the program
                return 0;
            break;

            case '0':// Help command: list options again
                print_options();
            break;

            default:
                cout << "Invalid choice: '" << user_input << "'\n";
                cout << "\tEnter the command '0' to list all valid commands.\n";
            break;
        }
    }
    return 0;
}

void print_options(){

    cout << R"(You may select one of the following options:
1 Read a library from a file
2 Write the library to a file
3 Print the library
4 Search and print all books by a specific author
5 Search and print all books with a given name
6 Add a book to the library
7 Remove a book from the library
8 Exit this program

0 Help command: List all valid command options (this screen))" << "\n\n";
}