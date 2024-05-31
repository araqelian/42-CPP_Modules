/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:41:48 by darakely          #+#    #+#             */
/*   Updated: 2023/01/24 14:57:52 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "./AAnimal.hpp"
#include "./Brain.hpp"

class Cat : public AAnimal
{
	Brain*	brain;
public:
	Cat();
	Cat(const Cat& other);
	Cat& operator=(const Cat& other);
	~Cat();

	void				makeSound() const;
	std::string			get_class_name();
	void				set_brain_idea(int index, const std::string& idea);
	const std::string&	get_brain_idea(int i) const;
};

#endif