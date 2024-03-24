#include <iostream>
#include <string>

using namespace std;

class Book {
private:
    string author;
    string name;
    string description;
    string userName;
    int condition; // Condition rating from 0 to 5
    int returnPeriod; 
    string librarian;


public:
    Book(string author, string name, string description, int condition) {
        this->author = author;
        this->name = name;
        this->description = description;
        this->condition = condition;

        this->userName = "";    
    }

    void getBook(string userName, string librarian , int returnPeriod) {
        this->userName = userName;
        this->librarian = librarian;
        this->returnPeriod = returnPeriod;
    }

    void returnBook(int newCondition) {
        if (newCondition < condition) {
            cout << "Condition has worsened!" << endl;
            cout << "You need to pay for the damage." << endl;
            // Add your code to handle payment here
        } else {
            cout << "Condition remains the same or improves. No additional charges." << endl;
        }
        condition = newCondition; // Update condition regardless
    }

    string getUserName() const {
        return userName;
    }
    int getCondition() const {
        return condition;
    }
    string getLibrarian() const {
        return librarian;
    }
    string getBookName() const {
        return name;
    }
};

int main() {
    Book books[5] = {
        Book("Author 1", "Book Name 1", "Description 1", 4), 
        Book("Author 2", "Book Name 2", "Description 2", 3), 
        Book("Author 3", "Book Name 3", "Description 3", 2), 
        Book("Author 4", "Book Name 4", "Description 4", 1), 
        Book("Author 5", "Book Name 5", "Description 5", 1)  
    };

    cout << "Which book would you like to get?" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << i + 1 << ". " << books[i].getBookName() << endl;
    }

    int bookIndex;
    cout << "Enter the number corresponding to the book: ";
    cin >> bookIndex;
    bookIndex--;

    if (bookIndex >= 0 && bookIndex < 5) {
        string userName;
        string librarian;
        int returnPeriod;
        cout << "Enter your name: ";
        cin >> userName;
        cout << "Enter librarian's name: ";
        cin >> librarian;
        cout << "enter return value in days: ";
        cin >> returnPeriod;

        books[bookIndex].getBook(userName, librarian, returnPeriod);
        cout << "Book successfully obtained!" << endl;
    } else {
        cout << "Invalid book number entered. Exiting..." << endl;
        return 1;
    }
    cout << "now return the book";
    int newCondition;
    do {
        cout << "Enter the condition (from 0 to 5): ";
        cin >> newCondition;
        if (newCondition < 0 || newCondition > 5) {
            cout << "Invalid condition. Please enter a value between 0 and 5." << endl;
        }
    } while (newCondition < 0 || newCondition > 5);

    books[bookIndex].returnBook(newCondition);
        
    return 0;
}