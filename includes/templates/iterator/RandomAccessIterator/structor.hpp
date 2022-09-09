/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:54:46 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/09 10:59:37 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RANDOMACCESSITERATOR_HPP
# ifndef RANDOMACCESSITERATOR_STRUCTOR_HPP
#  define RANDOMACCESSITERATOR_STRUCTOR_HPP
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

template
<
	typename Iter
>
RandomAccessIterator
	(RandomAccessIterator<Iter,
	 typename ft::enable_if<
	 	(ft::is_same<Iter, typename Container::pointer>::value),
			Container>::type
	 > const & it)
	:_M_current(it.base())
{	}

~RandomAccessIterator	(void)
{
#ifdef __DEBUG__
DTOR
#endif
}

#  undef CLASS_NAME
# endif
#endif

