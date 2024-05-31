/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:05:47 by darakely          #+#    #+#             */
/*   Updated: 2023/04/13 15:48:04 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

PmergeMe::PmergeMe() : _flag(15) { }

PmergeMe::PmergeMe(const PmergeMe& other)
{
	(void)other;
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this != &other)
	{

	}
	return *this;
}

PmergeMe::~PmergeMe() { }

void	PmergeMe::parse_input(char** input)
{
	std::string	str;
	size_t		len;
	
	for (int i = 1; input[i] != 0; ++i)
	{
		str += input[i];
		str += " ";
	}
	len = str.length();
	
	for (size_t i = 0; i < len; ++i)
	{
		if (isdigit(str[i]) == 0)
		{
			if (str[i] == '+')
			{
				if (i > 0 && (isdigit(str[i - 1]) == 1 || str[i - 1] == '-' || str[i - 1] == '+'))
				{
					std::cout << "Error: bad input." << std::endl;
					return ;
				}
				else if (i == 0)
				{
					if (isdigit(str[i + 1]) == 0)
					{
						std::cout << "Error: bad input." << std::endl;
						return ;
					}
				}
			}
			else if (str[i] == ' ' || str[i] == '\t')
				continue ;
			else
			{
				std::cout << "Error: bad input." << std::endl;
				return ;
			}
		}
	}
	
	std::stringstream 	s(str);
	std::string			temp;
	long long			i = 0;

	while (std::getline(s, temp, ' '))
	{
		i = atoll(temp.c_str());
		if (i > INT_MAX)
		{
			std::cout << "Erorr: out of range." << std::endl;
			return ;
		}
	}
	temp.clear();
	fill_containers(str);
}

void	PmergeMe::fill_containers(std::string& str)
{
	struct timeval	start, start_l, end_l, end_list, end_vector;

	gettimeofday(&start, 0);
	
	std::stringstream	s(str);
	std::string			temp;

	while (std::getline(s, temp, ' '))
	{
		this->_list.push_back(atoi(temp.c_str()));
		this->_vector.push_back(atoi(temp.c_str()));
	}
	temp.clear();

	std::cout << "Before:\t";
	for (std::list<int>::iterator it = this->_list.begin(); it != this->_list.end(); ++it)
	{
		std::cout << *it << " ";
	}

	std::cout << std::endl;
	
	gettimeofday(&start_l, 0);
	
	this->_list = mergeSort_for_list(this->_list, this->_list.size());
	
	gettimeofday(&end_l, 0);

	gettimeofday(&end_list, 0);
	
	this->_vector = mergeSort_for_vector(this->_vector, this->_vector.size());
	
	gettimeofday(&end_vector, 0);

	
	std::cout << "After:\t";
	
	for (std::list<int>::iterator it = this->_list.begin(); it != this->_list.end(); ++it)
	{
		std::cout << *it << " ";
	}
	
	std::cout << std::endl;
	
	long l_seconds = end_list.tv_sec - start.tv_sec;
    long l_microseconds = end_list.tv_usec - start.tv_usec;
    long l_duration = l_seconds * 1000000 + l_microseconds;

	long v_seconds = (end_vector.tv_sec - start.tv_sec) - (end_l.tv_sec - start_l.tv_sec);
    long v_microseconds = (end_vector.tv_usec - start.tv_usec) - (end_l.tv_usec - start_l.tv_usec);
    long v_duration = v_seconds * 1000000 + v_microseconds;
	
	std::cout << "Time to process a range of " << this->_list.size() << " elements with std::list " << "  \t:\t" << l_duration / 1000.00000 << std::endl;
	std::cout << "Time to process a range of " << this->_list.size() << " elements with std::vector " << "\t:\t" << v_duration / 1000.00000 << std::endl;
}

std::vector<int>	PmergeMe::mergeSort_for_vector(std::vector<int>& vector, size_t size)
{
	if (vector.size() <= 1)
		return vector;

	if (size < this->_flag)
		return insertionSort_for_vector(vector);
	
	std::vector<int> left, right;

	size_t	mid = vector.size() / 2;
	std::vector<int>::const_iterator it = vector.cbegin();

	for (size_t i = 0; i < mid; ++i)
	{
		left.push_back(*it);
		++it;
	}

	while (it != vector.end())
	{
		right.push_back(*it);
		++it;
	}
	
	left = mergeSort_for_vector(left, size - 1);
	right = mergeSort_for_vector(right, size - 1);
	
	return merge_for_vector(left, right);
}

std::vector<int>	PmergeMe::insertionSort_for_vector(std::vector<int>& vector)
{
	int	num = 0;
	for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); ++it)
	{
		num = *it;
		std::vector<int>::iterator prev = it - 1;
		
		while (prev >= vector.begin() && *prev > num)
		{
			*(prev + 1) = *prev;
			--prev;
		}
		*(prev + 1) = num;
	}
	return vector;
}

std::vector<int>	PmergeMe::merge_for_vector(std::vector<int>& left, std::vector<int>& right)
{
	std::vector<int>	res;
	
	while (!left.empty() && !right.empty())
	{
		if (left.front() < right.front())
		{
			res.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			res.push_back(right.front());
			right.erase(right.begin());
		}
	}

	while (!left.empty())
	{
		res.push_back(left.front());
		left.erase(left.begin());
	}

	while (!right.empty())
	{
		res.push_back(right.front());
		right.erase(right.begin());
	}

	return res;
}

std::list<int>	PmergeMe::mergeSort_for_list(std::list<int>& list, size_t size)
{
	if (list.size() <= 1)
		return list;
		
	if (size < this->_flag)
		return insertionSort_for_list(list);

	std::list<int>	left, right;
	
	size_t	mid = list.size() / 2;
	std::list<int>::const_iterator it = list.cbegin();

	for (size_t i = 0; i < mid; ++i)
	{
		left.push_back(*it);
		++it;
	}
	
	while (it != list.end())
	{
		right.push_back(*it);
		++it;
	}

	left = mergeSort_for_list(left, size - 1);
	right = mergeSort_for_list(right, size - 1);

	return merge_for_list(left, right);
}

std::list<int>	PmergeMe::merge_for_list(std::list<int>& left, std::list<int>& right)
{
	std::list<int>	res;

	while (!left.empty() && !right.empty())
	{
		if (left.front() <= right.front())
		{
			res.push_back(left.front());
			left.pop_front();
		}
		else
		{
			res.push_back(right.front());
			right.pop_front();
		}
	}

	while (!left.empty())
	{
		res.push_back(left.front());
		left.pop_front();
	}

	while (!right.empty())
	{
		res.push_back(right.front());
		right.pop_front();
	}
	
	return res;
}

std::list<int>	PmergeMe::insertionSort_for_list(std::list<int>& list)
{
	int	num = 0;
	
	for (std::list<int>::iterator it = ++list.begin(); it != list.end(); ++it)
	{
		num = *it;
		std::list<int>::iterator prev = std::prev(it);
		
		while (it != list.begin() && *prev > num)
		{
			*it = *prev;
			--it;
			--prev;
		}
		*it = num;
	}
	
	return list;
}