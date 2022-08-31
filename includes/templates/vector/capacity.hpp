/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.capacity.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:39:20 by rgeny             #+#    #+#             */
/*   Updated: 2022/08/30 14:40:33 by rgeny            ###   ########.fr       */
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

# endif
#endif
