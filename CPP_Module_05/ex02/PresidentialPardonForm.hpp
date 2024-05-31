/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:43:46 by darakely          #+#    #+#             */
/*   Updated: 2023/01/25 20:49:33 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

#include "./AForm.hpp"

class PresidentialPardonForm : public AForm
{
	std::string	target;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& new_target);
	PresidentialPardonForm(const PresidentialPardonForm& other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

	std::string	getTarget() const;
	void		execute(Bureaucrat const & executor) const;
};

#endif