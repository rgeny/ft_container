/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:06:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/19 21:04:54 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# ifndef NAMESPACE
#  define NAMESPACE ft
#  define FT
# endif

# include <iostream>
# include <vector>
# include <algorithm>
# include <list>
# include <string>
# include <iterator>

# include "vector.hpp"

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
