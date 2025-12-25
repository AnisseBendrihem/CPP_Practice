/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 22:14:43 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/25 23:26:20 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    std::cout <<"creation"<< std::endl;
}
Zombie::~Zombie()
{
    std::cout <<"destruction"<< std::endl;
}
void Zombie::setName(std::string name)
{
    _name = name;
}

void Zombie::announce(int n)
{
    std::cout<<"Hello Ladys le me indtroduce my self as "<< _name<< n<<std::endl;
}  