/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 16:19:55 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/25 20:28:19 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <list>
#include <sstream>
#include <cstdlib>

class RPN
{
	private:
		std::stack<int, std::list<int> > _stack;

		bool isOperator(const std::string &token) const;
		int calcul(int a, int b, char op) const;

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		
		int motherCalcul(const std::string &expression);
};

#endif