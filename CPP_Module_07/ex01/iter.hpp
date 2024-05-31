/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:22:16 by darakely          #+#    #+#             */
/*   Updated: 2023/01/29 11:39:02 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <class T>

void	iter(T *arr, size_t len, void(*foo)(T&))
{
	for (size_t i = 0; i < len; i++)
		foo(arr[i]);
	std::cout << std::endl << std::endl;
}

template <class T>

void	Print(T& prt)
{
	std::cout << prt << "\t";
}

#endif