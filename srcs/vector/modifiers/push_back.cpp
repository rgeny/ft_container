/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 18:03:18 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/02 18:16:07 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

template
<
	typename T,
	typename Class
>
static void	_test	(Class & v,
					 T value)
{
	TRY_CATCH
	(
		std::cout	<< std::string("v.push_back( ") +
					   std::to_string(value) +
					   ");";
		v.push_back(value);
		_print_val_and_size<T>	(v);
	);
}

int	main	(void)
{
	NAMESPACE::vector<int>	v;

	for (size_t i = 0; i < 15; i++)
		_test(v, i * v.size());
}
