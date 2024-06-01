/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:10:05 by darakely          #+#    #+#             */
/*   Updated: 2023/01/28 15:39:56 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./Convert.hpp"


int	main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Error\nTry this: ./convert literal" << std::endl;
	else
	{
		Convert conv;
		conv.setArgument(argv[1]);
		if (conv.convert_num(conv.getArgument()) == 0)
			return 0;

		static_cast<char>(conv);
		static_cast<int>(conv);
		static_cast<float>(conv);
		static_cast<double>(conv);
	}
	return 0;
}
