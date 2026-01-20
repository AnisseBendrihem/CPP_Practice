/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:40:37 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/09 01:25:38 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
    std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string new_type) : type(new_type)
{
    std::cout << "AAnimal parameterized constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copieWanted)
{
    std::cout << "AAnimal copy constructor called" << std::endl;
    *this = copieWanted;
}

AAnimal& AAnimal::operator=(const AAnimal &copieWanted)
{
    std::cout << "AAnimal assignment operator called" << std::endl;
    if(this != &copieWanted)
    {
        this->type = copieWanted.type;
    }
    return *this;
}

AAnimal::~AAnimal()
{
    std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
    return this->type;
}


