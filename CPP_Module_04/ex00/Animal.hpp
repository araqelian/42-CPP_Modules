/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:41:45 by darakely          #+#    #+#             */
/*   Updated: 2023/01/24 12:25:32 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string	type;
	
public:
	Animal();
	Animal(const Animal& other);
	Animal& operator = (const Animal& other);
	virtual ~Animal();

	virtual void				makeSound() const;
	const std::string&			getType() const;
	std::string					get_class_name();
};

#endif