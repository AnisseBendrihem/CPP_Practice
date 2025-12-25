/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 23:29:52 by abendrih          #+#    #+#             */
/*   Updated: 2025/12/25 23:59:49 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main ()
{
    std::string brain = "HI THIS IS BRAIN";
    std::string *stringPTR = &brain;
    std::string &stringREF = brain;

    std::cout << "Address of brain:     " << &brain << std::endl;
    std::cout << "Address in stringPTR: " << stringPTR << std::endl;
    std::cout << "Address of stringREF: " << &stringREF << std::endl;

    std::cout << "Value of brain:       " << brain << std::endl;
    std::cout << "Value of stringPTR:   " << *stringPTR << std::endl;
    std::cout << "Value of stringREF:   " << stringREF << std::endl;

    return 0;
}