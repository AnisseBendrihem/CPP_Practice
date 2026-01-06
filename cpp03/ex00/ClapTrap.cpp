/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:50:32 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/06 14:41:37 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string newName) : _Name(newName)
{
    std::cout<<"Initialise " <<_Name <<std::endl;
    _Hp = 10;
    _Mp = 10;
    _Ad = 0;
}
ClapTrap::~ClapTrap()
{
    std::cout<<"Destruction " <<_Name <<std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (_Hp <= 0)
    {
        std::cout << "ClapTrap " << _Name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (_Mp <= 0)
    {
        std::cout << "ClapTrap " << _Name << " has no energy left to attack!" << std::endl;
        return;
    }
    _Mp--;
    std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing " << _Ad << " points of damage!" << std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
    if (_Hp <= 0)
    {
        std::cout << _Name << " is already dead!" << std::endl;
        return;
    }
    _Hp -= amount;
    if (_Hp < 0)
        _Hp = 0;
    std::cout << _Name << " lost " << amount << " Hp, he has now " << _Hp << " left" << std::endl;
} 
void ClapTrap::beRepaired(unsigned int amount)
{
    if (_Hp <= 0)
    {
        std::cout << _Name << " is dead and cannot repair!" << std::endl;
        return;
    }
    if (_Mp <= 0)
    {
        std::cout << _Name << " has no energy left to repair!" << std::endl;
        return;
    }
    _Mp--;
    _Hp += amount;
    std::cout << _Name << " repaired himself, he has now " << _Hp << " hp" << std::endl;
}
