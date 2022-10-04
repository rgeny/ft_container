/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:05:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/10/04 18:03:57 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_PRIVATE_HPP
#  define VECTOR_PRIVATE_HPP

template < typename InputIt >
void	_insert	(iterator pos,
				 InputIt first,
				 InputIt last,
				 std::input_iterator_tag)
{
	while (first != last)
	{
		this->insert(pos, *first);
		++first;
	}
}

template < typename ForwardIterator >
void	_insert	(iterator pos,
				 ForwardIterator first,
				 ForwardIterator last,
				 std::forward_iterator_tag)
{
	size_t	position = pos - this->begin(),
			count = std::distance(first, last);

	if (&(*first) < &(*last))
		this->insert(pos, count, *first);
	else
		this->insert(pos, count, T() );
	
	for (iterator it = this->begin() + position;
		 first != last;
		 ++it, ++first)
	{
		*it = *first;
	}
}

void	_destroy	(pointer it,
					 pointer ite)
{
	while (it != ite)
	{
		_T_alloc.destroy(it);
		it++;
	}
}

void	_destroy_all	(void)
{
	for (pointer it = _data, ite = _data + _size;
		 it != ite;
		 it++)
	{
		_T_alloc.destroy(it);
	}
}

void	_construct	(pointer first,
					 pointer end,
					 T	value)
{
	while (first < end)
	{
		_T_alloc.construct(first, value);
		++first;
	}
}
template
<
	typename InputIt
>
void	_construct	(pointer first,
					 pointer last,
					 InputIt first_val,
					 InputIt last_val)
{
	while (first < last &&
			first_val < last_val)
	{
		_T_alloc.construct(first, *first_val);
		++first;
		++first_val;
	}
}

# endif
#endif

