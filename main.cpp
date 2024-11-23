// main.cpp
#include <iostream>
#include "Library.hpp"

using namespace std;

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

