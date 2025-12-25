/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 01:52:52 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/25 21:53:07 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie patien1("foo");
    Zombie *clone = newZombie("ZOO");
    randomChump("choo");

    patien1.announce();
    clone->announce();
    delete clone;
}
