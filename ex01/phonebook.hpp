#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Contact
{
private:
    string firstName;
    string lastName;
    string nickname;
    string phoneNumber;
    string darkestSecret;
public:
    void setFirstName(const string &firstName);
    void setLastName(const string &lastName);
    void setNickname(const string &nickname);
    void setPhoneNumber(const string &phoneNumber);
    void setDarkestSecret(const string &darkestSecret);
    string getFirstName() const;
    string getLastName() const;
    string getNickname() const;
    string getPhoneNumber() const;
    string getDarkestSecret() const;
};

class PhoneBook
{
    private:
        Contact contacts[8];
        int contactCount;
    public:
        PhoneBook();
        void addContact(const Contact &contact);
        void deleteContact(int index);
        void searchContact() const;
        void showContacts() const;
        void showContactInfo(int index) const;
        void exitPhoneBook() const;
};


#endif
