/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:25:32 by darakely          #+#    #+#             */
/*   Updated: 2023/01/21 12:26:46 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanB.hpp"
#include "./Weapon.hpp"

HumanB::HumanB(std::string name) { name_humanB = name; }

void    HumanB::setWeapon(Weapon& weapon) {m_weapon = &weapon;}

void    HumanB::attack()
{
    std::cout << name_humanB << " attacks with their " << m_weapon->getType() << std::endl;
}