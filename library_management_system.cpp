#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool available;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        available = true;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added successfully.\n";
    }

    void issueBook(string title) {
        for (auto &book : books) {
            if (book.title == title && book.available) {
                book.available = false;
                cout << "Book issued successfully.\n";
                return;
            }
        }
        cout << "Book not available.\n";
    }

    void returnBook(string title) {
        for (auto &book : books) {
            if (book.title == title) {
                book.available = true;
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void searchBook(string keyword) {
        bool found = false;
        for (auto &book : books) {
            if (book.title.find(keyword) != string::npos ||
                book.author.find(keyword) != string::npos) {
                cout << "ID: " << book.id
                     << " | Title: " << book.title
                     << " | Author: " << book.author
                     << " | " << (book.available ? "Available" : "Issued") << "\n";
                found = true;
            }
        }
        if (!found) cout << "No matching books found.\n";
    }
};

int main() {
    Library library;

    library.addBook(1, "C++ Basics", "Bjarne");
    library.addBook(2, "Data Structures", "Mark");

    library.searchBook("C++");
    library.issueBook("C++ Basics");
    library.returnBook("C++ Basics");

    return 0;
}
