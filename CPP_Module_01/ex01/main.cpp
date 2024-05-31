/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:53:21 by darakely          #+#    #+#             */
/*   Updated: 2023/01/20 16:54:01 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

int main(int argc, char **argv)
{
	if (argc < 3)
		std::cout << "Please enter the number(argv[1]) and name(argv[2]) of the zombies!" << std::endl;
	else
	{
		Zombie *z = zombieHorde(atoi(argv[1]), argv[2]);
		for (int i = 0; i < atoi(argv[1]); i++)
			z[i].announce();
		delete [] z;
	}
	return 0;
}