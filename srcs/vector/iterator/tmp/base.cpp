/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:20:54 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/19 20:25:09 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

#define SIZE 48
#define VAL 17

int	main	(void)
{
	NAMESPACE::vector<short>	v(SIZE);

	init_vector<short>(v, SIZE, VAL);

	std::cout	<< "test base : "
				<< std::endl;
	{
		for (NAMESPACE::vector<short>::iterator it = v.begin(), ite = v.end();
			it != ite;
			it++)
		{
			std::cout	<< *(it.base())
						<< std::endl;
		}
	}
}
