/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:06:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/27 12:35:38 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# ifndef NAMESPACE
#  define NAMESPACE ft
#  define FT "ft"
# else
# define FT "std"
# endif

# define PRINT_EXECUTE(fct)	std::cout	<< #fct \
										<< " == " \
										<< (fct) \
										<< std::endl;
# define EXECUTE_AND_PRINT(ope)	ope; \
								std::cout	<< #ope \
											<< std::endl;

# include <iostream>
# include <algorithm>
# include <list>
# include <string>
# include <iterator>
# include <climits>

# include <vector>
# include "vector.hpp"
# include <map>

# include <stack>
# include "stack.hpp"

template<class T>
void	_print_val	(T val)
{
	std::cout	<< val
				<< std::endl;
}

template<class T>
void	_print_size (T & v)
{
	std::cout	<< "size     : "
				<< v.size()
				<< std::endl
				<< "max_size : "
				<< v.max_size()
				<< std::endl
				<< "capacity : "
				<< v.capacity()
				<< std::endl;
}

template<class T1, class T2>
void	_print_val_and_size	(T1 & v)
{
	_print_size(v);
	std::for_each(v.begin(), v.end(), _print_val<T2>);
}

void	_print_nl	(std::string msg);

template <class T>
void	init_vector	(NAMESPACE::vector<T> & v
					,size_t size
					,T const & val)
{
	for (size_t i = 0; i < size; i++)
		v[i] = ((val + i) * size) / (i + 1);
}

template
<
	typename T,
	class Container
>
void	fill_stack	(NAMESPACE::stack<T, Container> & stack,
					 T start,
					 T end)
{
	while (start <= end)
	{
		stack.push(start);
		start++;
	}
	std::cout	<< "size = "
				<< stack.size()
				<< std::endl;
}

template
<
	typename T,
	class Container
>
void	fill_stack	(NAMESPACE::stack<T, Container> & stack,
					 T start,
					 T end,
					 std::string str_name)
{
	while (start <= end)
	{
		stack.push(start);
		start++;
	}
	std::cout	<< str_name
				<< ".size() = "
				<< stack.size()
				<< std::endl;
}

template
<
	typename T,
	class Container
>
void	empty_the_stack	(NAMESPACE::stack<T, Container> & stack)
{
	_print_nl	("empty the stack");
	while (!stack.empty())
	{
		std::cout	<< stack.top()
					<< " ";
		stack.pop();
	}
	std::cout	<< std::endl
				<< "size = "
				<< stack.size()
				<< std::endl;
}

template
<
	typename T,
	class Container
>
void	empty_the_stack	(NAMESPACE::stack<T, Container> & stack,
						 std::string str_name)
{
	_print_nl	((std::string("empty_the_stack") + str_name).c_str());
	while (!stack.empty())
	{
		std::cout	<< stack.top()
					<< " ";
		stack.pop();
	}
	std::cout	<< std::endl
				<< str_name
				<< ".size = "
				<< stack.size()
				<< std::endl;
}

//template<>
//void	init_vector<std::string>	(NAMESPACE::vector<std::string> & v
//									,size_t size
//									,std::string const & val)
//{
//	for (size_t i = 0; i < size; i++)
//	{
//		v[i] = val;
//	}
//}

#endif
