/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:50:32 by darakely          #+#    #+#             */
/*   Updated: 2023/01/26 12:29:20 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AForm.hpp"

AForm::AForm() : name("Unnamed"), is_signed(false), sign_grade(150), execute_grade(150)
{
	std::cout << "Default constructor for " << this->getName();
	std::cout << " obj called by AForm class!" << std::endl;
}

AForm::AForm(const AForm& other) \
: name(other.name), is_signed(other.is_signed), \
sign_grade(other.sign_grade), execute_grade(other.execute_grade)
{
	std::cout << "Copy constructor for " << this->getName();
	std::cout << " obj called by AForm class!" << std::endl;
	
	if (this->sign_grade < 1 || this->execute_grade < 1)		throw AForm::GradeTooHighException();
	if (this->sign_grade > 150 || this->execute_grade > 150)	throw AForm::GradeTooLowException();	
}

AForm&	AForm::operator=(const AForm& other)
{
	std::cout << "Overload assignment operator for ";
	std::cout << this->getName() << " obj called by AForm class!" << std::endl;
	if (this != &other)
		this->is_signed = other.is_signed;
	return *this;
}

AForm::AForm(const std::string& new_name, int new_sign_grade, int new_execute_grade) \
: name(new_name), is_signed(false), sign_grade(new_sign_grade), execute_grade(new_execute_grade)
{
	std::cout << "Parameterized constructor for " << this->getName();
	std::cout << " obj called by AForm class!" << std::endl;	
}

AForm::~AForm()
{
	std::cout << "Destructor for " << this->getName();
	std::cout << " obj called by AForm class!" << std::endl;
}

std::ostream&	operator << (std::ostream& o, const AForm& afrm)
{
	o << "[NAME]: " << afrm.getName();
	o << " [IS SIGNED]: " << afrm.getIsSigned();
	o << " [SIGN GRADE]: " << afrm.getSignGrade();
	o << " [EXECUTE GRADE]: " << afrm.getExecuteGrade();
	return o;
}

void	AForm::beSigned(Bureaucrat& brt)
{
	if (brt.getGrade() > this->sign_grade)
		this->is_signed = false;	
	else
		this->is_signed = true;
	brt.signForm(*this);
}

const std::string	AForm::getName() const { return this->name; }
bool				AForm::getIsSigned() const { return this->is_signed; }
int					AForm::getSignGrade() const { return this->sign_grade; }
int					AForm::getExecuteGrade() const {return this->execute_grade; }

const char			*AForm::GradeTooHighException::what() const throw() { return "Ops! Grade or Execute Grade is too height!"; }
const char			*AForm::GradeTooLowException::what() const throw() { return "Ops! Grade or Execute Grade is too low!"; }
const char			*AForm::UnsignedFormException::what() const throw() { return "Ops! An unsigned form can't be executed!"; }
const char			*AForm::UnsuccessException::what() const throw() { return "Ops! Unsuccessful attempt at robotization!"; }