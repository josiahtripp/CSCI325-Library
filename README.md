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

To read in a library from a file, each book is read in one-by-one. Once the file is opened, a priming read 
is conducted, folled by a loop which will continue to add books to the library as long as they are being 
read in from the file. 

To prevent already-sorted library files from being sorted by the program when being read in, I implemented 
some simple logic to insert books using push_back() is the library is already sorted. When reading in a book 
from the file, the author name of the current book-to-be-read-in is compared to the author name of the previous 
book read in. If the author name of the new book is alphabetically more than (or equal to) the author name of 
the previous book, then the loop will cintinue using push_back() to load books.

If a book is read in in which the author's name is alphabetically lower than the previous book, then the 
library file is no longer considered sorted, and any subsequent books read in from that file will be added 
to the list using insert_sorted().

*-Josiah*

### Writing out the library to a file: `write_to_file()`

Due to the inner workings of the program and how it handles reading in files & adding new books via the interface, 
all books within the current library are sorted. this makes it very simple to print out, as all that needs to be done is 
to iterate through the books and print out (to file) the data associated with each one.

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

The implementation of the print function is almost identical to that of the write_to_file() function. 
The library is iterated through & each book's data is printed out. (albeit, with some more readable 
formatting to stdout instead of to a file)

Additionally, for the implementation in the driver program, I also made an accessor method called `count()`, 
which returns the number of books in the current library (STL list "`.size()`")

*-Josiah*

### Removing a book to the library: `delete_book()`

The library is iterated through using an iterator. (I know, hard to believe right?)
For every book in the library, the author's name & the title of the book are compared to the 
passed auhtor's name and book title. If there's a match, then the STL list method erase() is called 
and is passed the current iterator, removing that book from the list.

*-Josiah*