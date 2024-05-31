/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 13:19:37 by darakely          #+#    #+#             */
/*   Updated: 2023/01/21 13:37:06 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>


class Replace
{
    std::ofstream   outFile;
    std::ifstream   infile;
    std::string     r_filename;
    std::string     r_s1;
    std::string     r_s2;
    
public:
    Replace(std::string filename, std::string s1, std::string s2);
    void    replace_file();
    
};

#endif