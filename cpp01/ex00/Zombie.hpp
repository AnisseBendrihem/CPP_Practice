/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:53:49 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/25 21:58:03 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class Zombie
{
    private :
        std::string _name;
    public :
        Zombie(std::string name) ;
        ~Zombie();
        void announce();
};
Zombie* newZombie(std::string name);
void randomChump(std::string name);


#endif