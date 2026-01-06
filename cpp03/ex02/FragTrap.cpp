/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:00:00 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/06 19:51:51 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
FragTrap::FragTrap() : ClapTrap()
{
    this->_Hp = 100;
    this->_Mp = 100;
    this->_Ad = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string newName) : ClapTrap(newName)
{
    this->_Hp = 100;
    this->_Mp = 100;
    this->_Ad = 30;
    std::cout << "FragTrap " << this->_Name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copieWanted) : ClapTrap(copieWanted)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = copieWanted;
}

FragTrap& FragTrap::operator=(const FragTrap &copieWanted)
{
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &copieWanted)
    {
        this->_Name = copieWanted._Name;
        this->_Hp = copieWanted._Hp;
        this->_Mp = copieWanted._Mp;
        this->_Ad = copieWanted._Ad;
    }
    return *this;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap " << this->_Name << " destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << this->_Name << " requests a high five!" << std::endl;
}