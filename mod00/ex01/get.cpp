/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 20:47:52 by emuzun            #+#    #+#             */
/*   Updated: 2026/02/16 14:39:25 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myAwesomePhoneBook.hpp"

string	Contact::getFirstName(void)
{
	return (this->firstName);
}

string	Contact::getLastName(void)
{
	return (this->lastName);
}

string	Contact::getNickname(void)
{
	return (this->nickname);
}

string	Contact::getPhoneNumber(void)
{
	return (this->phoneNumber);
}

string	Contact::getDarkestSecret(void)
{
	return (this->darkestSecret);
}