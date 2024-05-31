/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:38:20 by darakely          #+#    #+#             */
/*   Updated: 2023/01/28 11:10:40 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

#include <iostream>

class Data
{
	std::string	value;

public:
	Data();
	Data(const Data& other);
	Data(const std::string& new_value);
	Data& operator = (const Data& other);
	~Data();

	std::string	getValue() const;
};

#endif