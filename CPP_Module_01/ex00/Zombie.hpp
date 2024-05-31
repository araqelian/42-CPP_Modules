/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:50:54 by darakely          #+#    #+#             */
/*   Updated: 2023/01/20 15:12:21 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	std::string name;
public:
	Zombie(std::string new_name);
	~Zombie();
	void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
#endif