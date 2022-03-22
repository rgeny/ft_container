/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:58:02 by rgeny             #+#    #+#             */
/*   Updated: 2022/03/22 14:31:23 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <memory>

#define SIZE 500000000


#include "vector.hpp"

int	main(void)
{


	ft::vector<int>	v1;
	ft::vector<int>::value_type	x;

	x = 4;
	std::cout << x << std::endl;


//	std::allocator<int>	Alloc;
//	try
//	{
//		int *				x		= Alloc.allocate(SIZE);
//		for (std::size_t i = 0; i < SIZE; i++)
//			x[i] = i;
//		for (std::size_t i = 0; i < SIZE; i++)
//			std::cout << x[i] << std::endl;
//		Alloc.deallocate(x, SIZE);
//	}
//	catch (std::exception & s)
//	{
//		std::cout << "\n\n\n\nTEST\n\n\n\n\n";
//		std::cout << s.what() << std::endl;
//	}
	return (0);
}

