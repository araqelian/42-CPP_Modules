/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:25:29 by darakely          #+#    #+#             */
/*   Updated: 2023/01/21 12:22:59 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "./Weapon.hpp"
#include <iostream>

class HumanB
{
    std::string name_humanB;
    Weapon *m_weapon;
public:
    void    attack();
    void	setWeapon(Weapon& weapon);
    HumanB(std::string name);
};

#endif