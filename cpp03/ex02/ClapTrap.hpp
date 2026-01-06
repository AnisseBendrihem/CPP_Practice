/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:00:00 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/06 19:51:51 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
    protected:
        std::string _Name;
        int _Hp;
        int _Mp;
        int _Ad;
    
    public:
        ClapTrap();
        ClapTrap(std::string newName);
        ClapTrap(const ClapTrap &copieWanted);
        ClapTrap& operator=(const ClapTrap &copieWanted);
        ~ClapTrap();
    
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
    
};

#endif
