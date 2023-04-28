/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:52:31 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/27 17:03:45 by youngmch         ###   ########.fr       */
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
	std::cout << "getRawBits member function called." << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	this->_value = raw;
}
