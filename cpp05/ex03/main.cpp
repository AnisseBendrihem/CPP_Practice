/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 00:18:36 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/14 03:02:42 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << "ex03 test with intern creating forms" << std::endl;
	
	Intern intern;
	Bureaucrat killian("killian", 5);
	Bureaucrat piw("piw", 72);
	Bureaucrat dorain("dorain", 145);

	std::cout << "\nform creation with intern" << std::endl;
	try
	{
		AForm *form1 = intern.makeForm("presidential pardon", "tutu");
		AForm *form2 = intern.makeForm("robotomy request", "toto");
		AForm *form3 = intern.makeForm("shrubbery creation", "garden");

		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;

		std::cout << "\nsign test" << std::endl;
		killian.signForm(*form1);
		piw.signForm(*form2);
		dorain.signForm(*form3);

		std::cout << "\nexecute test" << std::endl;
		killian.executeForm(*form1);
		piw.executeForm(*form2);
		dorain.executeForm(*form3);

		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	std::cout << "\nunknown form test" << std::endl;
	try
	{
		AForm *unknownForm = intern.makeForm("unknown form", "test");
		delete unknownForm;
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	return 0;
}
