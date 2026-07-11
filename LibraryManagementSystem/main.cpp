#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book
{
public:
    int id;
    string title;
    string author;
    bool issued;

    Book(int i, string t, string a)
    {
        id = i;
        title = t;
        author = a;
        issued = false;
    }
};

vector<Book> library;

// Add Book
void addBook()
{
    int id;
    string title, author;

    cout << "\nEnter Book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    library.push_back(Book(id, title, author));

    cout << "\nBook Added Successfully!\n";
}

// Display Books
void displayBooks()
{
    if (library.empty())
    {
        cout << "\nNo Books Available!\n";
        return;
    }

    cout << "\n========== BOOK LIST ==========\n";

    for (int i = 0; i < library.size(); i++)
    {
        cout << "\nBook ID : " << library[i].id;
        cout << "\nTitle   : " << library[i].title;
        cout << "\nAuthor  : " << library[i].author;
        cout << "\nStatus  : ";

        if (library[i].issued)
            cout << "Issued";
        else
            cout << "Available";

        cout << "\n----------------------------";
    }
}

// Search Book
void searchBook()
{
    int id;
    cout << "\nEnter Book ID to Search: ";
    cin >> id;

    for (int i = 0; i < library.size(); i++)
    {
        if (library[i].id == id)
        {
            cout << "\nBook Found!\n";
            cout << "Title : " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "Status: ";

            if (library[i].issued)
                cout << "Issued\n";
            else
                cout << "Available\n";

            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

// Issue Book
void issueBook()
{
    int id;
    cout << "\nEnter Book ID to Issue: ";
    cin >> id;

    for (int i = 0; i < library.size(); i++)
    {
        if (library[i].id == id)
        {
            if (library[i].issued)
            {
                cout << "\nBook Already Issued!\n";
            }
            else
            {
                library[i].issued = true;
                cout << "\nBook Issued Successfully!\n";
            }
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

// Return Book
void returnBook()
{
    int id;
    cout << "\nEnter Book ID to Return: ";
    cin >> id;

    for (int i = 0; i < library.size(); i++)
    {
        if (library[i].id == id)
        {
            if (!library[i].issued)
            {
                cout << "\nBook is Already Available!\n";
            }
            else
            {
                library[i].issued = false;
                cout << "\nBook Returned Successfully!\n";
            }
            return;
        }
    }

    cout << "\nBook Not Found!\n";
}

int main()
{
    int choice;

    do
    {
        cout << "\n===================================";
        cout << "\n   LIBRARY MANAGEMENT SYSTEM";
        cout << "\n===================================";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Exit";

        cout << "\n\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addBook();
            break;

        case 2:
            displayBooks();
            break;

        case 3:
            searchBook();
            break;

        case 4:
            issueBook();
            break;

        case 5:
            returnBook();
            break;

        case 6:
            cout << "\nThank You!\n";
            break;

        default:
            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 6);

    return 0;
}