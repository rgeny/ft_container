/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   increment.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:40:11 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/19 21:10:35 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

#define SIZE 56
#define VAL -7

int	main	(void)
{
	NAMESPACE::vector<int>	v(SIZE);

	init_vector<int>(v, SIZE, VAL);

	std::cout	<< "post increment"
				<< std::endl;
	{
		for (NAMESPACE::vector<int>::iterator it = v.begin(), ite = v.end();
			it != ite;)
		{
			std::cout	<< *it++
						<< std::endl;
		}
	}

	std::cout	<< "pre increment"
				<< std::endl;
	{
		size_t	i = 0;
		for (NAMESPACE::vector<int>::iterator it = v.begin();
		
			i < v.size() - 1;
			i++)
		{
			std::cout	<< *++it
						<< std::endl;
		}
	}
}
