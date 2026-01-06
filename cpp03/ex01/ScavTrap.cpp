/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:00:00 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/06 19:41:44 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    this->_Hp = 100;
    this->_Mp = 50;
    this->_Ad = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName)
{
    this->_Hp = 100;
    this->_Mp = 50;
    this->_Ad = 20;
    std::cout << "ScavTrap " << this->_Name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copieWanted) : ClapTrap(copieWanted)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = copieWanted;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &copieWanted)
{
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &copieWanted)
    {
        this->_Name = copieWanted._Name;
        this->_Hp = copieWanted._Hp;
        this->_Mp = copieWanted._Mp;
        this->_Ad = copieWanted._Ad;
    }
    return *this;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap " << this->_Name << " destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if (this->_Hp <= 0)
    {
        std::cout << "ScavTrap " << this->_Name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (this->_Mp <= 0)
    {
        std::cout << "ScavTrap " << this->_Name << " has no energy left to attack!" << std::endl;
        return;
    }
    this->_Mp--;
    std::cout << "ScavTrap " << this->_Name << " attacks " << target << ", causing " << this->_Ad << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
    std::cout << "ScavTrap " << this->_Name << " is now in Gate keeper mode" << std::endl;
}