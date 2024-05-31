/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:01:58 by darakely          #+#    #+#             */
/*   Updated: 2023/01/23 12:39:33 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

ScavTrap::~ScavTrap() { std::cout << "Destructor for ScavTrap called!" << std::endl; }

ScavTrap::ScavTrap()
{
	std::cout << "Default constructor for ScavTrap called!" << std::endl;
	this->name = "Unnamed";
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(std::string new_name)
{
	std::cout << "Constructor parameterized for ScavTrap called!" << std::endl;
	this->name = new_name;
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& other)
{
	std::cout << "Copy constructor for ScavTrap called!" << std::endl;
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "Overload operator assignment for ScavTrap called!" << std::endl;
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	return *this;
}

void	ScavTrap::attack(const std::string& target)
{
	std::string msg("");
	
	if (hit_points == 0 && energy_points != 0)
		msg = "because it has no health!";
	else if (hit_points != 0 && energy_points == 0)
		msg = "because it has no energy!";
	else if (hit_points == 0 && energy_points == 0)
		msg = "because it has no health and energy!";
	if (hit_points == 0 || energy_points == 0)
	{
		std::cout << name << " cannot attack, " << msg;
		return ;
	}
	std::cout << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate() { std::cout << this->name << " is now in Gate keeper mode." << std::endl; }