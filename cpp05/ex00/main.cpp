/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 23:49:52 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/14 03:02:42 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "valid bureaucrat creation test" << std::endl;
	try
	{
		Bureaucrat killian("killian", 50);
		std::cout << killian << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	std::cout << "\ngrade too high test (0)" << std::endl;
	try
	{
		Bureaucrat piw("piw", 0);
		std::cout << piw << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << "\ngrade too low test (151)" << std::endl;
	try
	{
		Bureaucrat dorain("dorain", 151);
		std::cout << dorain << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << "\nincrement grade test" << std::endl;
	try
	{
		Bureaucrat hamid("hamid", 2);
		std::cout << hamid << std::endl;
		hamid.incrementGrade();
		std::cout << "after increment: " << hamid << std::endl;
		hamid.incrementGrade();
		std::cout << "after increment: " << hamid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << "\ndecrement grade test" << std::endl;
	try
	{
		Bureaucrat eve("eve", 149);
		std::cout << eve << std::endl;
		eve.decrementGrade();
		std::cout << "after decrement: " << eve << std::endl;
		eve.decrementGrade();
		std::cout << "after decrement: " << eve << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << "\ncopy constructor test" << std::endl;
	try
	{
		Bureaucrat frank("frank", 75);
		Bureaucrat frankCopy(frank);
		std::cout << "original: " << frank << std::endl;
		std::cout << "copy: " << frankCopy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	return 0;
}
