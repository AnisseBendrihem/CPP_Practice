/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:40:50 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/08 23:03:25 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog")
{
    std::cout << "Dog default constructor called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog &copieWanted) : AAnimal(copieWanted)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->brain = new Brain(*copieWanted.brain);
}

Dog& Dog::operator=(const Dog &copieWanted)
{
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &copieWanted)
    {
        AAnimal::operator=(copieWanted);
        delete this->brain;
        this->brain = new Brain(*copieWanted.brain);
    }
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
    delete this->brain;
}

void Dog::makeSound() const
{
    std::cout << "Woof! Woof!" << std::endl;
}

Brain* Dog::getBrain() const
{
    return this->brain;
}
