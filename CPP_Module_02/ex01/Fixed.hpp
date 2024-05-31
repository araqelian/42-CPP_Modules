/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:19:45 by darakely          #+#    #+#             */
/*   Updated: 2023/01/24 16:13:48 by darakely         ###   ########.fr       */
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
	Fixed();									//default constructor 
	Fixed(const int number);					//int constructor 
	Fixed(const float number);					//float constructor
	Fixed(const Fixed& other);					//copy constructor
	Fixed& operator = (const Fixed& other);		//copy assignment operator
	~Fixed();									//destructor

	float	toFloat(void) const;
	int		toInt(void) const;

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

std::ostream& operator << (std::ostream& out, Fixed const &in);

#endif