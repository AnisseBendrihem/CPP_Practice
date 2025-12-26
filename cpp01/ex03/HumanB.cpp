/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 00:06:50 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/26 03:52:05 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    _name = name;
}

HumanB::~HumanB()
{
}

std::string HumanB::getName()
{
    return(_name);
}
void HumanB::setName(std:: string name)
{
    _name = name;
}
void HumanB::setWeapon(Weapon &w)
{
    _weapon = &w;
}

void HumanB::attack()
{
    std::cout <<_name << "attacks with their" << _weapon->getType()<< std::endl;
}
