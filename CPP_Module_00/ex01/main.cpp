/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:57:05 by darakely          #+#    #+#             */
/*   Updated: 2023/01/20 13:29:51 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

#include <iostream>

void	print_data(std::string str)
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".|";
	else
		std::cout << std::setw(10) << str << "|";
}

void	show_promt(int i)
{
	if (i == 0)
		std::cout << "First Name -> ";
	else if (i == 1)
		std::cout << "Last Name -> ";
	else if (i == 2)
		std::cout << "Nickname -> ";
	else if (i == 3)
		std::cout << "Phone Number -> ";
	else if (i == 4)
		std::cout << "Darkest Secret -> ";
}

int	check_input(std::string str, int i)
{
	if (str.length() == 0)
	{
		std::cout << "The data can't be empty!" << std::endl;
		return -1;
	}
	if (i == 0 || i == 1)
	{
			
		for(unsigned int j = 0; j < str.length(); j++)
		{
			if (!isalpha(str[j]))
			{
				std::cout << "Use only [A-Z] or [a-z]!" << std::endl;
				return -1;
			}
		}
	}
	else if (i == 3)
	{
		for(unsigned int j = 0; j < str.length(); j++)
		{
			if ((!isdigit(str[j]) && str[j] != '+') || (str[j] == '+' && j != 0))
			{
				std::cout << "Use only [0-9] or \'+\'!" << std::endl;
				return (-1);
			}	
		}
	}
	return 0;
}

int	get_and_check_arg(std::string data[5])
{
	for(int i = 0; i < 5; i++)
	{
		show_promt(i);
		getline(std::cin, data[i]);
		if (check_input(data[i], i) == -1)
			return -1;
	}
	return 0;
}

int main()
{
	PhoneBook	book;
	std::string	data[5];
	std::string	arg;
	int			index = -1;
	
	while (true)
	{
		std::cout << "Please insert ADD, SEARCH or EXIT -> ";
		getline(std::cin, arg);
		if (std::cin.eof())
			break ;
		if (arg.compare("ADD") == 0)
		{
			std::cout << "\nEnter new contact" << std::endl;
			if (get_and_check_arg(data) == -1)
				continue ;
			book.set_contact(data);
			std::cout << "Contact added!" << std::endl;		
		}
		else if (arg.compare("SEARCH") == 0)
		{
			book.print_phonebook();
			std::cout << "Insert index to see contact in detail -> ";
			std::cin >> index;
			if (std::cin.eof())
				break ;
			std::cout << index << std::endl;
			if (index < 0 || index > book.get_size())
			{
				std::cout << "No such index in the PhoneBook!" << std::endl;
				std::cin.ignore(arg.length(), '\n');
				continue ;
			}
			book.print_contact(index);
			std::cin.ignore(arg.length(), '\n');
		}
		else if (arg.compare("EXIT") == 0)
			break ;
	}
	return 0;
}