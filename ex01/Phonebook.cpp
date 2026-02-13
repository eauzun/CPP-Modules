#include"phonebook.hpp"

PhoneBook::PhoneBook() : contactCount(0) {}

void PhoneBook::addContact(const Contact &contact)
{
    if (contactCount < 8)
    {
        contacts[contactCount] = contact;
        contactCount++;
    }
    else
    {
        cout << "PhoneBook is full. Cannot add more contacts." << endl;
    }
}

void PhoneBook::deleteContact(int index)
{
    if (index >= 0 && index < contactCount)
    {
        for (int i = index; i < contactCount - 1; i++)
        {
            contacts[i] = contacts[i + 1];
        }
        contactCount--;
    }
    else
    {
        cout << "Invalid index. Cannot delete contact." << endl;
    }
}

void PhoneBook::searchContact() const
{
    if (contactCount == 0)
    {
        cout << "PhoneBook is empty. No contacts to search." << endl;
        return;
    }

    cout << "Index | First Name | Last Name | Nickname" << endl;
    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < contactCount; i++)
    {
        cout << i << "     | " << contacts[i].getFirstName() << " | " 
             << contacts[i].getLastName() << " | " 
             << contacts[i].getNickname() << endl;
    }
}

void PhoneBook::showContacts() const
{
    if (contactCount == 0)
    {
        cout << "PhoneBook is empty. No contacts to show." << endl;
        return;
    }

    for (int i = 0; i < contactCount; i++)
    {
        cout << "Contact " << i << ":" << endl;
        cout << "First Name: " << contacts[i].getFirstName() << endl;
        cout << "Last Name: " << contacts[i].getLastName() << endl;
        cout << "Nickname: " << contacts[i].getNickname() << endl;
        cout << "Phone Number: " << contacts[i].getPhoneNumber() << endl;
        cout << "Darkest Secret: " << contacts[i].getDarkestSecret() << endl;
        cout << "-----------------------------" << endl;
    }
}

void PhoneBook::showContactInfo(int index) const
{
    if (index >= 0 && index < contactCount)
    {
        cout << "First Name: " << contacts[index].getFirstName() << endl;
        cout << "Last Name: " << contacts[index].getLastName() << endl;
        cout << "Nickname: " << contacts[index].getNickname() << endl;
        cout << "Phone Number: " << contacts[index].getPhoneNumber() << endl;
        cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << endl;
    }
    else
    {
        cout << "Invalid index. Cannot show contact info." << endl;
    }
}

void PhoneBook::exitPhoneBook() const
{
    cout << "Exiting PhoneBook. Goodbye!" << endl;
}

