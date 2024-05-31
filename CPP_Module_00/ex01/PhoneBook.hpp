/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:57:37 by darakely          #+#    #+#             */
/*   Updated: 2023/01/20 13:23:01 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "./Contact.hpp"

class PhoneBook
{
	Contact	arr_contact[8];
	int		index;
	int		size;
public:
	PhoneBook();
	
	void	set_contact(std::string data[5]);
	void	print_contact(int i);
	void	print_phonebook();
	int		get_size();
	
};

void	print_data(std::string str);

#endif