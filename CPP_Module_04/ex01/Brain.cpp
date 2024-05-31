/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:04:59 by darakely          #+#    #+#             */
/*   Updated: 2023/01/24 13:28:34 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Brain.hpp"

Brain::Brain()
{
	std::cout << "Default constructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "";
}

Brain::Brain(const Brain& other)
{
	std::cout << "Copy constructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
	std::cout << "Overload assignment operator for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
	if (this != &other)
		for (int i = 0; i < 100; i++)
			this->ideas[i] = other.ideas[i];
	return *this;
}

Brain::~Brain()
{
	std::cout << "Destructor for ";
	std::cout << this->get_class_name() << " class called!" << std::endl;
}

std::string			Brain::get_class_name() const { return "Brain"; }
const std::string&	Brain::get_ideas(int i) const { return ideas[i]; }
void				Brain::set_ideas(const int i, const std::string& idea) { ideas[i] = idea; }
