/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:47:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/06 15:53:35 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

template
<
	typename Iterator
>
static void	_test	(Iterator src)
{
	std::cout	<< "t4\n";
	Iterator	cpy_assign,
				cpy_construct(src),
				cpy_parameter(src.base());
	
	cpy_assign = src;
	TRY_CATCH
	(
		PRINT_EXECUTE(src == cpy_assign);
		PRINT_EXECUTE(cpy_assign == cpy_construct);
		PRINT_EXECUTE(cpy_construct == cpy_parameter);
		PRINT_EXECUTE(cpy_parameter == src);
		PRINT_EXECUTE(*src == *cpy_assign);
		PRINT_EXECUTE(*cpy_assign == *cpy_construct);
		PRINT_EXECUTE(*cpy_construct == *cpy_parameter);
		PRINT_EXECUTE(*cpy_parameter == *src);

		PRINT_EXECUTE(src++ == cpy_assign);
		PRINT_EXECUTE(cpy_assign++ == cpy_construct);
		PRINT_EXECUTE(cpy_construct++ == cpy_parameter);
		PRINT_EXECUTE(cpy_parameter++ == src);
		PRINT_EXECUTE(*src++ == *cpy_assign);
		PRINT_EXECUTE(*cpy_assign++ == *cpy_construct);
		PRINT_EXECUTE(*cpy_construct++ == *cpy_parameter);
		PRINT_EXECUTE(*cpy_parameter++ == *src);

		PRINT_EXECUTE(++src == cpy_assign);
		PRINT_EXECUTE(++cpy_assign == cpy_construct);
		PRINT_EXECUTE(++cpy_construct == cpy_parameter);
		PRINT_EXECUTE(++cpy_parameter == src);
		PRINT_EXECUTE(*(++src) == *cpy_assign);
		PRINT_EXECUTE(*(++cpy_assign) == *cpy_construct);
		PRINT_EXECUTE(*(++cpy_construct) == *cpy_parameter);
		PRINT_EXECUTE(*(++cpy_parameter) == *src);
	)
}

int	main	(void)
{
	NAMESPACE::vector<int>			v_int;
	NAMESPACE::vector<std::string>	v_str;
	std::string	str("ab");

	for (int i = 0; i < 25; i++)
	{
		v_int.push_back(i);
		v_str.push_back(str);
		for (size_t j = 0; j < str.size(); j++)
			str[j]++;
	}

	_test(v_int.begin());
	_test(v_int.begin() + v_int.size() / 2);
	_test(v_int.end() - 5);

	_test(v_str.begin());
	_test(v_str.begin() + v_int.size() / 2);
	_test(v_str.end() - 5);

	return (0);
}
