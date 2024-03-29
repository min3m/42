/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:52:35 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/24 16:27:04 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_value;
	static const int	_frac_bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &source);
	Fixed& operator = (const Fixed &source);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
