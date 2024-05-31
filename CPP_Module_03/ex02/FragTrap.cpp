/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:43:43 by darakely          #+#    #+#             */
/*   Updated: 2023/01/23 13:07:53 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

FragTrap::~FragTrap() { std::cout << "Destructor for FragTrap called!" << std::endl; }

FragTrap::FragTrap()
{
	std::cout << "Default constructor for FragTrap called!" << std::endl;
	this->name = "Unnamed";
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(std::string new_name)
{
	std::cout << "Constructor parameterized for FragTrap called!" << std::endl;
	this->name = new_name;
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
}

FragTrap::FragTrap(const FragTrap& other)
{
	std::cout << "Copy constructor for FragTrap called!" << std::endl;
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	std::cout << "Overload operator assignment for FragTrap called!" << std::endl;
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	return *this;
}
 
void	FragTrap::highFivesGuys() { std::cout << this->name << " gives everyone high fives." << std::endl;}

void	FragTrap::attack(const std::string& target)
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