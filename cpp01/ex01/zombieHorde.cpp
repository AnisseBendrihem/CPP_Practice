/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 22:08:22 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/25 23:21:06 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *clone = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        clone[i].setName(name);
        clone[i].announce(i);
    }
    return(clone);
}