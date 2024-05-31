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
	char	c_num = 0;
	int		i_num = 0;
	float	f_num = 0;
	double	d_num = 0;
	
	
	if (argc != 2)
		std::cout << "Error\nTry this: ./convert literal" << std::endl;
	else
	{
		Convert conv;
		conv.setArgument(argv[1]);
		if (conv.convert_num(conv.getArgument()) == 0)
			return 0;

		c_num = static_cast<char>(conv);
		i_num = static_cast<int>(conv);
		f_num = static_cast<float>(conv);
		d_num = static_cast<double>(conv);
	}
	return 0;
}