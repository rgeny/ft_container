/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:38:26 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/19 21:36:14 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

# define SIZE 31
# define VAL 4

int	main	(void)
{
	NAMESPACE::vector<int>	v(SIZE, VAL);
	std::cout	<< std::boolalpha;
	
	init_vector<int>(v, SIZE, VAL);
	
	std::cout	<< "Test =="
				<< std::endl;
	{
		NAMESPACE::vector<int>::iterator	it	= v.begin(),
											ite	= v.end();
		for (;it != ite;it++)
		{
			std::cout	<< (it == ite)
						<< std::endl;
		}
		std::cout	<< (it == ite)
					<< std::endl;
	}
	std::cout	<< "Test !="
				<< std::endl;
	{
		NAMESPACE::vector<int>::iterator	it	= v.begin(),
											ite	= v.end();
		for (;it != ite;it++)
		{
			std::cout	<< (it != ite)
						<< std::endl;
		}
		std::cout	<< (it != ite)
					<< std::endl;
	}
	std::cout	<< "Test <"
				<< std::endl;
	{
		NAMESPACE::vector<int>::iterator	it	= v.begin(),
											ite	= v.end();
		for (;it != ite;it++)
		{
			std::cout	<< (it < ite)
						<< std::endl;
		}
		std::cout	<< (it < ite)
					<< std::endl;
	}
	std::cout	<< "Test >"
				<< std::endl;
	{
		NAMESPACE::vector<int>::iterator	it	= v.begin(),
											ite	= v.end();
		for (;it != ite;it++)
		{
			std::cout	<< (it > ite)
						<< std::endl;
		}
		std::cout	<< (it > ite)
					<< std::endl;
	}
	std::cout	<< "Test <="
				<< std::endl;
	{
		NAMESPACE::vector<int>::iterator	it	= v.begin(),
											ite	= v.end();
		for (;it != ite;it++)
		{
			std::cout	<< (it <= ite)
						<< std::endl;
		}
		std::cout	<< (it <= ite)
					<< std::endl;
	}
	std::cout	<< "Test >="
				<< std::endl;
	{
		NAMESPACE::vector<int>::iterator	it	= v.begin(),
											ite	= v.end();
		for (;it != ite;it++)
		{
			std::cout	<< (it >= ite)
						<< std::endl;
		}
		std::cout	<< (it >= ite)
					<< std::endl;
	}
}
