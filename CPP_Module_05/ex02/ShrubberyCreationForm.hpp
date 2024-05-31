/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 10:40:29 by darakely          #+#    #+#             */
/*   Updated: 2023/01/26 11:51:07 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>

#include "./AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	std::string target;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& new_target);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
	~ShrubberyCreationForm();

	std::string	getTarget() const;
	void		execute(Bureaucrat const & executor) const;
};

#endif