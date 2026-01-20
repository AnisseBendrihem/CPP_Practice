/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:40:37 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/08 23:03:25 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string new_type) : type(new_type)
{
    std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal::Animal(const Animal &copieWanted)
{
    std::cout << "Animal copy constructor called" << std::endl;
    *this = copieWanted;
}

Animal& Animal::operator=(const Animal &copieWanted)
{
    std::cout << "Animal assignment operator called" << std::endl;
    if(this != &copieWanted)
    {
        this->type = copieWanted.type;
    }
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
    std::cout << "Animal makes a generic sound..." << std::endl;
}

std::string Animal::getType() const
{
    return this->type;
}