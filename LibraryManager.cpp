#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// Enumeration for the book status
enum BookStatus{AVAILABLE, BORROWED};

// Book structure to store book details
struct Book {
    int id;
    string title;
    string author;
    string releaseDate;
    BookStatus status;

    // Constructor to initialize a book
    Book(int id, string title, string author, string releaseDate) :
        id(id), title(title), author(author), releaseDate(releaseDate), status(AVAILABLE) {}
};

// Library class to manage the library operations
class Library {
private:
    vector<Book> books; // Vector to hold all books in the library

public:
    // Function to add a book to the library
    void addBook(int id, const string& title, const string& author, const string& releaseDate) {
        books.push_back(Book(id, title, author, releaseDate));
        cout << "Book added successfully!" << endl;
    }

    // Function to remove a book from the library
    void removeBook(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->id == id) {
                books.erase(it);
                cout << "Book removed successfully!" << endl;
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    // Function to search for a book by title or author
    void searchBook(const string& searchTerm) {
        bool found = false;
        for (const auto& book : books) {
            if (book.title == searchTerm || book.author == searchTerm) {
                displayBook(book);
                found = true;
            }
        }
        if (!found) {
            cout << "No book found matching the search term." << endl;
        }
    }

    // Function to display all books
    void displayAllBooks() {
        if (books.empty()) {
            cout << "No books in the library." << endl;
            return;
        }
        for (const auto& book : books) {
            displayBook(book);
        }
    }

    // Function to borrow a book
    void borrowBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (book.status == BORROWED) {
                    cout << "Sorry, this book is already borrowed." << endl;
                } else {
                    book.status = BORROWED;
                    cout << "You have successfully borrowed: " << book.title << endl;
                }
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    // Function to return a borrowed book
    void returnBook(int id) {
        for (auto& book : books) {
            if (book.id == id) {
                if (book.status == AVAILABLE) {
                    cout << "This book is already available." << endl;
                } else {
                    book.status = AVAILABLE;
                    cout << "You have successfully returned: " << book.title << endl;
                }
                return;
            }
        }
        cout << "Book not found!" << endl;
    }

    // Helper function to display a book's details
    void displayBook(const Book& book) {
        cout << "ID: " << book.id << ", Title: " << book.title << ", Author: " << book.author
             << ", Release Date: " << book.releaseDate
             << ", Status: " << (book.status == AVAILABLE ? "Available" : "Borrowed") << endl;
    }
};

int main() {
    Library lib;

    // Sample menu-driven interface
    int choice, id;
    string title, author, releaseDate;
    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Search Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Borrow Book\n";
        cout << "6. Return Book\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To clear the input buffer

        switch (choice) {
            case 1:
                cout << "Enter Book ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Title: ";
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter Release Date: ";
                getline(cin, releaseDate);
                lib.addBook(id, title, author, releaseDate);
                break;
            case 2:
                cout << "Enter Book ID to remove: ";
                cin >> id;
                lib.removeBook(id);
                break;
            case 3:
                cout << "Enter title or author to search: ";
                cin.ignore();
                getline(cin, title);
                lib.searchBook(title);
                break;
            case 4:
                lib.displayAllBooks();
                break;
            case 5:
                cout << "Enter Book ID to borrow: ";
                cin >> id;
                lib.borrowBook(id);
                break;
            case 6:
                cout << "Enter Book ID to return: ";
                cin >> id;
                lib.returnBook(id);
                break;
            case 7:
                cout << "Exiting the system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}



