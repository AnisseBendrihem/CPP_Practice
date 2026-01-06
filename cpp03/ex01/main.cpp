/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:00:00 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/06 19:41:44 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    std::cout << "=== Creation des ClapTraps ==" << std::endl;
    ClapTrap hamid("Hamid");
    ClapTrap piw("Piw");

    std::cout << "\n=== Creation des ScavTraps ===" << std::endl;
    ScavTrap robot("Robot");
    ScavTrap terminator("Terminator");

    std::cout << "\n=== Test attaque ClapTrap ===" << std::endl;
    hamid.attack("Piw");
    piw.takeDamage(0);

    std::cout << "\n=== Test attaque ScavTrap (20 degats) ===" << std::endl;
    robot.attack("Terminator");
    terminator.takeDamage(20);

    std::cout << "\n=== Test reparation ScavTrap ===" << std::endl;
    terminator.beRepaired(10);

    std::cout << "\n=== Test guardGate ===" << std::endl;
    robot.guardGate();
    terminator.guardGate();

    std::cout << "\n=== Test mort (Terminator prend 200 degats) ===" << std::endl;
    terminator.takeDamage(200);
    terminator.attack("Robot");
    terminator.beRepaired(10);

    std::cout << "\n=== Destruction ===" << std::endl;
    return 0;
}
