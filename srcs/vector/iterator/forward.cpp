/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:52:23 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/05 15:10:32 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

// dfl ctor -->	type a; type()
// it1 = it2
// *it++;
// *it;
#define SIZE 5

template
<
	typename Iterator
>
static void	_test	(Iterator src)
{
	TRY_CATCH
	(
		Iterator	it;

		PRINT_EXECUTE(it == Iterator());
		PRINT_EXECUTE(it == src);
		PRINT_AND_EXECUTE(it = src);
		PRINT_EXECUTE(*it);
		PRINT_EXECUTE(*src);
		PRINT_EXECUTE(*it++);
		PRINT_EXECUTE(*it);
		PRINT_EXECUTE(*src);
		PRINT_EXECUTE(*src++);
		PRINT_EXECUTE(*it);
		PRINT_EXECUTE(*src);
	)
}

int	main	(void)
{
	NAMESPACE::vector<size_t>	v;

	for (size_t i = 0; i < SIZE; i++)
		v.push_back((i - 1) * (i + 1));
	
	for (size_t i = 0; i < SIZE - 1; i++)
		_test(v.begin() + i);
}
