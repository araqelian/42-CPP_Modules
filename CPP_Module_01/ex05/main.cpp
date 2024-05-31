/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:04:21 by darakely          #+#    #+#             */
/*   Updated: 2023/01/21 15:46:34 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

int main()
{
	Harl		harl;
	std::string	param;

	while (true)
	{
		std::cout << "Please insert \"DEBUG\", \"INFO\", \"WARNING\", \"ERROR\" or \"EXIT\"(for exit program) -> ";
		getline(std::cin, param);
		if (param.compare("EXIT") == 0 || std::cin.eof())
			return 0;
		harl.complain(param);
	}
	
	return 0;
}