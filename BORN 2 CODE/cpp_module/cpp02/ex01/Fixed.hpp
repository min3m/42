/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:52:35 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/24 21:09:56 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int					_value;
	static const int	_frac_bits = 8;

public:
	Fixed();
	Fixed(const int _value);
	Fixed(const float _value);
	~Fixed();
	Fixed(const Fixed &source);
	Fixed& operator = (const Fixed &source);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator << (std::ostream &out, const Fixed &source);

#endif
