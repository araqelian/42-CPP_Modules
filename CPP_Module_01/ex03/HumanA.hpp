/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:25:35 by darakely          #+#    #+#             */
/*   Updated: 2023/01/21 18:43:37 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "./Weapon.hpp"

class HumanA
{
    std::string name_humanA;
    Weapon* m_weapon;
public:
    void    attack();
    HumanA(std::string name, Weapon& weapon);
};

#endif