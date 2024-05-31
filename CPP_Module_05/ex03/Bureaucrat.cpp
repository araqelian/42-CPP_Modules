/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:27:43 by darakely          #+#    #+#             */
/*   Updated: 2023/01/26 12:30:10 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Unnamed"), grade(150)
{
	std::cout << "Default constructor for " << this->getName();
	std::cout << " obj called by Bureaucrat class!" << std::endl;	
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade)
{
	std::cout << "Copy constructor for " << this->getName();
	std::cout << " obj called by Bureaucrat class!" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& other)
{
	std::cout << "Overload assignment operator for ";
	std::cout << this->getName() << " obj called by Bureaucrat class!" << std::endl;
	if (this != &other)
		grade = other.grade;
	return *this;
}

Bureaucrat::Bureaucrat(const std::string new_name, int new_grade) : name(new_name), grade(new_grade)
{
	std::cout << "Parameterized constructor for " << this->getName();
	std::cout << " obj called by Bureaucrat class!" << std::endl;
	if (new_grade < 1)		throw Bureaucrat::GradeTooHighException();
	if (new_grade > 150)	throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor for " << this->getName();
	std::cout << " obj called by Bureaucrat class!" << std::endl;
}

void	Bureaucrat::executeForm(const AForm& afrm)
{
	try
	{
		afrm.execute(*this);
		std::cout <<  this->name << " executed " << afrm.getName() << "." << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void				Bureaucrat::signForm(AForm& afrm) const
{
	if (afrm.getIsSigned())
		std::cout << this->getName() << " signed " << afrm.getName() << std::endl;
	else
		std::cout << this->getName() << " couldn’t sign " << afrm.getName() << " because he/she hasn't enough grade." << std::endl;
}

std::ostream&	operator << (std::ostream& o, const Bureaucrat& brt)
{
	o << brt.getName() << ", bureaucrat grade " << brt.getGrade();
	return o;
}

int					Bureaucrat::getGrade() const { return this->grade; }
const std::string	Bureaucrat::getName() const { return this->name; }
const char 			*Bureaucrat::GradeTooHighException::what() const throw() { return "Ops! Grade is too height!";}
const char			*Bureaucrat::GradeTooLowException::what() const throw() { return "Ops! Grade is too low!";}