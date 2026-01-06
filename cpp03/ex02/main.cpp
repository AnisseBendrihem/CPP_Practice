/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:00:00 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/06 19:51:51 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "=== Creation des ClapTraps ===" << std::endl;
    ClapTrap hamid("Hamid");
    ClapTrap piw("Piw");

    std::cout << "\n=== Creation des ScavTraps ===" << std::endl;
    ScavTrap robot("Robot");

    std::cout << "\n=== Creation des FragTraps ===" << std::endl;
    FragTrap monster("Monster");
    FragTrap beast("Beast");

    std::cout << "\n=== Test attaque ClapTrap (0 degats) ===" << std::endl;
    hamid.attack("Piw");
    piw.takeDamage(0);

    std::cout << "\n=== Test attaque ScavTrap (20 degats) ===" << std::endl;
    robot.attack("Monster");
    monster.takeDamage(20);

    std::cout << "\n=== Test attaque FragTrap (30 degats) ===" << std::endl;
    monster.attack("Beast");
    beast.takeDamage(30);

    std::cout << "\n=== Test reparation FragTrap ===" << std::endl;
    beast.beRepaired(15);

    std::cout << "\n=== Test guardGate (ScavTrap) ===" << std::endl;
    robot.guardGate();

    std::cout << "\n=== Test highFivesGuys (FragTrap) ===" << std::endl;
    monster.highFivesGuys();
    beast.highFivesGuys();

    std::cout << "\n=== Test mort (Beast prend 200 degats) ===" << std::endl;
    beast.takeDamage(200);
    beast.attack("Monster");
    beast.beRepaired(10);

    std::cout << "\n=== Destruction ===" << std::endl;
    return 0;
}
