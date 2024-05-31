/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:17:26 by darakely          #+#    #+#             */
/*   Updated: 2023/01/29 12:36:20 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <class T>
Array<T>::Array() : _n(0), _arr(new T[0]) {}

template <class T>
Array<T>::Array(unsigned int n)
{
	_n = n;
	_arr = new T[n];	
}

template <class T>
Array<T>::Array(const Array& other) : _n(other._n)
{
	_arr = new T[_n];

	for (unsigned int i = 0; i < _n; i++)
		_arr[i] = other._arr[i];	
}

template <class T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		_n = other._n;
		delete [] _arr;
		_arr = new T[_n];
		for (unsigned int i = 0; i < _n; i++)
			_arr[i] = other._arr[i];
	}
	return *this;
}

template <class T>
Array<T>::~Array() { delete [] _arr; }

template <class T>
T&	Array<T>::operator[](unsigned int index) const
{
	if (index > _n)
		throw Array<T>::OutOfBoundsException();
	return *(_arr + index);
}

template <class T>
unsigned int	Array<T>::size() const { return _n; }

template <class T>
const char	*Array<T>::OutOfBoundsException::what() const throw() { return "Ops! Index is out of bounds!"; }