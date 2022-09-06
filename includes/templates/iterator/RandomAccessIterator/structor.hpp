/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:54:46 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/06 16:11:58 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RANDOMACCESSITERATOR_HPP
# ifndef STRUCTOR_HPP
#  define STRUCTOR_HPP
#  define CLASS_NAME "RandomAccessIterator"

RandomAccessIterator	(void)
	:_M_current(Iterator())
{
#ifdef __DEBUG__
DFL_CTOR
#endif
}

RandomAccessIterator	(Iterator const & it)
	:_M_current(it)
{
#ifdef __DEBUG__
PAR_CTOR
#endif
}

RandomAccessIterator	(RandomAccessIterator const & it)
	:_M_current(it.base())
{
#ifdef __DEBUG__
CPY_CTOR
#endif
}

~RandomAccessIterator	(void)
{
#ifdef __DEBUG__
DTOR
#endif
}

#  undef CLASS_NAME
# endif
#endif

