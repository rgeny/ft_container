/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 12:29:45 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/01 15:16:52 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

template
<
	typename T,
	typename Class
>
static void	_test	(Class & v,
					 size_t n,
					 T const & val)
{
	try
	{
		_print_nl	(std::string("assign(") +
					 std::to_string(n) +
					 ", " +
					 std::to_string(val) +
					 ")");
		v.assign(n, val);
		_print_val_and_size<T>(v);
	}
	catch (std::exception const & err)
	{
		std::cout	<< "error"
					<< std::endl;
	}
}

template
<
	typename T,
	typename Class
>
static void	_test	(Class & v,
					 Class const & v2,
					 size_t first,
					 size_t last)
{
	try
	{
		_print_nl	(std::string("assign(v2.begin() + ") +
					 std::to_string(first) +
					 ", v2.end() - " +
					 std::to_string(last) +
					 ")");
		v.assign(v2.begin() + first, v2.end() - last);
		_print_val_and_size<T>(v);
	}
	catch (std::exception const & err)
	{
		std::cout	<< "error"
					<< std::endl;
	}
}

int	main	(void)
{
	NAMESPACE::vector<char>	v;
	_test<char>	(v, 0, 'a');
	_test<char>	(v, 17, 'b');
	_test<char>	(v, 3, 'c');
	_test<char>	(v, v.size(), 'd');
	_test<char>	(v, 98, 'e');
	_test<char>	(v, 0, 'f');
	_test<char>	(v, 39, 'g');

	NAMESPACE::vector<char>	v2, v3(17);
	_test<char>	(v2, v, 0, 0);
	_test<char>	(v2, v, 0, v.size());
	_test<char>	(v2, v, v.size(), 0);
	_test<char>	(v2, v, v.size(), v.size());
	_test<char>	(v2, v, v.size() - 1, v.size());
	_test<char>	(v2, v, v.size(), v.size() - 1);
	_test<char>	(v2, v, v.size() - 1, v.size() - 1);
	_test<char>	(v3, 0, 0);
}
