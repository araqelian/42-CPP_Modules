/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darakely <darakely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 17:12:21 by darakely          #+#    #+#             */
/*   Updated: 2023/04/12 15:42:56 by darakely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RPN__
#define __RPN__

#include <iostream>
#include <stack>

class RPN
{
public:
	RPN();
	RPN(const RPN&);
	RPN& operator = (const RPN&);
	~RPN();

public:
	void	check_and_run_command(char*);

private:
	std::stack<int>		_stack;
};

#endif