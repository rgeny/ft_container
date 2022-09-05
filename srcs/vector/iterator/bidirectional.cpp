/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:29:56 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/05 15:41:43 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

#define SIZE 7

template
<
	typename Iterator
>
static void	_test	(Iterator src)
{
	TRY_CATCH
	(
		Iterator	it(src);

		PRINT_EXECUTE(src == it);
		PRINT_EXECUTE(*src);
		PRINT_EXECUTE(*it);
		PRINT_AND_EXECUTE(it--);
		PRINT_EXECUTE(*src);
		PRINT_EXECUTE(*it);
		PRINT_AND_EXECUTE(--it);
		PRINT_EXECUTE(src == it);
		PRINT_EXECUTE(*src);
		PRINT_EXECUTE(*it);
	)
}

int	main	(void)
{
	NAMESPACE::vector<int>	v;

	for (int i = 0; i < SIZE; i++)
	{
		v.push_back(i * 3);
	}
	for (size_t i = 2; i < SIZE; i++)
		_test(v.begin() + i);
}
