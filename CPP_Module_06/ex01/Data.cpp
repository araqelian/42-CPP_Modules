/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 10:39:47 by darakely          #+#    #+#             */
/*   Updated: 2023/01/28 11:10:36 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Data.hpp"

Data::~Data() { }
Data::Data() : value("") { }
Data::Data(const Data& other) : value(other.value) { }
Data::Data(const std::string& new_value) { this->value = new_value; }
Data&	Data::operator=(const Data& other) { if (this != &other) this->value = other.value; return *this; }
std::string	Data::getValue() const { return this->value; }
