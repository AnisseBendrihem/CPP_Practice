/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abendrih <abendrih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:21:22 by abendrih          #+#    #+#             */
/*   Updated: 2026/01/05 14:26:54 by abendrih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int                 _value;              
    static const int    _fractionalBits = 8;

public:
    Fixed();                               
    Fixed(const Fixed &other);              
    Fixed &operator=(const Fixed &other);  
    ~Fixed();                

    int     getRawBits(void) const;         
    void    setRawBits(int const raw);    
};

#endif
