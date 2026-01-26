/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:45:04 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/26 01:37:11 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try
	{
		PmergeMe pm;

		pm.parse(ac, av);
		pm.print("Before:", pm.getVec());

		double tVec = pm.sort(pm.getVec());
		double tDeq = pm.sort(pm.getDeq());

		pm.print("After:", pm.getVec());
		pm.printTime(tVec, tDeq);
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
