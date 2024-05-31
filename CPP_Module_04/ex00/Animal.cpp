/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:45:35 by darakely          #+#    #+#             */
/*   Updated: 2023/01/24 12:59:19 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"

Animal::Animal()
{
	std::cout << "Default constructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal& other)
{
	std::cout << "Copy constructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	if (this != &other)
		this->type = other.type;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Overload assignment operator for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Destructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
}

void				Animal::makeSound() const { std::cout << "I'm a generic animal, I don't have a unique sound!" << std::endl; }
const std::string&	Animal::getType() const { return  this->type; }
std::string			Animal::get_class_name() { return "Animal"; }