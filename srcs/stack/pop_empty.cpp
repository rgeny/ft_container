/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_empty.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:07:08 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/26 18:07:25 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

int	main	(void)
{
	NAMESPACE::stack<int, std::vector<int> >	s;

	_print_nl	("test pop with empty stack");
	{
		s.pop();
	}
}
