/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:04:45 by darakely          #+#    #+#             */
/*   Updated: 2023/01/21 16:21:20 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple- \
pickle-specialketchup burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didnt put \
enough bacon in my burger! If you did, I wouldnt be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. Ive been coming for \
years whereas you started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void(Harl::*ptr_funcs[4])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string check_param[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int i = 0;
	for ( ; i < 5 && level.compare(check_param[i]); i++);
	if (i > 3)
		return ;
	(this->*ptr_funcs[i])();
}