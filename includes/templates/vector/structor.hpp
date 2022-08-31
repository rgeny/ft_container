/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:07:15 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/31 14:22:02 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_STRUCTOR_HPP
#  define VECTOR_STRUCTOR_HPP

explicit	vector	(allocator_type const & alloc = allocator_type())
	:_alloc(alloc)
	,_size(0)
	,_capacity(0)
	,_data(NULL)
{	}

explicit	vector	(size_type n
					,value_type const & val = value_type()
					,allocator_type const & alloc = allocator_type())
	:_alloc(alloc)
	,_size(0)
	,_capacity(0)
	,_data(NULL)
{
	this->assign(n, val);
}

template < class InputIterator >
vector	(InputIterator first
		,InputIterator last
		,allocator_type const & alloc = allocator_type()
		,typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type = 0)
	:_alloc(alloc)
	,_size(0)
	,_capacity(0)
	,_data(NULL)
{
	this->assign(first, last);
}

vector	(vector const & src)
	:_alloc(src._alloc)
	,_size(0)
	,_capacity(0)
	,_data(NULL)
{
	this->assign(src.begin(), src.end());
}

~vector	(void)
{
#ifdef FT_CONTAINER_DEBUG
	std::cout	<< "vector destructor."
				<< std::endl;
#endif
	this->clear();
#ifdef FT_CONTAINER_DEBUG
	std::cout	<< "_capacity = "
				<< _capacity
				<< std::endl
				<< "_data = "
				<< _data
				<< std::endl;
#endif
	_alloc.deallocate(_data, _capacity);
}

# endif
#endif