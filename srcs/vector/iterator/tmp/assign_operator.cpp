/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_operator.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 19:28:40 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/19 20:09:06 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

#define SIZE 12
#define VAL 164.17f

int	main	(void)
{
	NAMESPACE::vector<double>	v(SIZE);

	init_vector<double>(v, SIZE, VAL);

	for (NAMESPACE::vector<double>::iterator it = v.begin(), ite = v.end(), it2 = it;
		it != ite;
		it++, it2 = it)
	{
		std::cout	<< "it : "
					<< *it
					<< std::endl
					<< "copy : "
					<< *it2
					<< std::endl
					<< "addr : "
					<< std::boolalpha
					<< (it.base() == it2.base())
					<< std::endl;
	}
}
