/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:30:58 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/05 19:23:12 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
    int                 _value;
    static const int    _fractionalBits = 8;

public:
    Fixed();
    Fixed(const int n);                        
    Fixed(const float n);                       
    Fixed(const Fixed &other);                  
    Fixed &operator=(const Fixed &other);       
    ~Fixed();                                 

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;              
    int     toInt(void) const;                  
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
