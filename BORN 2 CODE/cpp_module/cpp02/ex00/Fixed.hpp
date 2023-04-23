/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngmch <youngmch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 21:52:35 by youngmch          #+#    #+#             */
/*   Updated: 2023/04/23 22:25:21 by youngmch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
private:
	int					value;
	static const int	frac_bits;
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &source);
	Fixed& operator = (const Fixed &source);
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
