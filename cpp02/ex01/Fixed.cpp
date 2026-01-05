/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:30:55 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/05 19:23:23 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
    std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed(const int n) : _value(n * 256)
// Version avec bitshift : _value(n << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}


Fixed::Fixed(const float n) : _value(roundf(n * 256))
// Version avec bitshift : _value(roundf(n * (1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
    return this->_value;
}

void Fixed::setRawBits(int const raw)
{
    this->_value = raw;
}


float Fixed::toFloat(void) const
{
    // return (float)this->_value / 256; version normale
    return (float)this->_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_value / 256;
    // return this->_value >> _fractionalBits; version de mec qui se la pete
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
