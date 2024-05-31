/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 11:59:41 by darakely          #+#    #+#             */
/*   Updated: 2023/04/13 18:00:52 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : key(""), value(0) { }

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
{
	this->key = other.key;
	this->value = other.value;
	for (std::map<std::string, float>::const_iterator it = other._database.cbegin(); \
		it != other._database.cend(); ++it)
		{
			this->_database[it->first] = it->second;
		}
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		this->key = other.key;
		this->value = other.value;
		this->_database.clear();
		for (std::map<std::string, float>::const_iterator it = other._database.cbegin(); \
			it != other._database.cend(); ++it)
		{
			this->_database[it->first] = it->second;
		}
	}
	return *this;
}

BitcoinExchange::~BitcoinExchange() { }

void	BitcoinExchange::parse_input_file(char* file)
{
	std::ifstream	input_file;
	std::ifstream	temp;
	std::ifstream	database;
	
	input_file.open(file, std::ios::in);
	temp.open(file, std::ios::in);
	database.open("./data.csv", std::ios::in);
	
	if (input_file.fail() || input_file.is_open() == 0)
	{
		std::cout << "Error: " << strerror(errno)  << " (input file)." << std::endl;
		return ;
	}

	if (database.fail() || database.is_open() == 0)
	{
		std::cout << "Error: " << strerror(errno) << " (database file)." << std::endl;
		return ;
	}

	std::string	check;
	std::getline(input_file, check);

	if (check != "date | value")
	{
		std::cout << "Error: Each line in this file must use the following format: \"date | value\"" << std::endl;
		return ;
	}

	std::string	check_argument;
	std::string	for_database;
	size_t		pos = 0;
	std::string	value;

	int			flag = 0;
	std::getline(database, for_database);
	while (std::getline(database, for_database))
	{
		pos = for_database.find(',');	
		value = for_database.substr(pos + 1);
		this->_database.insert(std::make_pair(for_database.substr(0, pos), atof(value.c_str())));
	}	
	
	while (std::getline(input_file, check))
	{
		std::getline(temp, check_argument);
		flag = check_valid_date(temp, check);
		if (flag != false)
			flag = check_valid_value(check);
		if (flag != false)
		{
			std::map<std::string, float>::const_iterator it = this->_database.find(this->key);
			if (it == this->_database.end())
			{
				it = this->_database.lower_bound(this->key);
				if (it != this->_database.begin())
					--it;
				std::cout << it->first << " => " << this->value << " = " << it->second * this->value << std::endl;
			}
			else
				std::cout << it->first << "=> " << this->value << " = " << it->second * this->value << std::endl;
		}
	}

	this->_database.clear();
	input_file.close();
	database.close();
	temp.close();
}

bool	BitcoinExchange::check_valid_value(std::string& str)
{	
	std::string	for_split;
	std::string	num;

	for_split = str.substr(str.find('|') + 1);
	
	size_t	len = for_split.size();
	size_t	i = 0;
	int		dot = 0;

	for (; i < len && (for_split[i] == ' ' || for_split[i] == '\t'); ++i)
		;
	
	num = for_split.substr(i);

	if (for_split[i] == '-' || for_split[i] == '+')
		++i;
	for (; i < len; ++i)
	{
		if (for_split[i] == ' ' || for_split[i] == '\t')
			continue ;
		if (!(for_split[i] >= '0' && for_split[i] <= '9'))
		{
			if (for_split[i] == '.')
			{
				if (dot > 0 || (i > 0 && !(for_split[i + 1] >= '0' && for_split[i + 1] <= '9')))
					return error_msg("numeric argument required => ", for_split);
				++dot;
			}
			else
				return error_msg("numeric argument required => ", for_split);
		}
	}

	float	f_num = atof(num.c_str());

	if (f_num < 0)
		return error_msg("not a positive number.");

	if (f_num > 1000)
		return error_msg("too large a number.");

	this->value = f_num;

	return true;
}

bool	BitcoinExchange::check_valid_date(std::ifstream& temp, std::string& str)
{
	std::string		for_split;
	int				minus = 0;
	size_t			len = str.length();


	if (str.find('|') == std::string::npos)
		return error_msg("bad input => ", str);
	
	if (len < 10 || str[4] != '-' || str[7] != '-')
		return error_msg("bad input => ", str);
	
	for_split = str.substr(0, str.find('|'));
	len = for_split.length();

	for (size_t i = 0; i < len; ++i)
	{
		if (for_split[i] == ' ' || for_split[i] == '\t')
			continue ;
		if (!(for_split[i] >= '0' && for_split[i] <= '9'))
		{
			if (str[i] == '-')
			{
				if (minus > 2)
					return error_msg("bad input => ", str);
				++minus;
			}
			else
				return error_msg("bad input => ", str);
		}
	}

	std::string	year;
	std::string	month;
	std::string	day;
	
	std::string	for_find;

	for (int i = 0; i < 3; ++i)
	{
		if (i != 2)
			std::getline(temp, for_find, '-');
		else
		{
			if (str.find('|') != std::string::npos)
				std::getline(temp, for_find, '|');
			else if (str.find(' ') != std::string::npos)
				std::getline(temp, for_find, ' ');
			else
			{
				std::stringstream s(str);
				for (int i = 0; i < 3; ++i)
					std::getline(s, for_find, '-');
			}
		}
		if (i == 0)
			year = for_find;
		else if (i == 1)
			month = for_find;
		else if (i == 2)
			day = for_find;
	}
	
	const char*	c_day = day.c_str();
	if (day.find(' ') != std::string::npos)
		day = day.substr(0, day.find(' '));
	else
		day = day.substr(0, strlen(c_day));

	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		return error_msg("bad input => ", str);

	int	i_year = atoi(year.c_str());
	int	i_month = atoi(month.c_str());
	int	i_day = atoi(day.c_str());

	if (i_year < 2009 || i_year > 2022)
		return error_msg("date not found in database => ", str);

	if (i_month < 1 || i_month > 12)
		return error_msg("invalid month => ", str);

	if (i_day < 1 || i_day > 31)
		return error_msg("invalid day => ", str);
		
	int	daysInMonth = 31;

	if (i_month == 4 || i_month == 6 || i_month == 9 || i_month == 11)
		daysInMonth = 30;
	
	if (i_month == 2)
		daysInMonth = 28 + (i_year % 4 == 0);

	if (i_day > daysInMonth)
		return error_msg("invalid day => ", str);

	this->key = for_split;

	return true;
}

bool	BitcoinExchange::error_msg(const char*	msg, std::string str)
{
	std::cout << "Error: " << msg << " " << str << std::endl;
	return false;
}