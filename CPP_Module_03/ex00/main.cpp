/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:48:24 by darakely          #+#    #+#             */
/*   Updated: 2023/01/23 12:00:19 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

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

	return 0;
}