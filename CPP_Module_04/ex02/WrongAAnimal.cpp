/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:10:52 by darakely          #+#    #+#             */
/*   Updated: 2023/01/24 15:13:19 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongAAnimal.hpp"

WrongAAnimal::WrongAAnimal()
{
	std::cout << "Default constructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	this->type = "WrongAAnimal";
}

WrongAAnimal::WrongAAnimal(const WrongAAnimal& other)
{
	std::cout << "Copy constructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	this->type = other.type;
}

WrongAAnimal&	WrongAAnimal::operator=(const WrongAAnimal& other)
{
	std::cout << "Overload assignment operator for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

WrongAAnimal::~WrongAAnimal()
{
	std::cout << "Destructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
}

void				WrongAAnimal::makeSound() const { std::cout << "I'm WrongAAnimal: I don't have a unique sound!" << std::endl; }
std::string			WrongAAnimal::get_class_name() const { return "WrongAAnimal"; }
const std::string&	WrongAAnimal::getType() const { return this->type; }