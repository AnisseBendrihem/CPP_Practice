/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 00:07:15 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/26 02:38:00 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include "iostream"

#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon
{
    private :
        std::string _name;
    public :
        Weapon(std::string name);
        ~Weapon();
        std::string getType();
        void setType(std:: string name);
};
#endif
