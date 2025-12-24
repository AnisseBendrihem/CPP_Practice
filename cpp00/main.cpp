/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 23:44:21 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/24 23:57:44 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

int main ()
{
    phonebook T_phone;
    std::string cmd;
    
    std::cout<< "Bienvenue operateur saisissez les commandes ADD, SEARCH or EXIT" << std::endl;
    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, cmd);
        if (cmd == "ADD")
            T_phone.add_contact();
        else if (cmd == "SEARCH")
            T_phone.search_contact();
        else if (cmd == "EXIT")
            return(0);
        else
            std::cout<< "error : plz entrer ADD, SEARCH or EXIT" << std::endl;
    }
    return (1);
}
