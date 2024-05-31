/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:25:38 by darakely          #+#    #+#             */
/*   Updated: 2023/01/21 12:26:39 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HumanA.hpp"
#include "./Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) { name_humanA = name, m_weapon = &weapon;}

void    HumanA::attack()
{
    std::cout << name_humanA << " attacks with their " << m_weapon->getType() << std::endl;
}