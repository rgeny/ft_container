/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modifiers.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:35:12 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/01 15:04:22 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_MODIFIERS_HPP

template < class InputIterator >
void	assign	(InputIterator first
				,InputIterator last
				,typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type = 0)
{
	this->clear();
	this->insert(this->begin(), first, last);
//	this->insert(0, first, last);
//	if (first == last) //à revoir
//		return ;
//	for (pointer it = _data, ite = _data + _capacity;
//		 it < ite;
//		 it++)
//	{
//		_alloc.destroy(it);
//	}
//	_alloc.deallocate(_data, _capacity);
//	_size = std::distance(first, last);
//	_capacity = _size;
//	_data = _alloc.allocate(_size);
//	for (size_type i = 0; first != last; i++, first++)
//		_alloc.construct(_data + i, *first);
}
void	assign	(size_type n
				,const_reference val)
{
	this->clear();
	this->insert(this->begin(), n, val);
//	this->insert(0, n, val);
//	for (pointer it = _data, ite = _data + _size;
//		 it < ite;
//		 it++)
//	{
//		 _alloc.destroy(it);
//	}
//	_alloc.deallocate(_data, _size);
//	_size = n;
//	_capacity = n;
//	_data = _alloc.allocate(n);
//	for (pointer it = _data, ite = _data + _size;
//		 it < ite;
//		 it++)
//	{
//		_alloc.construct(it, val);
//	}
}

void	clear	(void)
{
	_destroy_all();
	_size = 0;
}

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
	_destroy_all();
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
	if (count > _capacity)
		this->reserve(ft::max(count, _size * 2));

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

iterator	insert	(iterator pos,
					 const_reference value)
{
	size_t	emplace = pos - this->begin();
	this->insert(pos, 1, value);
	return (this->begin() + emplace);
}

void	insert	(iterator pos,
				 size_type count,
				 const_reference value)
{
	size_t	emplace = pos - this->begin();
#ifdef FT_CONTAINER_DEBUG
	std::cout	<< "emplace = "
				<< emplace
				<< std::endl
				<< "insert pos = "
				<< &(*pos)
				<< std::endl
				<< "insert end() = "
				<< &(*this->end())
				<< std::endl
				<< "insert begin() = "
				<< &(*this->begin())
				<< std::endl
				<< "insert count = "
				<< count
				<< std::endl
				<< "_size + count = "
				<< _size + count
				<< std::endl;
#endif
	this->resize(ft::max(count, _size + count), value);

	if (emplace >= _size - count)
		return ;
#ifdef FT_CONTAINER_DEBUG
	std::cout	<< "t1\n";
#endif


	for (iterator	lhs = this->end() - 1,
					rhs = lhs - count,
					ite = this->begin() + emplace - 1;
		 rhs != ite;
		 lhs--, rhs--)
	{
		ft::swap(*lhs, *rhs);
	}
}


template
<
	typename InputIt
>
void	insert	(iterator pos,
				 InputIt first,
				 InputIt last,
				 typename ft::enable_if<!ft::is_integral<InputIt>::value>::type = 0)
{
	size_t	emplace = pos - this->begin(),
			count = std::distance(first, last);

#ifdef FT_CONTAINER_DEBUG
	std::cout	<< "insert template count = "
				<< count
				<< std::endl
				<< "insert template emplace ="
				<< emplace
				<< std::endl;
#endif
	this->insert(pos, count, T() );

	for (iterator it = this->begin() + emplace;
		 first != last;
		 it++, first++)
	{
		*it = *first;
	}
		 
}



# endif
#endif
