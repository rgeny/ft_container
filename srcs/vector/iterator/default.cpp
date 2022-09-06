/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:47:53 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/06 18:03:21 by rgeny            ###   ########.fr       */
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
	
	NAMESPACE::vector<int>::iterator				vit;
	NAMESPACE::vector<int>::const_iterator			const_vit;
	NAMESPACE::vector<std::string>::iterator		strit;
	NAMESPACE::vector<std::string>::const_iterator	const_strit;

	vit			= v_int.begin();
	const_vit	= v_int.begin();
	_test(vit);
	_test(const_vit);
	vit			= v_int.begin() + v_int.size() / 2;
	const_vit	= v_int.begin() + v_int.size() / 2;
	_test(vit);
	_test(const_vit);
	vit			= v_int.end() - 5;
	const_vit	= v_int.end() - 5;
	_test(vit);
	_test(const_vit);

	strit			= v_str.begin();
	const_strit	= v_str.begin();
	_test(strit);
	_test(const_strit);
	strit			= v_str.begin() + v_str.size() / 2;
	const_strit	= v_str.begin() + v_str.size() / 2;
	_test(strit);
	_test(const_strit);
	strit			= v_str.end() - 5;
	const_strit	= v_str.end() - 5;
	_test(strit);
	_test(const_strit);

	return (0);
}
