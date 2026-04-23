#include <iostream>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isIssued;

    void addBook() {
        cout << "Enter Book ID: ";
        cin >> id;
        cout << "Enter Book Title: ";
        cin >> title;
        cout << "Enter Author Name: ";
        cin >> author;
        isIssued = false;
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nAuthor: " << author;
        cout << "\nStatus: " << (isIssued ? "Issued" : "Available") << endl;
    }
};

int main() {
    Book b[100];
    int count = 0;
    int choice, id;
    string searchTitle, searchAuthor;

    do {
        cout << "\n===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Issue Book\n";
        cout << "4. Return Book\n";
        cout << "5. Search by Title\n";
        cout << "6. Search by Author\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                b[count].addBook();
                count++;
                break;

            case 2:
                for(int i = 0; i < count; i++) {
                    b[i].display();
                }
                break;

            case 3:
                cout << "Enter Book ID to issue: ";
                cin >> id;
                for(int i = 0; i < count; i++) {
                    if(b[i].id == id && !b[i].isIssued) {
                        b[i].isIssued = true;
                        cout << "Book Issued Successfully!\n";
                        break;
                    }
                }
                break;

            case 4:
                cout << "Enter Book ID to return: ";
                cin >> id;
                for(int i = 0; i < count; i++) {
                    if(b[i].id == id && b[i].isIssued) {
                        b[i].isIssued = false;
                        cout << "Book Returned Successfully!\n";
                        break;
                    }
                }
                break;

            case 5:
                cout << "Enter Title to search: ";
                cin >> searchTitle;
                for(int i = 0; i < count; i++) {
                    if(b[i].title == searchTitle) {
                        b[i].display();
                    }
                }
                break;

            case 6:
                cout << "Enter Author to search: ";
                cin >> searchAuthor;
                for(int i = 0; i < count; i++) {
                    if(b[i].author == searchAuthor) {
                        b[i].display();
                    }
                }
                break;
        }

    } while(choice != 7);

    return 0;
}