/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_function.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 17:24:23 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/05 17:32:37 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

#define SIZE 13

template
<
	typename Iterator
>
static void	_test	(Iterator it1,
					 Iterator it2,
					 int dist)
{
	TRY_CATCH
	(
		PRINT_EXECUTE(std::distance(it1, it2));

		PRINT_AND_EXECUTE(std::advance(it1, dist));
		PRINT_EXECUTE(std::distance(it1, it2));
		PRINT_AND_EXECUTE(std::advance(it1, -dist));
		PRINT_EXECUTE(std::distance(it1, it2));

		PRINT_AND_EXECUTE(std::advance(it2, dist));
		PRINT_EXECUTE(std::distance(it1, it2));
		PRINT_AND_EXECUTE(std::advance(it2, -dist));
		PRINT_EXECUTE(std::distance(it1, it2));
	);
}

int	main	(void)
{
	NAMESPACE::vector<int>	v;

	for (int i = 0; i < SIZE; i++)
		v.push_back( -i * 4);
	for (int i = 0; i < SIZE / 2; i++)
		_test(v.begin() + i, v.end() - i - 1, i);

	return (0);
}
