/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myAwesomePhoneBook.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:28:31 by emuzun            #+#    #+#             */
/*   Updated: 2026/02/16 14:38:26 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYAWESOMEPHONEBOOK_HPP
# define MYAWESOMEPHONEBOOK_HPP

# include <iostream>
# include <string>
# include <iomanip>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::setw;

class Contact
{
private:
	string	firstName;
	string	lastName;
	string	nickname;
	string	phoneNumber;
	string	darkestSecret;

public:
	void	setFirstName(string str);
	void	setLastName(string str);
	void	setNickname(string str);
	void	setPhoneNumber(string str);
	void	setDarkestSecret(string str);

	string	getFirstName(void);
	string	getLastName(void);
	string	getNickname(void);
	string	getPhoneNumber(void);
	string	getDarkestSecret(void);
};

class PhoneBook
{
private:
	Contact	contacts[8];
	int		oldest;
	int		count;

public:
	PhoneBook(void);
	void	add(void);
	void	search(void);
};

#endif