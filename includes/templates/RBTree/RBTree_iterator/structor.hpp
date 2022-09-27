/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:45:07 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/23 16:58:38 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_ITERATOR_HPP
#ifndef RBTREE_ITERATOR_STRUCTOR_HPP
# define RBTREE_ITERATOR_STRUCTOR_HPP

RBTree_iterator	(void)
	:_current()
{
#ifdef __DEBUG__
DFL_CTOR
#endif
}

RBTree_iterator	(node_pointer node)
	:_current(node)
{
#ifdef __DEBUG__
PAR_CTOR
#endif
}

RBTree_iterator	(RBTree_iterator const & src)
	:_current(src.base())
{
#ifdef __DEBUG__
CPY_CTOR
#endif
}

template < typename _T >
RBTree_iterator	(RBTree_iterator<_T> const & src)
	:_current(src.base())
{
#ifdef __DEBUG__
CONST_CPY_CTOR
#endif
}

# endif
#endif

