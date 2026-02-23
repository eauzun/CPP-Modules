/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:28:43 by emuzun            #+#    #+#             */
/*   Updated: 2026/02/16 14:37:20 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myAwesomePhoneBook.hpp"
#include <cstdlib>

PhoneBook::PhoneBook(void)
{
	this->oldest = 0;
	this->count = 0;
}

void	PhoneBook::add(void)
{
	string	input;

	cout << "\n=== ADD NEW CONTACT ===" << endl;

	cout << "First name: ";
	getline(cin, input);
	if (input.empty())
	{
		cout << "Error: Field cannot be empty!" << endl;
		return ;
	}
	this->contacts[this->oldest].setFirstName(input);

	cout << "Last name: ";
	getline(cin, input);
	if (input.empty())
	{
		cout << "Error: Field cannot be empty!" << endl;
		return ;
	}
	this->contacts[this->oldest].setLastName(input);

	cout << "Nickname: ";
	getline(cin, input);
	if (input.empty())
	{
		cout << "Error: Field cannot be empty!" << endl;
		return ;
	}
	this->contacts[this->oldest].setNickname(input);

	cout << "Phone number: ";
	getline(cin, input);
	if (input.empty())
	{
		cout << "Error: Field cannot be empty!" << endl;
		return ;
	}
	this->contacts[this->oldest].setPhoneNumber(input);

	cout << "Darkest secret: ";
	getline(cin, input);
	if (input.empty())
	{
		cout << "Error: Field cannot be empty!" << endl;
		return ;
	}
	this->contacts[this->oldest].setDarkestSecret(input);

	this->oldest = (this->oldest + 1) % 8;
	
	if (this->count < 8)
		this->count++;

	cout << "Contact added successfully!" << endl;
}

void	PhoneBook::search(void)
{
	string	input;
	int		index;

	if (this->count == 0)
	{
		cout << "Phonebook is empty!" << endl;
		return ;
	}

	cout << endl;
	cout << "|" << setw(10) << "Index" << "|";
	cout << setw(10) << "First Name" << "|";
	cout << setw(10) << "Last Name" << "|";
	cout << setw(10) << "Nickname" << "|" << endl;
	cout << "|----------|----------|----------|----------|" << endl;

	for (int i = 0; i < this->count; i++)
	{
		string	fname = this->contacts[i].getFirstName();
		string	lname = this->contacts[i].getLastName();
		string	nname = this->contacts[i].getNickname();

		if (fname.length() > 10)
			fname = fname.substr(0, 9) + ".";
		if (lname.length() > 10)
			lname = lname.substr(0, 9) + ".";
		if (nname.length() > 10)
			nname = nname.substr(0, 9) + ".";

		cout << "|" << setw(10) << i << "|";
		cout << setw(10) << fname << "|";
		cout << setw(10) << lname << "|";
		cout << setw(10) << nname << "|" << endl;
	}
	
	cout << "\nEnter index: ";
	getline(cin, input);

	if (input.empty())
	{
		cout << "Error: Invalid index!" << endl;
		return ;
	}

	for (size_t i = 0; i < input.length(); i++)
	{
		if (!std::isdigit(input[i]))
		{
			cout << "Error: Index must be a number!" << endl;
			return ;
		}
	}

	index = std::atoi(input.c_str());

	if (index < 0 || index >= this->count)
	{
		cout << "Error: Index out of range!" << endl;
		return ;
	}

	cout << "\n=== CONTACT DETAILS ===" << endl;
	cout << "First name: " << this->contacts[index].getFirstName() << endl;
	cout << "Last name: " << this->contacts[index].getLastName() << endl;
	cout << "Nickname: " << this->contacts[index].getNickname() << endl;
	cout << "Phone number: " << this->contacts[index].getPhoneNumber() << endl;
	cout << "Darkest secret: " << this->contacts[index].getDarkestSecret() << endl;
}