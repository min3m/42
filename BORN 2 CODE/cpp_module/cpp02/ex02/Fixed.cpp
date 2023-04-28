/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:52:31 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/27 17:06:24 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed()
	:_value(0)
{
}

Fixed::Fixed(const Fixed &source)
{
	*this = source;
}

Fixed::~Fixed()
{
}

Fixed& Fixed::operator = (const Fixed &source)
{
	this->_value = source.getRawBits();
	if (this == &source)
		return (*this);
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
	this->_value = _value << _frac_bits;
	std::cout << "INT constructor : " << this->_value << std::endl;
}

Fixed::Fixed(const float _value)
{
	this->_value = roundf(_value * (1 << _frac_bits));
	std::cout << "Float constructor : " << this->_value << std::endl;
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

//EX02

bool Fixed::operator > (const Fixed &source) const
{
	return (_value > source._value) ? true : false;
}

bool Fixed::operator < (const Fixed &source) const
{
	return (_value < source._value) ? true : false;
}

bool Fixed::operator >= (const Fixed &source) const
{
	return (_value >= source._value) ? true : false;
}

bool Fixed::operator <= (const Fixed &source) const
{
	return (_value <= source._value) ? true : false;
}

bool Fixed::operator == (const Fixed &source) const
{
	return (_value == source._value) ? true : false;
}

bool Fixed::operator != (const Fixed &source) const
{
	return (_value != source._value) ? true : false;
}

Fixed Fixed::operator + (const Fixed &source) const
{
	return Fixed(this->toFloat() + source.toFloat());
}

Fixed Fixed::operator - (const Fixed &source) const
{
	return Fixed(this->toFloat() - source.toFloat());
}

Fixed Fixed::operator * (const Fixed &source) const
{
	return Fixed(this->toFloat() * source.toFloat());
}

Fixed Fixed::operator / (const Fixed &source) const
{
	return Fixed(this->toFloat() / source.toFloat());
}

Fixed &Fixed::operator ++() //pre
{
	this->_value++;
	return (*this);
}

Fixed Fixed::operator ++(int) //post
{
	Fixed tmp;
	tmp = (*this);
	this->_value++;
	return (tmp);
}

Fixed &Fixed::operator --() //pre
{
	this->_value--;
	return (*this);
}

Fixed Fixed::operator --(int)  //post
{
	Fixed tmp;
	tmp = (*this);
	this->_value--;
	return (tmp);
}

Fixed &Fixed::max(Fixed &s1, Fixed &s2)
{
	return ((s1 > s2) ? s1 : s2);
}

const Fixed &Fixed::max(const Fixed &s1, const Fixed &s2)
{
	return ((s1 > s2) ? s1 : s2);
}

Fixed &Fixed::min(Fixed &s1, Fixed &s2)
{
	return ((s1 > s2) ? s2 : s1);
}

const Fixed &Fixed::min(const Fixed &s1, const Fixed &s2)
{
	return ((s1 > s2) ? s1 : s2);
}
