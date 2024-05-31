/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:19:42 by darakely          #+#    #+#             */
/*   Updated: 2023/01/22 15:42:40 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"

int		Fixed::getRawBits()const { return fixed_point; }
void	Fixed::setRawBits(int const raw) { fixed_point = raw; }

Fixed::~Fixed() { std::cout << "Destructor called" <<std::endl; }

Fixed::Fixed()
{
	fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
{
	this->setRawBits(number << fractional_bits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
{
	this->setRawBits((int)roundf(number * (1 << fractional_bits)));
	std::cout << "Float constructor called" << std::endl;	
}


Fixed::Fixed(const Fixed& other)
{
	*this = other;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	fixed_point = other.fixed_point;
	return *this;
}

std::ostream& operator << (std::ostream& out, Fixed const &in)
{	
	out << in.toFloat();
	return out;
}

float	Fixed::toFloat() const { return (float)(fixed_point) / (1 << fractional_bits); }
int		Fixed::toInt() const { return fixed_point >> fractional_bits; }