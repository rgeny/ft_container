/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:47:50 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/22 22:54:50 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef REVERSE_ITERATOR_HPP
# ifndef REVERSE_ITERATOR_STRUCTOR_HPP
#  define REVERSE_ITERATOR_STRUCTOR_HPP

reverse_iterator	(void)
	:current()
{
#ifdef __DEBUG__
DFL_CTOR
#endif
}

explicit reverse_iterator	(iterator_type	src)
	:current(src)
{
#ifdef __DEBUG__
PAR_CTOR
#endif
}

reverse_iterator	(reverse_iterator const & src)
	:current(src.base())
{
#ifdef __DEBUG__
CPY_CTOR
#endif
}

template < typename Iter >
reverse_iterator	(reverse_iterator<Iter> const & src)
	:current(src.base())
{
#ifdef __DEBUG__
std::cout	<< CLASS_NAME " const cpy constructor."
			<< std::endl;
#endif
}


# endif
#endif

