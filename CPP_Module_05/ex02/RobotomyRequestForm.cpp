/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:14:03 by darakely          #+#    #+#             */
/*   Updated: 2023/01/26 11:58:39 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RobotomyRequestForm.hpp"
#include "./AForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robotomy", 72, 45)
{
	std::cout << "Default constructor for " << this->getName();
	std::cout << " obj called by RobotomyRequestForm class!" << std::endl;
	target = "";
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& new_target) : AForm("Robotomy", 72, 45)
{
	std::cout << "Parameterized constructor for " << this->getName();
	std::cout << " obj called by RobotomyRequestForm class!" << std::endl;	
	target = new_target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
{
	std::cout << "Copy constructor for " << this->getName();
	std::cout << " obj called by RobotomyRequestForm class!" << std::endl;
	this->target = other.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	std::cout << "Overload assignment operator for " << this->getName();
	std::cout << " obj called by RobotomyRequestForm class!" << std::endl;
	if (this != &other)
		this->target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Destructor for " << this->getName();
	std::cout << " obj called by RobotomyRequestForm class!" << std::endl;
}

std::string		RobotomyRequestForm::getTarget() const { return this->target; }

void			RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::UnsignedFormException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
	if (std::rand() % 2 == 0)
		std::cout  << this->getTarget() << " has been robotomized successfully." << std::endl;
	else
		throw AForm::UnsuccessException();
}