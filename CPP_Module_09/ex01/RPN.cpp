/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:18:46 by darakely          #+#    #+#             */
/*   Updated: 2023/04/12 15:34:39 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN.hpp"

RPN::RPN() { }

RPN::RPN(const RPN& other)
{
	this->_stack = other._stack;
}

RPN&	RPN::operator=(const RPN& other)
{
	if (this != &other)
	{
		this->_stack = other._stack;
	}
	return *this;
}

RPN::~RPN() { }

void	RPN::check_and_run_command(char* str)
{
	std::string	s = str;
	size_t		len = s.length();
	int			operand_1 = 0;
	int			operand_2 = 0;
	

	for(size_t i = 0; i < len; ++i)
	{
		if (!(s[i] >= '0' && s[i] <= '9') && !(s[i] == '-' || s[i] == '+' || s[i] == '*' || s[i] == '/' || s[i] == ' '))
		{
			std::cout << "Error" << std::endl;
			return ;
		}
	}
	
	for (size_t i = 0; i < len; ++i)
	{
		if (s[i] == ' ')
			continue;
		if (s[i] >= '0' && s[i] <= '9')
			this->_stack.push(s[i] - 48);
		else
		{
			if (this->_stack.size() > 1)
				;
			else
			{
				std::cout << "Error" << std::endl;
				while (this->_stack.empty() == 0)
				{
					this->_stack.pop();
				}
				return ;
			}
			if (s[i] == '+')
			{
				operand_2 = this->_stack.top();
				this->_stack.pop();
				operand_1 = this->_stack.top();
				this->_stack.pop();
				this->_stack.push(operand_1 + operand_2);
			}
			else if (s[i] == '-')
			{
				operand_2 = this->_stack.top();
				this->_stack.pop();
				operand_1 = this->_stack.top();
				this->_stack.pop();
				this->_stack.push(operand_1 - operand_2);
			}
			else if (s[i] == '*')
			{
				operand_2 = this->_stack.top();
				this->_stack.pop();
				operand_1 = this->_stack.top();
				this->_stack.pop();
				this->_stack.push(operand_1 * operand_2);
			}
			else if (s[i] == '/')
			{
				operand_2 = this->_stack.top();
				this->_stack.pop();
				operand_1 = this->_stack.top();
				this->_stack.pop();
				if (operand_2 != 0)
					;
				else
				{
					std::cout << "Error" << std::endl;
					while (this->_stack.empty() == 0)
					{
						this->_stack.pop();
					}
					return ;
				}
				this->_stack.push(operand_1 / operand_2);
			}
		}
	}
	
	if (this->_stack.size() != 1)
	{
		std::cout << "Error" << std::endl;
		while (this->_stack.empty() == 0)
		{
			this->_stack.pop();
		}
		return ;
	}

	std::cout << this->_stack.top() << std::endl;
	
	while (this->_stack.empty() == 0)
	{
		this->_stack.pop();
	}
}