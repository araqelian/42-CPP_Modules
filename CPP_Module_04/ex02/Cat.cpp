/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:45:40 by darakely          #+#    #+#             */
/*   Updated: 2023/01/24 15:00:50 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"
#include "./Brain.hpp"

Cat::Cat()
{
	std::cout << "Default constructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	this->type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat& other) : AAnimal(other)
{
	std::cout << "Copy constructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	brain = new Brain();
}

Cat&	Cat::operator=(const Cat& other)
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

Cat::~Cat()
{
	std::cout << "Destructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	delete brain;
}

void			Cat::makeSound() const { std::cout << "😽 Miauuu ..." << std::endl; }
std::string		Cat::get_class_name() { return "Cat"; }