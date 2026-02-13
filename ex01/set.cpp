#include "phonebook.hpp"

void Contact::setFirstName(const string &firstName)
{
    this->firstName = firstName;
}

void Contact::setLastName(const string &lastName)
{
    this->lastName = lastName;
}

void Contact::setNickname(const string &nickname)
{
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const string &phoneNumber)
{
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const string &darkestSecret)
{
    this->darkestSecret = darkestSecret;
}