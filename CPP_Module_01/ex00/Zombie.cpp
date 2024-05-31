/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:50:45 by darakely          #+#    #+#             */
/*   Updated: 2023/01/20 15:22:48 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie::Zombie(std::string new_name)
{
	name = new_name;
	std::cout << "Zombie named " << name << " crated!" << std::endl;
}

Zombie::~Zombie() { std::cout << "Zombie named " << name << " destroyed!"<<std::endl; }

void	Zombie::announce() {std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl; }