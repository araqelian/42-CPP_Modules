/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:29:28 by darakely          #+#    #+#             */
/*   Updated: 2023/04/05 17:59:34 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: arguments must be one." << std::endl;
		return EXIT_FAILURE;
	}

	RPN	rpn;

	rpn.check_and_run_command(argv[1]);

	return EXIT_SUCCESS;
}