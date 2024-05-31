/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:25:09 by darakely          #+#    #+#             */
/*   Updated: 2023/01/31 11:10:30 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

class NotFoundException : public std::exception
{

public:
	const char	*what() const throw()
	{
		return "Ops! Element not found!";
	}
};

template <typename T>
void	easyfind(T const &a, int toFind)
{
	typename T::const_iterator it = std::find(a.cbegin(), a.cend(), toFind);
	if (it != a.end())
	{
		std::cout << "Element " << toFind <<" found at position : ";
        std::cout << it - a.begin() << " (counting from zero)" << std::endl;
	}
	else
		throw NotFoundException();
}

#endif