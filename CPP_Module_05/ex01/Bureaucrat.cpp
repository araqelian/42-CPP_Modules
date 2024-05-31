/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:06:07 by darakely          #+#    #+#             */
/*   Updated: 2023/01/26 14:09:25 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"
#include "./Form.hpp"

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150)
{
	std::cout << "Default constructor for ";
	std::cout << this->getName() << " obj called! (class Bureaucrat)" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
	std::cout << "Copy constructor for ";
	std::cout << this->getName() << " obj called! (class Bureaucrat)" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string new_name, int new_grade) : name(new_name), grade(new_grade)
{
	std::cout << "Parameterized constructor for ";
	std::cout << this->getName() << " obj called! (class Bureaucrat)" << std::endl;
	if (new_grade < 1)		throw Bureaucrat::GradeTooHighException();
	if (new_grade > 150)	throw Bureaucrat::GradeTooLowException();
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other) 
{
	std::cout << "Overload assignment operator for ";
	std::cout << this->getName() << " obj called! (class Bureaucrat)" << std::endl;
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor for ";
	std::cout << this->getName() <<  " obj called! (class Bureaucrat)" << std::endl;
}

int					Bureaucrat::getGrade() const { return this->grade; }
const std::string	Bureaucrat::getName() const { return this->name; }

std::ostream&	operator << (std::ostream &o, const Bureaucrat& brt)
{
	o << brt.getName() << ", bureaucrat grade " << brt.getGrade();
	return o;
}

void		Bureaucrat::increment()
{
	if (this->grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

void		Bureaucrat::decrement()
{
	if (this->grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void		Bureaucrat::signForm(Form& frm) const
{
	if (frm.getIsSigned())
		std::cout << this->getName() << " signed " << frm.getName() << std::endl;
	else
		std::cout << this->getName() << " couldn’t sign " << frm.getName() << " because he/she hasn't enough grade." << std::endl;
}

const char	*Bureaucrat::GradeTooHighException::what() const throw() { return "Ops! Grade is too height!"; }
const char	*Bureaucrat::GradeTooLowException::what() const throw() { return "Ops! Grade is too low!"; }