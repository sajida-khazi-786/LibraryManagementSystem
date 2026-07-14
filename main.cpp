#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Library
{
public:
    int bookID;
    string title;
    string author;
    bool issued;

    void addBook()
    {
        ofstream file("library.txt", ios::app);

        cout << "\nEnter Book ID: ";
        cin >> bookID;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, title);

        cout << "Enter Author Name: ";
        getline(cin, author);

        issued = false;

        file << bookID << endl;
        file << title << endl;
        file << author << endl;
        file << issued << endl;

        file.close();

        cout << "\nBook Added Successfully!\n";
    }

    void displayBooks()
    {
        ifstream file("library.txt");

        if (!file)
        {
            cout << "\nNo Books Available.\n";
            return;
        }

        int id;
        string bookTitle, bookAuthor;
        bool status;

        cout << "\n========== BOOK LIST ==========\n";

        while (file >> id)
        {
            file.ignore();
            getline(file, bookTitle);
            getline(file, bookAuthor);
            file >> status;

            cout << "\nBook ID      : " << id;
            cout << "\nTitle        : " << bookTitle;
            cout << "\nAuthor       : " << bookAuthor;
            cout << "\nStatus       : ";

            if (status)
                cout << "Issued";
            else
                cout << "Available";

            cout << "\n----------------------------";
        }

        file.close();
    }

    void searchByTitle()
    {
        ifstream file("library.txt");

        string searchTitle;
        bool found = false;

        cin.ignore();

        cout << "\nEnter Book Title to Search: ";
        getline(cin, searchTitle);

        int id;
        string bookTitle, bookAuthor;
        bool status;

        while (file >> id)
        {
            file.ignore();
            getline(file, bookTitle);
            getline(file, bookAuthor);
            file >> status;

            if (bookTitle == searchTitle)
            {
                cout << "\nBook Found!";
                cout << "\nBook ID : " << id;
                cout << "\nTitle   : " << bookTitle;
                cout << "\nAuthor  : " << bookAuthor;
                cout << "\nStatus  : " << (status ? "Issued" : "Available") << endl;

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\nBook Not Found.\n";
        }

        file.close();
    }

    void searchByAuthor()
    {
        ifstream file("library.txt");

        string searchAuthor;
        bool found = false;

        cin.ignore();

        cout << "\nEnter Author Name to Search: ";
        getline(cin, searchAuthor);

        int id;
        string bookTitle, bookAuthor;
        bool status;

        while (file >> id)
        {
            file.ignore();
            getline(file, bookTitle);
            getline(file, bookAuthor);
            file >> status;

            if (bookAuthor == searchAuthor)
            {
                cout << "\nBook ID : " << id;
                cout << "\nTitle   : " << bookTitle;
                cout << "\nAuthor  : " << bookAuthor;
                cout << "\nStatus  : " << (status ? "Issued" : "Available") << endl;

                found = true;
            }
        }

        if (!found)
        {
            cout << "\nNo Books Found For This Author.\n";
        }

        file.close();
    }

    void issueBook()
    {
        cout << "\nBook Issued Successfully (Demo Version).\n";
    }

    void returnBook()
    {
        cout << "\nBook Returned Successfully (Demo Version).\n";
    }
};

int main()
{
    Library library;
    int choice;

    do
    {
        cout << "\n===================================";
        cout << "\n      LIBRARY MANAGEMENT SYSTEM";
        cout << "\n===================================";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Issue Book";
        cout << "\n4. Return Book";
        cout << "\n5. Search Book by Title";
        cout << "\n6. Search Book by Author";
        cout << "\n7. Exit";
        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            library.addBook();
            break;

        case 2:
            library.displayBooks();
            break;

        case 3:
            library.issueBook();
            break;

        case 4:
            library.returnBook();
            break;

        case 5:
            library.searchByTitle();
            break;

        case 6:
            library.searchByAuthor();
            break;

        case 7:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 7);

    return 0;
}