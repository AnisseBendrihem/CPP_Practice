/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 00:18:36 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/14 03:23:09 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::cout << "ex02 test with abstract forms" << std::endl;
	
	try
	{
		Bureaucrat killian("killian", 5);
		Bureaucrat piw("piw", 72);
		Bureaucrat dorain("dorain", 145);

		PresidentialPardonForm form1("tutu");
		RobotomyRequestForm form2("toto");
		ShrubberyCreationForm form3("garden");

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl;

		std::cout << "\nsign test" << std::endl;
		killian.signForm(form1);
		piw.signForm(form2);
		dorain.signForm(form3);

		std::cout << "\nexecute form test" << std::endl;
		killian.executeForm(form1);
		piw.executeForm(form2);
		dorain.executeForm(form3);
	}
	catch (std::exception &e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}

	return 0;
}
