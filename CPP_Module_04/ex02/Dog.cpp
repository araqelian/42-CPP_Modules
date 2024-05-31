/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:45:37 by darakely          #+#    #+#             */
/*   Updated: 2023/01/24 15:01:42 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"

Dog::Dog()
{
	std::cout << "Default constructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	this->type = "Dog";
	brain = new Brain();
}

Dog::Dog(const Dog& other) : AAnimal(other)
{
	std::cout << "Copy constructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	brain = new Brain();
}

Dog&	Dog::operator=(const Dog& other)
{
	std::cout << "Overload assignment operator for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	if (this != &other)
	{
		this->type = other.type;
		delete brain;
		brain = new  Brain();
		for (int i = 0; i < 100; i++)
			brain->set_ideas(i, other.brain->get_ideas(i));
		
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Destructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	delete brain;
}

void			Dog::makeSound() const { std::cout << "🐕 Gaf gaf ..." << std::endl; }
std::string		Dog::get_class_name() { return "Dog"; }