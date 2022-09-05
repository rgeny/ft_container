/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:42:30 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/05 17:16:42 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

//a + n
//n + a
//a - n
//a - b
//a < b
//a > b
//a <= b
//a >= b
//a += n
//a -= n
//a[n]
#define SIZE 8

template
<
	typename Iterator
>
static void	_test	(Iterator it,
					 size_t n)
{
	TRY_CATCH
	(
		Iterator	cpy(it);

		PRINT_EXECUTE(cpy < it);
		PRINT_EXECUTE(cpy <= it);
		PRINT_EXECUTE(cpy > it);
		PRINT_EXECUTE(cpy >= it);
		PRINT_EXECUTE((cpy + n) < it);
		PRINT_EXECUTE((cpy + n) <= it);
		PRINT_EXECUTE((cpy + n) > it);
		PRINT_EXECUTE((cpy + n) >= it);
		PRINT_EXECUTE(cpy[n] < *it);
		PRINT_EXECUTE(cpy[n] <= *it);
		PRINT_EXECUTE(cpy[n] > *it);
		PRINT_EXECUTE(cpy[n] >= *it);
		PRINT_EXECUTE((cpy - n) < it);
		PRINT_EXECUTE((cpy - n) <= it);
		PRINT_EXECUTE((cpy - n) > it);
		PRINT_EXECUTE((cpy - n) >= it);
		PRINT_EXECUTE(cpy[-n] < *it);
		PRINT_EXECUTE(cpy[-n] <= *it);
		PRINT_EXECUTE(cpy[-n] > *it);
		PRINT_EXECUTE(cpy[-n] >= *it);

		PRINT_AND_EXECUTE(cpy += n);
		PRINT_EXECUTE(cpy < it);
		PRINT_EXECUTE(cpy <= it);
		PRINT_EXECUTE(cpy > it);
		PRINT_EXECUTE(cpy >= it);
		PRINT_EXECUTE(*cpy < it[n]);
		PRINT_EXECUTE(*cpy <= it[n]);
		PRINT_EXECUTE(*cpy > it[n]);
		PRINT_EXECUTE(*cpy >= it[n]);

		PRINT_AND_EXECUTE(cpy -= n);
		PRINT_EXECUTE(cpy < it);
		PRINT_EXECUTE(cpy <= it);
		PRINT_EXECUTE(cpy > it);
		PRINT_EXECUTE(cpy >= it);

		PRINT_AND_EXECUTE(cpy -= n);
		PRINT_EXECUTE(cpy < it);
		PRINT_EXECUTE(cpy <= it);
		PRINT_EXECUTE(cpy > it);
		PRINT_EXECUTE(cpy >= it);
		PRINT_EXECUTE(*cpy < it[-n]);
		PRINT_EXECUTE(*cpy <= it[-n]);
		PRINT_EXECUTE(*cpy > it[-n]);
		PRINT_EXECUTE(*cpy >= it[-n]);
	)
}

int	main	(void)
{
	NAMESPACE::vector<int>	v;

	for (int i = 0; i < SIZE; i++)
		v.push_back(i * 7 / 3);
	for (int i = 0; i < SIZE / 2; i++)
		_test(v.begin() + i, i);
}
