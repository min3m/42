/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:52:31 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/23 22:27:38 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed()
	:value(0)
{
}

Fixed::Fixed(const Fixed &source)
	:value(source.value), frac_bits(source.frace_bits)
{
}

Fixed::~Fixed()
{
}
