/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 00:22:32 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/25 00:52:26 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"


phonebook::phonebook()
{
    std::cout <<"initialisatuin du phonebook" << std::endl;
    i = 0;
    count = 0;
}

phonebook::~phonebook()
{
    std::cout <<"desintegration du phonebook" << std::endl;
}

void phonebook:: add_contact()
{
    array_contact[i].set_index(i);
    std::string buffer;
    std::cout<< "First name :> ";
    std::getline(std::cin,buffer);
    array_contact[i].set_first_name(buffer);
    std::cout<< "Last name :> ";
    std::getline(std::cin,buffer);
    array_contact[i].set_last_name(buffer);
    std::cout<< "Nick name :> ";
    std::getline(std::cin,buffer);
    array_contact[i].set_nickname(buffer);
    std::cout<< "Phone :> ";
    std::getline(std::cin,buffer);
    array_contact[i].set_phone_number(buffer);
    std::cout<< "Darkest secre :> ";
    std::getline(std::cin,buffer);
    array_contact[i].set_darkest_secret(buffer);    
    i = (i + 1) % 2;
    if (count < 2)
        count++;
}

void phonebook:: search_contact()
{
    for (int j = 0 ; j < count; j++)
    {        
        std::cout <<  "voci le contacte numero: " << j<< std::endl; 

        std::cout << array_contact[j].get_index() <<std::endl;
        std::cout << array_contact[j].get_first_name() <<std::endl;
        std::cout << array_contact[j].get_last_name() <<std::endl;
        std::cout << array_contact[j].get_nickname() <<std::endl;
        std::cout << array_contact[j].get_phone_number() <<std::endl;
        std::cout << array_contact[j].get_darkest_secret() <<std::endl;
    }
}