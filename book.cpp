#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

class ContactBook {
private:
    vector<Contact> contacts;

    void displayContact(const Contact& contact) const {
        cout << "Name: " << contact.name << endl;
        cout << "Phone: " << contact.phone << endl;
        cout << "Email: " << contact.email << endl;
        cout << "--------------------------" << endl;
    }

public:
    void addContact() {
        Contact newContact;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, newContact.name);
        cout << "Enter phone number: ";
        getline(cin, newContact.phone);
        cout << "Enter email: ";
        getline(cin, newContact.email);
        contacts.push_back(newContact);
        cout << "Contact added successfully!\n";
    }

    void searchContact() const {
        string query;
        cout << "Enter name or phone number to search: ";
        cin.ignore();
        getline(cin, query);

        bool found = false;
        for (const auto& contact : contacts) {
            if (contact.name.find(query) != string::npos || contact.phone.find(query) != string::npos) {
                displayContact(contact);
                found = true;
            }
        }

        if (!found) {
            cout << "No matching contact found.\n";
        }
    }

    void editContact() {
        string query;
        cout << "Enter name or phone number to search for editing: ";
        cin.ignore();
        getline(cin, query);

        for (auto& contact : contacts) {
            if (contact.name.find(query) != string::npos || contact.phone.find(query) != string::npos) {
                cout << "Contact found:\n";
                displayContact(contact);

                cout << "Enter new name (leave blank to keep current): ";
                string newName;
                getline(cin, newName);
                if (!newName.empty()) {
                    contact.name = newName;
                }

                cout << "Enter new phone (leave blank to keep current): ";
                string newPhone;
                getline(cin, newPhone);
                if (!newPhone.empty()) {
                    contact.phone = newPhone;
                }

                cout << "Enter new email (leave blank to keep current): ";
                string newEmail;
                getline(cin, newEmail);
                if (!newEmail.empty()) {
                    contact.email = newEmail;
                }

                cout << "Contact updated successfully!\n";
                return;
            }
        }

        cout << "No matching contact found.\n";
    }

    void displayAllContacts() const {
        if (contacts.empty()) {
            cout << "No contacts available.\n";
            return;
        }

        for (const auto& contact : contacts) {
            displayContact(contact);
        }
    }
};

int main() {
    ContactBook contactBook;
    int choice;

    do {
        cout << "\n--- Contact Book ---\n";
        cout << "1. Add Contact\n";
        cout << "2. Search Contact\n";
        cout << "3. Edit Contact\n";
        cout << "4. Display All Contacts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                contactBook.addContact();
                break;
            case 2:
                contactBook.searchContact();
                break;
            case 3:
                contactBook.editContact();
                break;
            case 4:
                contactBook.displayAllContacts();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}