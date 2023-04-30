/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:52:35 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/30 16:49:27 by youngmch         ###   ########.fr       */
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
	bool operator > (const Fixed &source) const;
	bool operator < (const Fixed &source) const;
	bool operator >= (const Fixed &source) const;
	bool operator <= (const Fixed &source) const;
	bool operator == (const Fixed &source) const;
	bool operator != (const Fixed &source) const;
	Fixed operator + (const Fixed &source) const;
	Fixed operator - (const Fixed &source) const;
	Fixed operator * (const Fixed &source) const;
	Fixed operator / (const Fixed &source) const;
	Fixed &operator ++(); //pre
	Fixed operator ++(int); //post
	Fixed &operator --(); //pre
	Fixed operator --(int);  //post
	static Fixed &max(Fixed &s1, Fixed &s2);
	static const Fixed &max(const Fixed &s1, const Fixed &s2);
	static Fixed &min(Fixed &s1, Fixed &s2);
	static const Fixed &min(const Fixed &s1, const Fixed &s2);
};

std::ostream& operator << (std::ostream &out, const Fixed &source);

#endif
