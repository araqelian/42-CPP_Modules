/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:25:53 by darakely          #+#    #+#             */
/*   Updated: 2023/01/21 16:55:55 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

int main(int argc, char **argv)
{
	Harl harl;
	std::string check[5] = { "DEBUG", "INFO", "WARNING", "ERROR", "" };
	int	i = 0;
	if (argc != 2)
	{
		std::cout << "Error!" << std::endl;
		exit(EXIT_FAILURE);
	}
	for (; i < 5 && check[i].compare(argv[1]); i++);
	switch (i)
	{
		case 0: harl.debug();
		case 1: harl.info();
		case 2: harl.warning();
		case 3: harl.error(); break;
		default: std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	
	return 0;
}