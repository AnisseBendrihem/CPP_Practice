/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:00:00 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/06 19:51:51 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
ClapTrap::ClapTrap() : _Name("default"), _Hp(10), _Mp(10), _Ad(0)
{
    std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copieWanted)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = copieWanted;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &copieWanted)
{
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &copieWanted)
    {
        _Name = copieWanted._Name;
        _Hp = copieWanted._Hp;
        _Mp = copieWanted._Mp;
        _Ad = copieWanted._Ad;
    }
    return *this;
}

ClapTrap::ClapTrap(std::string newName) : _Name(newName), _Hp(10), _Mp(10), _Ad(0)
{
    std::cout << "Initialise " << _Name << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destruction " << _Name << std::endl;
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