/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:40:55 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/09 01:26:32 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== Test with abstract class ===" << std::endl;
    const AAnimal* hamid = new Dog();
    const AAnimal* piwpiw = new Cat();

    std::cout << std::endl;
    std::cout << "Type of hamid: " << hamid->getType() << std::endl;
    std::cout << "Type of piwpiw: " << piwpiw->getType() << std::endl;

    std::cout << std::endl;
    hamid->makeSound();
    piwpiw->makeSound();

    std::cout << std::endl;
    delete hamid;
    delete piwpiw;

    std::cout << std::endl;
    std::cout << "=== Test array of AAnimals ===" << std::endl;
    AAnimal* animals[4];
    
    for (int k = 0; k < 2; k++)
        animals[k] = new Dog();
    for (int k = 2; k < 4; k++)
        animals[k] = new Cat();

    std::cout << std::endl;
    for (int k = 0; k < 4; k++)
    {
        std::cout << "Animal " << k << " type: " << animals[k]->getType() << std::endl;
        animals[k]->makeSound();
    }

    std::cout << std::endl;
    for (int k = 0; k < 4; k++)
        delete animals[k];

    return 0;
}
