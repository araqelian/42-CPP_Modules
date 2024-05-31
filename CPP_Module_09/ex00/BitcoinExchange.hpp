/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:56:46 by darakely          #+#    #+#             */
/*   Updated: 2023/04/12 15:42:23 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BITCOIN__
#define __BITCOIN__

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <unistd.h>

class BitcoinExchange
{
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange&);
	BitcoinExchange& operator = (const BitcoinExchange&);
	~BitcoinExchange();

public:

	void	parse_input_file(char*);

private:
	std::map<std::string, float>	_database;
	
	std::string		key;
	float			value;

	bool	check_valid_date(std::ifstream&, std::string&);
	bool	check_valid_value(std::string&);
	bool	error_msg(const char*, std::string str = "");
};

#endif