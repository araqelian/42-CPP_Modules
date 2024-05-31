/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 18:51:21 by darakely          #+#    #+#             */
/*   Updated: 2023/01/22 13:43:08 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	int					fixed_point;
	static const int	fractional_bits;

public:
	Fixed();										//construckor
	Fixed(const Fixed& other);						//copy constructor
	Fixed& operator = (const Fixed& other);			//copy assignment operator
	~Fixed();										//destructor
	
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif