/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 02:01:51 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/25 21:46:40 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name) :_name(name)
{ 
    
}
 Zombie::~Zombie()
{
    
}
void Zombie::announce()
{
    std::cout<< _name << ": BraiiiiiiinnnzzzZ..."<< std::endl;
}
