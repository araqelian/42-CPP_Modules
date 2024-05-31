/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:22:57 by darakely          #+#    #+#             */
/*   Updated: 2023/01/26 14:50:07 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Intern.hpp"
#include "./AForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() { std::cout << "Default constructor called by Intern class!" << std::endl; }

Intern::Intern(const Intern& other)
{
	std::cout << "Copy constructor called by Intern class!" << std::endl;
	(void)other;
}

Intern&	Intern::operator=(const Intern& other)
{
	std::cout << "Overload assignment operator called by Intern class!" << std::endl;
	if (this != &other) {}
	return *this;
}

Intern::~Intern() { std::cout << "Destructor called by Intern class!" << std::endl; }

const char	*Intern::InternException::what() const throw() { return "Hl@ checnq stace!"; }

AForm	*Intern::makeForm(const std::string& formName, const std::string& formTarget) const
{
	AForm *(Intern::*ptr_member_func[3])(const std::string& target) const = {&Intern::Pmake, &Intern::Rmake, &Intern::SHmake};
	std::string	request[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	for (int i = 0; i < 3; i++)
	{
		if (formName.compare(request[i]) == 0)
		{
			std::cout << "Intern creates " << formName << std::endl;;
			return ((this->*ptr_member_func[i])(formTarget));
		}
	}
	throw InternException();
}

AForm	*Intern::Pmake(const std::string& target) const { return new PresidentialPardonForm(target); }
AForm	*Intern::Rmake(const std::string& target) const { return new RobotomyRequestForm(target); }
AForm	*Intern::SHmake(const std::string& target) const { return new ShrubberyCreationForm(target); }

