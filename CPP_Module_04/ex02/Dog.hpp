/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:41:52 by darakely          #+#    #+#             */
/*   Updated: 2023/01/24 14:59:25 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "./AAnimal.hpp"
#include "./Brain.hpp"

class Dog : public AAnimal
{
	Brain*	brain;
public:
	Dog();
	Dog(const Dog& other);
	Dog& operator=(const Dog& other);
	~Dog();

	void				makeSound() const ;
	std::string			get_class_name();
	void				set_brain_idea(int i, const std::string& idea);
	const std::string&	get_brain_idea(int i) const;
};

#endif