/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:04:14 by darakely          #+#    #+#             */
/*   Updated: 2023/04/13 15:29:41 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	__MERGE__
#define __MERGE__

#include <climits>
#include <cstdlib>
#include <sys/time.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <limits>
#include <list>

class	PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe& operator = (const PmergeMe&);
	~PmergeMe();

public:

	void				parse_input(char**);

private:
	std::list<int>		_list;
	std::vector<int>	_vector;
	size_t				_flag;

	void				fill_containers(std::string&);
	
	std::list<int>		mergeSort_for_list(std::list<int>&, size_t);
	std::list<int>		merge_for_list(std::list<int>&, std::list<int>&);
	std::list<int>		insertionSort_for_list(std::list<int>&);

	std::vector<int>	mergeSort_for_vector(std::vector<int>&, size_t);
	std::vector<int>	merge_for_vector(std::vector<int>&, std::vector<int>&);
	std::vector<int>	insertionSort_for_vector(std::vector<int>&);
};

#endif
