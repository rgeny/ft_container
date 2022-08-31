/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:35:12 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/31 14:55:52 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_MODIFIERS_HPP

template < class InputIterator >
void	assign	(InputIterator first
				,InputIterator last
				,typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type = 0)
{
	if (first == last) //à revoir
		return ;
	for (pointer it = _data, ite = _data + _capacity;
		 it < ite;
		 it++)
	{
		_alloc.destroy(it);
	}
	_alloc.deallocate(_data, _capacity);
	_size = std::distance(first, last);
	_capacity = _size;
	_data = _alloc.allocate(_size);
	for (size_type i = 0; first != last; i++, first++)
		_alloc.construct(_data + i, *first);
}
void	assign	(size_type n
				,const_reference val)
{
	for (pointer it = _data, ite = _data + _size;
		 it < ite;
		 it++)
	{
		 _alloc.destroy(it);
	}
	_alloc.deallocate(_data, _size);
	_size = n;
	_capacity = n;
	_data = _alloc.allocate(n);
	for (pointer it = _data, ite = _data + _size;
		 it < ite;
		 it++)
	{
		_alloc.construct(it, val);
	}
}

void	clear	(void)
{
	for (pointer it = _data, ite = _data + _size;
		 it < ite;
		 it++)
	{
		_alloc.destroy(it);
	}
	_size = 0;
}

//iterator	insert	(iterator position,
//					 value_type const & val)
//{
//	return (_data);
//}
//void insert (iterator position, size_type n, const value_type& val);
//template <class InputIterator>
//void insert (iterator position, InputIterator first, InputIterator last);

void	reserve	(size_type new_cap)
{
#ifdef FT_CONTAINER_DEBUG
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
	this->clear();
	_alloc.deallocate(_data, _capacity);
	_data = new_data;
	_capacity = new_cap;

#ifdef FT_CONTAINER_DEBUG
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
	this->reserve(count);
	
	if (_size < count)
	{
		for (size_type i = _size; i < count; i++)
			_alloc.construct(_data + i, value);
	}
	else
	{
		for (size_type i = _size; i < count; i++)
			_alloc.destroy(_data + i);
	}

	_size = count;
}

//iterator	insert	(iterator pos,
//					 const_reference value)
//{
//	this->insert(pos, 1, value);
//	return (pos - 1);
//}
//
//void	insert	(iterator pos,
//				 size_type count,
//				 const_reference value)
//{
//	this->resize(_size + count, value);
//
//	for (iterator it = this->end() + count - 1, ite = this->end - 1;
//		 it != ite;
//		 --it)
//	{
//		*it = *(it - count);
//	}
//}
//
//
//1 2 3 4 5 6 7 8
//
//insert(1, 2)
//
//1 2 3 4 5 6 7 8 0 0
//1 2 3 4 5 6 7 8 0 0
//
//template
//<
//	typename InputIt
//>
//void	insert	(iterator pos,
//				 InputIt first,
//				 InputIt last)
//{
//}
//


# endif
#endif
