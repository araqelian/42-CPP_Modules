/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:57:29 by darakely          #+#    #+#             */
/*   Updated: 2023/01/20 13:27:06 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	size = 0;
	index = 0;
}

int		PhoneBook::get_size() { return size; }

void	PhoneBook::set_contact(std::string data[5])
{
	arr_contact[index].set_first_name(data[0]);
	arr_contact[index].set_last_name(data[1]);
	arr_contact[index].set_nickname(data[2]);
	arr_contact[index].set_phone_number(data[3]);
	arr_contact[index].set_darkest_secret(data[4]);
	index++;
	if (index > 7)
		index = 0;
	if (size < 8)
		size++;
}

void	PhoneBook::print_phonebook()
{
	std::cout << std::endl;
	std::cout << "|";
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|";
	std::cout << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		print_data(arr_contact[i].get_first_name());
		print_data(arr_contact[i].get_last_name());
		print_data(arr_contact[i].get_nickname());
		std::cout << std::endl;
	}
}

void	PhoneBook::print_contact(int i)
{
	std::cout << std::endl;
	std::cout << "First Name:\t" << arr_contact[i].get_first_name() << std::endl;
	std::cout << "Last Name:\t" << arr_contact[i].get_last_name() << std::endl;
	std::cout << "Nickname:\t" << arr_contact[i].get_nickname() << std::endl;
	std::cout << "Phone Number:\t" << arr_contact[i].get_phone_number() << std::endl;
	std::cout << "Darkest Secret:\t" << arr_contact[i].get_darkest_secret() << std::endl;
}