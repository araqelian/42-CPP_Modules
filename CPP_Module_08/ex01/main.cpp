/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:54:25 by darakely          #+#    #+#             */
/*   Updated: 2023/01/31 13:01:22 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"

int main()
{
	Span sp = Span(5);
	
	std::vector<int> MyBigVector;

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	
	sp.addRandomNums(MyBigVector, 10000);	

	try
	{
		sp.addRange(MyBigVector.begin(), MyBigVector.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Span sp_1(20000);
	try
	{
		sp_1.addRandomNums(MyBigVector, 10000);
		sp_1.addRange(MyBigVector.begin(), MyBigVector.end());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	

	return 0;
}