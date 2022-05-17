/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 19:08:49 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/17 19:21:23 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

int	main	(void)
{
	std::cout	<< "clear empty vector<int> :"
				<< std::endl;
	{
		NAMESPACE::vector<int>	v;

		v.clear();

		_print_val_and_size<NAMESPACE::vector<int>, int> (v);
	}
	std::cout	<< "clear vector<int> :"
				<< std::endl;
	{
		NAMESPACE::vector<int>	v(10000, 17);

		v.clear();

		_print_val_and_size<NAMESPACE::vector<int>, int> (v);
	}
}
