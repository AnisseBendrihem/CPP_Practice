/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 21:40:55 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/08 23:11:10 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== Test basic creation and destruction ===" << std::endl;
    const Animal* piwpiw = new Dog();
    const Animal* mamumi = new Cat();

    std::cout << std::endl;
    delete piwpiw;
    delete mamumi;

    std::cout << std::endl;
    std::cout << "=== Test array of Animals ===" << std::endl;
    Animal* animals[4];
    
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

    std::cout << std::endl;
    std::cout << "=== Test deep copy ===" << std::endl;
    Dog originalDog;
    originalDog.getBrain()->ideas[0] = "I want to play!";
    originalDog.getBrain()->ideas[1] = "I want to eat!";

    Dog copyDog(originalDog);

    std::cout << std::endl;
    std::cout << "Original dog idea 0: " << originalDog.getBrain()->ideas[0] << std::endl;
    std::cout << "Copy dog idea 0: " << copyDog.getBrain()->ideas[0] << std::endl;

    copyDog.getBrain()->ideas[0] = "I want to sleep!";

    std::cout << std::endl;
    std::cout << "After modifying copy:" << std::endl;
    std::cout << "Original dog idea 0: " << originalDog.getBrain()->ideas[0] << std::endl;
    std::cout << "Copy dog idea 0: " << copyDog.getBrain()->ideas[0] << std::endl;

    std::cout << std::endl;
    return 0;
}
