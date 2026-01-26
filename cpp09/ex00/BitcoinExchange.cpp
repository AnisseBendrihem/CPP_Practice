/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 23:31:03 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/25 16:03:18 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

//=============================================================================================
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other): _database(other._database) {}
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

//=============================================================================================

bool BitcoinExchange::_isValidDate(const std::string& date) const
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (size_t i = 0; i < date.length(); ++i)
    {
        if (i == 4 || i == 7)
            continue;
        if (date[i] < '0' || date[i] > '9')
            return false;
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
        return false;

    if (day < 1)
        return false;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}
double BitcoinExchange::_parseValue(const std::string& valueStr) const
{
    std::stringstream ss(valueStr);
    double value;

    if (!(ss >> value))
        return -1;

    std::string remaining;
    ss >> remaining;
    if (!remaining.empty())
        return -1;

    return value;
}
bool BitcoinExchange::_validateValue(const std::string& valueStr, double value) const
{
    if (!valueStr.empty() && valueStr[0] == '-')
    {
        std::cerr << "Error: not a positive number." << std::endl;
        return false;
    }
    if (value == -1)
    {
        std::cerr << "Error: bad input => " << valueStr << std::endl;
        return false;
    }
    if (value > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return false;
    }

    return true;
}

std::string BitcoinExchange::_trim(const std::string& str) const
{
    size_t start = str.find_first_not_of(" \t");
    size_t end = str.find_last_not_of(" \t");

    if (start == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

//===================================================================================

void BitcoinExchange::loadCsv(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open database file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t comma_pos = line.find(',');
        if (comma_pos == std::string::npos)
            continue;

        std::string date = line.substr(0, comma_pos);
        std::string value_str = line.substr(comma_pos + 1);

        std::stringstream ss(value_str);
        double value;
        if (!(ss >> value))
            continue;

        _database[date] = value;
    }
    file.close();
}

void BitcoinExchange::processTxt(const std::string& filename)
{
    std::ifstream file(filename.c_str());

    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line);

    while (std::getline(file, line))
    {
        size_t pipe_pos = line.find('|');
        if (pipe_pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = _trim(line.substr(0, pipe_pos));
        std::string value_str = _trim(line.substr(pipe_pos + 1));

        if (!_isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        double value = _parseValue(value_str);

        if (!_validateValue(value_str, value))
            continue;

        double rate = getExchangeRate(date);
        if (rate == -1)
            continue;

        double result = value * rate;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
    file.close();
}

double BitcoinExchange::getExchangeRate(const std::string& date) const
{
    std::map<std::string, double>::const_iterator it = _database.find(date);

    if (it != _database.end())
        return it->second;

    it = _database.lower_bound(date);

    if (it == _database.begin())
    {
        std::cerr << "Error: date too early (before database start)." << std::endl;
        return -1;
    }
    --it;
    return it->second;
}
