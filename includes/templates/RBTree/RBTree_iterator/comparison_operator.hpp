/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparison_operator.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgeny <rgeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:51:21 by rgeny             #+#    #+#             */
/*   Updated: 2022/09/23 16:54:03 by rgeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifdef RBTREE_ITERATOR_HPP
#ifndef RBTREE_ITERATOR_COMPARISON_OPERATOR_HPP
# define RBTREE_ITERATOR_COMPARISON_OPERATOR_HPP

template
<
	typename _T_left,
	typename _T_right
>
bool	operator==	(RBTree_iterator<_T_left> const & lhs,
					 RBTree_iterator<_T_right> const & rhs)
{	return (lhs.base() == rhs.base());	}

template
<
	typename _T
>
bool	operator==	(RBTree_iterator<_T> const & lhs,
					 RBTree_iterator<_T> const & rhs)
{	return (lhs.base() == rhs.base());	}


template
<
	typename _T_left,
	typename _T_right
>
bool	operator!=	(RBTree_iterator<_T_left> const & lhs,
					 RBTree_iterator<_T_right> const & rhs)
{	return ( ! (lhs == rhs) );	}

template
<
	typename _T
>
bool	operator!=	(RBTree_iterator<_T> const & lhs,
					 RBTree_iterator<_T> const & rhs)
{	return ( ! (lhs == rhs) );	}

# endif
#endif

