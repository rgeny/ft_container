/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dctor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:36:06 by rgeny             #+#    #+#             */
/*   Updated: 2022/03/22 14:30:57 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef VECTOR_HPP
# ifndef DCTOR_HPP
#  define DCTOR_HPP

explicit	vector	(const allocator_type &		alloc	= allocator_type())
{
	DFL_CTOR("Vector")
}

explicit	vector	(size_type					n
					,const value_type &			val		= value_type()
					,const allocator_type &		alloc	= allocator_type())
{
	FILL_CTOR("Vector")
}

template <class InputIterator>
			vector	(InputIterator				first
					,InputIterator				last
					,const allocator_type &		alloc	= allocator_type())
{
	RANGE_CTOR("Vector")
}
			vector	(const vector &				x)
{
	CPY_CTOR("Vector")
}

# endif
# undef DCTOR_HPP
#endif
