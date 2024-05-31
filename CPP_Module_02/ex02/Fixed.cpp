/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:14:56 by darakely          #+#    #+#             */
/*   Updated: 2023/01/22 16:17:12 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"


Fixed::Fixed() { fixed_point = 0; }
Fixed::~Fixed() {}
Fixed::Fixed(const Fixed& other) { *this = other; }

Fixed& Fixed::operator=(const Fixed& other)
{
	fixed_point = other.fixed_point;
	return *this;
}

Fixed::Fixed(const int number)
{
	this->setRawBits(number << fractional_bits);
}

Fixed::Fixed(const float number)
{
	this->setRawBits((int)roundf(number * (1 << fractional_bits)));
}

float	Fixed::toFloat() const { return (float)(fixed_point) / (1 << fractional_bits); }
int		Fixed::toInt() const { return fixed_point >> fractional_bits; }

std::ostream& operator << (std::ostream& out, Fixed const &in)
{	
	out << in.toFloat();
	return out;
}

int		Fixed::getRawBits()const { return fixed_point; }

void	Fixed::setRawBits(int const raw) { fixed_point = raw; }

bool	Fixed::operator > (const Fixed& other) { return this->getRawBits() > other.getRawBits(); }
bool	Fixed::operator < (const Fixed& other) { return this->getRawBits() < other.getRawBits(); }
bool	Fixed::operator >= (const Fixed& other) { return this->getRawBits() >= other.getRawBits(); }
bool	Fixed::operator <= (const Fixed& other) { return this->getRawBits() <= other.getRawBits(); }
bool	Fixed::operator == (const Fixed& other) { return this->getRawBits() == other.getRawBits(); }
bool	Fixed::operator != (const Fixed& other) { return this->getRawBits() != other.getRawBits(); }

Fixed	Fixed::operator + (const Fixed& other) { return Fixed(this->toFloat() + other.toFloat()); }
Fixed	Fixed::operator - (const Fixed& other) { return Fixed(this->toFloat() - other.toFloat()); }
Fixed	Fixed::operator * (const Fixed& other) { return Fixed(this->toFloat() * other.toFloat()); }
Fixed	Fixed::operator / (const Fixed& other) { return Fixed(this->toFloat() / other.toFloat()); }

Fixed&	Fixed::operator ++ () { ++this->fixed_point; return *this; }
Fixed&	Fixed::operator -- () { --this->fixed_point; return *this; }
Fixed	Fixed::operator -- (int) { Fixed tmp(*this); --this->fixed_point; return tmp;}
Fixed	Fixed::operator ++ (int) { Fixed tmp(*this); ++this->fixed_point; return tmp;}

Fixed& Fixed::min(Fixed &a, Fixed &b) { return a.getRawBits() < b.getRawBits() ? a : b; }
Fixed& Fixed::max(Fixed &a, Fixed &b) { return a.getRawBits() > b.getRawBits() ? a : b; }
const Fixed& Fixed::min(const Fixed &a, const Fixed &b) { return a.getRawBits() < b.getRawBits() ? a : b; }
const Fixed& Fixed::max(const Fixed &a, const Fixed &b) { return a.getRawBits() > b.getRawBits() ? a : b; }