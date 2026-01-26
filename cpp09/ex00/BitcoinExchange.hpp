/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 23:31:07 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/25 16:10:30 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

class BitcoinExchange {
private:
    std::map<std::string, double> _database;
    
    bool        _isValidDate(const std::string& date) const;
    double      _parseValue(const std::string& valueStr) const;
    bool        _validateValue(const std::string& valueStr, double value) const;
    std::string _trim(const std::string& str) const;
    
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    void    loadCsv(const std::string& filename);
    void    processTxt(const std::string& filename);
    double  getExchangeRate(const std::string& date) const;
};

#endif
