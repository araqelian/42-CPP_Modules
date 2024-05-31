/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:27:07 by darakely          #+#    #+#             */
/*   Updated: 2023/01/20 18:17:57 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie* new_zombie = new Zombie[N];
	for(int i = 0; i < N; i++)
		new_zombie[i].set_name(name);
	return new_zombie;
}