/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:40:43 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/09 01:26:46 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>
#include <iostream>

class AAnimal
{
    protected:
        std::string type;
    
    public:
        AAnimal();
        AAnimal(std::string new_type);
        AAnimal(const AAnimal &copieWanted);
        AAnimal& operator=(const AAnimal &copieWanted);
        virtual ~AAnimal();
        virtual void makeSound() const = 0;
        // Je promets que cette méthode existe dans ma famille, 
        // mais je ne donne pas d'implémentation. Mes enfants DOIVENT la donner.
        std::string getType() const;
};

#endif
