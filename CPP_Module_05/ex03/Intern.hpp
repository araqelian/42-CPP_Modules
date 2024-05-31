/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:18:28 by darakely          #+#    #+#             */
/*   Updated: 2023/01/26 14:38:33 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;

class Intern
{
	AForm	*Pmake(const std::string& target) const;
	AForm	*Rmake(const std::string& target) const;
	AForm	*SHmake(const std::string& target) const;

public:
	Intern();
	Intern(const Intern& other);
	Intern& operator = (const Intern& other);
	~Intern();
	
	class InternException : public std::exception
	{
		const char	*what() const throw();
	};
	
	AForm	*makeForm(const std::string& formName, const std::string& formTarget) const;
};

#endif