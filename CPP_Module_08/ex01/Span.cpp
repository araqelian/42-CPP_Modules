/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:54:27 by darakely          #+#    #+#             */
/*   Updated: 2023/01/31 12:59:46 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Span.hpp"

Span::Span() { _MySpanVector.reserve(0); }

Span::Span(unsigned int N) { _MySpanVector.reserve(N); }

Span::Span(const Span& other)
{
	this->_MySpanVector.clear();
	this->_MySpanVector.reserve(other._MySpanVector.capacity());
	this->_MySpanVector = other._MySpanVector;
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		this->_MySpanVector.clear();
		this->_MySpanVector.reserve(other._MySpanVector.capacity());
		this->_MySpanVector = other._MySpanVector;
	}
	return *this;
}

Span::~Span() { _MySpanVector.clear(); }

const char	*Span::NotEnoughSpaceException::what() const throw()	{ return "Ops! Not enough space in span to add new elements!"; }
const char	*Span::SpanIsFullException::what() const throw()		{ return "Ops! Can't add new element (span already full)!"; }
const char	*Span::NotEnoughElementsException::what() const throw()	{ return "Ops! Not enough elements for a span!"; }


void	Span::addRandomNums(std::vector<int>& vec, int size)
{
	std::srand(time(0));
	for (int i = 0; i < size; i++)
		vec.push_back(std::rand());
}

void	Span::addNumber(int n)
{
	if (_MySpanVector.size() == _MySpanVector.capacity())
	{
		throw	SpanIsFullException();
		return ;
	}
	_MySpanVector.push_back(n);
	std::cout << "[" << n << "]" << "\tadded to span!" << std::endl;
}

void	Span::addRange(it begin, it end)
{
	if (end < begin)
		return ;
	if (static_cast<unsigned int>(std::distance(begin, end)) > (_MySpanVector.capacity() - _MySpanVector.size()))
		throw NotEnoughSpaceException();
	
	_MySpanVector.insert(_MySpanVector.end(), begin, end);

	std::cout << std::distance(begin, end) << " integers added to span!" << std::endl;

}

unsigned int	Span::shortestSpan()
{
	if (_MySpanVector.size() < 2)
	{
		throw NotEnoughElementsException();
		return -1;
	}
	
	std::vector<int> sortVec(_MySpanVector);
	std::sort(sortVec.begin(), sortVec.end());
	
	unsigned int min = -1;

	for (std::vector<int>::iterator it = sortVec.begin(); it + 1 != sortVec.end(); it++)
	{
		if (static_cast<unsigned int>(*(it + 1) - *it) < min)
			min = static_cast<unsigned int>(*(it + 1) - *it);
	}
	std::cout << "The shortest span is\t";
	return min;
}

unsigned int	Span::longestSpan()
{
	if (_MySpanVector.size() < 2)
	{
		throw NotEnoughElementsException();
		return -1;
	}
	
	std::vector<int> sortVec(_MySpanVector);
	std::sort(sortVec.begin(), sortVec.end());
	
	std::vector<int>::iterator begin = sortVec.begin();
	std::vector<int>::iterator end = sortVec.end();

	unsigned int max = static_cast<unsigned int>(*(end - 1) - *begin);
	std::cout << "The longest span is\t";
	return max;
}