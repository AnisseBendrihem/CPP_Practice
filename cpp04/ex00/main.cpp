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
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "=== Test with Animal (polymorphism works) ===" << std::endl;
    const Animal* hamid = new Animal();
    const Animal* piwpiw = new Dog();
    const Animal* mamumi = new Cat();

    std::cout << std::endl;
    std::cout << "Type of piwpiw: " << piwpiw->getType() << std::endl;
    std::cout << "Type of mamumi: " << mamumi->getType() << std::endl;

    std::cout << std::endl;
    mamumi->makeSound();
    piwpiw->makeSound();
    hamid->makeSound();

    std::cout << std::endl;
    delete hamid;
    delete piwpiw;
    delete mamumi;

    std::cout << std::endl;
    std::cout << "=== Test with WrongAnimal (no polymorphism) ===" << std::endl;
    const WrongAnimal* dorian = new WrongAnimal();
    const WrongAnimal* killian = new WrongCat();

    std::cout << std::endl;
    std::cout << "Type of killian: " << killian->getType() << std::endl;

    std::cout << std::endl;
    killian->makeSound();
    dorian->makeSound();

    std::cout << std::endl;
    delete dorian;
    delete killian;

    return 0;
}