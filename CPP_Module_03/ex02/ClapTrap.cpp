/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:48:37 by darakely          #+#    #+#             */
/*   Updated: 2023/01/23 12:45:23 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

ClapTrap::~ClapTrap() { std::cout << "Default destructor for ClapTrap called!" << std::endl; }

ClapTrap::ClapTrap()
{ 
	std::cout << "Default constructor for ClapTrap called!" << std::endl;
	ClapTrap::hit_points = 10;
	ClapTrap::energy_points = 10;
	ClapTrap::attack_damage = 0;
}

ClapTrap::ClapTrap(const std::string c_name)
{
	std::cout << "Constructor parameterized for ClapTrap called!" << std::endl;
	this->name = c_name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor for ClapTrap called!" << std::endl;
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Overload operator assignment for ClapTrap called!" << std::endl; 
	this->name = other.name;
	this->hit_points = other.hit_points;
	this->energy_points = other.energy_points;
	this->attack_damage = other.attack_damage;
	return *this;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_points <= amount)
	{
		hit_points = 0;
		std::cout << name << " was killed!" << std::endl;
		return ;
	}
	hit_points -= amount;
	std::cout << name << " was damaged (it lost " << amount << " hit points)!" << std::endl;	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::string msg(" was repaired ");
	if (energy_points == 0)
	{
		std::cout << name << " cannot repair itself, because it has no energy!" << std::endl;
		return ;
	}
	if (hit_points == 0)
		msg = " rose again ";
	hit_points += amount;
	energy_points--;
	std::cout << name << msg << "(it got " << amount << " hit points)!" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
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

void	ClapTrap::set_name(std::string new_name) { name = new_name; }
void	ClapTrap::set_hit_points(unsigned int new_hit) { hit_points = new_hit; }
void	ClapTrap::set_energy_points(unsigned int new_energy) { energy_points = new_energy; }
void	ClapTrap::set_attack_damage(unsigned int new_attack) { attack_damage = new_attack; }