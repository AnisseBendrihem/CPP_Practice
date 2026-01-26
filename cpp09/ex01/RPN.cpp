/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:19:55 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/25 20:31:17 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//==============================================================================
RPN::RPN() {}
RPN::RPN(const RPN &other) : _stack(other._stack) {}
RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}
RPN::~RPN() {}

//===============================================================================
bool RPN::isOperator(const std::string &token) const
{
	return (token == "+" || token == "-" || token == "*" || token == "/");
}

int RPN::calcul(int a, int b, char op) const
{
	switch (op)
	{
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '*':
			return a * b;
		case '/':
			if (b == 0)
				throw std::runtime_error("Error: division by zero");
			return a / b;
		default:
			throw std::runtime_error("Error: unknown operator");
	}
}

int RPN::motherCalcul(const std::string &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.length() == 1 && std::isdigit(token[0]))
			_stack.push(token[0] - '0');
		else if (isOperator(token))
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			int b = _stack.top(); // insere le premier dans b 
			_stack.pop();  // puis on le degage 
			int a = _stack.top(); // insere le dexieme dans a 
			_stack.pop(); //puis on degage 
			int result = calcul(a, b, token[0]);
			_stack.push(result);
		}
		else
			throw std::runtime_error("Error");
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");

	return _stack.top();
}
