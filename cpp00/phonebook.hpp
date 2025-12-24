/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:39:14 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/25 00:38:08 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include "contact.hpp"

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

class phonebook
{
    private:
        contact array_contact[2];
        int i;
        int count;
    public:
        phonebook();
        ~phonebook();         
        void add_contact();
        void search_contact();
};

#endif