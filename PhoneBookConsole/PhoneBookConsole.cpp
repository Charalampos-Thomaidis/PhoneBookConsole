#include <iostream>
#include <string>

using namespace std;

const int MAX_ENTRIES = 100;

class Person
{
public:
    string name;
    int number;
};

class PhoneBook
{
private:
    Person entries[MAX_ENTRIES];
    int count;

public:
    PhoneBook() : count(0) {}

    void displayDirectory() const
    {
        if (count == 0)
        {
            cout << "The directory is empty." << endl;
            return;
        }

        cout << "Phone Book Directory:" << endl;
        for (int i = 0; i < count; i++)
        {
            cout << entries[i].name << ": " << entries[i].number << endl;
        }
    }

    void importEntry()
    {
        if (count >= MAX_ENTRIES)
        {
            cout << "The phone book is full. Cannot add more entries." << endl;
            return;
        }

        Person newEntry;

        cout << "Enter the name: ";
        cin.ignore();
        getline(cin, newEntry.name);

        cout << "Enter the phone number: ";
        cin >> newEntry.number;

        entries[count] = newEntry;
        count++;

        cout << "Entry added succesfully." << endl;
    }

    void deleteEntry()
    {
        if (count == 0)
        {
            cout << "The directory is empty. No entries to delete." << endl;
            return;
        }

        string name;
        cout << "Enter the name to delete: ";
        cin.ignore();
        getline(cin, name);

        int index = -1;
        for (int i = 0; i < count; i++)
        {
            if (entries[i].name == name)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cout << "Entry not found." << endl;
            return;
        }

        for (int i = index; i < count - 1; i++)
        {
            entries[i] = entries[i + 1];
        }
        count--;

        cout << "Entry deleted succesfully." << endl;
    }

    void searchByName() const
    {
        if (count == 0)
        {
            cout << "The directory is empty. No entries to search." << endl;
            return;
        }

        string name;
        cout << "Enter the name to search: ";
        cin.ignore();
        getline(cin, name);

        int index = -1;
        for (int i = 0; i < count; i++)
        {
            if (entries[i].name == name)
            {
                index = i;
                break;
            }
        }

        if (index == -1)
        {
            cout << "Entry not found." << endl;
            return;
        }

        cout << "Name: " << entries[index].name << ", Phone Number: " << entries[index].number << endl;
    }
};
int main()
{
    PhoneBook phoneBook;

    cout << "Welcome to the Phone Book!" << endl;

    while (true)
    {
        cout << "\nMenu:\n1. Display Directory\n2. Import/Change Entry\n3. Delete Entry\n4. Search by Name\n5. Exit\n";
        cout << "Enter your choice (1-5): ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1: phoneBook.displayDirectory();
            break;
        case 2: phoneBook.importEntry();
            break;
        case 3: phoneBook.deleteEntry();
            break;
        case 4: phoneBook.searchByName();
            break;
        case 5:
            cout << "Thank you for using the Phone Book. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}