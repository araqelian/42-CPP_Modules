/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 11:26:44 by darakely          #+#    #+#             */
/*   Updated: 2023/01/29 11:40:42 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./iter.hpp"

int main()
{
	std::cout << "___________ START INT ___________" << std::endl << std::endl;
	
	int	arr[] = {7, 10, -1, 98, 65};
	size_t len = sizeof(arr) / sizeof(arr[0]);
	iter(arr, len, Print);
	
	std::cout << "___________ END INT ___________" << std::endl << std::endl;

	std::cout << "___________ START FLOAT ___________" << std::endl << std::endl;

	float	f_arr[] = {11.45, 78.0, -1.6, 2.65, 7.5};
	len = sizeof(f_arr) / sizeof(f_arr[0]);
	iter(f_arr, len, Print);

	std::cout << "___________ END FLOAT ___________" << std::endl << std::endl;

	std::cout << "___________ START STRING ___________" << std::endl << std::endl;

	std::string	s_arr[] = {"I", "love", "42", "Yerevan"};
	len = sizeof(s_arr) / sizeof(s_arr[0]);
	iter(s_arr, len, Print);
	
	std::cout << "___________ END STRING ___________" << std::endl << std::endl;

}