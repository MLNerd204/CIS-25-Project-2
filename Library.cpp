#include "Library.hpp"
#include <iostream>

using namespace std;

// Book constructor
Book::Book(int id, const string& title, const string& author, const string& releaseDate)
    : id(id), title(title), author(author), releaseDate(releaseDate), status(AVAILABLE) {}

// Function to add a book to the library
void Library::addBook(int id, const string& title, const string& author, const string& releaseDate) {
    books.push_back(Book(id, title, author, releaseDate));
    cout<<"Book added successfully!"<<endl;
}

// Function to remove a book from the library
void Library::removeBook(int id) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == id) {
            books.erase(it);
            cout<<"Book removed successfully!"<<endl;
            return;
        }
    }
    cout<<"Book not found!"<<endl;
}

// Function to search for a book by title or author
void Library::searchBook(const string& searchTerm) {
    bool found = false;
    for (const auto& book : books) {
        if (book.title == searchTerm || book.author == searchTerm) {
            displayBook(book);
            found = true;
        }
    }
    if (!found) {
        cout<<"No book found matching the search term."<<endl;
    }
}

// Function to display all books
void Library::displayAllBooks() {
    if (books.empty()) {
        cout<< "No books in the library."<<endl;
        return;
    }
    for (const auto& book : books) {
        displayBook(book);
    }
}

// Function to borrow a book
void Library::borrowBook(int id) {
    for (auto& book : books) {
        if (book.id == id) {
            if (book.status == BORROWED) {
                cout<<"Sorry, this book is already borrowed."<<endl;
            } else {
                book.status = BORROWED;
                cout<<"You have successfully borrowed: "<<book.title<<endl;
            }
            return;
        }
    }
    cout<<"Book not found!"<<endl;
}

// Function to return a borrowed book
void Library::returnBook(int id) {
    for (auto& book : books) {
        if (book.id == id) {
            if (book.status == AVAILABLE) {
                cout<<"This book is already available."<<endl;
            } else {
                book.status = AVAILABLE;
                cout<<"You have successfully returned: "<<book.title<<endl;
            }
            return;
        }
    }
    cout<<"Book not found!"<<endl;
}

// Helper function to display a book's details
void Library::displayBook(const Book& book) {
    cout<<"ID: "<< book.id <<", Title: "<< book.title <<", Author: "<< book.author
              << ", Release Date: " << book.releaseDate
              << ", Status: "<<(book.status == AVAILABLE ? "Available" : "Borrowed")<<endl;
}
