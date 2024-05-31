/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:10:59 by darakely          #+#    #+#             */
/*   Updated: 2023/01/24 17:33:01 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>

class AAnimal
{
protected:
	std::string	type;

public:
	AAnimal();
	AAnimal(const AAnimal& other);
	AAnimal& operator =(const AAnimal& other);
	virtual ~AAnimal();

	virtual void		makeSound() const = 0;
	const std::string&	getType() const;
	std::string			get_class_name() const;
};

#endif