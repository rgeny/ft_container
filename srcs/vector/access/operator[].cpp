/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator[].cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 10:09:46 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/03 10:14:56 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

template
<
	typename T,
	typename Class
>
static void	_test	(Class v,
					 size_t pos)
{
	TRY_CATCH
	(
		_print_nl	("std::cout	<< v[" +
					 ft::to_string(pos) +
					 "] << std::endl;");
		std::cout	<< v[pos]
					<< std::endl;
	)
}

int	main	(void)
{
	NAMESPACE::vector<short>	v;

	for (short i = 0; i < 10; i++)
		v.push_back(i * i * i);
	for (size_t i = 0; i < 10; i++)
		_test<short>	(v, i);
}
