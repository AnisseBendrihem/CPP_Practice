/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 13:50:35 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/06 14:47:00 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== Creation des ClapTraps ===" << std::endl;
    ClapTrap hamid("Hamid");
    ClapTrap piw("Piw");

    std::cout << "\n=== Test attaque et degats ===" << std::endl;
    hamid.attack("Piw");
    piw.takeDamage(0);

    std::cout << "\n=== Test reparation ===" << std::endl;
    piw.beRepaired(5);

    std::cout << "\n=== Test mort (Piw prend 20 degats) ===" << std::endl;
    piw.takeDamage(20);
    piw.attack("Hamid");
    piw.beRepaired(10);

    std::cout << "\n=== Test epuisement energie (Hamid fait 10 actions) ===" << std::endl;
    for (int i = 0; i < 10; i++)
        hamid.attack("Piw");
    std::cout << "\n=== Hamid essaie d'agir sans energie ===" << std::endl;
    hamid.attack("Piw");
    hamid.beRepaired(5);

    std::cout << "\n=== Destruction ===" << std::endl;
    return 0;
}