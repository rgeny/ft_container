/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structor.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:45:07 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/28 17:47:21 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_ITERATOR_HPP
#ifndef RBTREE_ITERATOR_STRUCTOR_HPP
# define RBTREE_ITERATOR_STRUCTOR_HPP

Tree_iterator	(void)
	:_current()
{
#ifdef __DEBUG__
DFL_CTOR
#endif
}

Tree_iterator	(node_pointer node)
	:_current(node)
{
#ifdef __DEBUG__
PAR_CTOR
#endif
}

Tree_iterator	(Tree_iterator const & src)
	:_current(src.base())
{
#ifdef __DEBUG__
CPY_CTOR
#endif
}

template < typename _T >
Tree_iterator	(Tree_iterator<_T> const & src)
	:_current(src.base())
{
#ifdef __DEBUG__
CONST_CPY_CTOR
#endif
}

# endif
#endif

