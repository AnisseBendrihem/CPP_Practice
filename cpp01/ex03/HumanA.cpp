/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 00:06:44 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/26 01:58:13 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &mendatory) : _weapon(mendatory)
{
    _name = name;
}

HumanA::~HumanA()
{
}

std::string HumanA::getName()
{
    return(_name);
}

void HumanA::setName(std:: string name)
{
    _name = name;
}

void HumanA::attack()
{
    std::cout <<_name << "attacks with their" << _weapon.getType()<< std::endl;
}
