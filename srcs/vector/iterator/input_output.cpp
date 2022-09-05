/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_output.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 14:09:39 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/05 18:12:56 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

#define SIZE 5

template
<
	typename Iterator
>
static void	_test	(Iterator it1,
					 Iterator it2)
{
	TRY_CATCH
	(
		PRINT_EXECUTE(*it1);
		PRINT_EXECUTE(*it2);
		PRINT_EXECUTE(it1->size());
		PRINT_EXECUTE(it2->size());
		PRINT_EXECUTE(it1 == it2);
		PRINT_EXECUTE(it2 == it1);
		PRINT_EXECUTE(it1 != it2);
		PRINT_EXECUTE(it2 != it1);
	)
}

int	main	(void)
{
	NAMESPACE::vector<std::string>	v;
	std::string	str("abc");

	for (int i = 0; i < SIZE; i++)
	{
		v.push_back(str);
		for (size_t j = 0; j < str.size(); j++)
			str[j]++;
	}

	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			_test(v.begin() + i, v.begin() + j);
		}
	}
	PRINT_EXECUTE((v.begin() + SIZE) == (v.end()));
	PRINT_EXECUTE((v.begin() + SIZE) != (v.end()));

	return (0);
}
