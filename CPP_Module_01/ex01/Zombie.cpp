/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    Zombie.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:27:10 by darakely          #+#    #+#             */
/*   Updated: 2023/01/20 15:43:38 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

void	Zombie::set_name(std::string name)
{
	z_name = name;
	std::cout << "Zombie were named " << z_name << " created successfully!" <<std::endl;
}

void	Zombie::announce()
{
	std::cout << z_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}