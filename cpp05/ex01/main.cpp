/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 00:18:36 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/14 03:04:23 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "bureaucrat and form test" << std::endl;
	try
	{
		Bureaucrat killian("killian", 5);
		Bureaucrat piw("piw", 50);
		Bureaucrat dorain("dorain", 149);
		Bureaucrat hamid("hamid", 1);

		Form form1("form1", 10, 20);
		Form form2("form2", 45, 60);
		Form form3("form3", 1, 1);

		std::cout << killian << std::endl;
		std::cout << piw << std::endl;
		std::cout << dorain << std::endl;
		std::cout << hamid << std::endl;

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << "\nworking sign test" << std::endl;
	try
	{
		Bureaucrat killian("killian", 5);
		Form form1("form1", 10, 20);

		killian.signForm(form1);
		std::cout << form1 << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << "\ngrade too low to sign test" << std::endl;
	try
	{
		Bureaucrat piw("piw", 50);
		Form form2("form2", 45, 60);

		piw.signForm(form2);
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << "\ninvalid form grade too high test" << std::endl;
	try
	{
		Form invalidForm("invalid_form", 0, 10);
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << "\ninvalid form grade too low test" << std::endl;
	try
	{
		Form invalidForm("invalid_form", 10, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	return 0;
}
