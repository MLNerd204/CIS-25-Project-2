#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <string>
#include <vector>

using namespace std;

// Enumeration for the book status
enum BookStatus { AVAILABLE, BORROWED };

// Book structure to store book details
struct Book {
    int id;
    string title;
    string author;
    string releaseDate;
    BookStatus status;

    // Constructor to initialize a book
    Book(int id, const string& title, const string& author, const string& releaseDate);
};

// Library class to manage the library operations
class Library {
private:
    vector<Book> books; // Vector to hold all books in the library

public:
    // Function to add a book to the library
    void addBook(int id, const string& title, const string& author, const string& releaseDate);

    // Function to remove a book from the library
    void removeBook(int id);

    // Function to search for a book by title or author
    void searchBook(const string& searchTerm);

    // Function to display all books
    void displayAllBooks();

    // Function to borrow a book
    void borrowBook(int id);

    // Function to return a borrowed book
    void returnBook(int id);

    // Helper function to display a book's details
    void displayBook(const Book& book);
};

#endif // LIBRARY_HPP
