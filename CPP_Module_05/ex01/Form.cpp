/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 14:51:39 by darakely          #+#    #+#             */
/*   Updated: 2023/01/26 14:11:56 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Form.hpp"
#include "./Bureaucrat.hpp"

Form::Form() : name("Unnamed"), is_signed(false), sign_grade(150), execute_grade(150)
{
	std::cout << "Default constructor for ";
	std::cout << this->getName() << " obj called! (class Form)" << std::endl;
}

Form::Form(const Form& other) \
: name(other.name), is_signed(other.is_signed), \
sign_grade(other.sign_grade), execute_grade(other.execute_grade)
{
	std::cout << "Copy constructor for ";
	std::cout << this->getName() << " obj called! (class Form)" << std::endl;
}

Form& Form::operator=(const Form& other)
{
	std::cout << "Overload assignment operator for ";
	std::cout << this->getName() << " obj called! (class Form)" << std::endl;
	if (this != &other)
		this->is_signed = other.is_signed;
	return *this;
}

Form::Form(const std::string& new_name, int new_sign_grade, int new_execute_grade) \
: name(new_name), is_signed(false), sign_grade(new_sign_grade), execute_grade(new_execute_grade)
{
	std::cout << "Parameterized constructor for ";
	std::cout << this->getName() << " obj called! (class Form)" << std::endl;
	if (this->sign_grade < 1 || this->execute_grade < 1)		throw Form::GradeTooHighException();
	if (this->sign_grade > 150 || this->execute_grade > 150)	throw Form::GradeTooLowException();
}

Form::~Form()
{
	std::cout << "Destructor for ";
	std::cout << this->getName() << " obj called! (class Form)" << std::endl;
}

const char			*Form::GradeTooHighException::what() const throw() { return "Ops! Grade or Execute Grade is too height!"; }
const char			*Form::GradeTooLowException::what() const throw() { return "Ops! Grade or Execute Grade is too low!"; }

const std::string	Form::getName() const { return this->name; }
bool				Form::getIsSigned() const { return this->is_signed; }
int					Form::getSignGrade() const { return this->sign_grade; }
int					Form::getExecuteGrade() const { return this->execute_grade; }

std::ostream& operator << (std::ostream& o, const Form& frm)
{
	o << "[NAME]: " << frm.getName();
	o << " [IS_SIGNED]: " << frm.getIsSigned();
	o << " [SIGN_GRADE]: " << frm.getSignGrade();
	o << " [EXECUTE_GRADE]: " << frm.getExecuteGrade();
	
	return o;
}

void				Form::beSigned(Bureaucrat& brt)
{
	if (brt.getGrade() > this->sign_grade)
		throw Bureaucrat::GradeTooLowException();
	this->is_signed = true;
	brt.signForm(*this);
}