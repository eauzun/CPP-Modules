/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myAwesomePhoneBook.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 14:28:17 by emuzun            #+#    #+#             */
/*   Updated: 2026/02/16 14:29:40 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myAwesomePhoneBook.hpp"

/*
** ============================================================================
** MAIN: Program giriş noktası
** ============================================================================
** Minishell'deki main loop gibi:
** - PhoneBook instance yarat (stack'te, malloc yok!)
** - Sonsuz döngü: komut bekle
** - ADD / SEARCH / EXIT işle
*/
int	main(void)
{
	PhoneBook	pb;
	string		cmd;

	cout << "\n*** MY AWESOME PHONEBOOK ***" << endl;
	cout << "Commands: ADD, SEARCH, EXIT" << endl;

	while (1)
	{
		cout << "\n> ";
		
		// Komut oku (EOF kontrolü ile)
		if (!getline(cin, cmd))
		{
			cout << "\nExiting..." << endl;
			break ;
		}

		// Boş satır → ignore
		if (cmd.empty())
			continue ;

		// Komut işle
		if (cmd == "ADD")
			pb.add();
		else if (cmd == "SEARCH")
			pb.search();
		else if (cmd == "EXIT")
		{
			cout << "Goodbye!" << endl;
			break ;
		}
		else
			cout << "Unknown command. Try: ADD, SEARCH, EXIT" << endl;
	}

	return (0);
}