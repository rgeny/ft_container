/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dereferencing.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:26:11 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/19 20:34:43 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

#define SIZE 185
#define VAL 0.000001
#define VAL2 "abc"

int	main	(void)
{
	NAMESPACE::vector<float>	v(SIZE);

	init_vector<float>(v, SIZE, VAL);

	std::cout	<< "Test operator*"
				<< std::endl;
	{
		for (NAMESPACE::vector<float>::iterator it = v.begin(), ite = v.end();
			it != ite;
			it++)
		{
			std::cout	<< *it
						<< std::endl;
		}
	}

	std::cout	<< "Test operator->"
				<< std::endl;
	{
		NAMESPACE::vector<std::string>	v(SIZE, VAL2);

		for (NAMESPACE::vector<std::string>::iterator it = v.begin(), ite = v.end();
			it != ite;
			it++)
		{
			std::cout	<< it->size()
						<< ":"
						<< it->c_str()
						<< std::endl;
		}
	}

	std::cout	<< "Test operator[]"
				<< std::endl;
	{
		NAMESPACE::vector<float>::iterator	it = v.begin();

		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout	<< it[i]
						<< std::endl;
		}
	}
}
