/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   at.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:27:58 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/02 19:42:18 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

template
<
	typename T,
	typename Class
>
static void	_test	(Class v,
					 size_t n)
{
	TRY_CATCH
	(
		_print_nl	(std::string("v.at(") +
					 ft::to_string(n) +
					 ");");
		std::cout	<< v.at(n)
					<< std::endl;
	);
}

int	main	(void)
{
	NAMESPACE::vector<std::string>	v;
	std::string	str("abc");

	for (int i = 0; i < 24; i++)
	{
		v.push_back(str);
		str[0]++;
		str[1]++;
		str[2]++;
	}

	for (size_t i = 0; i <= v.size(); i++)
		_test<std::string>(v, i);
}
