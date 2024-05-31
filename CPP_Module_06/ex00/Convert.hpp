/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:28:40 by darakely          #+#    #+#             */
/*   Updated: 2023/01/28 15:26:32 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

class Convert
{
	std::string	argument;
public:
	Convert();
	Convert(const Convert& other);
	Convert& operator = (const Convert& other);
	~Convert();

	int		check_pseudo_literals(std::string literal);
	int		convert_num(std::string literal);

	
	int		check_arg_for_char(std::string literal);
	int		check_arg_for_int(std::string literal);
	int		check_arg_for_float(std::string literal);
	int		check_arg_for_double(std::string literal);

	
	std::string	getArgument() const;
	void		setArgument(std::string new_argument);

	
	operator	char();
	operator	int();
	operator	float();
	operator 	double();
};

#endif