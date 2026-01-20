/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 00:18:36 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/14 03:02:42 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("shrubbery creation", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("shrubbery creation", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	if (this != &other)
		_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &b) const
{
	if (b.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!isSigned())
		throw FormNotSignedException();
	std::ofstream file((_target + "_shrubbery").c_str());
	file << "    _-_" << std::endl;
	file << "   /(_)\\  " << std::endl;
	file << "  (_/_\\_)" << std::endl;
	file << "   / | \\" << std::endl;
	file << "    | |" << std::endl;
	file.close();
	std::cout << "shrubbery form executed" << std::endl;
}
