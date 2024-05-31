/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:02:14 by darakely          #+#    #+#             */
/*   Updated: 2023/01/21 13:27:59 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Replace.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error!" << std::endl;
        std::cout << "Please insert:" <<std::endl;
        std::cout << "argv[1] -> filename" << std::endl;
        std::cout << "argv[2] -> str to find" << std::endl;
        std::cout << "argv[3] -> str to replace" << std::endl;
    }
    else
    {
        Replace replace(argv[1], argv[2], argv[3]);
        replace.replace_file();
    }
    return 0;
}