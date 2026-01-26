/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:45:02 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/26 02:29:16 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cctype>
#include <sstream>

// ============================================================================
// FORME CANONIQUE
// ============================================================================

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe &src) : _vec(src._vec), _deq(src._deq) {}
PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	if (this != &src)
	{
		_vec = src._vec;
		_deq = src._deq;
	}
	return *this;
}
PmergeMe::~PmergeMe() {}

// ============================================================================
// VALIDATION
// ============================================================================

bool PmergeMe::_isNumber(const std::string &s) const
{
	if (s.empty())
		return false;

	size_t i = 0;
	if (s[0] == '+')
		i = 1;

	if (i == s.size())
		return false;

	for (; i < s.size(); ++i)
	{
		if (!std::isdigit(s[i]))
			return false;
	}
	return true;
}

int PmergeMe::_toInt(const std::string &s) const
{
	std::istringstream iss(s);
	long val = 0;

	iss >> val;
	if (!iss || !iss.eof() || val <= 0 || val > INT_MAX)
		throw std::runtime_error("Error");
	return static_cast<int>(val);
}

// ============================================================================
// JACOBSTHAL
// ============================================================================

// Génère l'ordre d'insertion basé sur la suite de Jacobsthal
// n = nombre d'éléments "pend" à insérer
std::vector<size_t> PmergeMe::_getJacobOrder(size_t n) const
{
	std::vector<size_t> order;          // le contenaire a return
	if (n <= 1)                       
		return order;

	size_t prev = 1;                    // J(k-1) : nombre de Jacobsthal précédent
	size_t curr = 1;                    // J(k)   : nombre de Jacobsthal actuel

	// Parcourt les "groupes" définis par Jacobsthal : 1, 1, 3, 5, 11, 21...
	while (curr < n)
	{
		size_t lim = curr;              // borne haute du groupe actuel
		if (curr > n)                   // si dépasse n, on cap à n
			lim = n;
		// Ajoute les indices du groupe en ordre DÉCROISSANT (de lim à prev+1)
		for (size_t i = lim; i > prev; --i)
			order.push_back(i - 1);     // -1 car indices commencent à 0

		size_t next = curr + 2 * prev;  // formule Jacobsthal : J(k+1) = J(k) + 2*J(k-1)
		prev = curr;                    // décale : prev devient curr
		curr = next;                    // décale : curr devient next
	}

	// Ajoute les indices restants après le dernier groupe de Jacobsthal
	if (prev < n)
	{
		for (size_t i = n; i > prev; --i)
			order.push_back(i - 1);
	}

	return order;                    
}

// ============================================================================
// PARSING
// ============================================================================

void PmergeMe::parse_andfill(int ac, char **av)
{
	std::set<int> seen;

	for (int i = 1; i < ac; ++i)
	{
		std::istringstream iss(av[i]);
		std::string tok;

		while (iss >> tok)
		{
			if (!_isNumber(tok))
				throw std::runtime_error("Error");

			int val = _toInt(tok);

			if (!seen.insert(val).second)
				throw std::runtime_error("Error");

			_vec.push_back(val);
			_deq.push_back(val);
		}
	}

	if (_vec.empty())
		throw std::runtime_error("Error");
}

// ============================================================================
// AFFICHAGE
// ============================================================================

void PmergeMe::printTime(double tVec, double tDeq) const
{
	std::cout << "Time to process a range of " << _vec.size()
	          << " elements with std::vector : " << tVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deq.size()
	          << " elements with std::deque  : " << tDeq << " us" << std::endl;
}

std::vector<int> &PmergeMe::getVec() { return _vec; }
std::deque<int> &PmergeMe::getDeq() { return _deq; }
