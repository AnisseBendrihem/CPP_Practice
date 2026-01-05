/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:26:38 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/05 19:41:40 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// ============== CONSTRUCTEURS ET DESTRUCTEUR ==============

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int n) : _value(n << _fractionalBits) {}

Fixed::Fixed(const float n) : _value(roundf(n * (1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed &other) 
{ 
    *this = other; 
}

Fixed::~Fixed() {}

// ============== OPÉRATEUR D'ASSIGNATION ==============

Fixed &Fixed::operator=(const Fixed &other)
{
    if (this != &other)
        this->_value = other.getRawBits();
    return *this;
}

// ============== OPÉRATEURS DE COMPARAISON ==============

bool Fixed::operator>(const Fixed &other) const
{
    return this->_value > other._value;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->_value < other._value;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_value >= other._value;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_value <= other._value;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_value == other._value;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_value != other._value;
}

// ============== OPÉRATEURS ARITHMÉTIQUES ==============

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    return Fixed(this->toFloat() / other.toFloat());
}

// ============== OPÉRATEURS D'INCRÉMENTATION/DÉCRÉMENTATION ==============

// Pré-incrémentation : ++a
Fixed &Fixed::operator++()
{
    this->_value++;
    return *this;
}

// Post-incrémentation : a++
Fixed Fixed::operator++(int)
{
    Fixed tmp(*this);
    this->_value++;
    return tmp;
}

// Pré-décrémentation : --a
Fixed &Fixed::operator--()
{
    this->_value--;
    return *this;
}

// Post-décrémentation : a--
Fixed Fixed::operator--(int)
{
    Fixed tmp(*this);
    this->_value--;
    return tmp;
}

// ============== FONCTIONS MEMBRES ==============

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
    return (float)this->_value / (1 << _fractionalBits);
}

int Fixed::toInt(void) const
{
    return this->_value >> _fractionalBits;
}

// ============== FONCTIONS STATIQUES MIN/MAX ==============

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

// ============== SURCHARGE DE << ==============

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
    out << fixed.toFloat();
    return out;
}
