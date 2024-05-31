/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:14:53 by darakely          #+#    #+#             */
/*   Updated: 2023/01/22 15:59:31 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	int					fixed_point;
	static const int	fractional_bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	Fixed& operator = (const Fixed& other);
	
	Fixed(const int number);
	Fixed(const float number);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	
	bool	operator > (const Fixed& other);
	bool	operator < (const Fixed& other);
	bool	operator >= (const Fixed& other);
	bool	operator <= (const Fixed& other);
	bool	operator == (const Fixed& other);
	bool	operator != (const Fixed& other);
	
	Fixed	operator + (const Fixed& other);
	Fixed	operator - (const Fixed& other);
	Fixed	operator * (const Fixed& other);
	Fixed	operator / (const Fixed& other);

	Fixed&	operator -- ();
	Fixed&	operator ++ ();
	Fixed	operator ++ (int);
	Fixed	operator -- (int);

	static Fixed		&min(Fixed &a, Fixed &b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed &a, const Fixed &b);
	static const Fixed	&max(const Fixed &a, const Fixed &b);
};

std::ostream& operator << (std::ostream& out, Fixed const &in);

#endif