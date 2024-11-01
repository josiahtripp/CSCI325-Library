# CSCI325-Library

Contained here is a simple digital-library application for managing & viewing book inventories.<br>
*Created by Josiah Tripp & Elise Lightner*

## Main Driver: `"main.cpp"`

The primary goal I kept in mind while developing the driver program was **ease of use**.<br>
Since the functionality of this program is quite similar to that of the individual *linked list phonebook* 
assignment, I used the main driver program of that assignemnt as a guide for making this driver program.
 
To break it down simply, the user is prompted to enter a character, corresponging to one of the menu options, 
which then leads to a specific switch case. Depending on the case, the user will be prompted for input for the 
required fields. Additionally, if the user enter an invalid menu option, they're notified of their invalid 
choice & are given instructions on how to list menu options again.

*-Josiah*

## Class Methods

Written below are some comments about the developmental process of each method within the "Library" class.
<br>

### Adding books to the front of the library: `push_front()`

This function was very easy to implement. All that needed to be done was to take the book passed 
to the function & pass it to the STL list push_front() method of our library list "books"

*-Josiah*

### Adding books to the front of the library: `push_back()`

The process of implementing this function was nearly identical to that of the push_front() method, 
with the only difference being passing the book to the STL list push_back() method instead of push_front().

*-Josiah*

### Reading in a library from a file: `read_from_file()`

lorem ipsum

*-Josiah*

### Writing out the library to a file: `write_to_file()`

lorem ipsum

*-Josiah*

### Adding books into the right spot in the library: `insert_sorted()`

lorem ipsum

*-Elise*

### Finding all the books by an author: `find_author()`

lorem ipsum

*-Elise*

### Finding all the books with a given name: `find_album()`

lorem ipsum

*-Elise*

### Listing all of the books in the library: `print()`

lorem ipsum

*-Josiah*

### Removing a book to the library: `delete_book()`

lorem ipsum

*-Josiah*