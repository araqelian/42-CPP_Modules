/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:42:04 by darakely          #+#    #+#             */
/*   Updated: 2023/01/28 11:25:34 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Data.hpp"

uintptr_t	serialize(Data* ptr) { return reinterpret_cast<uintptr_t>(ptr); }
Data*		deserialize(uintptr_t raw) { return reinterpret_cast<Data*>(raw); }

int main()
{
	Data		data("Hello, world!");
	uintptr_t	ptr = serialize(&data);
	Data		*dataPTR = deserialize(ptr);

	std::cout << "addr. data:\t" << &data << std::endl;
	std::cout << "addr. dataPTR:\t" << dataPTR << std::endl << std::endl;

	std::cout << "value data:\t" << data.getValue() << std::endl;
	std::cout << "value dataPTR:\t" << dataPTR->getValue() << std::endl;
}