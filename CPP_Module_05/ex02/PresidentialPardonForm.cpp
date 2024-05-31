/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:43:44 by darakely          #+#    #+#             */
/*   Updated: 2023/01/26 10:10:33 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("President", 25, 5), target("")
{
	std::cout << "Default constructor for " << this->getName();
	std::cout << " obj called by PresidentialPardonForm class!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& new_target) : AForm("President", 25, 5), target(new_target)
{
	std::cout << "Parameterized constructor for " << this->getName();
	std::cout << " obj called by PresidentialPardonForm class!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) \
: AForm("President", 25, 5), target(other.target)
{
	std::cout << "Copy constructor for " << this->getName();
	std::cout << " obj called by PresidentialPardonForm class!" << std::endl;	
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	std::cout << "Overload assignment operator for " << this->getName();
	std::cout << " obj called by PresidentialPardonForm class!" << std::endl;
	if (this != &other)
		this->target = other.target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Destructor for " << this->getName();
	std::cout << " obj called by PresidentialPardonForm class!" << std::endl;	
}

std::string	PresidentialPardonForm::getTarget() const { return this->target; }

void		PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::UnsignedFormException();
	if  (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}