/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:24:47 by darakely          #+#    #+#             */
/*   Updated: 2023/01/21 12:02:09 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Weapon.hpp"

Weapon::Weapon(std::string type_weapon) {  setType(type_weapon); }

void    Weapon::setType(std::string new_type) { type = new_type; }

const std::string&  Weapon::getType() { return type; }