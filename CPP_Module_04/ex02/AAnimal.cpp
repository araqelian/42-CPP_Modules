/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:10:49 by darakely          #+#    #+#             */
/*   Updated: 2023/01/24 15:09:49 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AAnimal.hpp"

AAnimal::AAnimal()
{
	std::cout << "Default constructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	this->type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal& other)
{
	std::cout << "Copy constructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	this->type = other.type;
}

AAnimal&	AAnimal::operator=(const AAnimal& other)
{
	std::cout << "Overload assignment operator for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	if (this != &other)
		this->type = other.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
}

void				AAnimal::makeSound() const { std::cout << "I'm AAnimal: I don't have a unique sound!" << std::endl; }
std::string			AAnimal::get_class_name() const { return "AAnimal"; }
const std::string&	AAnimal::getType() const { return this->type; }