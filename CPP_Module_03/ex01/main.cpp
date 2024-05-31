/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:48:24 by darakely          #+#    #+#             */
/*   Updated: 2023/01/23 12:54:57 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

int main()
{
	ClapTrap	c_trap;
	ClapTrap	a("name_1");
	ClapTrap	b("name_2");
	ClapTrap	c = a;

	for (int i = 0; i < 5; i++)
		a.attack("urish name_1");

	for (int i = 0; i < 5; i++)
		b.attack("urish name_2");

	ScavTrap	s_trap;
	ScavTrap	a_1("name_1 ScavTrap");
	ScavTrap	b_1("name_2 ScavTrap");
	ScavTrap	c_1 = a_1;
	
	for (int i = 0; i < 5; i++)
		a_1.attack("urish name_1 ScavTrap");

	for (int i = 0; i < 5; i++)
		b_1.attack("urish name_2 ScavTrap");

	return 0;
}