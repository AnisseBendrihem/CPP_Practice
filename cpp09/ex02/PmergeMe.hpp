/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 18:45:00 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/26 02:21:51 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <set>
#include <stdexcept>
#include <string>
#include <sys/time.h>
#include <utility>
#include <vector>

class PmergeMe
{
private:
	std::vector<int>	_vec;
	std::deque<int>		_deq;

	// Validation
	bool				_isNumber(const std::string &s) const;
	int					_toInt(const std::string &s) const;

	// Jacobsthal
	std::vector<size_t>	_getJacobOrder(size_t n) const;

	// Tri Ford-Johnson
	template <typename T>
	void				_sort(T &c);

	template <typename T>
	void				_insert(T &c, int val, int limit);

public:
	PmergeMe();
	PmergeMe(const PmergeMe &src);
	PmergeMe &operator=(const PmergeMe &src);
	~PmergeMe();

	void	parse_andfill(int ac, char **av);
	void	printTime(double tVec, double tDeq) const;

	std::vector<int>	&getVec();
	std::deque<int>		&getDeq();

	template <typename T>
	void	print(const std::string &prefix, const T &c) const;

	template <typename T>
	double	sort(T &c);
};

// Print template - affiche n'importe quel conteneur
template <typename T>
void PmergeMe::print(const std::string &prefix, const T &c) const
{
	std::cout << prefix;
	for (typename T::const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << " " << *it;
	std::cout << std::endl;
}

template <typename T>
double PmergeMe::sort(T &c)
{
	T tmp = c;
	timeval t1, t2;

	gettimeofday(&t1, NULL);
	_sort(tmp);
	gettimeofday(&t2, NULL);

	c.swap(tmp);
	return (t2.tv_sec - t1.tv_sec) * 1000000.0 + (t2.tv_usec - t1.tv_usec);
}

// Sort template - trie et retourn
// ============================================================================
// TEMPLATES
// ============================================================================

// Insere val a sa place triee (limite de recherche = limit, -1 = fin)
template <typename T>
void PmergeMe::_insert(T &c, int val, int limit)
{
	typename T::iterator end = c.end();

	if (limit != -1)
	{
		for (typename T::iterator it = c.begin(); it != c.end(); ++it)
		{
			if (*it == limit)
			{
				end = it;
				break;
			}
		}
	}

	typename T::iterator pos = std::lower_bound(c.begin(), end, val);
	c.insert(pos, val);
}

// Algorithme Ford-Johnson simplifie
template <typename T>
void PmergeMe::_sort(T &c)
{
	if (c.size() <= 1)
		return;

	// 1. Creer les paires (grand, petit)
	std::vector<std::pair<int, int> > pairs;
	typename T::iterator it = c.begin();
	int odd = -1;
	bool hasOdd = false;

	while (it != c.end())
	{
		int a = *it++;
		if (it == c.end())
		{
			hasOdd = true;
			odd = a;
			break;
		}
		int b = *it++;

		if (a > b)
			pairs.push_back(std::make_pair(a, b));
		else
			pairs.push_back(std::make_pair(b, a));
	}

	// 2. Trier les paires (std::pair compare .first puis .second)
	std::sort(pairs.begin(), pairs.end());

	// 3. Chaine principale = tous les grands
	c.clear();
	for (size_t i = 0; i < pairs.size(); ++i)
		c.push_back(pairs[i].first);

	// 4. Inserer les petits selon Jacobsthal
	_insert(c, pairs[0].second, pairs[0].first);

	std::vector<size_t> order = _getJacobOrder(pairs.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		if (order[i] < pairs.size())
			_insert(c, pairs[order[i]].second, pairs[order[i]].first);
	}

	// 5. Inserer l'element impair
	if (hasOdd)
		_insert(c, odd, -1);
}

#endif
