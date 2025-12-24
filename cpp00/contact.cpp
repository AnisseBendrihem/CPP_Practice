/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:39:42 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/24 23:21:03 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"

//constreucteur et destructeur
contact::contact()
{
}
contact::~contact()
{
}

//getter
int contact:: get_index()
{
    return(index);
}
std::string contact:: get_first_name()
{
    return(first_name);
}
std::string contact:: get_last_name()
{
    return(last_name);
}
std::string contact:: get_nickname()
{
    return(nickname);
}
std::string contact:: get_phone_number()
{
    return(phone_number);
}
std::string contact:: get_darkest_secret()
{
    return(darkest_secret);
}

//setter
void contact:: set_index(int new_index)
{
    index = new_index;
}
void contact:: set_first_name(std::string new_first_name)
{
    first_name = new_first_name;
}
void contact:: set_last_name(std::string new_last_name)
{
    last_name = new_last_name;
}
void contact:: set_nickname(std::string new_nickname)
{
    nickname = new_nickname;
}
void contact:: set_phone_number(std::string new_phone_number)
{
    phone_number = new_phone_number;
}
void contact:: set_darkest_secret(std::string new_darkest_secret)
{
    darkest_secret = new_darkest_secret;
}
