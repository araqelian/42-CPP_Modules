/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:51:41 by darakely          #+#    #+#             */
/*   Updated: 2023/01/25 16:56:06 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

#include "./Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	const std::string	name;
	bool				is_signed;
	const int			sign_grade;
	const int			execute_grade;

public:
	Form();
	Form(const Form& other);
	Form& operator = (const Form& other);
	Form(const std::string& new_name, int new_sign_grade, int new_execute_grade);
	~Form();

	class GradeTooHighException : public std::exception
	{
		const char	*what() const throw();	
	};
	class GradeTooLowException : public std::exception
	{
		const char	*what() const throw();
	};

	const std::string	getName() const;
	bool				getIsSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	
	void				beSigned(Bureaucrat& brt);
};

std::ostream&	operator << (std::ostream& o, const Form& frm);

#endif