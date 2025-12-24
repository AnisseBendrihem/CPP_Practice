/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:10:45 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/25 00:37:41 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

#ifndef CONTACT_HPP
#define CONTACT_HPP

class contact
{
    private:
        int index;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
        
    public:
        //constreucteur et destructeur
        contact();
        ~contact();
        //getter
        int  get_index();
        std::string  get_first_name();
        std::string  get_last_name();
        std::string  get_nickname();
        std::string  get_phone_number();
        std::string  get_darkest_secret();
        //setter
        void set_index(int new_index);
        void set_first_name(std::string new_first_name);
        void set_last_name(std::string new_last_name);
        void set_nickname(std::string new_nickname);
        void set_phone_number(std::string new_phone_number);
        void set_darkest_secret(std::string new_darkest_secret);
        
};

#endif