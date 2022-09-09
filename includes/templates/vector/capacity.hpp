/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:39:20 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/09 19:32:36 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_CAPACITY_HPP
#  define VECTOR_CAPACITY_HPP

size_type	size	(void)	const
{
	return (_size);
}

size_type	max_size	(void) const
{
	return (_alloc.max_size());
}

size_type	capacity	(void) const
{
	return (_capacity);
}

bool	empty	(void) const
{
	return (_size == 0);
}

void	reserve	(size_type new_cap)
{
#ifdef __DEBUG__
	std::cout	<< "_capacity in reserve begin = "
				<< _capacity
				<< std::endl
				<< "_data in reserve begin = "
				<< _data
				<< std::endl;
#endif

	if (new_cap > this->max_size())
		throw (std::length_error(FT_VECTOR_LENGTH_ERROR));
	if (new_cap <= _capacity)
		return ;

	pointer	new_data = _alloc.allocate(new_cap);

	for (size_type i = 0;
		 i < _size;
		 i++)
	{
		_alloc.construct(new_data + i, _data[i]);
	}
	_destroy_all();
	_alloc.deallocate(_data, _capacity);
	_data = new_data;
	_capacity = new_cap;

#ifdef __DEBUG__
	std::cout	<< "_capacity in reserve end = "
				<< _capacity
				<< std::endl
				<< "_data in reserve end = "
				<< _data
				<< std::endl;
#endif
}

void	resize	(size_type count,
				 value_type value = T() )
{
	if (count == _size)
		return ;
	if (count > _capacity)
		this->reserve(ft::max(count, _size * 2));

	if (count > _size)
	{
		for (size_type i = _size; i < count; i++)
			_alloc.construct(_data + i, value);
	}
	else
	{
		for (size_type i = count; i < _size; i++)
			_alloc.destroy(_data + i);
	}

	_size = count;
}



# endif
#endif
