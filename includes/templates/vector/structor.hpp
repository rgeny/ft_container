/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:07:15 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/19 14:30:15 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_STRUCTOR_HPP
#  define VECTOR_STRUCTOR_HPP
#  define CLASS_NAME "ft::vector"

#  include "print.hpp"

explicit	vector	(allocator_type const & alloc = allocator_type())
	:_alloc(alloc)
	,_T_alloc(_T_allocator_type())
	,_size(0)
	,_capacity(0)
	,_data(NULL)
{
#ifdef __DEBUG__
DFL_CTOR
#endif
}

explicit	vector	(size_type n
					,value_type const & val = value_type()
					,allocator_type const & alloc = allocator_type())
	:_alloc(alloc)
	,_T_alloc(_T_allocator_type())
	,_size(0)
	,_capacity(0)
	,_data(NULL)
{
#ifdef __DEBUG__
PAR_CTOR
#endif
	this->insert(this->begin(), n, val);
}

template < class InputIterator >
vector	(InputIterator first
		,InputIterator last
		,allocator_type const & alloc = allocator_type()
		,typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type = 0)
	:_alloc(alloc)
	,_T_alloc(_T_allocator_type())
	,_size(0)
	,_capacity(0)
	,_data(NULL)
{
#ifdef __DEBUG__
RANGE_CTOR
#endif
	this->insert(this->begin(), first, last);
}

vector	(vector const & src)
	:_alloc(src._alloc)
	,_T_alloc(src._T_alloc)
	,_size(0)
	,_capacity(0)
	,_data(NULL)
{
#ifdef __DEBUG__
CPY_CTOR
#endif
	this->insert(this->begin(), src.begin(), src.end());
}

~vector	(void)
{
#ifdef __DEBUG__
	DTOR
#endif
	this->clear();
#ifdef __DEBUG__
	std::cout	<< "_capacity = "
				<< _capacity
				<< std::endl
				<< "_data = "
				<< _data
				<< std::endl;
#endif
	_T_alloc.deallocate(_data, _capacity);
}

#  undef CLASS_NAME
# endif
#endif
