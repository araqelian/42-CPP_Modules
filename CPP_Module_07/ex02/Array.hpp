/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:43:35 by darakely          #+#    #+#             */
/*   Updated: 2023/01/29 12:28:43 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstdlib>
#include <iostream>
#include <exception>
#include <ctime>

#define MAX_VAL 750

template <class T>

class Array
{
	T*				_arr;
	unsigned int	_n;
public:
	Array();
	Array(unsigned int n);
	Array(const Array& other);
	Array& operator = (const Array& other);
	~Array();

	T				&operator[](unsigned int index) const;
	unsigned int	size() const;

	class OutOfBoundsException : public std::exception
	{
		const char	*what() const throw();
	};
	
};

#include "./Array.tpp"

#endif
