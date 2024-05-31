/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:07:55 by darakely          #+#    #+#             */
/*   Updated: 2023/01/29 11:19:37 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <class T>

void swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

template <class T>

T max(T& a, T& b)
{
	return a > b ? a : b;
}

template <class T>

T min(T& a, T& b)
{
	return a < b ? a : b;
}

#endif