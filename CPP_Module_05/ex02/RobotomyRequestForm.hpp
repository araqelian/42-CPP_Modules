/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:13:29 by darakely          #+#    #+#             */
/*   Updated: 2023/01/26 10:29:13 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQESTFORM_HPP
#define ROBOTOMYREQESTFORM_HPP

#include <iostream>

#include "./AForm.hpp"
#include "./Bureaucrat.hpp"

class RobotomyRequestForm : public AForm
{
	std::string	target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& new_target);
	RobotomyRequestForm(const RobotomyRequestForm& other);
	RobotomyRequestForm& operator = (const RobotomyRequestForm& other);
	~RobotomyRequestForm();

	std::string	getTarget() const;
	void		execute(Bureaucrat const & executor) const;
};

#endif