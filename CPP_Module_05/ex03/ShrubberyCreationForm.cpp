/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:24:29 by darakely          #+#    #+#             */
/*   Updated: 2023/01/26 12:00:51 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ShrubberyCreationForm.hpp"
#include "./AForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Shrubbery", 145, 137), target("")
{
	std::cout << "Default constructor for " << this->getName();
	std::cout << " obj called by ShrubberyCreationForm class!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& new_target) : AForm("Shrubbery", 145, 137), target(new_target)
{
	std::cout << "Parameterized constructor for " << this->getName();
	std::cout << " obj called by ShrubberyCreationForm class!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : target(other.target)
{
	std::cout << "Copy constructor for " << this->getName();
	std::cout << " obj called by ShrubberyCreationForm class!" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	std::cout << "Overload assignment operator for " << this->getName();
	std::cout << " obj called by ShrubberyCreationForm class!" << std::endl;
	if (this != &other)
		this->target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Destructor for " << this->getName();
	std::cout << " obj called by ShrubberyCreationForm class!" << std::endl;
}

std::string	ShrubberyCreationForm::getTarget() const { return this->target; }

void		ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getIsSigned() == false)
		throw AForm::UnsignedFormException();
	if (executor.getGrade() > this->getExecuteGrade())
		throw AForm::GradeTooLowException();
		
	std::string fileName = this->getTarget() + "_shrubbery";
	std::ofstream ofs(fileName);
	
	if (!ofs.is_open())
	{
		std::cout << "Error\n" << strerror(errno) << std::endl;
		return ;
	}
	ofs << "                       .  ,****** **  ,                     " << std::endl;
	ofs << "            .  ** *** ***//*******//*****                   " << std::endl;
	ofs << "          * ,**/******/////*///***//////**                  " << std::endl;
	ofs << "       ,***//////////**(((//////**(((*****,*** ******,      " << std::endl;
	ofs << "       *//****//*/*******,*/(//(/****/*////*****////****    " << std::endl;
	ofs << "      *****///((***/////*/////////***///////*****((/*/**,.  " << std::endl;
	ofs << "   **.****//(((((((/*//////****////**(((///****(((/*****    " << std::endl;
	ofs << "     */(((***/////****////*//////*/////***/***((*/////****  " << std::endl;
	ofs << "    ,**(***/////////**/*((///(////**//****///****////#//****" << std::endl;
	ofs << "   **((((((/////////(((((/#((((((((((((/*/////****(%%##(***," << std::endl;
	ofs << " ,**((***((((((((/######(((((#(((*/*/*((((((((*%%###(****.  " << std::endl;
	ofs << " ***/((((%%#%#%&%#(((#%#(((%%((%%&#((((#***(%#%%##%%%%**    " << std::endl;
	ofs << "  *.***/(/(///%%#(%%%%%#%%*%%%&##(%#%%%*(%##%(*%%%%%* ,     " << std::endl;
	ofs << "         **(((((((%#####*%%%%%%##%%&(%(%/((((((**           " << std::endl;
	ofs << "            *, ,*, .*#&&#####&(/#((##((/.    *              " << std::endl;
	ofs << "                         &%(#%#((..#(/                      " << std::endl;
	ofs << "                          &#(#((##(#*                       " << std::endl;
	ofs << "                          &#((##(#                          " << std::endl;
	ofs << "                          &##(#(#                           " << std::endl;
	ofs << "                          ###(((*                           " << std::endl;
	ofs << "                         (#&#((**                           " << std::endl;
	ofs << "                        &&&#(#((#/                          " << std::endl;
	ofs << "                       &%##&(#((##*                         " << std::endl;
	ofs << "                     &&&&&&#(%(((##(.                       " << std::endl;
	ofs << "                     &#%##%%#&%#*%&##(                      " << std::endl;
	ofs.close();
}