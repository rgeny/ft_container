/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crash_top.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 18:04:34 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/26 18:05:16 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

int	main	(void)
{
	NAMESPACE::stack<int, std::vector<int> >	s;

	_print_nl	("test top with empty stack");
	{
		std::cout	<< "top = "
					<< s.top()
					<< std::endl;
	}	

	return (0);
}
