/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:42:12 by darakely          #+#    #+#             */
/*   Updated: 2023/01/26 12:28:59 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

#include "./Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	const std::string	name;
	bool				is_signed;
	const int			sign_grade;
	const int			execute_grade;

public:
	AForm();
	AForm(const AForm& other);
	AForm& operator = (const AForm& other);
	AForm(const std::string& new_name, int new_sign_grade, int new_execute_grade);
	virtual ~AForm();

	class GradeTooHighException : public std::exception
	{
		const char	*what() const throw();	
	};
	class GradeTooLowException : public std::exception
	{
		const char	*what() const throw();
	};

	class UnsignedFormException : public std::exception
	{
		const char	*what() const throw();	
	};

	class UnsuccessException : public std::exception
	{
		const char	*what() const throw();
	};

	const std::string	getName() const;
	bool				getIsSigned() const;
	int					getSignGrade() const;
	int					getExecuteGrade() const;
	
	void				beSigned(Bureaucrat &brt);
	virtual void		execute(Bureaucrat const & executor) const = 0;
};

std::ostream&	operator << (std::ostream& o, const AForm& afrm);

#endif