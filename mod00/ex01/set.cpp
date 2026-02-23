/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 20:48:21 by emuzun            #+#    #+#             */
/*   Updated: 2026/02/16 14:29:45 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myAwesomePhoneBook.hpp"

void	Contact::setFirstName(string str)
{
	this->firstName = str;
}

void	Contact::setLastName(string str)
{
	this->lastName = str;
}

void	Contact::setNickname(string str)
{
	this->nickname = str;
}

void	Contact::setPhoneNumber(string str)
{
	this->phoneNumber = str;
}

void	Contact::setDarkestSecret(string str)
{
	this->darkestSecret = str;
}