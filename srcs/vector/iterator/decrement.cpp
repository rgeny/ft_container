/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrement.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:40:11 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/19 21:10:28 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

#define SIZE 56
#define VAL 2147483647

int	main	(void)
{
	NAMESPACE::vector<long>	v(SIZE);

	init_vector<long>(v, SIZE, VAL);

	std::cout	<< "post decrement"
				<< std::endl;
	{
		for (NAMESPACE::vector<long>::iterator it = v.begin(), ite = v.end();
			it != ite;)
		{
			if (ite == v.end())
				ite--;
			std::cout	<< *ite--
						<< std::endl;
		}
	}

	std::cout	<< "pre decrement"
				<< std::endl;
	{
		size_t	i = 0;
		for (NAMESPACE::vector<long>::iterator it = v.end();
			i < v.size() - 1;
			i++)
		{
			std::cout	<< *--it
						<< std::endl;
		}
	}
}
