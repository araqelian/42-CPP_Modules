/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:20:44 by darakely          #+#    #+#             */
/*   Updated: 2023/01/21 14:53:57 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2)
{
    r_filename = filename;
    r_s1 = s1;
    r_s2 = s2;
}

void    Replace::replace_file()
{
    std::ifstream   check_infile(r_filename);
    std::string     str;
    size_t          pos = 0;
    size_t          i = 0;

    if (!check_infile.is_open())
    {
        std::cout << "Error!" << std::endl;
        std::cout << std::strerror(errno) << "!" << std::endl;   
        exit(EXIT_FAILURE);
    }
    if (getline(check_infile, str, '\0'))
    {
        std::ofstream   openOutfile(r_filename + ".replace");
        pos = str.find(r_s1);
        while (pos != std::string::npos)
        {
            openOutfile << str.substr(i, pos - i);
            openOutfile << r_s2;
            i = pos + r_s1.length();
            pos = str.find(r_s1, pos + 1);
        }
        openOutfile.close();   
    }
    else
    {
        std::cout << "Error!" << std::endl;
        std::cout << "Empty file!" << std::endl;
        exit (EXIT_FAILURE);
    }
}