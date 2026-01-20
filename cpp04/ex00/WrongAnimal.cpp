/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:41:00 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/08 23:03:25 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string new_type) : type(new_type)
{
    std::cout << "WrongAnimal parameterized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copieWanted)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = copieWanted;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copieWanted)
{
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    if(this != &copieWanted)
    {
        this->type = copieWanted.type;
    }
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal makes a generic sound..." << std::endl;
}

std::string WrongAnimal::getType() const
{
    return this->type;
}