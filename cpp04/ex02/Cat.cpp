/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:40:46 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/08 23:03:25 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat")
{
    std::cout << "Cat default constructor called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const Cat &copieWanted) : AAnimal(copieWanted)
{
    std::cout << "Cat copy constructor called" << std::endl;
    this->brain = new Brain(*copieWanted.brain);
}

Cat& Cat::operator=(const Cat &copieWanted)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &copieWanted)
    {
        AAnimal::operator=(copieWanted);
        delete this->brain;
        this->brain = new Brain(*copieWanted.brain);
    }
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
    delete this->brain;
}

void Cat::makeSound() const
{
    std::cout << "Meow! Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
    return this->brain;
}
