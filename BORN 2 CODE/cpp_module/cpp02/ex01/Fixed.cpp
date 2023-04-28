/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:52:31 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/27 17:06:08 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed()
	:_value(0)
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const Fixed &source)
{
	std::cout << "Copy constructor called." << std::endl;
	*this = source;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

Fixed& Fixed::operator = (const Fixed &source)
{
	std::cout << "Copy assignment operator called." << std::endl;
	if (this == &source)
		return (*this);
	this->_value = source.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

//EX01

Fixed::Fixed(const int _value)
{
	std::cout << "Int constructor called." << std::endl;
	this->_value = _value << _frac_bits;
}

Fixed::Fixed(const float _value)
{
	std::cout << "Float constructor called." << std::endl;
	this->_value = roundf(_value * (1 << _frac_bits));
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << _frac_bits));
}

int Fixed::toInt(void) const
{
	return (_value >> _frac_bits);
}

std::ostream& operator << (std::ostream &out, const Fixed &source)
{
	out << source.toFloat();
	return (out);
}
