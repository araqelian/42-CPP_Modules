/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 15:25:14 by darakely          #+#    #+#             */
/*   Updated: 2023/01/31 11:08:40 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./easyfind.hpp"

int main()
{
	//std::vector<int> vec = {1, 10, 9462, 58, 52};    // -std=c++11
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(10);
	vec.push_back(9462);
	vec.push_back(58);
	vec.push_back(52);

	// std::cout << vec[0] << " " << vec[1] << " " << vec[2] \
	// << " " << vec[3] << " " << vec[4] << std::endl << std::endl;
	

	//vec.reserve(100);
	//std::cout << vec.capacity() << std::endl;


	std::cout << "Elements the int vector:\t";
	std::cout << vec.at(0) << " " << vec.at(1) << " " << vec.at(2) \
	<< " " << vec.at(3) << " " << vec.at(4) << std::endl << std::endl;
	
	try
	{
		std::cout << "Find element \'10\'" << std::endl;
		easyfind(vec, 10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Find element \'-1\'" << std::endl;
		easyfind(vec, -1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Find element \'789\'" << std::endl;
		easyfind(vec, 789);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Find element \'52\'" << std::endl;
		easyfind(vec, 52);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
	
	vec.clear();
}