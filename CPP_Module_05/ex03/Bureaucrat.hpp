/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:24:35 by darakely          #+#    #+#             */
/*   Updated: 2023/01/26 12:29:10 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "./AForm.hpp"

class AForm;

class Bureaucrat
{
	const std::string	name;
	int					grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator = (const Bureaucrat& other);
	Bureaucrat(const std::string new_name, int new_grade);
	~Bureaucrat();

	class GradeTooHighException : public std::exception
	{
		const char	*what() const throw();	
	};
	class GradeTooLowException : public std::exception
	{
		const char	*what() const throw();	
	};
	
	int					getGrade() const;
	const std::string	getName() const;
	void				signForm(AForm& afrm) const;
	void				executeForm(const AForm& afrm);
};

std::ostream&	operator << (std::ostream &o, const Bureaucrat& brt);

#endif