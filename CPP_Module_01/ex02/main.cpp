/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:13:39 by darakely          #+#    #+#             */
/*   Updated: 2023/01/20 18:41:30 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string A = "HI THIS IS BRAIN";
    std::string *stringPTR = &A;
    std::string &stringREF = A;

    std::cout << "The memory address of the string variable ->\t" << &A << std::endl;
    std::cout << "The memory address held by stringPTR ->\t\t" << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF ->\t\t" << &stringREF << std::endl <<std::endl;
    
    std::cout << "The value of the string variable ->\t" << A << std::endl; 
    std::cout << "The value pointed to by stringPTR ->\t" << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF ->\t" << stringREF << std::endl;
    return 0;
}