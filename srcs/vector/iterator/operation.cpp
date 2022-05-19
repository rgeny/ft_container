/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 21:11:25 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/19 21:31:13 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

#define SIZE 9100
#define VAL 2147483647

int	main	(void)
{
	NAMESPACE::vector<unsigned int>	v(SIZE);

	init_vector<unsigned int>(v, SIZE, VAL);

	std::cout	<< std::endl
				<< "operator+"
				<< std::endl;
	{
		for (size_t i = 0, size = v.size();
			i < size;
			i++)
		{
			std::cout	<< *(v.begin() + i)
						<< std::endl;
		}
	}
	std::cout	<< std::endl
				<< "operator-"
				<< std::endl;
	{
		for (size_t i = 1, size = v.size();
			i <= size;
			i++)
		{
			std::cout	<< *(v.end() - i)
						<< std::endl;
		}
	}
	std::cout	<< std::endl
				<< "operator+="
				<< std::endl;
	{
		size_t	i = 1;
		for (NAMESPACE::vector<unsigned int>::iterator it = v.begin();
			i < v.size();
			i += i)
		{
			std::cout	<< *it
						<< std::endl;
			it += i;
		}
	}
	std::cout	<< std::endl
				<< "operator-="
				<< std::endl;
	{
		size_t	i = 1;
		for (NAMESPACE::vector<unsigned int>::iterator it = v.end();
			i < v.size();
			i += i)
		{
			it -= i;
			std::cout	<< *it
						<< std::endl;
		}
	}
}
