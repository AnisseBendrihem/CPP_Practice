/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 22:09:28 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/25 23:21:06 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class Zombie
{
    private:
        std::string _name;
    
    public:
        Zombie();
        ~Zombie();
        void announce(int n);    
        void setName(std::string name);    
};

Zombie* zombieHorde( int N, std::string name );
#endif