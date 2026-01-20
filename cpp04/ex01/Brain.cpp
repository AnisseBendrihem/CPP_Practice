/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:40:37 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/08 23:03:25 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain default constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = "Empty idea";
}

Brain::Brain(const Brain &copieWanted)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = copieWanted;
}

Brain& Brain::operator=(const Brain &copieWanted)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if (this != &copieWanted)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = copieWanted.ideas[i];
    }
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}
