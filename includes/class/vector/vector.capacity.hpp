/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.capacity.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 18:39:20 by rgeny             #+#    #+#             */
/*   Updated: 2022/05/17 18:41:00 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef VECTOR_CAPACITY_HPP
#  define VECTOR_CAPACITY_HPP

size_type	size	(void)	const
{
	return (this->_size);
}

size_type	max_size	(void) const
{
	return (this->_alloc.max_size());
}

size_type	capacity	(void) const
{
	return (this->_capacity);
}

# endif
#endif
