/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 17:05:33 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/10 16:11:53 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_PRIVATE_HPP
#  define VECTOR_PRIVATE_HPP

void	_destroy	(pointer it,
					 pointer ite)
{
	while (it != ite)
	{
		_alloc.destroy(it);
		it++;
	}
}

void	_destroy_all	(void)
{
	for (pointer it = _data, ite = _data + _size;
		 it != ite;
		 it++)
	{
		_alloc.destroy(it);
	}
}

void	_construct	(pointer first,
					 pointer end,
					 T	value)
{
	while (first < end)
	{
		_alloc.construct(first, value);
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
		_alloc.construct(first, *first_val);
		++first;
		++first_val;
	}
}

# endif
#endif

