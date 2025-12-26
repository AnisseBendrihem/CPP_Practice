/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 00:07:09 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/26 02:37:32 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string name) : _name(name)
{
    
}

Weapon::~Weapon()
{
    
}

std::string Weapon::getType()
{
    return(_name);
}
void Weapon::setType(std:: string name)
{
    _name = name;
}