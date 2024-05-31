/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAAnimal.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:10:55 by darakely          #+#    #+#             */
/*   Updated: 2023/01/24 14:20:39 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGAANIMAL_HPP
#define WRONGAANIMAL_HPP

#include <iostream>

class WrongAAnimal
{
protected:
	std::string	type;

public:
	WrongAAnimal();
	WrongAAnimal(const WrongAAnimal& other);
	WrongAAnimal& operator =(const WrongAAnimal& other);
	virtual ~WrongAAnimal();

	virtual void		makeSound(void) const;
	std::string			get_class_name() const;
	const std::string&	getType() const;	
};

#endif