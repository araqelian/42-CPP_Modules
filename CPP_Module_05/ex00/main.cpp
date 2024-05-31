/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:06:04 by darakely          #+#    #+#             */
/*   Updated: 2023/01/25 14:46:32 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Bureaucrat.hpp"

int main()
{
	Bureaucrat Davit;
	
	std::cout << "Hi! My name is " << Davit.getName() << std::endl;
	std::cout << "My grade is " << Davit.getGrade() << std::endl;

	Bureaucrat Ashot("Ashot", 10);

	std::cout << "Hi! My name is " << Ashot.getName() << std::endl;
	std::cout << "My grade is " << Ashot.getGrade() << std::endl;
	
	Bureaucrat Hoso("Hoso", 50);

	std::cout << "Hi! My name is " << Hoso.getName() << std::endl;
	std::cout << "My grade is " << Hoso.getGrade() << std::endl << std::endl;

	std::cout << "___________________ START ORIGINAL OPERATOR '<<' ___________________" << std::endl << std::endl;

	std::cout << Davit.getName() << ", bureaucrat grade " << Davit.getGrade() << std::endl;
	std::cout << Ashot.getName() << ",\t bureaucrat grade " << Ashot.getGrade() << std::endl;
	std::cout << Hoso.getName() << ",\t bureaucrat grade " << Hoso.getGrade() << std::endl << std::endl; 

	std::cout << "___________________ END ORIGINAL OPERATOR '<<' ___________________" << std::endl << std::endl;

	std::cout << "___________________ START try and catch ___________________" << std::endl << std::endl;

	try
	{
		Bureaucrat Ero("Ero", 80);
		std::cout << "\n\t___________________ START OVERLOAD OPERATOR '<<' ___________________" << std::endl << std::endl;
		std::cout << Ero << std::endl;
		std::cout << "\n\t___________________ END OVERLOAD OPERATOR '<<' ___________________" << std::endl << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat Suro("Suro", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat Raz("Raz", 20);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "___________________ END try and catch ___________________" << std::endl << std::endl;


	return 0;
}