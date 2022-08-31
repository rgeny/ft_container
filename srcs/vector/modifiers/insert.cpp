/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 16:32:04 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/31 19:58:13 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

template
<
	typename T,
	typename Class
>
static void	_test	(Class & v,
					 size_t pos,
					 typename Class::size_type count,
					 T value)
{
	try
	{
		_print_nl	(std::string("insert(v.begin() + ") +
					  std::to_string(pos) +
					  ", " +
					  std::to_string(count) +
					  ", " +
					  std::to_string(value) +
					  ")");
		v.insert(v.begin() + pos, count, value);
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
					 size_t pos,
					 Class & v2,
					 size_t first,
					 size_t last)
{
	try
	{
		_print_nl	(std::string("insert(v.begin() + ") +
					  std::to_string(pos) +
					  ", v2.begin() + " +
					  std::to_string(first) +
					  ", v2.end() - " +
					  std::to_string(last) +
					  ")");
		v.insert(v.begin() + pos, v2.begin() + first, v2.end() - last);
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
	NAMESPACE::vector<int>	v;

	_test<int>	(v, 0, 3, 3);
	_test<int>	(v, 0, 2, 4);
	_test<int>	(v, 3, 1, 5);
	_test<int>	(v, v.size(), 4, 1);
	_test<int>	(v, v.size() - 7, 5, 2);
	_test<int>	(v, 0, 6, 0);
	_test<int>	(v, 0, 0, 4);

	NAMESPACE::vector<int>	v2;
	_test<int>	(v2, 0, v, 0, 0);
	_test<int>	(v2, v2.size() / 2, v, 0, 0);
	_test<int>	(v2, 0, v, v.size() / 2, 0);
	_test<int>	(v2, 0, v, 0, v.size() / 2);
	_test<int>	(v, v.size() / 4, v, 0, 0);
	_test<int>	(v, v.size() / 4, v, v.size(), v.size());

//	_test<int>	(v, v.size() + 1, 2, 7);
}

//3 -->end
//3
//3 --> rhs
//4
//4 --> lhs

//4 -->ite
//4
//3
//3
//3 --> rhs
//5 --> lhs


