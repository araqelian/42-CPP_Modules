/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:30:10 by darakely          #+#    #+#             */
/*   Updated: 2023/01/28 15:50:14 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Convert.hpp"

Convert::Convert() : argument("") { }
Convert::~Convert()	{ }
Convert::Convert(const Convert& other) : argument(other.argument) { }



Convert&	Convert::operator=(const Convert& other)
{
	if (this != &other)
		this->argument = other.argument;
	return *this;
}

void		Convert::setArgument(std::string new_argument) { argument = new_argument; }
std::string	Convert::getArgument() const { return this->argument; }


int	Convert::check_pseudo_literals(std::string literal)
{
	if (literal.compare("nan") == 0 || literal.compare("nanf") == 0)
	{
		std::cout << "char:\t" << "impossible" << std::endl;
		std::cout << "int:\t" << "impossible" <<  std::endl;
		std::cout << "float:\t" <<  "nanf" << std::endl;
		std::cout << "double:\t" << "nan" <<  std::endl;
		return 0;
	}
	if (literal.compare("-inf") == 0 || literal.compare("-inff") == 0)
	{
		std::cout << "char:\t" << "impossible" << std::endl;
		std::cout << "int:\t" << "impossible" <<  std::endl;
		std::cout << "float:\t" <<  "-inff" << std::endl;
		std::cout << "double:\t" << "-inf" <<  std::endl;
		return 0;
	}
	if (literal.compare("+inf") == 0 || literal.compare("+inff") == 0)
	{
		std::cout << "char:\t" << "impossible" << std::endl;
		std::cout << "int:\t" << "impossible" <<  std::endl;
		std::cout << "float:\t" <<  "+inff" << std::endl;
		std::cout << "double:\t" << "+inf" <<  std::endl;
		return 0;
	}
	return -1;
}

int	Convert::check_arg_for_int(std::string literal)
{
	unsigned int i = 0;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	for (; i < literal.length() && literal[i] != '.'; i++)
		if (!isdigit(literal[i]))
			return -1;
	return 0;
}

int	Convert::check_arg_for_float(std::string literal)
{
	int	count = 0;
	unsigned int i = 0;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	for (; i < literal.length(); i++)
	{
		if (literal[i] == 'f' && count == 0)
			continue ;
		if (literal[i] == 'f')
			count++;
		if (!isdigit(literal[i]) && literal[i] != '.')
			return -1;
	}
	return 0;
}

int	Convert::check_arg_for_double(std::string literal)
{
	unsigned int i = 0;
	if (literal[0] == '-' || literal[0] == '+')
		i++;
	for (; i < literal.length(); i++)
	{
		if (!isdigit(literal[i]) && literal[i] != 'f' && literal[i] != '.')
			return -1;
	}
	return 0;
	
}

Convert::operator int()
{
	long long i;
	if (check_arg_for_int(argument) != 0)
	{
		std::cout << "int:\timpossible" << std::endl;
		return -1;
	}
	std::istringstream(argument) >> i;
	if (i < INT_MIN || i > INT_MAX)
	{
		std::cout << "int:\tout of range" << std::endl;
		return -1;
	}
	std::cout << "int:\t" << i << std::endl;
	return i;
}

Convert::operator float()
{
	double	i = 0;
	double	min;
	double	max;
	if (check_arg_for_float(argument) != 0)
	{
		std::cout << "float:\timpossible" << std::endl;
		return -1;
	}
	min = std::numeric_limits<float>::min() - 1;
	max = std::numeric_limits<float>::max() - 1;
	if (argument.find("f") > argument.length())
		std::istringstream(argument) >> i;
	else
		std::istringstream(argument.substr(0, argument.find("f"))) >> i;
	if (i < min || i > max)
	{
		std::cout << "float:\tout of range" << std::endl;
		return -1;
	}
	std::cout << "float:\t" << std::fixed << std::setprecision(1) << i << "f" << std::endl;
	return i;
}

Convert::operator double()
{
	long double i;
	long double min;
	long double max;
	
	if (check_arg_for_double(argument) != 0)
	{
		std::cout << "double:\timpossible" << std::endl;
		return -1;
	}
	min = std::numeric_limits<double>::min() - 1;
	max = std::numeric_limits<double>::max() - 1;
	if (argument.find("f") > argument.length())
		std::istringstream(argument) >> i;
	else
		std::istringstream(argument.substr(0, argument.find("f"))) >> i;
	if (i < min || i > max)
	{
		std::cout << "double:\tout of range" << std::endl;
		return -1;
	}
	std::cout << "double:\t" << std::fixed << std::setprecision(1) << i << std::endl;
	return i;
}

Convert::operator char()
{
	char	c = 0;
	int		i = 0;
	if (argument.length() == 1)
	{
		c = argument[0];
		if (isalpha(argument[0]))
		{
			std::cout << "char:\t\'" << c << "\'" << std::endl;
			return c; 
		}
		else
		{
			std::istringstream(argument) >> i;
			c = static_cast<char>(i);
			if (c < 0)
				std::cout << "char:\timpossible" << std::endl;
			else if (isprint(c))
				std::cout << "char:\t\'" << c << "\'" << std::endl;
			else
				std::cout << "char:\tNon displayable" << std::endl;
			return c;
		}
	}
	std::istringstream(argument) >> i;
	if (i < CHAR_MIN || i > CHAR_MAX)
	{
		std::cout << "char:\tout of range" << std::endl;
		return -1;
	}
	c = static_cast<char>(i);
	if (c < 0)
		std::cout << "char:\timpossible" << std::endl;
	else if (isprint(c))
		std::cout << "char:\t\'" << c << "\'" << std::endl;
	else
		std::cout << "char:\tNon displayable" << std::endl;
	return c;
}

int	Convert::convert_num(std::string literal)
{
	if (check_pseudo_literals(literal) == 0)
		return 0;
	return -1;
}